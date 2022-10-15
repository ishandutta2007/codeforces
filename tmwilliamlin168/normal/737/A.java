import java.io.*;
import java.util.*;

public class MainA {
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt(), k=in.nextInt(), s=in.nextInt(), t=in.nextInt();
		int[] c = new int[n], v = new int[n], g = new int[k+1];
		for(int i=0; i<n; ++i) {
			c[i]=in.nextInt();
			v[i]=in.nextInt();
		}
		for(int i=0; i<k; ++i)
			g[i]=in.nextInt();
		g[k]=s;
		Arrays.sort(g);
		int l=1, r=(int)1e9, ans=(int)1e9+1;
		while(l<=r) {
			int mid=(l+r)/2;
			long cT=0, prev=0;
			for(int j=0; j<=k; ++j) {
				if(g[j]-prev>mid) {
					cT=Integer.MAX_VALUE;
					break;
				}
				cT+=Math.max(2*(g[j]-prev)-(mid-(g[j]-prev)), g[j]-prev);
				//System.out.println(cT+" "+(2*(g[j]-prev)-(v[i]-(g[j]-prev))));
				if(cT>t)
					break;
				prev=g[j];
			}
			if(cT<=t) {
				ans=mid;
				r=mid-1;
			} else
				l=mid+1;
		}
		int minC=Integer.MAX_VALUE;
		for(int i=0; i<n; ++i)
			if(v[i]>=ans)
				minC=Math.min(c[i], minC);
		if(minC==Integer.MAX_VALUE)
			System.out.println(-1);
		else
			System.out.println(minC);
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
		
		public StdIn(String filename) {
			try{
				din = new DataInputStream(new FileInputStream(filename));
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
			{
				ret = ret * 10 + c - '0';
			}  while ((c = read()) >= '0' && c <= '9');

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
			do {
				ret = ret * 10 + c - '0';
			}
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

			do {
				ret = ret * 10 + c - '0';
			}
			while ((c = read()) >= '0' && c <= '9');

			if (c == '.')
			{
				while ((c = read()) >= '0' && c <= '9')
				{
					ret += (c - '0') / (div *= 10);
				}
			}

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