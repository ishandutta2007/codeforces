//package round439;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
//	String INPUT = "3 1 2 3";
//	String INPUT = "2 1 1 2";
//	String INPUT = "4 1 2 3";
//	String INPUT = "5 1 4 5";
//	String INPUT = "5 1 3 5";
//	String INPUT = "4 1 1 3";
//	String INPUT = "4 2\r\n" + 
//			"2 3 1 2 ";
//	String INPUT = "4 2\r\n" + 
//			"2 4 1 4 ";
	String INPUT = "";
	
	//    A1 A2 A3 ...
	// A0              An
	// A0*(A1+...+An)
	// A1*(A2+...+An)
	// ((A0+..+An)^2-A0^2-..-An^2)/2
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] ps = new int[m][];
		for(int i = 0;i < m;i++){
			ps[i] = na(2);
		}
//		for(int i = 1;i <= n;i++)tr(i, n, count(i,n));
		int mod = 1000000007;
		long ans = (long)n*n % mod;
		for(int i = 1;i < 1<<m;i++){
			int[] inds = new int[Integer.bitCount(i)];
			int p = 0;
			for(int j = 0;j < m;j++){
				if(i<<~j<0)inds[p++] = j;
			}
			int o = Integer.bitCount(i);
			do{
				// 0:0->1, 1:1->0
				for(int ptn = 0;ptn < 1<<o;ptn++){
					ans += go(inds, ptn, ps, n);
					ans %= mod;
//					tr("ans", i, inds, ptn, ans);
				}
			}while(nextPermutation(inds));
		}
		out.println(ans % mod);
	}
	
	long go(int[] inds, int ptn, int[][] ps, int n)
	{
		// collide?
		int[][] paths = new int[2*(inds.length-1)][];
		int p = 0;
		for(int i = 0;i < inds.length-1;i++){
			int f = ptn<<~i>=0 ? ps[inds[i]][1] : ps[inds[i]][0];
			int t = ptn<<~(i+1)>=0 ? ps[inds[i+1]][0] : ps[inds[i+1]][1];
			int lca = lca(f, t);
			paths[p++] = new int[]{f, lca};
			if(lca != t){
				int clca = t/(Integer.highestOneBit(t)/Integer.highestOneBit(lca)/2);
				paths[p++] = new int[]{t, clca};
			}
		}
		for(int i = 0;i < p;i++){
			for(int j = i+1;j < p;j++){
				if(col(paths[i], paths[j]))return 0;
			}
		}
//		tr("UM");
		int[] st = {
				ptn<<~0>=0 ? ps[inds[0]][0] : ps[inds[0]][1],
				ptn<<~(inds.length-1)>=0 ? ps[inds[inds.length-1]][1] : ps[inds[inds.length-1]][0]
		};
		if(st[0] == st[1])return 0;
//		tr("OK", st);
		int[] tops = new int[2];
		for(int j = 0;j < 2;j++){
			int top = 0;
			for(int i = 0;i < p;i++){
				int lcad = lca(st[j], paths[i][0]);
				if(Integer.highestOneBit(lcad) >= Integer.highestOneBit(paths[i][1])){
					top = Math.max(top, lcad);
				}
			}
			if(top == st[j])return 0; // collide
			
			if(top == 0){
				top = 1;
			}else{
				int otop = top;
				top = st[j] / (Integer.highestOneBit(st[j]) / Integer.highestOneBit(top) / 2);
				assert top / 2 == otop;
			}
			tops[j] = top;
		}
//		tr(st, tops);
		if(tops[0] == tops[1]){
			return calc(tops[0], paths, p, n, st[0], st[1]);
		}else{
			return (long)all(tops[0], paths, p, n, st[0]) * 
					all(tops[1], paths, p, n, st[1]);
		}
	}
	
	int count(int x, int n)
	{
		int first = Integer.highestOneBit(n) / Integer.highestOneBit(x) * x;
		int last = Integer.highestOneBit(n) / Integer.highestOneBit(x) * (x+1);
		int base = Integer.highestOneBit(n) / Integer.highestOneBit(x) - 1;
		return base + Math.max(0, Math.min(last-first, n-first+1));
	}
	
	int all(int top, int[][] paths, int p, int n, int tar)
	{
		int[] lroot = new int[p];
		int q = 0;
		for(int i = 0;i < p;i++){
			int llca = lca(paths[i][1], tar);
			if(Integer.highestOneBit(llca) < Integer.highestOneBit(top))continue;
			lroot[q++] = paths[i][1];
		}
		boolean[] ng = new boolean[q];
		for(int i = 0;i < q;i++){
			for(int k = 0;k < q;k++){
				if(i == k)continue;
				if(lca(lroot[i], lroot[k]) == lroot[k]){
					ng[i] = true;
				}
			}
		}
		int all = count(top, n);
		for(int i = 0;i < q;i++){
			if(!ng[i]){
				all -= count(lroot[i], n);
			}
		}
		return all;
	}
	
	long calc(int top, int[][] paths, int p, int n, int t1, int t2)
	{
		int[] lroot = new int[p];
		int q = 0;
		for(int i = 0;i < p;i++){
			int llca = lca(paths[i][1], t1);
			if(Integer.highestOneBit(llca) < Integer.highestOneBit(top))continue;
			lroot[q++] = paths[i][1];
		}
		boolean[] ng = new boolean[q];
		for(int i = 0;i < q;i++){
			for(int k = 0;k < q;k++){
				if(i == k)continue;
				if(lca(lroot[i], lroot[k]) == lroot[k]){
					ng[i] = true;
				}
			}
		}
		int[] route = new int[100];
		int tl = lca(t1, t2);
		int r = 0;
		for(int z = t1;z != tl;z /= 2){
			route[r++] = z;
		}
		int or = r;
		for(int z = t2;z != tl;z /= 2){
			route[r++] = z;
		}
		route[r++] = tl;
		for(int i = or, j = r-1;i < j;i++,j--){
			int d = route[i]; route[i] = route[j]; route[j] = d;
		}
		route = Arrays.copyOf(route, r);
		int[] has = new int[r];
		for(int i = 0;i < r;i++){
			has[i] = count(route[i], n);
		}
		for(int i = or-1;i >= 1;i--){
			has[i] -= has[i-1];
		}
		for(int i = or+1;i < r-1;i++){
			has[i] -= has[i+1];
		}
		for(int i = 0;i < q;i++){
			if(!ng[i] && lca(lroot[i], tl) == tl){
				int hit = lca(lroot[i], t1);
				if(hit == tl)hit = lca(lroot[i], t2);
				for(int j = 0;j < r;j++){
					if(route[j] == hit){
						has[j] -= count(lroot[i], n);
						break;
					}
				}
			}
		}
		if(tl != t1 && tl != t2){
			has[or] = count(top, n) - count(tl, n) + 1;
			
			for(int i = 0;i < q;i++){
				if(!ng[i] && lca(lroot[i], tl) != tl){
					has[or] -= count(lroot[i], n);
				}
			}
		}else{
			int tlch = route[or == 0 ? 1 : r - 2];
			has[or] = count(top, n) - count(tlch, n);
			for(int i = 0;i < q;i++){
				if(!ng[i] && lca(lroot[i], tlch) != tlch){
					has[or] -= count(lroot[i], n);
				}
			}
		}
//		tr("route", route);
//		tr("has", has, lroot);
		long s1 = 0;
		long s2 = 0;
		for(int v : has){
			s1 += v;
			s2 += (long)v*v;
		}
		return (s1*s1-s2)/2;
	}
	
	public static int lca(long x, long y)
	{
		long xx = x<<Long.numberOfLeadingZeros(x);
		long yy = y<<Long.numberOfLeadingZeros(y);
		return (int)(x>>>Math.max(Long.numberOfLeadingZeros(Math.min(x, y)), 64-Long.numberOfLeadingZeros(xx^yy))-Long.numberOfLeadingZeros(x));
	}
	
	boolean col(int[] a, int[] b)
	{
		int l = lca(a[0], b[0]);
		if(Integer.highestOneBit(a[1]) <= Integer.highestOneBit(l) && Integer.highestOneBit(b[1]) <= Integer.highestOneBit(l)){
			return true;
		}else{
			return false;
		}
	}
	
	static boolean nextPermutation(int[] src) {
		int i;
		for (i = src.length - 2; i >= 0 && src[i] > src[i + 1]; i--)
			;
		if (i == -1)
			return false;
		int j;
		for (j = i + 1; j < src.length && src[i] < src[j]; j++)
			;
		int d = src[i];
		src[i] = src[j - 1];
		src[j - 1] = d;
		for (int p = i + 1, q = src.length - 1; p < q; p++, q--) {
			d = src[p];
			src[p] = src[q];
			src[q] = d;
		}
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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