import java.io.*;
import java.util.*;

public class MainC {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final long M=(long)1e9+7;
	
	public static void main(String[] args) {
		int q=in.nextInt();
		while(q-->0) {
			int x1=in.nextInt(), y1=in.nextInt(), x2=in.nextInt(), y2=in.nextInt(), k=in.nextInt();
			out.println((solve(x2, y2, k)-solve(x1-1, y2, k)-solve(x2, y1-1, k)+solve(x1-1, y1-1, k)+2*M)%M);
		}
		out.close();
	}
	
	static int x, y, k;
	static long[][][] dp = new long[31][8][2];
	static long solve(int x1, int y1, int k1) {
		if(x1<=0||y1<=0)
			return 0;
		x=x1;
		y=y1;
		k=k1;
		for(int i=0; i<dp.length; ++i)
			for(int j=0; j<dp[i].length; ++j)
				dp[i][j][0]=-1;
		long[] ans=cdp(30, k1>=1<<30?1:0, 0, 0);
		//System.out.println(x1+" "+y1+" "+k1+" "+ans);
		return (ans[0]+ans[1])%M;
	}
	
	static long[] cdp(int d, int sm, int xf, int yf) {
		long tx=xf==0?x%(1<<(d+1)):1<<(d+1), ty=yf==0?y%(1<<(d+1)):1<<(d+1);
		if(tx==0||ty==0)
			return new long[]{0, 0};
		//if(sm==1)
		//	return new long[]{tx*ty%M, s1(tx, ty)};
		if(d==0) {
			long[] r = new long[]{sm==1?tx*ty:k%2*(xf+yf==2?2:1), sm==1?tx+ty-2:0};
			//System.out.println(d+" "+sm+" "+xf+" "+yf+" "+r[0]+" "+r[1]);
			return r;
		}
		if(dp[d][sm*4+xf*2+yf][0]==-1) {
			long[] ans;
			long ans1=0, ans2=0;
			ans=cdp(d-1, (k>>d)%2|sm, (x>>d)%2|xf, (y>>d)%2|yf);
			ans1+=ans[0];
			ans2+=ans[1];
			if(((x>>d)%2|xf)==1&&((y>>d)%2|yf)==1) {
				ans=cdp(d-1, (k>>d)%2|sm, xf, yf);
				ans1+=ans[0];
				ans2+=ans[1];
			}
			if(((k>>d)%2|sm)==1) {
				if(((x>>d)%2|xf)==1) {
					ans=cdp(d-1, sm, xf, (y>>d)%2|yf);
					ans1+=ans[0];
					ans2+=ans[1]+(ans[0]<<d);
				}
				if(((y>>d)%2|yf)==1) {
					ans=cdp(d-1, sm, (x>>d)%2|xf, yf);
					ans1+=ans[0];
					ans2+=ans[1]+(ans[0]<<d);
				}
			}
			dp[d][sm*4+xf*2+yf]=new long[]{ans1%M, ans2%M};
		}
		//System.out.println(d+" "+sm+" "+xf+" "+yf+" "+dp[d][sm*4+xf*2+yf][0]+" "+dp[d][sm*4+xf*2+yf][1]);
		return dp[d][sm*4+xf*2+yf];
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
		public int[] readIntArray(int n) {
			int[] ar = new int[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextInt();
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
		public long[] readLongArray(int n) {
			long[] ar = new long[n];
			for(int i=0; i<n; ++i)
				ar[i]=nextLong();
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