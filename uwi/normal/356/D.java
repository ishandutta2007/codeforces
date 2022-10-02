//package round207;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), s = ni();
		int[] a = na(n);
		int max = -1;
		int maxi = -1;
		for(int i = 0;i < n;i++){
			if(a[i] > max){
				max = a[i];
				maxi = i;
			}
		}
		
		int ss = s - max;
		if(ss < 0){
			out.println(-1);
			return;
		}
		
		int q = (ss>>>6)+1;
		long[] dp = new long[q];
		dp[0] = 1L;
		int[] last = new int[ss+64];
		Arrays.fill(last, -1);
		int[] magic = {0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28, 62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11, 63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10, 51, 25, 36, 32,
	              60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};
		long[] pre = new long[q];
		for(int i = 0;i < n;i++){
			if(maxi == i)continue;
			System.arraycopy(dp, 0, pre, 0, q);
			for(int j = q-1-(a[i]>>>6);j >= 0;j--){
				int inf = j+(a[i]>>>6);
				if(inf+1 < q && (a[i]&63)>0)dp[inf+1] |= dp[j]>>>-a[i];
				if(inf < q)dp[inf] |= dp[j]<<a[i];
			}
			for(int j = 0;j < q;j++){
				for(long f = dp[j]^pre[j];f != 0L;f &= f-1){
					last[j<<6|magic[(int)((f&-f)*0x022fdd63cc95386dL>>>58)]] = i;
				}
			}
		}
		if(dp[ss>>>6]<<63-ss<0){
			int[][] b = new int[n][];
			int p = 0;
			int cur = ss;
			boolean[] used = new boolean[n];
			while(cur > 0){
				used[last[cur]] = true;
				cur -= a[last[cur]];
			}
			for(int i = 0;i < n;i++){
				if(!used[i]){
					b[p++] = new int[]{i, a[i]};
				}
			}
			Arrays.sort(b, 0, p, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					return a[1] - b[1];
				}
			});
			int[] rg = new int[n];
			int[] ret = new int[n];
			Arrays.fill(ret, -1);
			Arrays.fill(rg, -1);
			for(int i = p-1;i >= 1;i--){
				ret[b[i][0]] = b[i-1][0];
				rg[b[i][0]] = b[i][1]-b[i-1][1];
			}
			ret[b[0][0]] = -1;
			rg[b[0][0]] = b[0][1];
			for(int i = 0;i < n;i++){
				if(rg[i] == -1)rg[i] = a[i];
				out.print(rg[i] + " ");
				if(ret[i] == -1){
					out.println(0);
				}else{
					out.println(1 + " " + (ret[i]+1));
				}
			}
		}else{
			out.println(-1);
		}
	}
	
	void run() throws Exception
	{
//		int n = 70000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(70000)+1 + " ");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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