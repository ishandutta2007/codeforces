import java.io.*;
import java.util.*;

public class MainB {
	
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt(), k=in.nextInt();
		int[] a = in.readIntArray(n);
		int[] prev = new int[n], cPrev = new int[n+1];
		Arrays.fill(cPrev, -1);
		for(int i=0; i<n; ++i) {
			prev[i]=cPrev[a[i]];
			cPrev[a[i]]=i;
		}
		SegmentTree[] trees = new SegmentTree[k+1];
		for(int i=0; i<=k; ++i)
			trees[i] = new SegmentTree(n+1);
		for(int i=0; i<n; ++i) {
			for(int j=0; j<k; ++j)
				trees[j].add(prev[i]+1, i, 1);
			for(int j=1; j<=k; ++j)
				trees[j].add(i+1, i+1, trees[j-1].get(0, n));
		}
		System.out.println(trees[k].get(n, n));
	}
	
	static class SegmentTree {
		int n, l1, r1, v;
		int[] a, lazy;
		SegmentTree(int n) {
			this.n=n;
			a = new int[4*n];
			lazy = new int[4*n];
		}
		void add(int l, int r, int x) {
			l1=l;
			r1=r;
			v=x;
			add2(1, 0, n-1);
		}
		void add2(int i, int l2, int r2) {
			if(l1<=l2&&r2<=r1) {
				a[i]+=v;
				if(l2<r2) {
					lazy[2*i]+=v;
					lazy[2*i+1]+=v;
				}
			} else {
				int mid=(l2+r2)/2;
				push(i*2, l2, mid);
				push(i*2+1, mid+1, r2);
				if(l1<=mid)
					add2(i*2, l2, mid);
				if(mid<r1)
					add2(i*2+1, mid+1, r2);
				a[i]=Math.max(a[i*2], a[i*2+1]);
			}
		}
		void push(int i, int l, int r) {
			a[i]+=lazy[i];
			if(l<r) {
				lazy[2*i]+=lazy[i];
				lazy[2*i+1]+=lazy[i];
			}
			lazy[i]=0;
		}
		int get(int l, int r) {
			l1=l;
			r1=r;
			return get2(1, 0, n-1);
		}
		int get2(int i, int l2, int r2) {
			push(i, l2, r2);
			if(l1<=l2&&r2<=r1)
				return a[i];
			else {
				int mid=(l2+r2)/2, res=-Integer.MAX_VALUE;
				if(l1<=mid)
					res = Math.max(get2(2*i, l2, mid), res);
				if(mid<r1)
					res = Math.max(get2(2*i+1, mid+1, r2), res);
				return res;
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