//package round576;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Map;
import java.util.Set;
import java.util.SplittableRandom;

public class F3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long S = System.currentTimeMillis();
		int n = ni();
		int[] a = na(n);
		SplittableRandom gen = new SplittableRandom();

		Set<Integer> set = new HashSet<>();
		Set<Integer> twice = new HashSet<>();
		for(int v : a){
			if(!set.add(v)){
				twice.add(v);
			}
		}
		
		int[] c = new int[n];
		int p = 0;
		for(int x : set)c[p++] = x;
		for(int x : twice)c[p++] = x;
		c = Arrays.copyOf(c, p);
		
		long ag = 0;
		for(int v : a){
			ag = gcd3(ag, v);
		}
		if(ag != 1){
			out.println("NO");
			return;
		}
		
		long T = 350;
		boolean[] b = new boolean[p];
		while(System.currentTimeMillis() - S < T){
			long g = 0, h = 0;
			for(int i = 0;i < p;i++){
				b[i] = gen.nextBoolean();
				if(b[i]){
					if(g != ag)g = gcd3(g, c[i]);
				}else{
					if(h != ag)h = gcd3(h, c[i]);
				}
			}
			if(g == h){
				out.println("YES");
				
				Map<Integer, Boolean> once = new HashMap<>();
				Map<Integer, Boolean> twi = new HashMap<>();
				int w = 0;
				for(int v : c){
					if(!once.containsKey(v)){
						once.put(v, b[w]);
					}else{
						twi.put(v, b[w]);
					}
					w++;
				}
				
				for(int i = 0;i < n;i++){
					if(twi.containsKey(a[i])){
						out.print(twi.get(a[i]).equals(Boolean.TRUE) ? 2 :1 );
						twi.remove(a[i]);
					}else{
						out.print(once.get(a[i]).equals(Boolean.TRUE) ? 2 : 1);
					}
					out.print(" ");
				}
				out.println();
				return;
			}
		}
		out.println("NO");
	}
	
	public static long gcd3(long a, long b) {
		if(a == 0)return b;
		if(b == 0)return a;
		
		int ashift = Long.numberOfTrailingZeros(a);
		int bshift = Long.numberOfTrailingZeros(b);
		a >>>= ashift;
		b >>>= bshift;
		while(b != a){
			if(a > b){
				long t = a; a = b; b = t;
			}
			b -= a;
			b >>>= Long.numberOfTrailingZeros(b);
		}
		
		return a<<Math.min(ashift, bshift);
	}
//
//	
//	public static int gcd(int a, int b) {
//		while (b > 0) {
//			int c = a;
//			a = b;
//			b = c % b;
//		}
//		return a;
//	}
	
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append(gen.nextInt(1000000000) + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F3().run(); }
	
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