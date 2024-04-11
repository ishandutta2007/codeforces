//package round174;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), q = ni();
		long t = ni();
		int[] a = na(n);
		int[] gt = new int[n];
		Arrays.fill(gt, -1);
		boolean[] src = new boolean[n];
		Arrays.fill(src, true);
		for(int i = 0;i < q;i++){
			int x = ni()-1, y = ni()-1;
			gt[x] = y;
			src[y] = false;
		}
		int[] gold = new int[n];
		int[] bonus = new int[n];
		for(int i = 0;i < n;i++)gold[i] = a[i];
		boolean[] ved = new boolean[n];
		for(int i = 0;i < n;i++){
			if(src[i]){
				for(int j = i;j != -1 && !ved[j];j = gt[j]){
					ved[j] = true;
					if(gt[j] != -1){
						gold[gt[j]] += gold[j];
						bonus[gt[j]] = bonus[j] + a[j];
					}
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				out.println(0);
				return;
			}
		}
		
		for(int i = 0;i < n;i++){
			t -= bonus[i];
		}
		if(t < 0){
			out.println(0);
			return;
		}
		
		int mod = 1000000007;
		int[] dp = new int[(int)t+1];
		dp[0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j+gold[i] <= t;j++){
				dp[j+gold[i]] += dp[j];
				if(dp[j+gold[i]] >= mod)dp[j+gold[i]] -= mod;
			}
		}
//		tr(t);
//		tr(gold);
		
		out.println(dp[(int)t]);
//		tr(dp);
//		tr(bonus);
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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