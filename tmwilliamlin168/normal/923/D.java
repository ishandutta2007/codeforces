import java.io.*;
import java.util.*;

public class MainD {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		char[] s = in.next().toCharArray(), t = in.next().toCharArray();
		int n=s.length, m=t.length;
		int[] a = new int[n+1], b = new int[m+1];
		List<Integer> c1 = new ArrayList<Integer>(), c2 = new ArrayList<Integer>();
		c1.add(-1);
		c2.add(-1);
		for(int i=0; i<n; ++i)
			if(s[i]!='A') {
				++a[i+1];
				c1.add(i);
			}
		for(int i=0; i<m; ++i)
			if(t[i]!='A') {
				++b[i+1];
				c2.add(i);
			}
		for(int i=0; i<n; ++i)
			a[i+1]+=a[i];
		for(int i=0; i<m; ++i)
			b[i+1]+=b[i];
		int q=in.nextInt();
		while(q-->0) {
			int l1=in.nextInt()-1, r1=in.nextInt()-1, l2=in.nextInt()-1, r2=in.nextInt()-1;
			int s1=a[r1+1]-a[l1], s2=b[r2+1]-b[l2];
			if(!(s1%2==s2%2&&s2>=s1)) {
				out.print('0');
				continue;
			}
			int p1=Collections.binarySearch(c1, r1), p2=Collections.binarySearch(c2, r2);
			int ls1=c1.get(p1>=0?p1:-p1-2), ls2=c2.get(p2>=0?p2:-p2-2);
			ls1=Math.max(l1-1, ls1);
			ls2=Math.max(l2-1, ls2);
			//out.println(r1+" "+r2+" "+ls1+" "+ls2);
			if(r1-ls1!=r2-ls2&&!(((r1-ls1)%3==(r2-ls2)%3||s2>s1)&&r1-ls1>=r2-ls2)) {
				out.print('0');
				//out.println();
				continue;
			}
			if(s1==0&&s2!=0&&r1-ls1==r2-ls2) {
				out.print('0');
				continue;
			}
			out.print('1');
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