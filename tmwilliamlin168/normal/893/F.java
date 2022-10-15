import java.io.*;
import java.util.*;

public class MainF {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	static List<Integer>[] graph, nodesAtDep;
	static int[] dep;
	static int[][] lc, rc;
	
	public static void main(String[] args) {
		int n=in.nextInt(), r=in.nextInt()-1;
		int[] a = new int[n], lg = new int[n];
		graph = new List[n];
		nodesAtDep = new List[n];
		dep = new int[n];
		lg[0]=-2;
		for(int i=0; i<n; ++i) {
			a[i]=in.nextInt();
			lg[i]=lg[i>>1]+1;
			graph[i] = new ArrayList<Integer>();
			nodesAtDep[i] = new ArrayList<Integer>();
		}
		lg[0]=0;
		lc = new int[lg[n-1]+1][n];
		rc = new int[lg[n-1]+1][n];
		for(int i=0; i<n-1; ++i) {
			int u=in.nextInt()-1, v=in.nextInt()-1;
			graph[u].add(v);
			graph[v].add(u);
		}
		dfs1(r, -1);
		for(int i=0; i<n; ++i) {
			if(lc[0][i]==-1)
				continue;
			if(nodesAtDep[dep[i]+1].size()>lc[0][i])
				lc[0][i]=nodesAtDep[dep[i]+1].get(lc[0][i]);
			else
				lc[0][i]=-1;
		}
		for(int i=1; i<=lg[n-1]; ++i) {
			for(int j=0; j<n; ++j) {
				lc[i][j]=lc[i-1][j]==-1?-1:lc[i-1][lc[i-1][j]];
				rc[i][j]=rc[i-1][j]==-1?-1:rc[i-1][rc[i-1][j]];
			}
		}
		int[] pos = new int[n], ord = new int[n];
		int[][][] table = new int[lg[n-1]+1][lg[n-1]+1][n];
		for(int i1=0, i2=0; i1<n; ++i1) {
			for(int u : nodesAtDep[i1]) {
				pos[u]=i2++;
				ord[pos[u]]=u;
				table[0][0][pos[u]]=a[u];
			}
		}
		for(int i=1; i<=lg[n-1]; ++i)
			for(int j=0; j+(1<<i)<=n; ++j)
				table[0][i][j]=Math.min(table[0][i-1][j], table[0][i-1][j+(1<<(i-1))]);
		for(int i=1; i<=lg[n-1]; ++i) {
			for(int j=0; j<=lg[n-1]; ++j) {
				for(int k=0; k+(1<<j)<=n; ++k) {
					int li=lc[i-1][ord[k]], ri=rc[i-1][ord[k+(1<<j)-1]];
					if(li==-1||ri==-1||(li=pos[li])>(ri=pos[ri])) {
						table[i][j][k]=table[i-1][j][k];
						continue;
					}
					int j2=lg[ri-li];
					table[i][j][k]=Math.min(table[i-1][j][k], Math.min(table[i-1][j2][li], table[i-1][j2][ri-(1<<j2)+1]));
				}
			}
		}
		int m=in.nextInt(), ans=0;
		while(m-->0) {
			int x=(in.nextInt()+ans)%n, k=(in.nextInt()+ans)%n+1, li=pos[x], ri=li;
			ans=Integer.MAX_VALUE;
			for(int i=lg[n-1]; i>=0; --i) {
				if(k<1<<i)
					continue;
				int j=lg[ri-li];
				ans=Math.min(Math.min(table[i][j][li], table[i][j][ri-(1<<j)+1]), ans);
				li=lc[i][ord[li]];
				ri=rc[i][ord[ri]];
				if(li==-1||ri==-1||(li=pos[li])>(ri=pos[ri]))
					break;
				k-=1<<i;
			}
			out.println(ans);
		}
		out.close();
	}
	
	static void dfs1(int u, int p) {
		if(p!=-1)
			dep[u]=dep[p]+1;
		nodesAtDep[dep[u]].add(u);
		if(dep[u]+1<nodesAtDep.length)
			lc[0][u]=nodesAtDep[dep[u]+1].size();
		else
			lc[0][u]=-1;
		for(int v : graph[u])
			if(v!=p)
				dfs1(v, u);
		if(dep[u]+1<nodesAtDep.length&&!nodesAtDep[dep[u]+1].isEmpty())
			rc[0][u]=nodesAtDep[dep[u]+1].get(nodesAtDep[dep[u]+1].size()-1);
		else
			rc[0][u]=-1;
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