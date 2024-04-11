//package round599;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.InputMismatchException;
import java.util.Map;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] a = new int[n][];
		Map<Long, Long> ci = new HashMap<>();
		long[] sums = new long[n];
		for(int i = 0;i < n;i++){
			int K = ni();
			a[i] = na(K);
			for(int j = 0;j < K;j++){
				ci.put((long)a[i][j], (long)i<<32|j);
				sums[i] += a[i][j];
			}
		}
		
		long S = 0;
		for(long v : sums){
			S += v;
		}
		if(S % n != 0){
			out.println("No");
			return;
		}
		S /= n;
		
		int[] offsets = new int[n+1];
		for(int i = 0;i < n;i++){
			offsets[i+1] = offsets[i] + a[i].length;
		}
		
		int m = offsets[n];
		int[] f = new int[m];
		Arrays.fill(f, -1);
		for(int i = 0;i < n;i++){
			for(int j = 0;j < a[i].length;j++){
				long T = a[i][j] + S - sums[i];
				if(ci.containsKey(T)){
					long code = ci.get(T);
					int from = offsets[i] + j;
					int to = offsets[(int)(code>>>32)] + (int)code;
					if(from != to && i == (int)(code>>>32))continue;
					f[from] = to;
				}
			}
		}
		int[][] cs = getCycles(f);
		int[][] zcs = new int[1<<n][];
		for(int[] c : cs){
			int ptn = 0;
			for(int k : c){
				int ind = Arrays.binarySearch(offsets, k);
				if(ind < 0)ind = -ind-2;
				ptn |= 1<<ind;
			}
			if(Integer.bitCount(ptn) != c.length)continue;
			zcs[ptn] = c;
		}
		
		boolean[] dp = new boolean[1<<n];
		dp[0] = true;
		for(int i = 1;i < 1<<n;i++){
			if(zcs[i] != null){
				int mask = (1<<n)-1^i;
				for(int j = mask;j >= 0;j--){ j &= mask; 
					dp[i|j] |= dp[j];
				} // include j=0
			}
		}
		if(dp[(1<<n)-1]){
			int[] vals = new int[n];
			int[] tos = new int[n];
			
			int cur = (1<<n)-1;
			inner:
			while(cur > 0){
				for(int k = cur;k >= 0;k--){
					k &= cur;
					if(dp[cur^k] && zcs[k] != null){
						for(int l = 0;l < zcs[k].length;l++){
							int nl = (l+zcs[k].length-1) % zcs[k].length;
							int fclus = Arrays.binarySearch(offsets, zcs[k][l]);
							int tclus = Arrays.binarySearch(offsets, zcs[k][nl]);
							if(fclus < 0)fclus = -fclus-2;
							if(tclus < 0)tclus = -tclus-2;
							int val = a[fclus][zcs[k][l]-offsets[fclus]];
							vals[fclus] = val;
							tos[fclus] = tclus;
						}
						cur ^= k;
						continue inner;
					}
				}
			}
			
			out.println("Yes");
			for(int i = 0;i < n;i++){
				out.println(vals[i] + " " + (tos[i]+1));
			}
			
//			for(int i = 0;i < n;i++){
//				sums[i] -= vals[i];
//				sums[tos[i]] += vals[i];
//			}
//			
//			for(int i = 0;i < n;i++){
//				assert sums[i] == S;
//			}
			
		}else{
			out.println("No");
		}
	}
	
	
	int[][] getCycles(int[] f)
	{
		int n = f.length;
		int[][] ret = new int[n][];
		boolean[] ved = new boolean[n];
		int[] touched = new int[n];
		Arrays.fill(touched, -1);
		int[] path = new int[n];
		int q = 0;
		outer:
		for(int i = 0;i < n;i++){
			int p = 0;
			for(int j = i;j != -1;j = f[j]){
				if(touched[j] != -1){
					ret[q++] = Arrays.copyOfRange(path, touched[j], p);
					break;
				}
				if(ved[j])break;
				touched[j] = p;
				path[p++] = j;
				ved[j] = true;
			}
			for(int k = 0;k < p;k++){
				touched[path[k]] = -1;
			}
		}
		return Arrays.copyOf(ret, q);
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