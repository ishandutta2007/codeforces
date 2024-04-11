//package round192;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	int[][] fif = enumFIF(30, mod);
	
	public static int[][] enumFIF(int n, int mod)
	{
		int[] f = new int[n+1];
		int[] invf = new int[n+1];
		invf[1] = 1;
		for(int i = 2;i <= n;i++){
			invf[i] = (int)(invf[mod%i]*(long)(mod-mod/i)%mod);
		}
		
		f[0] = invf[0] = 1;
		for(int i = 1;i <= n;i++){
			f[i] = (int)((long)f[i-1] * i % mod);
			invf[i] = (int)((long)invf[i-1] * invf[i] % mod);
		}
		return new int[][]{f, invf};
	}
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int K = ni();
		int[] b = na(K);
		Arrays.sort(b);
		
		if(K == 0){
			out.println(fif[0][n]);
		}else if(K == 1){
			out.println((fif[0][n]-count(a, b[0])+mod)%mod);
		}else{
			out.println((fif[0][n]-count(a, b[0])-count(a,b[1])+count2(a,b[0],b[1])+2L*mod)%mod);
		}
	}
	
	int[][] collect(int[][] a)
	{
		Arrays.sort(a, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		int n = a.length;
		int c = 0;
		int p = 0;
		for(int i = 0;i < n;i++){
			c++;
			if(i == n-1 || a[i][0] != a[i+1][0] || a[i][1] != a[i+1][1]){
				a[p++] = new int[]{a[i][0], a[i][1], a[i][2], c};
				c = 0;
			}
		}
		return Arrays.copyOf(a, p);
	}
	
	long count2(int[] a, int x, int y)
	{
		int n = a.length;
		long sum = 0;
		for(int v : a)sum += v;
		int h = n/2;
		int nl = (int)Math.pow(3, h);
		First[] L = new First[nl];
		int[] ord = new int[h];
		int s = 0;
		do{
			long left = 0, right = 0;
			int[] num = new int[3];
			for(int i = 0;i < h;i++){
				num[ord[i]]++;
				if(ord[i] == 1)left += a[i];
				if(ord[i] == 2)right += a[i];
			}
			First f = new First();
			L[s++] = f;
			f.l = left; f.r = right;
			f.f = num;
		}while(inc(ord, 3));
		
		Comparator<First> comp = new Comparator<First>() {
			public int compare(First a, First b) {
				if(a.l != b.l)return Long.signum(a.l - b.l);
				return Long.signum(a.r-b.r);
			}
		};
		Arrays.sort(L, comp);
		
		Freq[] lfs = new Freq[nl];
		int p = 0;
		int pre = 0;
		for(int i = 0;i < nl;i++){
			if(i+1 == nl || L[i].l != L[i+1].l || L[i].r != L[i+1].r){
				Freq f = new Freq();
				f.l = L[i].l; f.r = L[i].r;
				f.fs = new int[i-pre+1][];
				for(int j = 0;j < i-pre+1;j++){
					f.fs[j] = L[pre+j].f;
				}
				f.fs = collect(f.fs);
				lfs[p++] = f;
				pre = i+1;
			}
		}
		
		Comparator<Freq> compf = new Comparator<Freq>() {
			public int compare(Freq a, Freq b) {
				if(a.l != b.l)return Long.signum(a.l - b.l);
				return Long.signum(a.r-b.r);
			}
		};
		
		int[] or = new int[n-h];
		Freq needle = new Freq();
		long ret = 0;
		do{
			long left = 0, right = 0;
			int[] num = new int[3];
			for(int i = 0;i < n-h;i++){
				num[or[i]]++;
				if(or[i] == 1)left += a[i+h];
				if(or[i] == 2)right += a[i+h];
			}
			
			needle.l = x-left; needle.r = sum-y-right;
			int ind = Arrays.binarySearch(lfs, 0, p, needle, compf);
			if(ind >= 0){
				Freq tar = lfs[ind];
				for(int[] c : tar.fs){
					ret += (long)fif[0][c[0]+num[0]]*fif[0][c[1]+num[1]]%mod*fif[0][c[2]+num[2]]%mod*c[3];
				}
			}
		}while(inc(or, 3));
		return ret%mod;
	}
	
	long count(int[] a, int x)
	{
		int n = a.length;
		int h = n/2;
		int nl = 1<<h;
		First[] L = new First[nl];
		int[] ord = new int[h];
		int s = 0;
		do{
			long left = 0;
			int[] num = new int[2];
			for(int i = 0;i < h;i++){
				num[ord[i]]++;
				if(ord[i] == 1)left += a[i];
			}
			First f = new First();
			L[s++] = f;
			f.l = left;
			f.f = num;
		}while(inc(ord, 2));
		
		Comparator<First> comp = new Comparator<First>() {
			public int compare(First a, First b) {
				return Long.signum(a.l - b.l);
			}
		};
		Arrays.sort(L, comp);
		
		Freq[] lfs = new Freq[nl];
		int p = 0;
		int pre = 0;
		for(int i = 0;i < nl;i++){
			if(i+1 == nl || L[i].l != L[i+1].l){
				Freq f = new Freq();
				f.l = L[i].l;
				f.fs = new int[i-pre+1][];
				for(int j = 0;j < i-pre+1;j++){
					f.fs[j] = L[pre+j].f;
				}
				lfs[p++] = f;
				pre = i+1;
			}
		}
		
		Comparator<Freq> compf = new Comparator<Freq>() {
			public int compare(Freq a, Freq b) {
				return Long.signum(a.l - b.l);
			}
		};
		
		int[] or = new int[n-h];
		Freq needle = new Freq();
		long ret = 0;
		do{
			long left = 0;
			int[] num = new int[2];
			for(int i = 0;i < n-h;i++){
				num[or[i]]++;
				if(or[i] == 1)left += a[i+h];
			}
			
			needle.l = x-left;
			int ind = Arrays.binarySearch(lfs, 0, p, needle, compf);
			if(ind >= 0){
				Freq tar = lfs[ind];
				for(int[] c : tar.fs){
					ret += (long)fif[0][c[0]+num[0]]*fif[0][c[1]+num[1]]%mod;
				}
			}
		}while(inc(or, 2));
		return ret%mod;
	}
	
	static class First
	{
		long l, r;
		int[] f;
	}
	
	static class Freq
	{
		long l, r;
		int[][] fs;
	}
	
	public static boolean inc(int[] a, int base)
	{
		int n = a.length;
		int i;
		for(i = n - 1;i >= 0 && a[i] == base - 1;i--);
		if(i == -1)return false;
		
		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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