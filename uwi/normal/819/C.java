//package round421;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int[] lpf = enumLowestPrimeFactors(1000005);
		for(int T = ni();T > 0;T--){
			int[] N = na(3);
			int[] M = na(3);
			int[] S = na(3);
			
			int[][] nf = new int[0][];
			for(int i = 0;i < 3;i++)nf = merge(nf, factorFast(N[i], lpf));
			
			int[][] sf = new int[][]{{2, 1}};
			for(int i = 0;i < 3;i++)sf = merge(sf, factorFast(S[i], lpf));
			long[] sdivs = enumDivisors(sf);
			long n = (long)N[0]*N[1]*N[2];
			long ans = 0;
			for(long v : sdivs){
				if(v <= n)ans++;
			}
			
			long[] up = new long[nf.length];
			int p = 0;
			for(int i = 0;i < nf.length;i++){
				while(p < sf.length && nf[i][0] > sf[p][0])p++;
				if(p < sf.length && nf[i][0] == sf[p][0]){
					if(sf[p][1] >= nf[i][1]){
						up[i] = Long.MAX_VALUE;
					}else{
						up[i] = 1;
						for(int k = 0;k <= sf[p][1];k++){
							up[i] *= nf[i][0];
						}
					}
				}else{
					up[i] = nf[i][0];
				}
			}
//			tr(nf);
//			tr(sf);
//			tr(up);
			
			long m = (long)M[0]*M[1]*M[2];
			long[] vals = new long[1<<nf.length];
			vals[0] = m;
			for(int i = 0;i < 1<<nf.length;i++){
				if(i > 0){
					vals[i] = -vals[i&i-1] / up[Integer.numberOfTrailingZeros(i)];
				}
				ans += vals[i];
			}
			out.println(ans);
		}
	}
	
	public static long[] enumDivisors(int[][] f)
	{
		int n = 1;
		for(int j = 0;j < f.length;j++){
			n *= f[j][1]+1;
		}
		long[] divs = new long[n];
		int p = 1;
		divs[0] = 1;
		for(int j = 0;j < f.length;j++){
			for(int q = p-1;q >= 0;q--){
				long b = divs[q];
				for(int k = 0;k < f[j][1];k++){
					b *= f[j][0];
//					if((long)b*b <= n)divs[p++] = b;
					divs[p++] = b;
				}
			}
		}
		return divs;
	}
	
	public static int[][] and(int[][] f1, int[][] f2)
	{
		int[][] f = new int[Math.min(f1.length, f2.length)][];
		int pf = 0, p1 = f1.length, p2 = f2.length;
		int i = 0, j = 0;
		while(i < p1 && j < p2){
			if(f1[i][0] < f2[j][0]){
				i++;
			}else if(f1[i][0] > f2[j][0]){
				j++;
			}else{
				f[pf++] = new int[]{f1[i][0], Math.min(f1[i][1], f2[j][1])};
				i++; j++;
			}
		}
		return Arrays.copyOf(f, pf);
	}
	
	public static int[][] merge(int[][] f1, int[][] f2)
	{
		int[][] f = new int[f1.length+f2.length][];
		int pf = 0;
		int p1 = f1.length;
		int p2 = f2.length;
		int i = 0, j = 0;
		while(i < p1 && j < p2){
			if(f1[i][0] < f2[j][0]){
				f[pf++] = Arrays.copyOf(f1[i++], 2);
			}else if(f1[i][0] > f2[j][0]){
				f[pf++] = Arrays.copyOf(f2[j++], 2);
			}else{
				f[pf] = Arrays.copyOf(f1[i++], 2);
				f[pf++][1] += f2[j++][1];
			}
		}
		while(i < p1){
			f[pf++] = Arrays.copyOf(f1[i++], 2);
		}
		while(j < p2){
			f[pf++] = Arrays.copyOf(f2[j++], 2);
		}
		return Arrays.copyOf(f, pf);
	}
	
	public static int[][] factorFast(int n, int[] lpf)
	{
		int[][] f = new int[9][];
		int q = 0;
		while(lpf[n] > 0){
			int p = lpf[n];
			if(q == 0 || p != f[q-1][0]){
				f[q++] = new int[]{p, 1};
			}else{
				f[q-1][1]++;
			}
			n /= p;
		}
		if(n > 1){
			// big prime
			return new int[][]{{n, 1}};
		}
		return Arrays.copyOf(f, q);
	}
	
	public static int[] enumLowestPrimeFactors(int n) {
		int tot = 0;
		int[] lpf = new int[n + 1];
		int u = n + 32;
		double lu = Math.log(u);
		int[] primes = new int[(int) (u / lu + u / lu / lu * 1.5)];
		for (int i = 2; i <= n; i++)
			lpf[i] = i;
		for (int p = 2; p <= n; p++) {
			if (lpf[p] == p)
				primes[tot++] = p;
			int tmp;
			for (int i = 0; i < tot && primes[i] <= lpf[p] && (tmp = primes[i] * p) <= n; i++) {
				lpf[tmp] = primes[i];
			}
		}
		return lpf;
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