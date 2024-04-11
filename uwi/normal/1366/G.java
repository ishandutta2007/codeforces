//package ecr89;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int I = Integer.MAX_VALUE / 2;
	
	void solve()
	{
		char[] s = (ns() + "$").toCharArray();
		char[] t = (ns() + "$").toCharArray();
		int n = s.length;
		int m = t.length;
		int[] dp = new int[n+1];
		Arrays.fill(dp, I);
		dp[0] = 0;
		int[] hs = new int[n+1];
		for(int i = 0;i < n;i++){
			hs[i+1] = hs[i] + (s[i] == '.' ? -1 : 1);
		}
		
		for(int d = 0;d < m;d++){
			dp = trans(dp, t[d], hs, s);
//			tr(dp);
		}
		out.println(dp[n]);
	}
	
	int[] trans(int[] dp, char c, int[] hs, char[] s)
	{
		int n = hs.length-1;
		
//		tr(c);
//		tr(hs);
//		tr(s);
		for(int i = 0;i < n;i++){
			dp[i] += hs[i];
		}
//		tr(dp);
		
		int[] stack = new int[n+1]; 
		int[] minhs = new int[n+1]; // <
		int[] cmin = new int[n+1];
		
		int sp = 0;
		int[] ndp = new int[n+1];
		Arrays.fill(ndp, I);
		for(int i = 0;i <= n;i++){
			if(i > 0 && s[i-1] == c){
				ndp[i] = cmin[sp-1] + hs[i-1];
			}
			
			int v = dp[i];
			while(sp > 0 && minhs[sp-1] >= hs[i]){
				v = Math.min(v, stack[sp-1]);
				sp--;
			}
			stack[sp] = v;
			minhs[sp] = hs[i];
			cmin[sp] = Math.min(sp == 0 ? I : cmin[sp-1], v-2*minhs[sp]);
			sp++;
			
//			tr(i);
//			tr(Arrays.copyOf(stack, sp));
//			tr(Arrays.copyOf(minhs, sp));
		}
		return ndp;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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