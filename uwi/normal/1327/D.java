//package educational.round84;
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
		for(int T = ni();T > 0;T--)go();
	}
	
	void go()
	{
		int n = ni();
		int[] f = na(n);
		for(int i = 0;i < n;i++)f[i]--;
		int[] co = na(n);
		int[][] cs = splitIntoCycles(f);
		
		int ans = 99999999;
		for(int[] cy : cs){
			int m = cy.length;
			int[] lcs = new int[m];
			for(int i = 0;i < m;i++)lcs[i] = co[cy[i]];
			for(int d = 1;d*d <= m;d++){
				if(m % d == 0){
					if(check(lcs, d))ans = Math.min(ans, d);
					if(check(lcs, m/d))ans = Math.min(ans, m/d);
				}
			}
		}
		out.println(ans);
	}
	
	
	boolean check(int[] f, int d)
	{
		int m = f.length;
		inner:
		for(int i = 0;i < d;i++){
			for(int j = i;j < m;j+=d){
				if(f[j] != f[i])continue inner;
			}
			return true;
		}
		return false;
	}
	
	public static int[][] splitIntoCycles(int[] f)
	{
		int n = f.length;
		int[][] cycles = new int[n][];
		boolean[] ved = new boolean[n];
		int[] row = new int[n];
		int q = 0;
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				int p = 0;
				for(int cur = i;!ved[cur];cur = f[cur]){
					ved[cur] = true;
					row[p++] = cur;
				}
				cycles[q++] = Arrays.copyOf(row, p);
			}
		}
		return Arrays.copyOf(cycles, q);
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