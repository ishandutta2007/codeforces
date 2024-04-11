//package round495;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int T = ni();
		int[] a = na(T);
		int[] f = new int[T];
		for(int v : a){
			f[v]++;
		}
		
		max = 0;
		for(int i = f.length-1;i >= 0;i--){
			if(f[i] > 0){
				max = i;
				break;
			}
		}
		
		for(int i = 1;i*i <= T;i++){
			if(T % i == 0){
				int[] res = ok(i, T/i, f);
				if(res != null){
					out.println(i + " " + (T/i));
					out.println((res[0]+1) + " " + (res[1]+1));
					return;
				}
			}
		}
		out.println(-1);
	}
	
	int max;
	
	int[] ok(int a, int b, int[] f)
	{
		if(f[0] != 1)return null;
		int dist = 0;
		for(int i = 1;i < f.length;i++){
			if(f[i] != 4*i){
				dist = i-1;
				break;
			}
		}
		for(int x = 0;x < a;x++){
			int y = max-x;
			if(y >= 0 && y < b){
				int ld = Math.min(x, a-1-x);
				ld = Math.min(ld, y);
				ld = Math.min(ld, b-1-y);
				if(ld == dist && simulate(a, b, x, y, f)){
					return new int[]{x, y};
				}
			}
		}
		return null;
	}
	
	boolean simulate(int a, int b, int x, int y, int[] f)
	{
		int[] lf = new int[f.length];
		for(int i = 0;i < a;i++){
			for(int j = 0;j < b;j++){
				lf[Math.abs(i-x)+Math.abs(j-y)]++;
			}
		}
		return Arrays.equals(lf, f);
	}
	
	void run() throws Exception
	{
//		int n = 720720, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append("0 ");
//		for (int i = 1; i < n; i++) {
//			sb.append(gen.nextInt(3)+1 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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