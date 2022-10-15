import java.io.*;
import java.util.*;

public class MainA {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final long INF=(long)1e18;
	static List<Integer>[] adj;
	static long[] a, s, l;
	static long ans;
	
	public static void main(String[] args) {
		int n=in.nextInt();
		adj = new List[n];
		for(int i=0; i<n; ++i)
			adj[i] = new ArrayList<Integer>();
		a = in.readLongArray(n, 0);
		s = new long[n];
		l = new long[n];
		Arrays.fill(l, 1);
		for(int i=0; i<n-1; ++i) {
			int u=in.nextInt()-1, v=in.nextInt()-1;
			adj[u].add(v);
			adj[v].add(u);
		}
		dfs(0, -1);
		out.println(ans);
		out.close();
	}
	
	static void dfs(int u, int p) {
		long mic=INF, cn=(adj[u].size()-(p==-1?0:1));
		if(cn==0) {
			s[u]=a[u];
			return;
		}
		for(int v : adj[u]) {
			if(v==p)
				continue;
			dfs(v, u);
			l[u]=l[u]/gcd(l[u], l[v])>INF/l[v]?INF:l[u]/gcd(l[u], l[v])*l[v];
		}
		for(int v : adj[u])
			if(v!=p)
				mic=Math.min(s[v]/l[u]*l[u], mic);
		for(int v : adj[u])
			if(v!=p)
				ans+=s[v]-mic;
		s[u]=mic*cn;
		l[u]=l[u]>INF/cn?INF:l[u]*cn;
//		System.out.println(u+" "+s[u]+" "+l[u]+" "+mic+" "+ans);
	}
	
	static long gcd(long a, long b) {
		while((a%=b)>0&&(b%=a)>0);
		return a^b;
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