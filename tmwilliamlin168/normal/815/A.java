import java.io.*;
import java.util.*;

public class MainA {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt(), m=in.nextInt();
		int[][] g = new int[n][];
		for(int i=0; i<n; ++i)
			g[i]=in.readIntArray(m);
		int ans1=0;
		StringBuilder ans2 = new StringBuilder();
		int i0=-1, j0=-1;
		while(true) {
			boolean allp=true;
			for(i0=0; i0<n&&allp; ++i0)
				for(j0=0; j0<m&&(allp=g[i0][j0]>0); ++j0);
			--i0;
			if(j0<m)
				break;
			if(n<m) {
				ans1+=n;
				for(int i=1; i<=n; ++i)
					ans2.append("row "+i+"\n");
			} else {
				ans1+=m;
				for(int i=1; i<=m; ++i)
					ans2.append("col "+i+"\n");
			}
			for(int i=0; i<n; ++i)
				for(int j=0; j<m; ++j)
					--g[i][j];
		}
		//System.out.println(i0+" "+j0);
		for(int i=0; i<n; ++i) {
			if(i==i0)
				continue;
			while(g[i][j0]>0) {
				++ans1;
				ans2.append("row "+(i+1)+"\n");
				for(int j=0; j<m; ++j)
					--g[i][j];
			}
		}
		for(int j=0; j<m; ++j) {
			if(j==j0)
				continue;
			while(g[i0][j]>0) {
				++ans1;
				ans2.append("col "+(j+1)+"\n");
				for(int i=0; i<n; ++i)
					--g[i][j];
			}
		}
		for(int i=0; i<n; ++i)
			for(int j=0; j<m; ++j)
				if(g[i][j]!=0)
					fk();
		out.println(ans1);
		out.println(ans2);
		out.close();
	}
	
	static void fk() {
		System.out.println(-1);
		System.exit(0);
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