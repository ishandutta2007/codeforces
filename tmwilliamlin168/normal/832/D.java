import java.io.*;
import java.util.*;

public class Main {
	
	//PLEASE HACK MY SOLUTION IT IS EASY TO UNDERSTAND
	
	static int[] log=new int[100001], depth;
	static List<Integer>[] graph;
	static int cDepth=0, n, q;
	static int[][] ancestors;

	public static void main(String[] args) {
		log[1]=0;
		for(int i=2; i<log.length; ++i)
			log[i]=log[i>>1]+1;
		
		StdIn in = new StdIn();
		n=in.nextInt();
		q=in.nextInt();
		graph = new List[n];
		depth=new int[n];
		ancestors = new int[n][log[n]+1];
		for(int i=0; i<n; ++i)
			graph[i]=new ArrayList<Integer>();
		for(int i=1; i<n; ++i) {
			int p_i=in.nextInt()-1;
			graph[i].add(p_i);
			graph[p_i].add(i);
		}
		dfs(0, -1);
		for(int i=1; i<ancestors[0].length; ++i) {
			for(int j=0; j<n; ++j) {
				if(ancestors[j][i-1]==-1)
					ancestors[j][i]=-1;
				else
					ancestors[j][i]=ancestors[ancestors[j][i-1]][i-1];
			}
		}
		StringBuilder output = new StringBuilder();
		for(int q_i=0; q_i<q; ++q_i) {
			int a=in.nextInt()-1, b=in.nextInt()-1, c=in.nextInt()-1;
			if(a==b&&b==c) {
				output.append("1\n");
				continue;
			}
			int ab=lca(a, b), ac=lca(a, c), bc=lca(b, c);
			if(a==b) {
				output.append(depth[a]+depth[c]-2*depth[ac]+1).append('\n');
				continue;
			}
			if(a==c||b==c) {
				output.append(depth[a]+depth[b]-2*depth[ab]+1).append('\n');
				continue;
			}
			int max=0;
			max=Math.max((depth[a]+depth[b]-2*depth[ab]+depth[a]+depth[c]-2*depth[ac]-(depth[b]+depth[c]-2*depth[bc]))/2+1, max);
			max=Math.max((depth[a]+depth[b]-2*depth[ab]+depth[b]+depth[c]-2*depth[bc]-(depth[a]+depth[c]-2*depth[ac]))/2+1, max);
			max=Math.max((depth[a]+depth[c]-2*depth[ac]+depth[b]+depth[c]-2*depth[bc]-(depth[a]+depth[b]-2*depth[ab]))/2+1, max);
			output.append(max).append('\n');
		}
		System.out.print(output);
	}
	
	static int lca(int v, int w) {
		if(depth[v]<depth[w]) {
			v^=w;
			w^=v;
			v^=w;
		}
		int depthDiff=depth[v]-depth[w];
		v=ancestor(v, depthDiff);
		if(v==w)
			return v;
		else {
			for(int i=log[n]; i>=0; --i) {
				if(ancestors[v][i]!=ancestors[w][i]) {
					v=ancestors[v][i];
					w=ancestors[w][i];
				}
			}
			return ancestors[v][0];
		}
	}

	static void dfs(int node, int parent) {
		ancestors[node][0]=parent;
		depth[node]=cDepth;
		++cDepth;
		for(int neighbor : graph[node])
			if(neighbor!=parent)
				dfs(neighbor, node);
		--cDepth;
	}
	
    static int ancestor(int v, int level) {
        int pow=0;
        while(level!=0) {
            if((level&1)==1)
                v=ancestors[v][pow];
            level>>=1;
            ++pow;
        }
        return v;
    }
	
	interface Input {
		public String next();
		public String nextLine();
		public int nextInt();
		public long nextLong();
		public double nextDouble();
	}
	static class StdIn implements Input {
		final private int BUFFER_SIZE = 1 << 17;
		final private int STRING_SIZE = 1 << 17;
		private DataInputStream din;
		private byte[] buffer;
		private int bufferPointer, bytesRead;

		public StdIn() {
			din = new DataInputStream(System.in);
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public StdIn(String filename) {
	        try{
	            din = new DataInputStream(new FileInputStream(filename));
	        } catch(Exception e) {
	            throw new RuntimeException();
	        }
			buffer = new byte[BUFFER_SIZE];
			bufferPointer = bytesRead = 0;
		}
		
		public String next() {
			byte[] buf = new byte[STRING_SIZE]; // string length
			int cnt = 0, c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				buf[cnt++] = (byte) c;
				c=read();
			}
			return new String(buf, 0, cnt);
		}

		public String nextLine() {
			byte[] buf = new byte[STRING_SIZE]; // line length
			int cnt = 0, c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				buf[cnt++] = (byte) c;
				c = read();
			}
			return new String(buf, 0, cnt);
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
			{
				ret = ret * 10 + c - '0';
			}  while ((c = read()) >= '0' && c <= '9');

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
			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');
			if (neg)
				return -ret;
			return ret;
		}

		public double nextDouble() {
			double ret = 0, div = 1;
			byte c = read();
			while (c <= ' ')
				c = read();
			boolean neg = (c == '-');
			if (neg)
				c = read();

			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');

			if (c == '.')
			{
				while ((c = read()) >= '0' && c <= '9')
				{
					ret += (c - '0') / (div *= 10);
				}
			}

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