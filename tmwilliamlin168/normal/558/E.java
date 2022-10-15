
import java.io.*;
import java.util.*;

public class MainE {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), q=in.nextInt();
		char[] s = in.next().toCharArray();
		SegTree[] trees = new SegTree[26];
		int[][] a = new int[26][n];
		for(int i=0; i<n; ++i)
			a[s[i]-'a'][i]=1;
		for(int i=0; i<26; ++i)
			trees[i] = new SegTree(a[i]);
		while(q-->0) {
			int l=in.nextInt()-1, r=in.nextInt()-1, k=in.nextInt();
			int[] cnt = new int[26];
			for(int i=0; i<26; ++i) {
				cnt[i]=trees[i].sum(l, r);
				trees[i].set(l, r, 0);
			}
			if(k==1)
				for(int i=0; i<26; l+=cnt[i], ++i)
					trees[i].set(l, l+cnt[i]-1, 1);
			else
				for(int i=0; i<26; r-=cnt[i], ++i)
					trees[i].set(r-cnt[i]+1, r, 1);
		}
		for(int i=0; i<26; ++i)
			for(int j=0; j<n; ++j)
				if(trees[i].sum(j, j)>0)
					s[j]=(char)(i+'a');
		out.println(s);
		out.close();
	}
	
	static class SegTree {
		int[] a, d;
		int n, x, l1, r1;
		SegTree(int b[]) {
			n=b.length;
			a = new int[4*n];
			d = new int[4*n];
			Arrays.fill(d, -1);
			build(1, 0, n-1, b);
		}
		void build(int i, int l, int r, int[] b) {
			if(l==r)
				a[i]=b[l];
			else {
				int mid=(l+r)/2;
				build(2*i, l, mid, b);
				build(2*i+1, mid+1, r, b);
				a[i]=a[2*i]+a[2*i+1];
			}
		}
		private void push(int i, int l, int r) {
			if(d[i]==-1)
				return;
			a[i]=d[i]*(r-l+1);
			if(l<r) {
				d[2*i]=d[i];
				d[2*i+1]=d[i];
			}
			d[i]=-1;
		}
		void set(int l, int r, int x) {
			if(l>r)
				return;
			l1=l;
			r1=r;
			this.x=x;
			set2(1, 0, n-1);
		}
		private void set2(int i, int l2, int r2) {
			if(l1<=l2&&r2<=r1) {
				d[i]=x;
				push(i, l2, r2);
			} else {
				int mid=(l2+r2)/2;
				push(2*i, l2, mid);
				push(2*i+1, mid+1, r2);
				if(l1<=mid)
					set2(2*i, l2, mid);
				if(mid<r1)
					set2(2*i+1, mid+1, r2);
				a[i]=a[2*i]+a[2*i+1];
			}
		}
		int sum(int l, int r) {
			l1=l;
			r1=r;
			return sum2(1, 0, n-1);
		}
		private int sum2(int i, int l2, int r2) {
			push(i, l2, r2);
			if(l1<=l2&&r2<=r1)
				return a[i];
			int mid=(l2+r2)/2;
			int r=0;
			if(l1<=mid)
				r+=sum2(2*i, l2, mid);
			if(mid<r1)
				r+=sum2(2*i+1, mid+1, r2);
			return r;
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