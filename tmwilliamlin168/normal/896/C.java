import java.io.*;
import java.util.*;

public class MainC {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	static long seed;
	
	public static void main(String[] args) {
		int n=in.nextInt(), m=in.nextInt();
		seed=in.nextLong();
		int vmax=in.nextInt();
		TreeMap<Integer, Long> intervals = new TreeMap<Integer, Long>();
		for(int i=0; i<n; ++i)
			intervals.put(i, rnd()%vmax+1L);
		intervals.put(n, 0L);
		while(m-->0) {
			int op=rnd()%4, l=rnd()%n, r=rnd()%n, x, y, i;
			if(l>r) {
				l^=r;
				r^=l;
				l^=r;
			}
			if(op==2)
				x=rnd()%(r-l+1);
			else
				x=rnd()%vmax+1;
			Map.Entry<Integer, Long> l2=intervals.floorEntry(l);
			if(l2.getKey()<l)
				intervals.put(l, l2.getValue());
			if(intervals.higherKey(r)>r+1)
				intervals.put(r+1, intervals.floorEntry(r).getValue());
			List<Map.Entry<Integer, Long>> entries = new ArrayList<Map.Entry<Integer, Long>>();  
			Map.Entry<Integer, Long> entry=intervals.floorEntry(l);
			while(entry!=null&&entry.getKey()<=r+1) {
				entries.add(entry);
				entry=intervals.higherEntry(entry.getKey());
			}
			List<Pair> valCnts = new ArrayList<Pair>();
			switch(op) {
			case 0:
				for(i=0; i<entries.size()-1; ++i)
					intervals.put(entries.get(i).getKey(), entries.get(i).getValue()+x);
				break;
			case 1:
				for(i=1; i<entries.size()-1; ++i)
					intervals.remove(entries.get(i).getKey());
				intervals.put(entries.get(0).getKey(), (long)x);
				break;
			case 2:
				for(i=0; i<entries.size()-1; ++i)
					valCnts.add(new Pair(entries.get(i).getValue(), entries.get(i+1).getKey()-entries.get(i).getKey()));
				Collections.sort(valCnts);
				i=0;
				while(x-valCnts.get(i).b>=0) {
					x-=valCnts.get(i).b;
					++i;
				}
				out.println(valCnts.get(i).a);
				break;
			case 3:
				y=(rnd()%vmax)+1;
				for(i=0; i<entries.size()-1; ++i)
					valCnts.add(new Pair(entries.get(i).getValue(), entries.get(i+1).getKey()-entries.get(i).getKey()));
				long t=0;
				for(Pair p : valCnts)
					t=(t+expM(p.a%y, x, y)*p.b)%y;
				out.println(t);
				break;
			}
		}
		out.close();
	}
	
	static int rnd() {
		int ret=(int)seed;
		seed=(seed*7+13)%1000000007;
		return ret;
	}
	
	static long expM(long b, int p, long m) {
		if(p==0)
			return 1;
		if(p%2==1)
			return b*expM(b*b%m, p/2, m)%m;
		return expM(b*b%m, p/2, m);
	}
	
	static class Pair implements Comparable<Pair> {
		long a;
		int b;
		Pair(long a, int b) {
			this.a=a;
			this.b=b;
		}
		public int compareTo(Pair o) {
			return Long.compare(a, o.a);
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