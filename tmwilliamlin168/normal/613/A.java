import java.io.*;
import java.util.*;

public class MainA {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		long px=in.nextInt(), py=in.nextInt();
		long[] x = new long[n], y = new long[n];
		for(int i=0; i<n; ++i) {
			x[i]=in.nextInt();
			y[i]=in.nextInt();
		}
		double r1, r2=0;
		if(pointInPolygon(px, py, x, y))
			r1=0;
		else {
			r1=Double.POSITIVE_INFINITY;
			for(int i=0, j=n-1; i<n; j=i++) {
				long ax=x[j]-x[i], ay=y[j]-y[i], bx=px-x[i], by=py-y[i];
				double ma=Math.hypot(ax, ay), c=Math.min(Math.max((ax*bx+ay*by)/ma/ma, 0), 1);
				r1=Math.min(Math.hypot(ax*c-bx, ay*c-by), r1);
			}
		}
		for(int i=0; i<n; ++i) {
			long ax=x[i]-px, ay=y[i]-py;
			r2=Math.max(ax*ax+ay*ay, r2);
		}
//		out.println(r2);
		out.println(Math.PI*(r2-r1*r1));
		out.close();
	}
	
	static boolean pointInPolygon(long px, long py, long[] x, long[] y) {
		int n=x.length, cnt=0;
		for(int i=0, j=n-1; i<n; j=i++) {
			if(y[i]==py&&(x[i]==px||y[j]==py&&(x[i]<=px||x[j]<=px)&&(x[i]>=px||x[j]>=px)))
				return false;
			if((y[i]>py)!=(y[j]>py)) {
				long det=(x[i]-px)*(y[j]-py)-(x[j]-px)*(y[i]-py);
				if(det==0)
					return false;
				if((det>0)!=(y[j]>y[i]))
					++cnt;
			}
		}
		return cnt%2==1;
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