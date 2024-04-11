import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final long M=(long)1e9+7;
	static int n=in.nextInt(), m=in.nextInt();
	static Map<Integer, Node> graph = new HashMap<Integer, Node>();
	
	public static void main(String[] args) {
		addNode(1);
		for(int i=0; i<m; ++i) {
			int u=in.nextInt(), v=in.nextInt();
			addNode(u).adj.add(v);
			addNode(v).adj.add(u);
		}
		for(Map.Entry<Integer, Node> nodeEntry : graph.entrySet()) {
			Node u=nodeEntry.getValue();
			for(int i=u.adj.size()-1; i>=0; --i) {
				if(!graph.containsKey(u.adj.get(i))) {
					u.s+=sts(u.adj.get(i));
					u.adj.remove(i);
				}
			}
		}
		long ans=0;
		for(Map.Entry<Integer, Node> nodeEntry : graph.entrySet())
			ans=(dfs(nodeEntry.getKey(), 0)+ans)%M;
		out.println(ans);
		out.close();
	}
	
	static Node addNode(int u) {
		if(u<=0)
			return null;
		Node node = graph.get(u);
		if(node!=null)
			return node;
		node = new Node();
		if(u>1)
			node.adj.add(u/2);
		if(u*2<=n)
			node.adj.add(u*2);
		if(u*2+1<=n)
			node.adj.add(u*2+1);
		graph.put(u, node);
		addNode(u/2);
		return node;
	}
	
	static long sts(int u) {
		long res=0;
		int l=u, r=u;
		while(r<=n) {
			res+=r-l+1;
			l=2*l;
			r=2*r+1;
		}
		return (res+Math.min(r, n)-Math.min(l, n+1)+1)%M;
	}
	
	static long dfs(int u, long ps) {
		Node node=graph.get(u);
		if(ps==0)
			ps=node.s;
		node.active=true;
		long res=ps*node.s;
		for(int v : node.adj)
			if(!graph.get(v).active)
				res+=dfs(v, ps);
		node.active=false;
		return res;
	}
	
	static class Node {
		List<Integer> adj = new ArrayList<Integer>();
		long s=1;
		boolean active;
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