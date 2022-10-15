import java.io.*;
import java.util.*;

public class MainC {
	static final StdIn in = new StdIn();
	static final PrintWriter out = new PrintWriter(System.out);
	static final long INF=(long)1e18;
	
	public static void main(String[] args) {
		int x=in.nextInt(), k=in.nextInt(), n=in.nextInt(), q=in.nextInt(), masks=0;
		int[] id2mask = new int[1<<k], mask2id = new int[1<<k];
		Arrays.fill(mask2id, -1);
		for(int i=1; i<1<<k; ++i)
			if(Integer.bitCount(i)==x)
				id2mask[mask2id[i]=masks++]=i;
		//System.out.println(Arrays.toString(id2mask));
		long[] c = in.readLongArray(k);
		TreeMap<Integer, Long> ps = new TreeMap<Integer, Long>();
		ps.put(0, 0L);
		ps.put(n-x, 0L);
		for(int i=0; i<q; ++i)
			ps.put(in.nextInt()-1, in.nextLong());
		long[][] tmat = new long[masks][masks], dp = new long[2][masks];
		for(int i=0; i<masks; ++i) {
			Arrays.fill(tmat[i], INF);
			if(((id2mask[i]>>(k-1))&1)!=0)
				tmat[i][mask2id[(id2mask[i]<<1)^1^(1<<k)]]=c[k-1];
			else {
				for(int j=0; j<k-1; ++j)
					if(((id2mask[i]>>j)&1)!=0)
						tmat[i][mask2id[((id2mask[i]^(1<<j))<<1)^1]]=c[j];
				tmat[i][mask2id[id2mask[i]<<1]]=0;
			}
		}
		//System.out.println(Arrays.deepToString(tmat));
		Arrays.fill(dp[0], INF);
		dp[0][0]=0;
		int lastI=0;
		for(Map.Entry<Integer, Long> entry : ps.entrySet()) {
			if(entry.getKey()>n-x)
				continue;
			//System.out.println(entry.getKey());
			if(entry.getKey()-lastI>k)
				dp[(entry.getKey()-k)&1]=matMult(matExp(tmat, entry.getKey()-lastI-k), dp[lastI&1]);
			//System.out.println(Math.max(entry.getKey()-k, lastI)+" "+Arrays.toString(dp[Math.max(entry.getKey()-k, lastI)&1]));
			for(int a=Math.max(entry.getKey()-k, lastI)+1; a<=entry.getKey(); ++a) {
				for(int i=0; i<masks; ++i) {
					if(((id2mask[i]>>(k-1))&1)!=0)
						dp[a&1][i]=dp[a&1^1][mask2id[(id2mask[i]<<1)^1^(1<<k)]]+c[k-1]+ps.getOrDefault(a+k-1, 0L);
					else {
						dp[a&1][i]=dp[a&1^1][mask2id[id2mask[i]<<1]];
						for(int j=0; j<k-1; ++j)
							if(((id2mask[i]>>j)&1)!=0)
								dp[a&1][i]=Math.min(dp[a&1^1][mask2id[((id2mask[i]^(1<<j))<<1)^1]]+c[j]+ps.getOrDefault(a+j, 0L), dp[a&1][i]);
					}
				}
				//System.out.println(a+" "+Arrays.toString(dp[a&1]));
			}
			lastI=entry.getKey();
		}
		out.println(dp[(n-x)&1][0]);
		out.close();
	}
	
	static long[][] matMult(long[][] x, long[][] y) {
		long[][] z = new long[x.length][x.length];
		for(int i=0; i<x.length; ++i) {
			Arrays.fill(z[i], INF);
			for(int j=0; j<x.length; ++j)
				for(int k=0; k<x.length; ++k)
					z[i][j]=Math.min(x[i][k]+y[k][j], z[i][j]);
		}
		return z;
	}
	
	static long[][] matExp(long[][] x, int p) {
		long[][] res = new long[x.length][x.length], pow = x;
		for(int i=0; i<x.length; ++i) {
			Arrays.fill(res[i], INF);
			res[i][i]=0;
		}
		while(p>0) {
			if(p%2==1)
				res=matMult(res, pow);
			pow=matMult(pow, pow);
			p/=2;
		}
		return res;
	}
	
	static long[] matMult(long[][] x, long[] y) {
		long[] z = new long[x.length];
		Arrays.fill(z, INF);
		for(int i=0; i<x.length; ++i)
			for(int j=0; j<x.length; ++j)
				z[i]=Math.min(x[i][j]+y[j], z[i]);
		return z;
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