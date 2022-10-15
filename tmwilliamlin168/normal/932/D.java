import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int q=in.nextInt(), cnt=1;
		long[] w = new long[q];
		int[][] nge = new int[q][19];
		long[][] ws = new long[q][19];
		Arrays.fill(nge[0], -1);
		long last=0;
		while(q-->0) {
			int qt=in.nextInt();
			if(qt==1) {
				int r=(int)((in.nextLong()^last)-1);
				w[cnt]=in.nextLong()^last;
				Arrays.fill(nge[cnt], -1);
				nge[cnt][0]=r;
				while(nge[cnt][0]!=-1&&w[nge[cnt][0]]<w[cnt])
					nge[cnt][0]=nge[nge[cnt][0]][0];
				if(nge[cnt][0]!=-1)
					ws[cnt][0]=w[nge[cnt][0]];
				for(int i=1; i<19; ++i) {
					nge[cnt][i]=nge[cnt][i-1]!=-1?nge[nge[cnt][i-1]][i-1]:-1;
					ws[cnt][i]=nge[cnt][i-1]!=-1?ws[cnt][i-1]+ws[nge[cnt][i-1]][i-1]:ws[cnt][i-1];
				}
				++cnt;
			} else {
				int r=(int)((in.nextLong()^last)-1);
				long x=in.nextLong()^last;
				if(w[r]>x) {
					out.println(last=0);
					continue;
				}
				x-=w[r];
				int ans=1;
				for(int i=18; i>=0; --i) {
					if(nge[r][i]==-1)
						continue;
					if(ws[r][i]<=x) {
						//out.println(i+" "+r+" "+ws[r][i]+" "+x);
						x-=ws[r][i];
						r=nge[r][i];
						ans+=1<<i;
					}
				}
				out.println(last=ans);
				//out.flush();
			}
		}
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