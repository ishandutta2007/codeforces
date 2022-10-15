import java.io.*;
import java.util.*;

public class MainD {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), k=in.nextInt(), q=in.nextInt();
		int[][] a = new int[n][k], b = new int[n][k];
		for(int i=0; i<k; ++i)
			for(int j=0; j<n; ++j)
				a[j][i]=in.nextInt();
		for(int i=0; i<n; ++i) {
			for(int j=0; j<k; ++j)
				b[i][j]=j;
			for(int j1=0; j1<k; ++j1) {
				for(int j2=j1+1; j2<k; ++j2) {
					if(a[i][b[i][j1]]>=a[i][b[i][j2]])
						continue;
					b[i][j1]^=b[i][j2];
					b[i][j2]^=b[i][j1];
					b[i][j1]^=b[i][j2];
				}
			}
		}
		List<BitSet> creatures = new ArrayList<BitSet>();
		for(int i=0; i<k; ++i) {
			BitSet bs = new BitSet(1<<k);
			for(int j=0; j<1<<k; ++j)
				if(((j>>i)&1)==1)
					bs.set(j);
			creatures.add(bs);
		}
		while(q-->0) {
			int qt=in.nextInt(), x=in.nextInt()-1, y=in.nextInt()-1;
			if(qt==1) {
				BitSet bs = (BitSet)creatures.get(x).clone();
				bs.or(creatures.get(y));
				creatures.add(bs);
			} else if(qt==2) {
				BitSet bs = (BitSet)creatures.get(x).clone();
				bs.and(creatures.get(y));
				creatures.add(bs);
			} else {
				BitSet bs = creatures.get(x);
				int i=-1, cm=0;
				for(; !bs.get(cm); ++i, cm|=1<<b[y][i]);
				out.println(a[y][b[y][i]]);
			}
		}
		out.close();
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