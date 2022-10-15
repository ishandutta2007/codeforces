import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final int INF=(int)2e9;
	
	public static void main(String[] args) {
		int n=in.nextInt(), m1=in.nextInt(), m2=in.nextInt(), t=in.nextInt(), m3=0;
		int[] x1 = in.readIntArray(m1, 0), x2 = in.readIntArray(m2, 0), x3 = new int[m1+m2+1];
		boolean[][] bl = new boolean[2][m1+m2+1];
		x3[m3++]=0;
		for(int i1=0, i2=0; i1<m1||i2<m2;) {
			if(i1<m1&&i2<m2&&x1[i1]==x2[i2]) {
				bl[0][m3-1]=bl[1][m3-1]=true;
				x3[m3++]=x1[i1++]+1;
				++i2;
			} else if(i2>=m2||i1<m1&&x1[i1]<x2[i2]) {
				bl[0][m3-1]=true;
				x3[m3++]=x1[i1++]+1;
			} else {
				bl[1][m3-1]=true;
				x3[m3++]=x2[i2++]+1;
			}
		}
		int[][] dp = new int[2][m3];
		Arrays.fill(dp[0], -INF);
		Arrays.fill(dp[1], -INF);
		dp[0][0]=0;
		boolean[][] sw = new boolean[2][m3];
		for(int i=0; i<m3-1; ++i) {
			if(dp[0][i]<0&&dp[1][i]<0) {
				System.out.println("No");
				return;
			}
			if(x3[i+1]==x3[i]+1) {
				if((!bl[0][i]||dp[0][i]>t)&&Math.min(dp[0][i]-(bl[0][i]?t:0), t)>dp[1][i]&&!bl[1][i]) {
					dp[1][i]=Math.min(dp[0][i]-(bl[0][i]?t:0), t);
					sw[1][i]=true;
				} else if((!bl[1][i]||dp[1][i]>t)&&Math.min(dp[1][i]-(bl[1][i]?t:0), t)>dp[0][i]&&!bl[0][i]) {
					dp[0][i]=Math.min(dp[1][i]-(bl[1][i]?t:0), t);
					sw[0][i]=true;
				}
			} else {
				if(Math.min(dp[0][i], t)>dp[1][i]) {
					dp[1][i]=Math.min(dp[0][i], t);
					sw[1][i]=true;
				} else if(Math.min(dp[1][i], t)>dp[0][i]) {
					dp[0][i]=Math.min(dp[1][i], t);
					sw[0][i]=true;
				}
			}
			if(dp[0][i]>=0&&dp[0][i]+x3[i+1]-x3[i]-2>=(bl[0][i]?t:0))
				dp[0][i+1]=dp[0][i]+x3[i+1]-x3[i]-(bl[0][i]?t:0);
			if(dp[1][i]>=0&&dp[1][i]+x3[i+1]-x3[i]-2>=(bl[1][i]?t:0))
				dp[1][i+1]=dp[1][i]+x3[i+1]-x3[i]-(bl[1][i]?t:0);
		}
		if(dp[0][m3-1]<0&&dp[1][m3-1]<0) {
			System.out.println("No");
			return;
		}
		out.println("Yes");
		List<Integer> swx = new ArrayList<Integer>();
		swx.add(m3);
		for(int i=m3-1, j=dp[0][i]>=0?0:1; i>=0; --i) {
			if(sw[j][i]) {
				swx.add(i);
				j^=1;
			}
		}
		out.println(swx.size()-1);
		for(int i=swx.size()-1; i>0; --i)
			out.print(x3[swx.get(i)]+" ");
		out.println();
		List<Pair> bs = new ArrayList<Pair>();
		int k=1;
		if(swx.get(swx.size()-1)!=0) {
			swx.add(0);
			k=0;
		}
		for(int i=swx.size()-1; i>0; --i, k^=1) {
			int ns=0;
			for(int j=swx.get(i); j<swx.get(i-1); ++j)
				if(bl[k][j])
					++ns;
			if(i>1&&x3[swx.get(i-1)+1]==x3[swx.get(i-1)]+1&&bl[k][swx.get(i-1)])
				++ns;
			for(int j=1; j<=ns; ++j)
				bs.add(new Pair(x3[swx.get(i)]+j*t-dp[k][swx.get(i)], k+1));
		}
		out.println(bs.size());
		for(Pair p : bs)
			out.println(p.a+" "+p.b);
		out.close();
	}
	
	static class Pair {
		int a, b;
		Pair(int a, int b) {
			this.a=a;
			this.b=b;
		}
	}
	
	static class StdIn {
		final private int BUFFER_SIZE = 1 << 16;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;
		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public StdIn(InputStream in) {
			try{
				din = new DataInputStream(in);
			} catch(Exception e) {
				throw new RuntimeException();
			}
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		public String next() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c=read();
			}
			return s.toString();
		}
		public String nextLine() {
			int c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			StringBuilder s = new StringBuilder();
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				s.append((char)c);
				c = read();
			}
			return s.toString();
		}
		public int nextInt() {
			int ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');

			if (neg)
				return -ret;
			return ret;
		}
		public int[] readIntArray(int n, int os) {
			int[] ar = new int[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextInt()+os;
			return ar;
		}
		public long nextLong() {
			long ret = 0;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}
		public long[] readLongArray(int n, long os) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong()+os;
			return ar;
		}
		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();
			do
				ret = ret * 10 + c - '0';
			while ((c = read()) >= '0' && c <= '9');
			if (c == '.')
				while ((c = read()) >= '0' && c <= '9')
					ret += (c - '0') / (div *= 10);
			if (neg)
				return -ret;
			return ret;
		}
		private void fillBuffer() throws IOException {
			bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
			if (bytesRead == -1)
				buffer[0] = -1;
		}
		private byte read() {
			try{
				if (bufferPointer == bytesRead)
					fillBuffer();
				return buffer[bufferPointer++];
			} catch(IOException e) {
				throw new RuntimeException();
			}
		}
		public void close() throws IOException {
			if (din == null)
				return;
			din.close();
		}
	}
}