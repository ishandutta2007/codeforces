//package round590;
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
		char[] s = ns().toCharArray();
		
		out.println(Math.max(go(s), go(rev(s))));
	}
	
	public static char[] rev(char[] a)
	{
		a = Arrays.copyOf(a, a.length);
		for(int i = 0, j = a.length-1;i < j;i++,j--){
			char c = a[i]; a[i] = a[j]; a[j] = c;
		}
		return a;
	}

	
	int go(char[] s)
	{
		int n = s.length;
		int[][] ptns = new int[21][n];
		int ans = 0;
		for(int i = 0;i < n;i++){
			int ptn = 0;
			for(int j = 0;j <= 20 && i-j >= 0;j++){
				if(ptn<<~(s[i-j]-'a')<0)break;
				ptn |= 1<<s[i-j]-'a';
				ptns[j][i] = ptn;
				ans = Math.max(ans, j+1);
			}
		}
		
		boolean[][] hit = new boolean[20][1<<20];
		int[] q = new int[1<<20];
		for(int i = n-1;i >= 0;i--){
			int k = 19;
			for(int j = 0;j < 20;j++){
				if(ptns[j][i] == 0)continue;
				while(k >= 0 && (i+1+k >= n || !hit[k][ptns[j][i]])){
					k--;
				}
				if(k >= 0){
					ans = Math.max(ans, j+k+2);
				}
			}
			for(int j = 0;j < 20 && i+j < n;j++){
				if(ptns[j][i+j] == 0)continue;
				int start = (1<<20)-1^ptns[j][i+j];
				int p = 0;
				if(hit[j][start])continue;
				q[p++] = start;
				for(int x = start;x != 0;x &= x-1) {
					int low = x&-x;
					int lp = p;
					for(int r = 0;r < p;r++){
						int cur = q[r];
						if(!hit[j][cur] && (cur&low) != 0){
							q[lp++] = cur^low;
						}
					}
					p = lp;
				}
				for(int r = 0;r < p;r++){
					hit[j][q[r]] = true;
				}
			}
		}
		return ans;
	}
	
	void run() throws Exception
	{
//		int n = 1000000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		for (int i = 0; i < n; i++) {
//			sb.append((char)('a'+gen.nextInt(20)));
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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