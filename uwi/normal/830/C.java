//package round424;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long val(long v, long j)
	{
		long w = v%j;
		return w == 0 ? 0 : j-w;
	}
	
	void solve()
	{
		int n = ni();
		long K = nl();
		SimpleMinHeapL heap = new SimpleMinHeapL(n);
		int[] vs = na(n);
		int p = 0;
		for(int i = 0;i < n;i++){
			heap.add(1L<<32|i);
		}
		long pre = 1;
		long hsum = 0;
		long[] otime = new long[n];
		long[] oval = new long[n];
		long[] oplus = new long[n];
		long plus = 0;
		long ret = -1;
		while(heap.size() > 0){
			long cur = heap.poll();
			int id = (int)cur;
			long time = cur>>>32;
			if(pre < time){
				long nhsum = hsum + plus * (time - pre - 1);
				if(nhsum <= K){
					ret = time-1;
				}else if(hsum <= K){
					// hsum + plus * x <= K
					ret = pre + (K-hsum)/plus;
				}
			}
		
			hsum += plus * (time-pre);
			hsum -= oval[id] + (long)(time-otime[id]) * oplus[id];
			plus -= oplus[id];
			
			long val = val(vs[id], time);
//			tr(time, id, hsum, plus);
			otime[id] = time;
			oplus[id] = (vs[id]+time-1)/time;
			oval[id] = val;
			if(oplus[id] > 1){
				long ntime = (vs[id]+oplus[id]-2) / (oplus[id]-1);
				heap.add(ntime<<32|id);
			}
			
			hsum += val;
			plus += (vs[id]+time-1)/time;
			
			pre = time;
		}
		{
			if(hsum <= K){
				// hsum + plus * x <= K
				ret = pre + (K-hsum)/plus;
			}
		}
		out.println(ret);
	}

public static class SimpleMinHeapL {
	public long[] a;
	public int n;
	public int pos;
	public static final long INF = Long.MAX_VALUE;
	
	public SimpleMinHeapL(int m)
	{
		n = m+1;
		a = new long[n];
		Arrays.fill(a, INF);
		pos = 1;
	}
	
	public SimpleMinHeapL(long[] in)
	{
		n = in.length+1;
		if((n&1)==1)n++;
		a = new long[n];
		pos = 1+in.length;
//		Arrays.fill(a, INF);
		a[0] = a[n-1] = a[n-2] = INF;
		System.arraycopy(in, 0, a, 1, in.length);
		for(int t = pos/2-1;t >= 1;t--){
			for(int c = t;2*c < pos;){
				int smaller = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
				if(a[smaller] < a[c]){
					long d = a[c]; a[c] = a[smaller]; a[smaller] = d;
					c = smaller;
				}else{
					break;
				}
			}
		}
	}
	
	public void add(long x)
	{
		a[pos++] = x;
		for(int c = pos-1, p = c>>>1;p >= 1 && a[c] < a[p];c>>>=1, p>>>=1){
			long d = a[p]; a[p] = a[c]; a[c] = d;
		}
	}
	
	public long poll()
	{
		if(pos == 1)return INF;
		pos--;
		long ret = a[1];
		a[1] = a[pos];
		a[pos] = INF;
		for(int c = 1;2*c < pos;){
			int smaller = a[2*c] < a[2*c+1] ? 2*c : 2*c+1;
			if(a[smaller] < a[c]){
				long d = a[c]; a[c] = a[smaller]; a[smaller] = d;
				c = smaller;
			}else{
				break;
			}
		}
		return ret;
	}
	
	public long min() { return a[1]; }
	public int size() { return pos-1; }
}

	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}