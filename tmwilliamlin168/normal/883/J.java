import java.io.*;
import java.util.*;

public class MainJ {
	
	public static void main(String[] args) {
		StdIn in = new StdIn();
		int n=in.nextInt(), m=in.nextInt();
		int[] a = in.readIntArray(n), b = in.readIntArray(m);
		Building[] buildings = new Building[m];
		for(int i=0; i<m; ++i)
			buildings[i]=new Building(b[i], in.nextInt());
		Arrays.sort(buildings, new Comparator<Building>() {
			public int compare(Building a, Building b) {
				return a.b-b.b;
			}
		});
		List<Integer>[] pricesByMonth = new List[n];
		for(int i1=n-1, i2=0; i1>=0; --i1) {
			pricesByMonth[i1] = new ArrayList<Integer>();
			while(i2<m&&buildings[i2].b<=a[i1])
				pricesByMonth[i1].add(buildings[i2++].p);
		}
		//System.out.println(Arrays.toString(pricesByMonth));
		long moneyLeft=0;
		PriorityQueue<Integer> demolishedPrices = new PriorityQueue<Integer>(Collections.reverseOrder());
		for(int i=0; i<n; ++i) {
			moneyLeft+=a[i];
			for(int price : pricesByMonth[i]) {
				if(moneyLeft>=price) {
					demolishedPrices.add(price);
					moneyLeft-=price;
				} else if(!demolishedPrices.isEmpty()) {
					int lPrice=demolishedPrices.peek();
					if(lPrice>price) {
						demolishedPrices.poll();
						demolishedPrices.add(price);
						moneyLeft+=lPrice-price;
					}
				}
			}
			//System.out.println(demolishedPrices);
		}
		System.out.println(demolishedPrices.size());
	}
	
	static class Building {
		int b, p;
		Building(int b, int p) {
			this.b=b;
			this.p=p;
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