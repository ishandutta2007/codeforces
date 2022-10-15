import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class MainC {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		Map<Long, Integer> wm = new HashMap<Long, Integer>(), hm = new HashMap<Long, Integer>();
		int ws=0, hs=0;
		Rect[] rs = new Rect[n];
		for(int i=0; i<n; ++i) {
			long wi=in.nextLong(), hi=in.nextLong();
			if(!wm.containsKey(wi))
				wm.put(wi, ws++);
			if(!hm.containsKey(hi))
				hm.put(hi, hs++);
			rs[i] = new Rect(wm.get(wi), hm.get(hi), in.nextLong());
		}
		if((long)ws*hs!=n)
			fk();
//		System.out.println("hi1");
		long[][] c = new long[ws][hs];
		for(int i=0; i<n; ++i)
			c[rs[i].w][rs[i].h]=rs[i].c;
		for(int i=0; i<ws-1; ++i)
			for(int j=0; j<hs-1; ++j)
				chkrat(c[i][j], c[i][j+1], c[i+1][j], c[i+1][j+1]);
		long gcd=0;
		for(int i=0; i<ws; ++i)
			for(int j=0; j<hs; ++j)
				gcd=gcd(c[i][j], gcd);
		int ans=0;
		for(long i=1; i*i<=gcd; ++i)
			if(gcd%i==0)
				ans+=gcd/i==i?1:2;
		out.println(ans);
		out.close();
	}
	
	static long gcd(long a, long b) {
		return b==0?a:gcd(b, a%b);
	}
	
	static void fk() {
		System.out.println(0);
		System.exit(0);
	}
	
	static void chkrat(long a1, long b1, long a2, long b2) {
		if(new BigInteger(a1+"").multiply(new BigInteger(b2+"")).compareTo(new BigInteger(a2+"").multiply(new BigInteger(b1+"")))!=0)
			fk();
	}
	
	static class Rect {
		int w, h;
		long c;
		Rect(int w, int h, long c) {
			this.w=w;
			this.h=h;
			this.c=c;
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