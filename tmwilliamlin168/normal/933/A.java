import java.io.*;
import java.util.*;

public class MainA {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		int[] a = in.readIntArray(n), p1 = new int[n+1], p2 = new int[n+1];
		for(int i=0; i<n; ++i) {
			p1[i+1]=p1[i];
			p2[i+1]=p2[i];
			if(a[i]==1)
				++p1[i+1];
			else
				++p2[i+1];
		}
		int ans=0;
		int[][] dp1 = new int[n][n], dp2 = new int[n][n];
		for(int i=0; i<n; ++i) {
			int s1=a[i]==1?1:0, lmx=0;
			dp1[i][i]=1;
			for(int j=i+1; j<n; ++j) {
				if(a[j]==1) {
					dp1[i][j]=s1+1;
					++s1;
				} else {
					lmx=dp1[i][j]=Math.max(s1, lmx)+1;
				}
			}
			int s2=a[i]==2?1:0;
			lmx=0;
			dp2[i][i]=1;
			for(int j=i+1; j<n; ++j) {
				if(a[j]==2) {
					dp2[i][j]=s2+1;
					++s2;
				} else {
					lmx=dp2[i][j]=Math.max(s2, lmx)+1;
				}
			}
		}
		for(int i=0; i<n; ++i) {
			for(int j=i; j<n; ++j) {
				ans=Math.max((i>0?dp1[0][i-1]:0)+p2[n]-p2[i], ans);
				ans=Math.max(p1[i]+dp2[i][j]+p2[n]-p2[j+1], ans);
				ans=Math.max(p1[j]+dp1[j][n-1], ans);
			}
		}
		//out.println(p1[2]);
		out.println(ans);
		out.close();
	}
	
	interface Input {
		public String next();
		public String nextLine();
		public int nextInt();
		public long nextLong();
		public double nextDouble();
	}
	static class StdIn implements Input {
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