import java.io.*;
import java.util.*;

public class MainF {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final int n=495, n2=n*n;
	static int[] id = new int[5833], win = new int[n2], quw = new int[n2/2], qul = new int[n2/2];
	static int idi, quwh, quwt, qulh, qult;
	static List<Integer>[] gin = new List[n2], gout = new List[n2];
	
	public static void main(String[] args) {
		dfs1(new int[5], 0, 8);
		for(int i=0; i<n2; ++i) {
			gin[i] = new ArrayList<Integer>();
			gout[i] = new ArrayList<Integer>();
		}
		dfs2(new int[5], new int[5], 0, 8, 8);
		while(quwh<quwt||qulh<qult) {
			while(qulh<qult) {
				for(int v : gin[qul[qulh++]]) {
					if(win[v]!=1) {
						win[v]=1;
						quw[quwt++]=v;
					}
				}
			}
			while(quwh<quwt) {
				for(int v : gin[quw[quwh++]]) {
					if(win[v]!=0)
						continue;
					boolean aw=true;
					for(int w : gout[v]) {
						if(win[w]!=1) {
							aw=false;
							break;
						}
					}
					if(aw) {
						win[v]=-1;
						qul[qult++]=v;
					}
				}
			}
		}
		int t=in.nextInt();
		while(t-->0) {
			int f=in.nextInt();
			int[] a = new int[5], b = new int[5];
			for(int i=0; i<8; ++i)
				++a[in.nextInt()];
			for(int i=0; i<8; ++i)
				++b[in.nextInt()];
			int ai=id[a2i(a)], bi=id[a2i(b)], ci=f==0?ai*n+bi:bi*n+ai;
			out.println(win[ci]==0?"Deal":((win[ci]==1)==(f==0)?"Alice":"Bob"));
		}
		out.close();
	}
	
	static int a2i(int[] a) {
		int r=0;
		for(int i=0, p=1; i<a.length-1; ++i, p*=9)
			r+=p*a[i];
		return r;
	}
	
	static void dfs1(int[] a, int i, int s) {
		if(i>=a.length) {
			id[a2i(a)]=idi++;
			return;
		}
		for(int j=i==a.length-1?s:0; j<=s; ++j) {
			a[i]=j;
			dfs1(a, i+1, s-j);
		}
	}
	
	static void dfs2(int[] a, int[] b, int i, int as, int bs) {
		if(i>=a.length) {
			int ai=id[a2i(a)], bi=id[a2i(b)];
			if(bi==n-1) {
				win[ai*n+bi]=-1;
				qul[qult++]=ai*n+bi;
			}
			for(int j=1; j<a.length; ++j) {
				for(int k=1; k<a.length; ++k) {
					if(a[j]==0||b[k]==0)
						continue;
					--a[j];
					++a[(j+k)%5];
					int ci=id[a2i(a)], u=ai*n+bi, v=bi*n+ci;
					gin[v].add(u);
					gout[u].add(v);
					++a[j];
					--a[(j+k)%5];
				}
			}
			return;
		}
		for(int j=i==a.length-1?as:0; j<=as; ++j) {
			for(int k=i==a.length-1?bs:0; k<=bs; ++k) {
				a[i]=j;
				b[i]=k;
				dfs2(a, b, i+1, as-j, bs-k);
			}
		}
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