import java.io.*;
import java.util.*;

public class MainB {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	static char[][] board;
	static char[] s;
	static int n, m, t;
	
	public static void main(String[] args) {
		n=in.nextInt();
		m=in.nextInt();
		board = new char[n][];
		for(int i=0; i<n; ++i)
			board[i]=in.next().toCharArray();
		s=in.next().toCharArray();
		List<Pair> dirs = new ArrayList<Pair>();
		dirs.add(new Pair(1, 0));
		dirs.add(new Pair(0, 1));
		dirs.add(new Pair(-1, 0));
		dirs.add(new Pair(0, -1));
		recur(new ArrayList<Pair>(), dirs);
		out.println(t);
		out.close();
	}
	
	static void recur(List<Pair> mapping, List<Pair> dirsLeft) {
		if(dirsLeft.isEmpty()) {
			int si=-1, sj=-1;
			for(int i=0; i<n; ++i) {
				for(int j=0; j<m; ++j) {
					if(board[i][j]=='S') {
						si=i;
						sj=j;
					}
				}
			}
			for(int k=0; k<s.length; ++k) {
				Pair dir=mapping.get(s[k]-'0');
				si+=dir.a;
				sj+=dir.b;
				if(si<0||si>=n||sj<0||sj>=m||board[si][sj]=='#')
					return;
				if(board[si][sj]=='E') {
					++t;
					return;
				}
			}
		} else {
			for(int i=0; i<dirsLeft.size(); ++i) {
				Pair p=dirsLeft.remove(i);
				mapping.add(p);
				recur(mapping, dirsLeft);
				mapping.remove(p);
				dirsLeft.add(i, p);
			}
		}
	}
	
	static class Pair {
		int a, b;
		Pair(int a, int b) {
			this.a=a;
			this.b=b;
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