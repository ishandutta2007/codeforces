//package round556;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		char[] s = ns(n);
		int[][] nexts = makeFatNext(s, 'a', 'z');
		
		int D = 255;
		int[][][] dp = new int[D][D][D];
		int[] L = new int[3];
		char[][] qs = new char[3][D];
		
		for(int z = 0;z < Q;z++){
			char t = nc();
			if(t == '+'){
				int id = ni()-1;
				char c = nc();
				qs[id][L[id]++] = c;
				for(int i = id == 0 ? L[0] : 0;i <= L[0];i++){
					for(int j = id == 1 ? L[1] : 0;j <= L[1];j++){
						for(int k = id == 2 ? L[2] : 0;k <= L[2];k++){
							int min = n+1;
							if(i-1 >= 0 && dp[i-1][j][k] < n){
								min = Math.min(min, nexts[qs[0][i-1]-'a'][dp[i-1][j][k]]);
							}
							if(j-1 >= 0 && dp[i][j-1][k] < n){
								min = Math.min(min, nexts[qs[1][j-1]-'a'][dp[i][j-1][k]]);
							}
							if(k-1 >= 0 && dp[i][j][k-1] < n){
								min = Math.min(min, nexts[qs[2][k-1]-'a'][dp[i][j][k-1]]);
							}
							dp[i][j][k] = min;
						}
					}
				}
			}else{
				int id = ni()-1;
				L[id]--;
			}
//			for(int i = 0;i <= L[0];i++){
//				for(int j = 0;j <= L[1];j++){
//					tr(i, j, dp[i][j]);
//				}
//			}
			out.println(dp[L[0]][L[1]][L[2]] <= n ? "YES" : "NO");
		}
	}
	
	public static int[][] makeFatNext(char[] s, char inf, char sup)
	{
		int n = s.length;
		int[][] next = new int[sup-inf+1][n+1];
		for(int i = 0;i < sup-inf+1;i++)next[i][n] = n+1;
		for(int i = s.length-1;i >= 0;i--){
			for(int j = 0;j < sup-inf+1;j++)next[j][i] = next[j][i+1];
			next[s[i]-inf][i] = i+1;
		}
		return next;
	}

	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(1000 + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append((char)('a'+gen.nextInt(26)));
//		}
//		sb.append("\n");
//		for (int i = 0; i < 250; i++) {
//			sb.append("+ 1 " + (char)('a'+gen.nextInt(26)) + "\n");
//		}
//		for (int i = 0; i < 250; i++) {
//			sb.append("+ 2 " + (char)('a'+gen.nextInt(26)) + "\n");
//		}
//		for (int i = 0; i < 250; i++) {
//			sb.append("+ 3 " + (char)('a'+gen.nextInt(26)) + "\n");
//		}
//		for (int i = 0; i < (1000-(250*3))/2; i++) {
//			sb.append("- 3\n");
//			sb.append("+ 3 " + (char)('a'+gen.nextInt(26)) + "\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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