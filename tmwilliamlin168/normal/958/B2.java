import java.io.*;
import java.util.*;

public class MainB {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		List<Integer>[] adj = new List[n];
		for(int i=0; i<n; ++i)
			adj[i] = new ArrayList<Integer>();
		for(int i=0; i<n-1; ++i) {
			int u=in.nextInt()-1, v=in.nextInt()-1;
			adj[u].add(v);
			adj[v].add(u);
		}
		int[] qu = new int[n], dist = new int[n], ans = new int[n], par = new int[n];
		int qt=0, qh=0, u=-1;
		qu[qt++]=0;
		Arrays.fill(dist, n);
		dist[0]=0;
		while(qh<qt) {
			u=qu[qh++];
			for(int v : adj[u]) {
				if(dist[v]>=n) {
					qu[qt++]=v;
					dist[v]=dist[u]+1;
				}
			}
		}
		qt=0;
		qh=0;
		qu[qt++]=u;
		Arrays.fill(dist, n);
		dist[u]=0;
		while(qh<qt) {
			u=qu[qh++];
			for(int v : adj[u]) {
				if(dist[v]>=n) {
					qu[qt++]=v;
					par[v]=u;
					dist[v]=dist[u]+1;
				}
			}
		}
		for(int i=n-1; i>=0; --i) {
			dist[qu[i]]=Math.max(-dist[qu[i]], 0);
			if(i>0)
				dist[par[qu[i]]]=Math.min(-(dist[qu[i]]+1), dist[par[qu[i]]]);
		}
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
			public int compare(Integer a, Integer b) {
				return -(dist[a]-dist[b]);
			}
		});
		pq.add(qu[0]);
		for(int i=1; i<n; ++i) {
			if(pq.isEmpty()) {
				ans[i]=ans[i-1];
				continue;
			}
			u=pq.poll();
			ans[i]=ans[i-1]+dist[u]+1;
			while(dist[u]>0) {
				int mv=-1;
				for(int v : adj[u])
					if(v!=par[u]&&(mv==-1||dist[v]>dist[mv]))
						mv=v;
				for(int v : adj[u])
					if(v!=par[u]&&v!=mv)
						pq.add(v);
				u=mv;
			}
		}
		ans[0]=1;
		for(int i=0; i<n; ++i)
			out.print(ans[i]+" ");
		out.close();
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