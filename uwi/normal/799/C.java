//package round413;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), C = ni(), D = ni();
		int[][] coins = new int[n][];
		int cp = 0;
		int[][] dias = new int[n][];
		int dp = 0;
		for(int i = 0;i < n;i++){
			int b = ni(), p = ni();
			char type = nc();
			if(type == 'C'){
				coins[cp++] = new int[]{b, p};
			}else{
				dias[dp++] = new int[]{b, p};
			}
		}
		long ret = 0;
		
		// CD
		int cmax = Integer.MIN_VALUE / 3;
		for(int i = 0;i < cp;i++){
			if(coins[i][0] > cmax && coins[i][1] <= C){
				cmax = coins[i][0];
			}
		}
		int dmax = Integer.MIN_VALUE / 3;
		for(int i = 0;i < dp;i++){
			if(dias[i][0] > dmax && dias[i][1] <= D){
				dmax = dias[i][0];
			}
		}
		ret = Math.max(ret, (long)cmax + dmax);
		
		// C2
		ret = Math.max(ret, go(Arrays.copyOf(coins, cp), C));
		
		// D2
		ret = Math.max(ret, go(Arrays.copyOf(dias, dp), D));
		out.println(ret);
	}
	
	long go(int[][] cs, int C)
	{
		if(cs.length <= 1)return 0;
		Arrays.sort(cs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[1] - b[1];
			}
		});
		int n = cs.length;
		int[] mb1 = new int[n+1];
		int[] mb2 = new int[n+1];
		Arrays.fill(mb1, Integer.MIN_VALUE / 3);
		Arrays.fill(mb2, Integer.MIN_VALUE / 3);
		for(int i = 0;i < n;i++){
			mb1[i+1] = mb1[i];
			mb2[i+1] = mb2[i];
			if(cs[i][0] >= mb1[i+1]){
				mb2[i+1] = mb1[i+1];
				mb1[i+1] = cs[i][0];
			}else if(cs[i][0] >= mb2[i+1]){
				mb2[i+1] = cs[i][0];
			}
		}
		long ret = 0;
		int p = n-1;
		for(int i = 0;i < n;i++){
			int rem = C - cs[i][1];
			while(p >= 0 && cs[p][1] > rem){
				p--;
			}
			if(p >= 0){
				if(i <= p && cs[i][0] == mb1[p+1]){
					ret = Math.max(ret, cs[i][0] + mb2[p+1]);
				}else{
					ret = Math.max(ret, cs[i][0] + mb1[p+1]);
				}
			}
		}
		return ret;
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