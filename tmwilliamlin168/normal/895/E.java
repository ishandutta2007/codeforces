import java.io.*;
import java.util.*;

public class MainE {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), q=in.nextInt();
		double[] a = new double[n];
		for(int i=0; i<n; ++i)
			a[i]=in.nextInt();
		SegTree st = new SegTree(a);
		while(q-->0) {
			int qt=in.nextInt();
			if(qt==1) {
				int l1=in.nextInt()-1, r1=in.nextInt()-1, l2=in.nextInt()-1, r2=in.nextInt()-1;
				double a1=1.0/(r1-l1+1), a2=1.0/(r2-l2+1), b1=a2*st.qry(l2, r2), b2=a1*st.qry(l1, r1);
				st.upd(l1, r1, 1-a1, a1*b1);
				st.upd(l2, r2, 1-a2, a2*b2);
			} else
				out.println(st.qry(in.nextInt()-1, in.nextInt()-1));
		}
		out.close();
	}
	
	static class SegTree {
		int n, l, r;
		double d1, d2;
		double[] a;
		double[] lMult, lAdd;
		SegTree(double[] b) {
			n=b.length;
			a = new double[4*n];
			lMult = new double[4*n];
			Arrays.fill(lMult, 1);
			lAdd = new double[4*n];
			build(1, 0, n-1, b);
		}
		void build(int i, int l2, int r2, double[] b) {
			if(l2==r2)
				a[i]=b[l2];
			else {
				int mid=(l2+r2)/2;
				build(2*i, l2, mid, b);
				build(2*i+1, mid+1, r2, b);
				a[i]=a[2*i]+a[2*i+1];
			}
		}
		private void push(int i, int l2, int r2) {
			a[i]*=lMult[i];
			a[i]+=lAdd[i]*(r2-l2+1);
			if(l2<r2) {
				lMult[2*i]*=lMult[i];
				lAdd[2*i]*=lMult[i];
				lAdd[2*i]+=lAdd[i];
				lMult[2*i+1]*=lMult[i];
				lAdd[2*i+1]*=lMult[i];
				lAdd[2*i+1]+=lAdd[i];
			}
			lMult[i]=1;
			lAdd[i]=0;
		}
		void upd(int l, int r, double d1, double d2) {
			this.l=l;
			this.r=r;
			this.d1=d1;
			this.d2=d2;
			upd2(1, 0, n-1);
		}
		private void upd2(int i, int l2, int r2) {
			if(l<=l2&&r2<=r) {
				lMult[i]*=d1;
				lAdd[i]*=d1;
				lAdd[i]+=d2;
				push(i, l2, r2);
			} else {
				int mid=(l2+r2)/2;
				push(2*i, l2, mid);
				push(2*i+1, mid+1, r2);
				if(l<=mid)
					upd2(2*i, l2, mid);
				if(mid<r)
					upd2(2*i+1, mid+1, r2);
				a[i]=a[2*i]+a[2*i+1];
			}
		}
		double qry(int l, int r) {
			this.l=l;
			this.r=r;
			return qry2(1, 0, n-1);
		}
		private double qry2(int i, int l2, int r2) {
			push(i, l2, r2);
			if(l<=l2&&r2<=r)
				return a[i];
			int mid=(l2+r2)/2;
			double res=0;
			if(l<=mid)
				res+=qry2(2*i, l2, mid);
			if(mid<r)
				res+=qry2(2*i+1, mid+1, r2);
			return res;
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