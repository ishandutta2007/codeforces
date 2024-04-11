import java.io.*;
import java.util.*;

public class MainF {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	static int blockSize;
	
	public static void main(String[] args) {
		int n=in.nextInt();
		blockSize=(int)Math.sqrt(n);
		long k=in.nextLong();
		long[] a = in.readLongArray(n), p = new long[n+1], coords = new long[3*(n+1)];
		for(int i=0; i<n; ++i) {
			if(a[i]==1)
				a[i]=in.nextLong();
			else
				a[i]=-in.nextLong();
			p[i+1]=a[i]+p[i];
			coords[3*i+3]=p[i+1]-k;
			coords[3*i+4]=p[i+1];
			coords[3*i+5]=p[i+1]+k;
		}
		coords[0]=-k;
		coords[2]=k;
		Arrays.sort(coords);
		int[] v = new int[n+1], l = new int[n+1], r = new int[n+1];
		for(int i=0; i<=n; ++i) {
			v[i]=Arrays.binarySearch(coords, p[i]);
			l[i]=Arrays.binarySearch(coords, p[i]-k);
			r[i]=Arrays.binarySearch(coords, p[i]+k);
		}
		int q=in.nextInt();
		Query[] queries = new Query[q];
		for(int i=0; i<q; ++i)
			queries[i] = new Query(in.nextInt()-1, in.nextInt(), i);
		Arrays.sort(queries, new Comparator<Query>() {
			public int compare(Query a, Query b) {
				return a.l/blockSize==b.l/blockSize?a.r-b.r:a.l-b.l;
			}
		});
		long[] ans = new long[q], cnt = new long[coords.length];
		long t=0;
		int ql=0, qr=-1;
		for(int i=0; i<q; ++i) {
			Query qi = queries[i];
			while(ql>qi.l) {
				--ql;
				t+=cnt[r[ql]];
				++cnt[v[ql]];
			}
			while(qr<qi.r) {
				++qr;
				t+=cnt[l[qr]];
				++cnt[v[qr]];
			}
			while(ql<qi.l) {
				--cnt[v[ql]];
				t-=cnt[r[ql]];
				++ql;
			}
			while(qr>qi.r) {
				--cnt[v[qr]];
				t-=cnt[l[qr]];
				--qr;
			}
			ans[qi.i]=t;
		}
		for(int i=0; i<q; ++i)
			out.println(ans[i]);
		out.close();
	}
	
	static class Query {
		int l, r, i;
		Query(int l, int r, int i) {
			this.l=l;
			this.r=r;
			this.i=i;
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