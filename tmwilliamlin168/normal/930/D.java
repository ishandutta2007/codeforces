import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final int e5=(int)1e5;
	
	public static void main(String[] args) {
		int n=in.nextInt();
		List<Pair> pts1 = new ArrayList<Pair>(), pts2 = new ArrayList<Pair>();
		for(int i=0; i<n; ++i) {
			int x=in.nextInt(), y=in.nextInt();
			if((x+y)%2==0)
				pts1.add(new Pair((x+y)/2+e5, (x-y)/2+e5));
			else
				pts2.add(new Pair((x+1+y)/2+e5, (x+1-y)/2+e5));
		}
		out.println(solve(pts1)+solve(pts2));
		out.close();
	}
	
	static long solve(List<Pair> pts) {
		int n=pts.size();
		int[] pmn1 = new int[2*e5+1], pmx1 = new int[2*e5+1], pmn2 = new int[2*e5+1], pmx2 = new int[2*e5+1];
		Arrays.fill(pmn1, 2*e5);
		Arrays.fill(pmn2, 2*e5);
		for(Pair p : pts) {
			pmn1[p.a]=Math.min(p.b, pmn1[p.a]);
			pmx1[p.a]=Math.max(p.b, pmx1[p.a]);
			pmn2[p.a]=Math.min(p.b, pmn2[p.a]);
			pmx2[p.a]=Math.max(p.b, pmx2[p.a]);
		}
		long t=0;
		for(int i=1; i<=2*e5; ++i) {
			pmn1[i]=Math.min(pmn1[i-1], pmn1[i]);
			pmx1[i]=Math.max(pmx1[i-1], pmx1[i]);
		}
		for(int i=2*e5; i>0; --i) {
			t+=Math.max(Math.min(pmx1[i-1], pmx2[i])-Math.max(pmn1[i-1], pmn2[i]), 0);
			pmn2[i-1]=Math.min(pmn2[i], pmn2[i-1]);
			pmx2[i-1]=Math.max(pmx2[i], pmx2[i-1]);
		}
		return t;
	}
	
	static class Pair {
		int a, b;
		Pair(int a, int b) {
			this.a=a;
			this.b=b;
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