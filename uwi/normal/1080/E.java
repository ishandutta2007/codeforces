//package round524;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Set;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		int[][] cum = new int[n][m+1];
		long[][] hs = new long[n][m+1];
		Random gen = new Random();
		long[] zob = new long[26];
		for(int i = 0;i < 26;i++)zob[i] = gen.nextLong();
		
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				cum[i][j+1] = cum[i][j] ^ 1<<map[i][j]-'a';
				hs[i][j+1] = hs[i][j] + zob[map[i][j]-'a'];
			}
		}
		long[] ptns = new long[n];
		long ans = 0;
		boolean[] mark = new boolean[n];
		for(int j = 0;j < m;j++){
			for(int k = j;k < m;k++){
				// [j,k]
				Set<Long> all = new HashSet<>();
				for(int i = 0;i < n;i++){
					int ptn = cum[i][k+1] ^ cum[i][j];
					long h = hs[i][k+1] - hs[i][j];
					if((ptn&ptn-1) != 0){
						mark[i] = true;
					}else{
						ptns[i] = h;
						all.add(h);
					}
				}
				for(int i = 0;i < n;i++){
					if(mark[i]){
						while(true){
							long v = gen.nextLong();
							if(all.add(v)){
								ptns[i] = v;
								break;
							}
						}
					}
				}
				
				int[] rads = palindrome(ptns);
				for(int i = 0;i < rads.length;i++){
					if(i % 2 == 0 && mark[i/2]){
						mark[i/2] = false;
						continue;
					}
					ans += (rads[i]+1)/2;
				}
//				tr(j, k, ans, rads, ptns, mark);
			}
		}
		out.println(ans);
	}
	
	public static int[] palindrome(long[] str)
	{
		int n = str.length;
		int[] r = new int[2*n];
		int k = 0;
		for(int i = 0, j = 0;i < 2*n;i += k, j = Math.max(j-k, 0)){
			// normally
			while(i-j >= 0 && i+j+1 < 2*n && str[(i-j)/2] == str[(i+j+1)/2])j++;
			r[i] = j;
			
			// skip based on the theorem
			for(k = 1;i-k >= 0 && r[i]-k >= 0 && r[i-k] != r[i]-k;k++){
				r[i+k] = Math.min(r[i-k], r[i]-k);
			}
		}
		return r;
	}

	
	void run() throws Exception
	{
//		int n = 249, m = 250;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < n; i++) {
//			for(int j = 0;j < m;j++){
//				sb.append((char)(gen.nextInt(26)+'a'));
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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