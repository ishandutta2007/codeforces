import java.io.*;
import java.util.*;

public class MainC {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), m=in.nextInt(), h=in.nextInt();
		int[] u = in.readIntArray(n, 0);
		List<Integer>[] graph = new List[n];
		for(int i=0; i<n; ++i)
			graph[i] = new ArrayList<Integer>();
		for(int i=0; i<m; ++i) {
			int x=in.nextInt()-1, y=in.nextInt()-1;
			if((u[x]+1)%h==u[y])
				graph[x].add(y);
			if((u[y]+1)%h==u[x])
				graph[y].add(x);
		}
		SCCFinder sf = new SCCFinder(graph);
		out.println(sf.ans.size());
		for(int ansi : sf.ans)
			out.print((ansi+1)+" ");
		out.close();
	}
	
	static class SCCFinder {
		List<Integer>[] graph;
		List<List<Integer>> sccs = new ArrayList<List<Integer>>();
		int[] tin, low, who;
		Stack<Integer> st = new Stack<Integer>();
		boolean[] inst;
		int n, time=1;
		List<Integer> ans;
		
		SCCFinder(List<Integer>[] graph) {
			this.graph=graph;
			n=graph.length;
			tin = new int[n];
			low = new int[n];
			who = new int[n];
			inst = new boolean[n];
			for(int i=0; i<n; ++i)
				if(tin[i]==0)
					dfs(i);
			for(List<Integer> scc : sccs) {
				boolean leaf=true;
				for(int u : scc)
					for(int v : graph[u])
						if(who[u]!=who[v])
							leaf=false;
				if(leaf&&(ans==null||ans.size()>scc.size()))
					ans=scc;
			}
		}
		void dfs(int u) {
			tin[u]=low[u]=time++;
			st.push(u);
			inst[u]=true;
			for(int v : graph[u]) {
				if(tin[v]==0) {
					dfs(v);
					low[u]=Math.min(low[u], low[v]);
				} else if(inst[v])
					low[u]=Math.min(low[u], tin[v]);
			}
			if(tin[u]==low[u]) {
				List<Integer> scc = new ArrayList<Integer>();
				do {
					scc.add(st.peek());
					inst[st.peek()]=false;
					who[st.peek()]=sccs.size();
				} while(st.pop()!=u);
				sccs.add(scc);
			}
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