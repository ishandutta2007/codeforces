//package round199;
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
		int n = 3;
		int m = ni();
		char[][] map = nm(n,m);
		int mod = 1000000007;
		int[] ptn = new int[m+1];
		for(int i = 0;i < m;i++){
			int ok = 0;
			for(int j = 0;j < 3;j++){
				if(map[j][i] == '.'){
					ok |= 1<<j;
				}
			}
			ptn[i] = ok;
		}
		
		int or = -1, oc = -1;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 3;j++){
				if(map[j][i] == 'O'){
					or = j; oc = i;
				}
			}
		}
		
		int[][][] dp = new int[m+1][1<<3][2]; // [pos][spaceptn][canmove]
		dp[0][ptn[0]][0] = 1;
		for(int i = 0;i < m;i++){
			for(int j = 0;j < 1<<3;j++){
				for(int l = 0;l < 2;l++){
					for(int k = 0;k <= 6;k+=3){ // ver
						int hor = j^k;
						if((j&k) == k && (ptn[i+1]&hor) == hor){
							int nl = l;
							if(oc == i){
								if(or == 0){
									if(k == 6)nl |= 1;
								}else if(or == 2){
									if(k == 3)nl |= 1;
								}
							}else if(oc == i+1){
								if((ptn[i]^j)<<31-or<0)nl |= 1;
							}else if(oc == i-1){
								if(hor<<31-or<0)nl |= 1;
							}
							dp[i+1][ptn[i+1]^hor][nl] += dp[i][j][l];
							if(dp[i+1][ptn[i+1]^hor][nl] >= mod)dp[i+1][ptn[i+1]^hor][nl] -= mod;
						}
					}
				}
			}
		}
		out.println(dp[m][0][1]);
	}
	
	void run() throws Exception
	{
//		int n = 9999, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int j = 0;j < 3;j++){
//			for(int i = 0;i < n;i++){
//				if(j == 2 && i == n-1){
//					sb.append('O');
//				}else{
//					sb.append('.');
//				}
//			}
//			sb.append('\n');
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