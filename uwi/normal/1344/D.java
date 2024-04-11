//package round639;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.PriorityQueue;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	// a-3b^2-3b-1 >= t
	// 3b^2+3b+1+t-a
	// 
	void solve()
	{
		int n = ni();
		long K = nl();
		int[] a = na(n);
		
		long low = -(long)4e18, high = 1000000001;
		while(high - low > 1){
			long h = high+low>>1;
			long s = 0;
			for(int i = 0;i < n;i++){
				long llow = 0, lhigh = a[i]+1;
				while(lhigh - llow > 1){
					long b = lhigh+llow>>1;
					if(a[i]-(3*b*b+3*b+1) >= h){
						llow = b;
					}else{
						lhigh = b;
					}
				}
				s += llow;
			}
			if(s > K){
				low = h;
			}else{
				high = h;
			}
		}
		long h = high;
		long s = 0;
		long[] bb = new long[n];
		for(int i = 0;i < n;i++){
			long llow = 0, lhigh = a[i]+1;
			while(lhigh - llow > 1){
				long b = lhigh+llow>>1;
				if(a[i]-(3*b*b+3*b+1) >= h){
					llow = b;
				}else{
					lhigh = b;
				}
			}
			s += llow;
			bb[i] = llow;
		}
		
		long rem = K-s;
		assert rem >= 0;
		PriorityQueue<long[]> pq = new PriorityQueue<>((x, y) -> 
			-Long.compare(x[0], y[0])
		);
		for(int i = 0;i < n;i++){
			if(bb[i] < a[i]){
				pq.add(new long[]{f(a[i], bb[i]+1) - f(a[i], bb[i]), i});
			}
		}
		while(rem > 0){
			long[] cur = pq.poll();
			int i = (int)cur[1];
			bb[i]++;
			rem--;
			if(bb[i] < a[i]){
				pq.add(new long[]{f(a[i], bb[i]+1) - f(a[i], bb[i]), i});
			}
		}
		for(long v : bb){
			out.print(v + " ");
		}
		out.println();
	}
	
	long f(long a, long b)
	{
		return b*(a-b*b);
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
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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