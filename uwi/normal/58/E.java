//package shinkan;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class O {
	InputStream is;
	PrintWriter out;
//	String INPUT = "";
	String INPUT = "";
	
	void solve()
	{
		String s = ns();
		String[] sp = s.split("[\\+=]");
		for(int i = 0;i < 3;i++){
			sp[i] = new StringBuilder(sp[i]).reverse().toString();
		}
		int A = sp[0].length();
		int B = sp[1].length();
		int C = sp[2].length();
		
		// height carry ended
		String[][][][][][] dp = new String[18][2][A+2][B+2][C+2][];
//		for(int a = 0;a < 16;a++){
//			for(int b = 0;b < 2;b++){
//				for(int c = 0;c <= A+1;c++){
//					for(int d = 0;d <= B+1;d++){
//						Arrays.fill(dp[a][b][c][d], 9999999);
//					}
//				}
//			}
//		}
		dp[0][0][0][0][0] = new String[]{"", "", ""};
		String[] best = null;
		for(int i = 0;i < 17;i++){
			String[] q = dp[i][0][A+1][B+1][C+1];
			if(q != null && (best == null || best[0].length() + best[1].length() + best[2].length() > 
			q[0].length() + q[1].length() + q[2].length())){
				best = q;
			}
			
			
			for(int carry = 0;carry < 2;carry++){
				
				
				for(int a = 0;a <= A+1;a++){
					for(int b = 0;b <= B+1;b++){
						for(int c = 0;c <= C+1;c++){
							if(dp[i][carry][a][b][c] == null)continue;
							String[] M = dp[i][carry][a][b][c];
							if(best != null){
								if(best[0].length() + best[1].length() + best[2].length() <=
								M[0].length() + M[1].length() + M[2].length())continue;
							}
//							tr(i, carry, a, b, c, dp[i][carry][a][b][c]);
							for(int av = 0;av <= (a == A+1 ? 0 : 9);av++){
								for(int bv = 0;bv <= (b == B+1 ? 0 : 9);bv++){
									int ne = av + bv + carry;
									int ncarry = ne / 10;
									int cv = ne % 10;
									if(c == C+1 && cv > 0)continue;
									
									int mask = 0;
									if(a < A){
										if(sp[0].charAt(a)-'0' == av){
											mask |= 1;
										}
									}else if(a == A && av == 0){
										mask |= 1;
									}
									if(b < B){
										if(sp[1].charAt(b)-'0' == bv){
											mask |= 2;
										}
									}else if(b == B && bv == 0){
										mask |= 2;
									}
									if(c < C){
										if(sp[2].charAt(c)-'0' == cv){
											mask |= 4;
										}
									}else if(c == C && cv == 0 && ncarry == 0){
										mask |= 4;
									}
									
									for(int j = 0;j < 8;j++){
										if((j&mask) == j){
											int na = a+(j&1);
											int nb = b+(j>>>1&1);
											int nc = c+(j>>>2&1);
											String[] nev = new String[]{
													(na == A + 1 ? "" :  ""+ av) + dp[i][carry][a][b][c][0],
													(nb == B + 1 ? "" :  ""+ bv) + dp[i][carry][a][b][c][1],
													(nc == C + 1 ? "" :  ""+ cv) + dp[i][carry][a][b][c][2]
											};
											String[] ex = dp[i+1][ncarry][na][nb][nc];
											if(ex == null || ex[0].length() + ex[1].length() + ex[2].length() > 
												nev[0].length() + nev[1].length() + nev[2].length()){
												dp[i+1][ncarry][na][nb][nc] = nev;
											}
										}
									}
								}
							}
						}
					}
				}
				
			}
		}
		
		out.println(best[0] + "+" + best[1] + "=" + best[2]);
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
	
	public static void main(String[] args) throws Exception { new O().run(); }
	
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