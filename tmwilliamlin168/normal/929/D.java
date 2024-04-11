import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final int mxC=(int)1e5;
	static final long INF=(long)1e10;
	static int n=in.nextInt(), a=in.nextInt()-1, b=in.nextInt()-1;
	static int[] g = in.readIntArray(n-1), k = in.readIntArray(n), nd = new int[n];
	
	public static void main(String[] args) {
		boolean[] vis = new boolean[mxC+1];
		vis[k[a]]=true;
		for(int i1=a+1, i2=a; i1<n; ++i1) {
			while(i2>0&&!vis[g[i1-1]])
				vis[k[--i2]]=true;
			if(i2==0&&!vis[g[i1-1]])
				i2=-1;
			nd[i1]=i2;
			vis[k[i1]]=true;
		}
		Arrays.fill(vis, false);
		vis[k[a]]=true;
		for(int i1=a-1, i2=a; i1>=0; --i1) {
			while(i2<n-1&&!vis[g[i1]])
				vis[k[++i2]]=true;
			if(i2==n-1&&!vis[g[i1]])
				i2=n;
			nd[i1]=i2;
			vis[k[i1]]=true;
		}
		long ans=cans(b, -1, n);
		out.println(ans>=INF?-1:ans);
		out.close();
	}
	
	static long cans(int d, int lb, int rb) {
		if(nd[d]<=lb||nd[d]>=rb)
			return INF;
		if(nd[d]==a)
			return Math.abs(d-a);
		return Math.abs(d-nd[d])+(nd[d]!=a?(d<a?cans(nd[d], d, rb):cans(nd[d], lb, d)):0);
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