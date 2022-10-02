//package goodbye2014;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void dfs(int l, int r, int ql, int qr, int[][] qs, int[][] items)
	{
		if(ql >= qr)return;
		if(l >= r-1)return;
		
		int h = (l+r)/2;
		int qll = -1;
		for(int i = ql;i < qr;i++){
			if(h <= qs[i][1]){
				qll = i;
				break;
			}
		}
		int qrr = -1;
		for(int i = qr-1;i >= ql;i--){
			if(qs[i][0] <= h){
				qrr = i;
				break;
			}
		}
		if(qll >= 0 && qrr >= 0){
			// [qll, qrr]
			int[] dp = new int[4001];
			Arrays.fill(dp, -99999999);
			dp[0] = 0;
			int[][] dps = new int[qrr-qll+1][];
			int p = qll;
			for(int i = h;p <= qrr;i++){
				for(int k = 4000-items[i][0];k >= 0;k--){
					dp[k+items[i][0]] = Math.max(dp[k+items[i][0]], dp[k] + items[i][1]);
				}
				boolean nice = false;
				while(p <= qrr && qs[p][1] == i){
					if(nice){
						dps[p-qll] = dps[p-qll-1];
					}else{
						dps[p-qll] = Arrays.copyOf(dp, 4001);
						for(int j = 1;j < 4001;j++){
							dps[p-qll][j] = Math.max(dps[p-qll][j], dps[p-qll][j-1]);
						}
					}
					nice = true;
					p++;
				}
			}
			dp = new int[4001];
			Arrays.fill(dp, -99999999);
			dp[0] = 0;
			p = qrr;
			while(p >= qll && qs[p][0] == h){
				int dpmax = 0;
				int ret = -1;
				for(int i = 0;i < 4001 && qs[p][2]-i >= 0;i++){
					dpmax = Math.max(dpmax, dp[i]);
					ret = Math.max(ret, dpmax + dps[p-qll][qs[p][2]-i]);
				}
				qs[p][4] = ret;
				p--;
			}
			for(int i = h-1;i >= l;i--){
				for(int k = 4000-items[i][0];k >= 0;k--){
					dp[k+items[i][0]] = Math.max(dp[k+items[i][0]], dp[k] + items[i][1]);
				}
				while(p >= qll && qs[p][0] == i){
					int dpmax = 0;
					int ret = -1;
					for(int j = 0;j < 4001 && qs[p][2]-j >= 0;j++){
						dpmax = Math.max(dpmax, dp[j]);
						ret = Math.max(ret, dpmax + dps[p-qll][qs[p][2]-j]);
					}
					qs[p][4] = ret;
					p--;
				}
			}
			dfs(l, h, ql, qll, qs, items);
			dfs(h, r, qrr+1, qr, qs, items);
		}else if(qll == -1){
			dfs(l, h, ql, qr, qs, items);
		}else if(qrr == -1){
			dfs(h, r, ql, qr, qs, items);
		}else{
			throw new RuntimeException();
		}
	}
	
	void solve()
	{
		int n = ni();
		int p = ni();
		int[][] items = new int[n][];
		for(int i = 0;i < n;i++){
			items[i] = new int[]{ni(), ni(), ni()};
		}
		Arrays.sort(items, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[2] - b[2];
			}
		});
		int[] ws = new int[n];
		for(int i = 0;i < n;i++){
			ws[i] = items[i][2] * 2;
		}
		
		int Q = ni();
		int[][] qs = new int[Q][];
		for(int z = 0;z < Q;z++){
			int v = ni(), b = ni();
			int l = -Arrays.binarySearch(ws, (v-p+1)*2-1)-1;
			int r = -Arrays.binarySearch(ws, v*2+1)-2;
			qs[z] = new int[]{l, r, b, z, -1};
		}
		Arrays.sort(qs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		dfs(0, n, 0, Q, qs, items);
		int[] ret = new int[Q];
		for(int i = 0;i < Q;i++){
			if(qs[i][4] == -1){
				if(qs[i][0] > qs[i][1]){
					qs[i][4] = 0;
				}else{
					qs[i][4] = items[qs[i][0]][0] <= qs[i][2] ? items[qs[i][0]][1] : 0;
				}
			}
			ret[qs[i][3]] = qs[i][4];
		}
		for(int i = 0;i < Q;i++){
			out.println(ret[i]);
		}
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