import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final long M=(long)1e9+7;
	static long[] fac, faci;
	
	public static void main(String[] args) {
		int n=in.nextInt();
		fac = new long[n+1];
		faci = new long[n+1];
		fac[0]=faci[0]=1;
		for(int i=1; i<=n; ++i)
			faci[i]=modI(fac[i]=fac[i-1]*i%M, M);
		List<List<Integer>> grps = new ArrayList<List<Integer>>();
		for(int i=0; i<n; ++i) {
			int ai=in.nextInt();
			for(int j=0; ; ++j) {
				if(j>=grps.size())
					grps.add(new ArrayList<Integer>());
				if(grps.get(j).size()>0&&!ps((long)grps.get(j).get(0)*ai))
					continue;
				grps.get(j).add(ai);
				break;
			}
		}
		long[][] dp = new long[grps.size()][n-grps.size()+1];
		dp[0][grps.get(0).size()-1]=fac[grps.get(0).size()];
		int ad=grps.get(0).size();
		for(int i=1; i<grps.size(); ++i) {
			for(int j=0; j<dp[i-1].length; ++j) {
				if(dp[i-1][j]==0)
					continue;
				for(int k=0; k<grps.get(i).size(); ++k)
					for(int l=Math.max(grps.get(i).size()+j-k-ad-1, 0); l<=Math.min(grps.get(i).size()-k, j); ++l)
						dp[i][j+k-l]=(fac[grps.get(i).size()]*nck(j, l)%M*nck(ad+1-j, grps.get(i).size()-k-l)%M*nck(grps.get(i).size()-1, k)%M*dp[i-1][j]+dp[i][j+k-l])%M;
			}
			ad+=grps.get(i).size();
		}
		//out.println(Arrays.deepToString(dp));
		out.println(dp[grps.size()-1][0]);
		out.close();
	}
	
	static long modI(long a, long m) {
		return (a%=m)<=1?1:((1-modI(m%a, a)*m)/a+m)%m;
	}
	
	static long nck(int n, int k) {
		return fac[n]*faci[k]%M*faci[n-k]%M;
	}
	
	static boolean ps(long x) {
		long lb=1, rb=M;
		while(lb<=rb) {
			long mb=(lb+rb)/2;
			if(mb*mb==x)
				return true;
			if(mb*mb<x)
				lb=mb+1;
			else
				rb=mb-1;
		}
		return false;
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