import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class MainC {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		int[] a = in.readIntArray(n, 0);
		if(n==1) {
			System.out.println(a[0]);
			for(int i=0; i<a[0]; ++i)
				System.out.print('a');
			return;
		}
		int m=0;
		for(int i=0; i<n; ++i)
			m+=a[i];
		for(int p=2; p<=m; ++p) {
			if(m%p!=0)
				continue;
			for(int i1=0; i1<n; ++i1) {
				for(int i2=i1; i2<(m/p%2==0?n:i1+1); ++i2) {
					int[] b = Arrays.copyOf(a, n);
					for(int j=0; j<m/p/2; ++j)
						b[i1]-=2;
					for(int j=0; j<(m/p+1)/2; ++j)
						b[i2]-=2;
					if(b[i1]<0||b[i2]<0)
						continue;
					boolean ok=true;
					for(int i=0; i<n&&ok; ++i) {
						if(b[i]%(m/p)!=0)
							ok=false;
						b[i]/=(m/p);
					}
					if(!ok)
						break;
					StringBuilder mp = new StringBuilder();
					if(m/p%2==1) {
						int oi=-1;
						for(int i=0; i<n&&ok; ++i) {
							if(b[i]%2==0)
								continue;
							if(oi!=-1)
								ok=false;
							oi=i;
						}
						if(!ok)
							break;
						for(int i=0; i<n; ++i)
							for(int j=0; j<b[i]/2; ++j)
								mp.append((char)('a'+i));
						if(oi!=-1)
							mp.append((char)('a'+oi));
						for(int i=n-1; i>=0; --i)
							for(int j=0; j<b[i]/2; ++j)
								mp.append((char)('a'+i));
						
					} else
						for(int i=0; i<n; ++i)
							for(int j=0; j<b[i]; ++j)
								mp.append((char)('a'+i));
					System.out.println(m/p);
					for(int j=0; j<m/p; ++j) {
						System.out.print((char)('a'+i1));
						System.out.print((char)('a'+i1));
						System.out.print(mp.reverse());
						++j;
						if(j>=m/p)
							break;
						System.out.print((char)('a'+i2));
						System.out.print((char)('a'+i2));
						System.out.print(mp.reverse());
					}
					return;
				}
			}
		}
		System.out.println(0);
		for(int i=0; i<n; ++i)
			for(int j=0; j<a[i]; ++j)
				System.out.print((char)('a'+i));
		out.close();
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