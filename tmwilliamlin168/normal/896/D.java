import java.io.*;
import java.util.*;

public class MainD {
	static StdIn in = new StdIn();
	static PrintWriter out = new PrintWriter(System.out);
	static long p;
	static List<Long> pFs = new ArrayList<Long>();
	static long[] fact1;
	static int[][] fact2;
	
	public static void main(String[] args) {
		int n=in.nextInt();
		p=in.nextLong();
		int l=in.nextInt(), r=in.nextInt();
		long p2=p;
		for(int i=2; i*i<=p2; ++i) {
			if(p2%i==0) {
				while(p2%i==0)
					p2/=i;
				pFs.add((long)i);
			}
		}
		if(p2>1)
			pFs.add(p2);
		fact1 = new long[2*n+1];
		fact2 = new int[pFs.size()][2*n+1];
		fact1[0]=1;
		for(int i=1; i<=2*n; ++i) {
			long a=i;
			for(int j=0; j<pFs.size(); ++j) {
				fact2[j][i]=fact2[j][i-1];
				while(a%pFs.get(j)==0) {
					a/=pFs.get(j);
					++fact2[j][i];
				}
			}
			fact1[i]=fact1[i-1]*a%p;
		}
		long ans1=0;
		for(int i=0; i<=n; ++i) {
			ans1=(ans1+nCk(n, i)*(nCk(n-i, (n-i)/2-(l+l%2*(n-i+1)%2)/2)-nCk(n-i, (n-i)/2-(r-(r+1)%2*(n-i)%2+2)/2)+p))%p;
			//if(i<1000)
			//	out.println(ans1);
			//out.println(ans1+" "+nCk(n, i)+" "+nCk(n-i, (n-i)/2-l/2));
		}
		out.println(ans1);
		out.close();
	}
	
	static long nCk(int n, int k) {
		if(k>n||k<0)
			return 0;
		long r=fact1[n]*modI(fact1[k])%p*modI(fact1[n-k])%p;
		for(int i=0; i<pFs.size(); ++i)
			r=r*expM(pFs.get(i), fact2[i][n]-fact2[i][k]-fact2[i][n-k])%p;
		return r;
	}
	
	static long expM(long b, int e) {
		if(e==0)
			return 1;
		if(e%2==1)
			return b*expM(b*b%p, e/2)%p;
		return expM(b*b%p, e/2);
    }
	
	static long modI(long a) {
        long m0 = p, t, q, x0 = 0, x1 = 1;
        while(a>1) {
            q = a / m0;
            t = m0;
            m0 = a % m0;
            a = t;
            t = x0;
            x0 = x1 - q * x0;
            x1 = t;
        }
        if(x1<0)
			x1 += p;
        return x1;
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