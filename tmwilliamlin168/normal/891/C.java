import java.io.*;
import java.util.*;

public class MainC {
	public static void main(String[] args) {
		final int maxW=(int)5e5;
		
		List<Integer>[] ew = new List[maxW+1];
		List<Pair>[] qew = new List[maxW+1];
		for(int i=1; i<=maxW; ++i) {
			ew[i] = new ArrayList<Integer>();
			qew[i] = new ArrayList<Pair>();
		}
		StdIn in = new StdIn();
		PrintWriter out = new PrintWriter(System.out);
		int n=in.nextInt(), m=in.nextInt();
		int[] u = new int[m], v = new int[m], w = new int[m];
		for(int i=0; i<m; ++i) {
			u[i]=in.nextInt()-1;
			v[i]=in.nextInt()-1;
			w[i]=in.nextInt();
			ew[w[i]].add(i);
		}
		int q=in.nextInt();
		for(int qi=0; qi<q; ++qi) {
			int k=in.nextInt();
			for(int j=0; j<k; ++j) {
				int a=in.nextInt()-1;
				qew[w[a]].add(new Pair(qi, a));
			}
		}
		boolean[] nok = new boolean[q];
		PDSU dsu = new PDSU(n);
		for(int cW=1; cW<=maxW; ++cW) {
			int dsuT=dsu.ops.size();
			Collections.sort(qew[cW], new Comparator<Pair>() {
				public int compare(Pair a, Pair b) {
					return a.a-b.a;
				}
			});
			for(int i=0; i<qew[cW].size(); ++i) {
				Pair qe = qew[cW].get(i);
				if(dsu.root(u[qe.b])==dsu.root(v[qe.b]))
					nok[qe.a]=true;
				else
					dsu.union(u[qe.b], v[qe.b]);
				if(i==qew[cW].size()-1||qe.a!=qew[cW].get(i+1).a)
					while(dsu.ops.size()>dsuT)
						dsu.undo();
			}
			for(int e : ew[cW])
				dsu.union(u[e], v[e]);
		}
		for(int qi=0; qi<q; ++qi)
			out.println(nok[qi]?"NO":"YES");
		out.close();
	}
	
	static class Pair {
		int a, b;
		Pair(int a, int b) {
			this.a=a;
			this.b=b;
		}
	}
	
	static class PDSU {
		int[] p, s;
		Stack<OP> ops = new Stack<OP>();
		PDSU(int n) {
			p = new int[n];
			for(int i=0; i<n; ++i)
				p[i]=i;
			s = new int[n];
			for(int i=0; i<n; ++i)
				s[i]=1;
		}
		void union(int a, int b) {
			a=root(a);
			b=root(b);
			if(a==b)
				return;
			if(s[b]>s[a]) {
				a^=b;
				b^=a;
				a^=b;
			}
			ops.push(new OP(a, b, s[a]));
			s[a]+=s[b];
			p[b]=a;
		}
		int root(int a) {
			return p[a]==a?a:root(p[a]);
		}
		void undo() {
			OP op=ops.pop();
			p[op.b]=op.b;
			s[op.a]=op.s;
		}
		class OP {
			int a, b, s;
			OP(int a, int b, int s) {
				this.a=a;
				this.b=b;
				this.s=s;
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