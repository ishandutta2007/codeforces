//package round623;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] cum;
	
	void solve()
	{
		// 8 4     2        1  
		//   +4 2 +2=4 2 1 +1=2 1 last
		int n = ni(), K = ni();
		if(K == 0) {
			out.println(0);
			return;
		}
		int[] a = na(K);
		cum = new int[(1<<n)+1];
		for(int v : a) {
			cum[v]++;
		}
		for(int i = 1;i <= 1<<n;i++) {
			cum[i] += cum[i-1];
		}
		long ret = dfs(0, 1<<n, 1, 0) + 2;
		ret = Math.max(ret, dfs(0, 1<<n, 0, 1) + 2);
		ret = Math.max(ret, dfs(0, 1<<n, 1, 1) + 2);
		ret = Math.max(ret, dfs(0, 1<<n, 2, 0) + 2);
		ret = Math.max(ret, dfs(0, 1<<n, 2, 1) + 2);
		out.println(ret);
	}
	
	Map<Long, Long> cache = new HashMap<>();
	
	long dfs(int l, int r, int wn, int ln)
	{
		long code = 0;
		code = code * 1000000009 + l;
		code = code * 1000000009 + r;
		code = code * 1000000009 + wn;
		code = code * 1000000009 + ln;
		if(cache.containsKey(code))return cache.get(code);
		
		int h = l+r>>1;
		if(r-l == 4) {
			int nr = cum[r] - cum[h];
			int nl = cum[h] - cum[l];
			if(nl > nr) {
				int d = nl; nl = nr; nr = d;
			}
			if(nl == 0) {
				if(nr == 0) {
					return wn + ln == 0 ? 0 : Long.MIN_VALUE / 3;
				}else if(nr == 1) {
					return wn + ln == 1 ? 2 : Long.MIN_VALUE / 3;
				}else {
					return wn == 1 && ln == 1 ? 3 : Long.MIN_VALUE / 3;
				}
			}else if(nl == 1) {
				if(nr == 1) {
					if(wn == 1 && ln == 1)return 4;
					if(wn == 2 && ln == 0)return 3;
					if(wn == 0 && ln == 1)return 3;
					return Long.MIN_VALUE / 3;
				}else {
					if(wn == 2 && ln == 1)return 4;
					if(wn == 1 && ln == 1)return 4;
					return Long.MIN_VALUE / 3;
				}
			}else if(nl == 2) {
				if(wn == 2 && ln == 1)return 4;
				return Long.MIN_VALUE / 3;
			}
			throw new RuntimeException();
		}
		
		long[] lptn = new long[4];
		Arrays.fill(lptn, Long.MIN_VALUE / 3);
		for(int lw = 0;lw <= 2;lw++) {
			for(int ll = 0;ll <= 1;ll++) {
				long v = dfs(l, h, lw, ll);
				if(lw == 2) {
					lptn[3] = Math.max(lptn[3], v + 1);
				}else if(lw == 0) {
					lptn[ll<<1] = Math.max(lptn[ll<<1], v + ll);
				}else if(ll == 1) {
					lptn[3] = Math.max(lptn[3], v + 1);
					lptn[2] = Math.max(lptn[2], v + 1);
				}else {
					lptn[1] = Math.max(lptn[1], v);
					lptn[2] = Math.max(lptn[2], v + 1);
				}
			}
		}
		
		long[] rptn = new long[4];
		Arrays.fill(rptn, Long.MIN_VALUE / 3);
		for(int lw = 0;lw <= 2;lw++) {
			for(int ll = 0;ll <= 1;ll++) {
				long v = dfs(h, r, lw, ll);
				if(lw == 2) {
					rptn[3] = Math.max(rptn[3], v + 1);
				}else if(lw == 0) {
					rptn[ll<<1] = Math.max(rptn[ll<<1], v + ll);
				}else if(ll == 1) {
					rptn[3] = Math.max(rptn[3], v + 1);
					rptn[2] = Math.max(rptn[2], v + 1);
				}else {
					rptn[1] = Math.max(rptn[1], v);
					rptn[2] = Math.max(rptn[2], v + 1);
				}
			}
		}
		
//		tr(l, r, wn, ln, lptn, rptn);
		
		long ret = Long.MIN_VALUE / 3;
		for(int i = 0;i < 4;i++) {
			for(int j = 0;j < 4;j++) {
				for(int k = (i&j)&1;k <= ((i|j)&1);k++) {
					for(int m = ((i&j)&2)>>1;m <= ((i|j)&2)>>1;m++) {
						if(k == wn && m == ln) {
							ret = Math.max(ret, lptn[i] + rptn[j] + k + m);
						}
					}
				}
			}
		}
		cache.put(code, ret);
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 17, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		Set<Integer> set = new HashSet<>();
//		for (int i = 0; i < m; i++) {
//			while(true) {
//				int x = gen.nextInt(1<<17)+1;
//				if(set.add(x)) {
//					sb.append(x + " ");
//					break;
//				}
//			}
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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