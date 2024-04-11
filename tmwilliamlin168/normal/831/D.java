import java.io.*;
import java.util.*;

public class Main {
	
	//PLEASE HACK MY SOLUTION IT IS EASY TO UNDERSTAND

	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt(), k=in.nextInt(), p=in.nextInt();
		List<Integer> pplLeft = new ArrayList<Integer>();
		List<Integer> pplRight = new ArrayList<Integer>();
		List<Integer> keys = new ArrayList<Integer>();
		for(int i=0; i<n; ++i) {
			int a_i=in.nextInt();
			if(a_i<p)
				pplLeft.add(a_i);
			else
				pplRight.add(a_i);
		}
		for(int i=0; i<k; ++i)
			keys.add(in.nextInt());
		Collections.sort(pplLeft);
		Collections.sort(pplRight);
		Collections.sort(keys);
		int[] leftTime = new int[k-n+1];
		int[] rightTime = new int[k-n+1];
		for(int i=0; i<k-n+1; ++i) {
			int time=0;
			for(int j=0; j<pplLeft.size(); ++j) {
				time=Math.max(Math.abs(pplLeft.get(j)-keys.get(i+j))+Math.abs(keys.get(i+j)-p), time);
			}
			leftTime[i]=time;
		}
		for(int i=0; i<k-n+1; ++i) {
			int time=0;
			for(int j=0; j<pplRight.size(); ++j) {
				time=Math.max(Math.abs(pplRight.get(pplRight.size()-j-1)-keys.get(k-i-j-1))+Math.abs(keys.get(k-i-j-1)-p), time);
			}
			rightTime[i]=time;
		}
		for(int i=1; i<k-n+1; ++i)
			rightTime[i]=Math.min(rightTime[i-1], rightTime[i]);
		int min=Integer.MAX_VALUE;
		for(int i=0; i<k-n+1; ++i)
			min=Math.min(Math.max(leftTime[i], rightTime[k-n-i]), min);
		System.out.println(min);
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
		final private int STRING_SIZE = 1 << 11;
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
			byte[] buf = new byte[STRING_SIZE]; // string length
			int cnt = 0, c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			while (c != -1)
			{
				if (c == ' ' || c == '\n'||c=='\r')
					break;
				buf[cnt++] = (byte) c;
				c=read();
			}
			return new String(buf, 0, cnt);
		}

		public String nextLine() {
			byte[] buf = new byte[STRING_SIZE]; // line length
			int cnt = 0, c;
			while((c=read())!=-1&&(c==' '||c=='\n'||c=='\r'));
			while (c != -1)
			{
				if (c == '\n'||c=='\r')
					break;
				buf[cnt++] = (byte) c;
				c = read();
			}
			return new String(buf, 0, cnt);
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