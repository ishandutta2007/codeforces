import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), w=in.nextInt();
		Pair[] ps = new Pair[n];
		for(int i=0; i<n; ++i)
			ps[i] = new Pair(in.nextInt(), in.nextInt());
//		List<Pair> p1 = new ArrayList<Pair>(), p2 = new ArrayList<Pair>();
//		for(int i=0; i<n; ++i) {
//			Pair p=new Pair(in.nextInt(), in.nextInt());
//			if(p.a<0)
//				p1.add(p);
//			else
//				p2.add(p);
//		}
//		int m=p2.size();
		Pair[] x = new Pair[n], y = new Pair[n];
		for(int i=0; i<n; ++i) {
//			x[i] = new Pair(p2.get(i).a, -(p2.get(i).b-w));
//			y[i] = new Pair(p2.get(i).a, -(p2.get(i).b+w));
			x[i] = new Pair(Math.abs(ps[i].a), Math.abs(ps[i].b-w));
			y[i] = new Pair(Math.abs(ps[i].a), Math.abs(ps[i].b+w));
		}
		Arrays.sort(x);
		Arrays.sort(y);
		List<Integer>[] toAdd = new List[n];
		for(int i=0; i<n; ++i)
			toAdd[i] = new ArrayList<Integer>();
		for(int i=0; i<n; ++i)
			toAdd[Arrays.binarySearch(y, new Pair(Math.abs(ps[i].a), Math.abs(ps[i].b+w)))]
					.add(Arrays.binarySearch(x, new Pair(Math.abs(ps[i].a), Math.abs(ps[i].b-w))));
		long ans=0;
		FenTree ft = new FenTree(n);
		for(int i=n-1; i>=0; --i) {
			Collections.sort(toAdd[i]);
			for(int ta : toAdd[i]) {
				ans+=ft.qry(ta+1);
				ft.upd(ta, 1);
			}
		}
		out.println(ans);
		out.close();
	}
	
	static class FenTree {
		int[] a;
		FenTree(int n) {
			a = new int[n+1];
		}
		void upd(int i, int x) {
			for(++i; i<a.length; i+=i&-i)
				a[i]+=x;
		}
		int qry(int i) {
			int r=0;
			for(; i>0; i-=i&-i)
				r+=a[i];
			return r;
		}
	}
	
	static class Pair implements Comparable<Pair> {
		int a, b;
		Pair(int a, int b) {
			this.a=a;
			this.b=b;
		}
		public int compareTo(Pair o) {
			return Double.compare((double)a/b, (double)o.a/o.b);
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