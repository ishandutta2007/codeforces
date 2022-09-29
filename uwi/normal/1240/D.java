//package round591;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Random;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	long mod = (1L<<61)-1;
	Random gen = new Random();
	long mul = BigInteger.probablePrime(61, gen).longValue();
	long mul2 = BigInteger.probablePrime(61, gen).longValue();
	
	long mul(long a, long b)
	{
		long low = (a&(1L<<31)-1)*(b&(1L<<31)-1); // 2^62
		long mid = (a>>>31)*(b&(1L<<31)-1) + (b>>>31)*(a&(1L<<31)-1);
		long high = 2L*((a>>>31)*(b>>>31)+(mid>>>31)); // <2^61
		high += low;
		high += (mid&((1L<<31)-1))<<31;
		while(high >= mod || high < 0)high -= mod;
		return high;
	}
	
	void solve()
	{
//		for(int i = 0;i < 1000000;i++){
//			long A = Math.abs(gen.nextLong() % ((1L<<61)-1));
//			long B = Math.abs(gen.nextLong() % ((1L<<61)-1));
//			long ac = mul(A, B);
//			long ex = BigInteger.valueOf(A).multiply(BigInteger.valueOf(B)).mod(BigInteger.valueOf(mod)).longValue();
//			if(ac != ex){
//				tr(A, B);
//			}
//			assert ac == ex;
//		}
		
		int[] map = shuffle(300005, gen);
		
		for(int T = ni();T > 0;T--){
			int n = ni();
			int[] a = na(n);
			ans = 0;
			for(int i = 0;i < n;i++){
				a[i] = map[a[i]];
			}
			dfs(0, n, a);
			out.println(ans);
		}
	}
	
	public static long invl(long a, long mod) {
		long b = mod;
		long p = 1, q = 0;
		while (b > 0) {
			long c = a / b;
			long d;
			d = a;
			a = b;
			b = d % b;
			d = p;
			p = q;
			q = d - c * q;
		}
		return p < 0 ? p + mod : p;
	}

	
	public static int[] shuffle(int n, Random gen){ int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = i; for(int i = 0;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }
	
	void add(Map<Long, Map<Long, Integer>> map, long key, long key2)
	{
		if(!map.containsKey(key)){
			map.put(key, new HashMap<>());
		}
		if(!map.get(key).containsKey(key2)){
			map.get(key).put(key2, 0);
		}
		map.get(key).put(key2, map.get(key).get(key2)+1);
	}
	
	long ans;
	
	void dfs(int l, int r, int[] a)
	{
		if(r-l < 2)return;
		
		int h = l+r>>1;
		int[] stack = new int[h-l+2];
		int sp = 0;
		Map<Long, Map<Long, Integer>> L = new HashMap<>();
		long[] hst = new long[h-l+2];
		long[] hst2 = new long[h-l+2];
		for(int i = h-1;i >= l;i--){
			if(sp > 0 && stack[sp-1] == a[i]){
				sp--;
			}else{
				hst[sp+1] = (mul(hst[sp], mul) + a[i]);
				if(hst[sp+1] >= mod)hst[sp+1] -= mod;
				hst2[sp+1] = (mul(hst2[sp], mul2) + a[i]);
				if(hst2[sp+1] >= mod)hst2[sp+1] -= mod;
				stack[sp] = a[i];
				sp++;
			}
			add(L, hst[sp], hst2[sp]);
		}
		
		sp = 0;
		for(int i = h;i < r;i++){
			if(sp > 0 && stack[sp-1] == a[i]){
				sp--;
			}else{
				hst[sp+1] = (mul(hst[sp], mul) + a[i]);
				if(hst[sp+1] >= mod)hst[sp+1] -= mod;
				hst2[sp+1] = (mul(hst2[sp], mul2) + a[i]);
				if(hst2[sp+1] >= mod)hst2[sp+1] -= mod;
				stack[sp] = a[i];
				sp++;
			}
			if(L.containsKey(hst[sp]) && L.get(hst[sp]).containsKey(hst2[sp])){
				ans += L.get(hst[sp]).get(hst2[sp]);
			}
		}
		
		dfs(l, h, a);
		dfs(h, r, a);
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