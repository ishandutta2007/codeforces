import java.io.*;
import java.util.*;

public class MainF {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), m=in.nextInt();
		List<Pair>[] adj = new List[n];
		for(int i=0; i<n; ++i)
			adj[i] = new ArrayList<Pair>();
		for(int i=0; i<m; ++i) {
			int u=in.nextInt()-1, v=in.nextInt()-1;
			Pair p=new Pair(u^v, i, u, v);
			adj[u].add(p);
			adj[v].add(p);
		}
		BCCFinder bccf = new BCCFinder(adj);
		boolean[] a = new boolean[m];
		for(Set<Pair> bcc : bccf.bccs) {
			Set<Integer> nodes = new HashSet<Integer>();
			for(Pair p : bcc) {
				nodes.add(p.c);
				nodes.add(p.d);
			}
//			System.out.println(nodes+" "+bcc);
			if(nodes.size()==bcc.size())
				for(Pair p : bcc) {
					a[p.b]=true;
//					System.out.println(p);
				}
		}
		int ans1=0;
		for(int i=0; i<m; ++i)
			if(a[i])
				++ans1;
		out.println(ans1);
		for(int i=0; i<m; ++i)
			if(a[i])
				out.print(i+1+" ");
		out.close();
	}
	
	static class BCCFinder {
		List<Pair>[] graph;
		int time=1;
		int[] tin, low;
		Stack<Pair> st = new Stack<Pair>();
		List<Set<Pair>> bccs = new ArrayList<Set<Pair>>();
		List<Integer> aps = new ArrayList<Integer>();
		List<Pair> bridges = new ArrayList<Pair>();
		BCCFinder(List<Pair>[] graph) {
			int n=graph.length;
			this.graph=graph;
			tin = new int[n];
			low = new int[n];
			for(int i=0; i<n; ++i)
				if(tin[i]==0)
					dfs(i, -1);
		}
		void dfs(int u, int p) {
			tin[u]=low[u]=time++;
			for(Pair pr : graph[u]) {
				int v=u^pr.a;
				if(tin[v]==0) {
					int ss=st.size();
					st.push(pr);
					dfs(v, u);
					low[u]=Math.min(low[v], low[u]);
					if(low[v]>=tin[u]) {
						Set<Pair> bcc = new HashSet<Pair>();
						while(ss<st.size())
							bcc.add(st.pop());
						bccs.add(bcc);
					}
				} else if(v!=p) {
					low[u]=Math.min(tin[v], low[u]);
					if(tin[u]>tin[v])
						st.push(pr);
				}
			}
		}
	}
	
	static class Pair {
		int a, b, c, d;
		Pair(int a, int b, int c, int d) {
			this.a=a;
			this.b=b;
			this.c=c;
			this.d=d;
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