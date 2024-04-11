import java.io.*;
import java.util.*;

public class MainB {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static int n;
	static long[] a, pa;
	static long A,m;
	
	public static void main(String[] args) {
		n=in.nextInt();
		A=in.nextLong();
		long cf=in.nextLong(), cm=in.nextLong();
		m=in.nextLong();
		long[] oa = in.readLongArray(n, 0);
		a = new long[n+1];
		pa = new long[n+1];
		long ans1=-1;
		int ans2=-1;
		for(int i=0; i<n; ++i) {
			a[i]=oa[i];
			int j=(int)(Math.random()*(i+1));
			a[i]^=a[j]^(a[j]=a[i]);
		}
		a[n]=A;
		Arrays.sort(a);
		for(int i=0; i<n; ++i)
			pa[i+1]=a[i]+pa[i];
//		System.out.println(fmsl(0));
//		System.out.println(fmsl(1));
//		if(n>0)
//			return;
		for(int i=n; i>=0; --i) {
			long msl=fmsl(i);
			if(msl<0)
				break;
			if((n-i)*cf+msl*cm>ans1) {
				ans1=(n-i)*cf+msl*cm;
				ans2=i;
			}
		}
		out.println(ans1);
//		out.println(ans2);
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>(new Comparator<Integer>() {
			public int compare(Integer i, Integer j) {
				return -Long.compare(oa[i], oa[j]);
			}
		});
		for(int i=0; i<n; ++i)
			pq.add(i);
		for(int i=0; i<n-ans2; ++i)
			oa[pq.poll()]=A;
		long msl=fmsl(ans2);
		for(int i=0; i<n; ++i)
			out.print(Math.max(msl, oa[i])+" ");
		out.close();
	}
	
	static long fmsl(int i) {
		long lb1=0, rb1=A;
		while(lb1<=rb1) {
			long mb1=(lb1+rb1)/2;
			int lb2=0, rb2=i-1;
			while(lb2<=rb2) {
				int mb2=(lb2+rb2)/2;
				if(a[mb2]>=mb1)
					rb2=mb2-1;
				else
					lb2=mb2+1;
			}
			if(mb1*lb2-pa[lb2]<=m-((n-i)*A-(pa[n]-pa[i])))
				lb1=mb1+1;
			else
				rb1=mb1-1;
		}
		return rb1;
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