//package round222;
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
	
	void solve()
	{
		char[] s = ns(1000001);
		int n = s.length;
		int Q = ni();
		int o = 1000000;
		int[] hs = new int[2000009];
		Arrays.fill(hs, -1);
		int p = 0;
		int h = o;
		hs[h] = 0;
		long[] rs = new long[n/2+3+Q];
		for(int i = 0;i < n;i++){
			if(s[i] == '('){
				h++;
			}else{
				h--;
				if(hs[h] != -1){
					rs[p++] = (long)(n-hs[h])<<40|0L<<20|i;
				}
			}
			hs[h] = i+1;
		}
		
		for(int i = 0;i < Q;i++){
			rs[p++] = (long)(n-(ni()-1))<<40|(long)(ni())<<20|i;
		}
		Arrays.sort(rs, 0, p);
		
		int[] ft = new int[n+2];
		int[] ret = new int[Q];
		for(int i = 0;i < p;i++){
			int y = (int)(rs[i]>>>20&(1<<20)-1);
			int z = (int)(rs[i]&(1<<20)-1);
			if(y == 0){
				addFenwick(ft, z, 2);
			}else{
				y--;
				ret[z] = sumFenwick(ft, y);
			}
		}
		for(int u : ret){
			out.println(u);
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 100000;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		for(int i = 0;i < n;i++){
//			sb.append("()".charAt(gen.nextInt(2)));
//		}
//		sb.append(" ");
//		sb.append(m + " ");
//		for(int i = 0;i < m;i++){
//			int a = gen.nextInt(n)+1;
//			int b = gen.nextInt(n)+1;
//			sb.append(Math.min(a, b) + " " + Math.max(a, b) + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C2().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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