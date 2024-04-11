import java.io.*;
import java.util.*;

public class MainB {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static int n=in.nextInt(), m=in.nextInt(), rt=-1, tu;
	static int[] d = in.readIntArray(n);
	static List<Edge>[] graph = new List[n];
	static boolean[] vis = new boolean[n], use = new boolean[m];
	
	public static void main(String[] args) {
		int pr=0;
		for(int i=0; i<n&&rt==-1; ++i) {
			if(d[i]==-1)
				rt=i;
			pr^=d[i];
		}
		if(rt==-1) {
			if(pr==1) {
				System.out.println(-1);
				return;
			}
			rt=0;
		}
		for(int i=0; i<n; ++i)
			graph[i] = new ArrayList<Edge>();
		for(int i=0; i<m; ++i) {
			int u=in.nextInt()-1, v=in.nextInt()-1;
			graph[u].add(new Edge(i, v));
			graph[v].add(new Edge(i, u));
		}
		dfs(rt);
		out.println(tu);
		for(int i=0; i<m; ++i)
			if(use[i])
				out.println(i+1);
		out.close();
	}
	
	static int dfs(int u) {
		int prt=d[u]==1?1:0;
		vis[u]=true;
		for(Edge e : graph[u]) {
			if(vis[e.uv])
				continue;
			int pr=dfs(e.uv);
			if(pr==1) {
				++tu;
				use[e.i]=true;
			}
			prt^=pr;
		}
		return prt;
	}
	
	static class Edge {
		int i, uv;
		Edge(int i, int uv) {
			this.i=i;
			this.uv=uv;
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