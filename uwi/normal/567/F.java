//package round314;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		int[] cl = new int[K];
		int[] sign = new int[K];
		int[] cr = new int[K];
		for(int i = 0;i < K;i++){
			cl[i] = ni()-1;
			String x = ns();
			if(x.equals("<")){
				sign[i] = -2;
			}else if(x.equals("<=")){
				sign[i] = -1;
			}else if(x.equals("=")){
				sign[i] = 0;
			}else if(x.equals(">=")){
				sign[i] = 1;
			}else if(x.equals(">")){
				sign[i] = 2;
			}else{
				throw new RuntimeException(x);
			}
			cr[i] = ni()-1;
		}
		
		long[][] dp = new long[n+1][2*n+1]; // [phase][#left]
		dp[0][0] = 1;
		for(int i = 0;i < n;i++){
			for(int j = 0;j <= 2*n;j++){
				if(dp[i][j] == 0)continue;
				int L = j;
				int R = 2*n-2*i+j-1;
				inner:
				for(int k = 0;k <= (i < n-1 ? 2 : 0);k++){
					for(int c = 0;c < K;c++){
						int vl = 0;
						if(cl[c] < L || cl[c] > R){
							vl = -1;
						}else if(L + k <= cl[c] && cl[c] <= R - (2-k)){
							vl = 1;
						}
						int vr = 0;
						if(cr[c] < L || cr[c] > R){
							vr = -1;
						}else if(L + k <= cr[c] && cr[c] <= R - (2-k)){
							vr = 1;
						}
						if(vl == vr && vl == 0){
							if(sign[c] == -1 || sign[c] == 0 || sign[c] == 1){
							}else{
								continue inner;
							}
						}else if(vl < vr){
							if(sign[c] < 0){
							}else{
								continue inner;
							}
						}else if(vl > vr){
							if(sign[c] > 0){
							}else{
								continue inner;
							}
						}
					}
					dp[i+1][j+k] += dp[i][j];
				}
			}
		}
		long ret = 0;
		for(int i = 0;i <= 2*n;i++){
			ret += dp[n][i];
		}
		out.println(ret);
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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