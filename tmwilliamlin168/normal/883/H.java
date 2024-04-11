import java.io.*;
import java.util.*;

public class MainH {
	
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt();
		int[] cnt = new int[256];
		String s = in.next();
		for(char c : s.toCharArray())
			++cnt[c];
		List<Character> oddEntries = new ArrayList<Character>();
		for(int i=0; i<256; ++i)
			if(cnt[i]%2==1) {
				oddEntries.add((char)i);
				--cnt[i];
			}
		if(oddEntries.isEmpty()) {
			StringBuilder a = new StringBuilder();
			StringBuilder b = new StringBuilder();
			int i=0;
			while(true) {
				while(i<256&&cnt[i]==0)
					++i;
				if(i>=256)
					break;
				a.append((char) i);
				b.append((char) i);
				cnt[i]-=2;
			}
			b.reverse();
			System.out.println(1);
			System.out.println(a.toString()+b.toString());
			return;
		}
		while(true) {
			if((n-oddEntries.size())/2%oddEntries.size()==0) {
				System.out.println(oddEntries.size());
				int i=0, pairsPWord=(n-oddEntries.size())/2/oddEntries.size();
				for(char c : oddEntries) {
					StringBuilder a = new StringBuilder();
					StringBuilder b = new StringBuilder();
					for(int j=0; j<pairsPWord; ++j) {
						while (cnt[i] == 0)
							++i;
						a.append((char) i);
						b.append((char) i);
						cnt[i] -= 2;
					}

					b.reverse();
					System.out.print(a.toString()+c+b.toString()+" ");
				}
				return;
			} else {
				for(int i=0; i<256; ++i) {
					if(cnt[i]>0) {
						oddEntries.add((char)i);
						oddEntries.add((char)i);
						cnt[i]-=2;
						break;
					}
				}
			}
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