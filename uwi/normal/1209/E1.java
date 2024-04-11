//package round584;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class E1 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			int n = ni(), m = ni();
			int[][] a = new int[n][];
			for(int i = 0;i < n;i++)a[i] = na(m);
			
			int[][] sss = new int[1<<n][m];
			for(int i = 1;i < 1<<n;i+=2){
				int[] ss = new int[m];
				for(int j = 0;j < m;j++){
					int cur = i;
					int lmax = 0;
					for(int sh = 0;sh < n;sh++){
						int s = 0;
						for(int k = 0;k < n;k++){
							if(cur<<~k<0){
								s += a[k][j];
							}
						}
						lmax = Math.max(lmax, s);
						cur = cur>>>1|(cur&1)<<n-1;
					}
					ss[j] = lmax;
				}
				sss[i] = ss;
			}
			ptns = new HashMap<>();
			dfs(new int[n], 0, -1);
			int ans = 0;
			if(n == 4 && m >= 4){
				int[] one = Arrays.copyOf(sss[1], m);
				Arrays.sort(one);
				ans = one[m-1] + one[m-2] + one[m-3] + one[m-4];
			}
			
			for(int[] cs : ptns.values()){
				if(cs.length == 4)continue;
				int[] u = new int[cs.length];
				inner:
				do{
					for(int i = 0;i < cs.length;i++){
						for(int j = i+1;j < cs.length;j++){
							if(u[i] == u[j])continue inner;
						}
					}
					int val = 0;
					for(int i = 0;i < cs.length;i++){
						val += sss[cs[i]][u[i]];
					}
					ans = Math.max(ans, val);
				}while(inc(u, m));
			}
			out.println(ans);
		}
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}

	
	Map<Long, int[]> ptns = new HashMap<>();
//	Set<Long> all = new HashSet<>();
	
	void dfs(int[] a, int pos, int max)
	{
		if(pos == a.length){
			int[] ptn = new int[max+1];
			int n = a.length;
			for(int i = 0;i < n;i++){
				ptn[a[i]] |= 1<<i;
			}
			for(int i = 0;i <= max;i++){
				ptn[i] = ptn[i]>>>Integer.numberOfTrailingZeros(ptn[i]);
			}
//			for(int i = 0;i <= max;i++){
//				int min = ptn[i];
//				int k = ptn[i];
//				for(int j = 0;j < 12;j++){
//					int nk = k>>>1|(k&1)<<11;
//					k = nk;
//					min = Math.min(min, k);
//				}
//				ptn[i] = min;
//			}
			Arrays.sort(ptn);
			long h = 0;
			for(int v : ptn){
				h= h * 1000000009 + v;
			}
//			all.add(h);
			ptns.put(h, ptn);
			return;
		}
		
		for(int i = 0;i <= max+1;i++){
			a[pos] = i;
			dfs(a, pos+1, Math.max(i, max));
		}
	}
	
	void run() throws Exception
	{
//		int n = 4, m = 100;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(40 + " ");
//		for(int rep = 0;rep < 40;rep++){
//			sb.append(n + " ");
//			sb.append(m + " ");
//			for (int i = 0; i < n*m; i++) {
//				sb.append(gen.nextInt(100000) + " ");
//			}
//		}
//		INPUT = sb.toString();


		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E1().run(); }
	
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