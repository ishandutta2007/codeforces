import java.io.*;
import java.util.*;

public class MainF {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	
	public static void main(String[] args) {
		int n=in.nextInt();
		long ans=0;
		List<Integer> gp = new ArrayList<Integer>(), rp = new ArrayList<Integer>(), bp = new ArrayList<Integer>();
		for(int i=0; i<n; ++i) {
			int p=in.nextInt(), c=in.nextInt();
			if(c==23)
				gp.add(p);
			else if(c==34)
				rp.add(p);
			else
				bp.add(p);
		}
		if(gp.isEmpty()) {
			if(!rp.isEmpty())
				ans+=rp.get(rp.size()-1)-rp.get(0);
			if(!bp.isEmpty())
				ans+=bp.get(bp.size()-1)-bp.get(0);
		} else {
			//ans+=gp.get(gp.size()-1)-gp.get(0);
			gp.add((int)2e9+69);
			int last=(int)-1e9-69, ri1, ri2=0, bi1, bi2=0;
			for(int gpi : gp) {
				long ccost=0;
				//red
				for(ri1=ri2; ri2<rp.size()&&rp.get(ri2)<gpi; ++ri2);
				if(ri1!=ri2) {
					ccost+=gpi-last;
					int mD=Math.max(rp.get(ri1)-last, gpi-rp.get(ri2-1));
					for(int i=ri1; i+1<ri2; ++i)
						mD=Math.max(rp.get(i+1)-rp.get(i), mD);
					ccost-=mD;
				}
				//blue
				for(bi1=bi2; bi2<bp.size()&&bp.get(bi2)<gpi; ++bi2);
				if(bi1!=bi2) {
					ccost+=gpi-last;
					int mD=Math.max(bp.get(bi1)-last, gpi-bp.get(bi2-1));
					for(int i=bi1; i+1<bi2; ++i)
						mD=Math.max(bp.get(i+1)-bp.get(i), mD);
					ccost-=mD;
				}
				if(gpi<1e9+1&&last>=1)
					//out.println("h"+(ccost+gpi-last)+(gpi-last)*2);
					ccost=Math.min(ccost+gpi-last, ((long)gpi-last)*2);
				//other
				ans+=ccost;
				//out.println(ans+" "+ccost);
				last=gpi;
			}
		}
		out.println(ans);
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