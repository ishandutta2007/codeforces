//package educational.round15;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long K = nl();
		int[] f = na(n);
		int[] w = na(n);
		
		int[][] sf = sparseNext(f);
		int[][] sm = sparseMin(sf, w);
		long[][] ss = sparseSum(sf, w);
		for(int i = 0;i < n;i++){
			out.println(sum(i, K, sf, ss) + " " + min(i, K, sf, sm));
		}
	}
	
	public static int[][] sparseNext(int[] f)
	{
		int n = f.length;
		final int m = 40; // 
		int[][] sf = new int[m][n];
		sf[0] = Arrays.copyOf(f, n);
		for(int i = 1;i < m;i++){
			for(int j = 0;j < n;j++){
				sf[i][j] = sf[i-1][j] == -1 ? -1 : sf[i-1][sf[i-1][j]];
			}
		}
		return sf;
	}
	
	public static int[][] sparseMin(int[][] sf, int[] w)
	{
		int n = w.length;
		final int m = 40; // 
		int[][] sm = new int[m][n];
		sm[0] = Arrays.copyOf(w, n);
		for(int i = 1;i < m;i++){
			for(int j = 0;j < n;j++){
				sm[i][j] = sf[i-1][j] == -1 ? sm[i-1][j] : Math.min(sm[i-1][j], sm[i-1][sf[i-1][j]]);
			}
		}
		return sm;
	}
	
	public static long[][] sparseSum(int[][] sf, int[] w)
	{
		int n = w.length;
		final int m = 40; // 
		long[][] sm = new long[m][n];
		for(int i = 0;i < n;i++){
			sm[0][i] = w[i];
		}
		for(int i = 1;i < m;i++){
			for(int j = 0;j < n;j++){
				sm[i][j] = sf[i-1][j] == -1 ? sm[i-1][j] : sm[i-1][j] + sm[i-1][sf[i-1][j]];
			}
		}
		return sm;
	}
	
	public static int go(int from, long step, int[][] sf)
	{
		int cur = from;
		for(int i = sf.length-1;i >= 0;i--){
			if(step<<~i<0){
				cur = sf[i][cur];
				if(cur == -1)break;
			}
		}
		return cur;
	}

	
	public static int min(int from, long step, int[][] sf, int[][] sm)
	{
		int cur = from;
		int min = Integer.MAX_VALUE;
		for(int i = sf.length-1;i >= 0;i--){
			if(step<<~i<0){
				min = Math.min(min, sm[i][cur]);
				cur = sf[i][cur];
				if(cur == -1)break;
			}
		}
		return min;
	}
	
	public static long sum(int from, long step, int[][] sf, long[][] ss)
	{
		int cur = from;
		long sum = 0;
		for(int i = sf.length-1;i >= 0;i--){
			if(step<<~i<0){
				sum += ss[i][cur];
				cur = sf[i][cur];
				if(cur == -1)break;
			}
		}
		return sum;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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