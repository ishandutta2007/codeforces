import java.io.*;
import java.util.*;

public class MainB {
	
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt(), w=in.nextInt(), h=in.nextInt();
		Dancer[] dancers = new Dancer[n];
		for(int i=0; i<n; ++i)
			dancers[i] = new Dancer(in.nextInt(), in.nextInt(), in.nextInt());
		//filter by x+y
		int mid=100000;
		List<Dancer>[] intersects = new List[200001];
		for(int i=0; i<n; ++i) {
			int xy=dancers[i].x+dancers[i].y;
			if(intersects[xy+mid]==null)
				intersects[xy+mid] = new ArrayList<Dancer>();
			intersects[xy+mid].add(dancers[i]);
		}
		for(int i=0; i<intersects.length; ++i) {
			if(intersects[i]==null)
				continue;
			List<Dancer> vDancers = new ArrayList<Dancer>(), hDancers = new ArrayList<Dancer>();
			for(Dancer dancer : intersects[i])
				if(dancer.g==1)
					vDancers.add(dancer);
				else
					hDancers.add(dancer);
			Collections.sort(vDancers, new Comparator<Dancer>() {
				public int compare(Dancer a, Dancer b) {
					return a.x-b.x;
				}
			});
			Collections.sort(hDancers, new Comparator<Dancer>() {
				public int compare(Dancer a, Dancer b) {
					return b.y-a.y;
				}
			});
			int nHDancers = hDancers.size();
			hDancers.addAll(vDancers);
			if(nHDancers>=hDancers.size())
				nHDancers=0;
			for(int j=0; j<hDancers.size(); ++j, nHDancers=(nHDancers+1)%hDancers.size()) {
				Dancer dancer1 = hDancers.get(j), dancer2 = hDancers.get(nHDancers);
				if(dancer2.g==1) {
					dancer1.fX=dancer2.x;
					dancer1.fY=h;
				} else {
					dancer1.fX=w;
					dancer1.fY=dancer2.y;
				}
			}
		}
		PrintWriter out = new PrintWriter(System.out);
		for(int i=0; i<n; ++i)
			out.println(dancers[i].fX+" "+dancers[i].fY);
		out.close();
	}
	
	static class Dancer {
		int g, p, t, x, y, fX, fY;
		Dancer(int g, int p, int t) {
			this.g=g;
			this.p=p;
			this.t=t;
			if(g==1) {
				x=p;
				y=-t;
			} else {
				y=p;
				x=-t;
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