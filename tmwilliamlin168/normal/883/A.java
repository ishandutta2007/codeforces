import java.io.*;
import java.util.*;

public class MainA {
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt(), m=in.nextInt(), a=in.nextInt();
		//i1 is next employee index
		//ePD = employees per door
		long d=in.nextLong(), i1=0, ans=0, ePD=1+d/a;
		long[] t = in.readLongArray(m);
		int i2=0; //i2 is next client index
		while(i1<n||i2<m) {
			//employee comes at a*(i1+1)
			//client comes at t[i2]
			if(i1<n&&(i2>=m||t[i2]>a*(i1+1)+d)) {
				//no clients for next door opening
				//long nextT=i2>=m?(long)a*n+d+1:t[i2];
				long nextT=(long)a*n+d+1;
				if(i2<m)
					nextT=Math.min(t[i2], nextT);
				long tDoors=(nextT-d-a*(i1+1)-1+a*ePD)/a/ePD;
				i1+=tDoors*ePD;
				ans+=tDoors;
			} else {
				//clients for next door opening
				//brute force
				if(i1<n&&(i2>=m||a*(i1+1)<=t[i2])) {
					//employee comes first
					while(i2<m&&t[i2]<=a*(i1+1)+d)
						++i2;
					i1+=ePD;
				} else {
					//client comes first
					long openT=t[i2];
					while(i2<m&&t[i2]<=openT+d)
						++i2;
					i1+=Math.max((d-(a*(i1+1)-openT)+a)/a, 0);
				}
				++ans;
			}
		}
		System.out.println(ans);
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