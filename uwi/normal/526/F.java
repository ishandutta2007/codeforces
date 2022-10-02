//package zepto2015;
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
	
	long ret = 0;
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++){
			int x = ni()-1;
			int y = ni()-1;
			a[x] = y;
		}
//		tr(a);
		ret = n;
		dfs(0, n, a);
		out.println(ret);
	}
	
	int[] z0 = new int[600001];
	int[] z1max = new int[1200001];
	int[] z1min = new int[1200001];
	
	void dfs(int L, int R, int[] a)
	{
		if(R-L <= 1)return;
		int H = (L+R)/2;
		final int o1 = 600000;
		
		// [L,H) [H,R)
		int nl = H-L, nr = R-H;
		int[] maxl = new int[nl];
		int[] minl = new int[nl];
		maxl[0] = minl[0] = a[H-1];
		for(int i = 1;i < nl;i++){
			maxl[i] = Math.max(maxl[i-1], a[H-1-i]);
			minl[i] = Math.min(minl[i-1], a[H-1-i]);
		}
		int[] maxr = new int[nr];
		int[] minr = new int[nr];
		maxr[0] = minr[0] = a[H];
		for(int i = 1;i < nr;i++){
			maxr[i] = Math.max(maxr[i-1], a[H+i]);
			minr[i] = Math.min(minr[i-1], a[H+i]);
		}
//		tr(minl, maxl);
//		tr(minr, maxr);
		
		// 0 3 1 2 4
		// [1,3]
		// # [2,3]
		// [1,4]
		// [0,4]
		// [0,3]
		
		int pmax = nr, pmin = nr;
		for(int i = nl-1;i >= 0;i--){
			int op0 = Math.max(pmax, pmin);
			while(pmax > 0 && maxr[pmax-1] > maxl[i]){
				if(pmax > pmin){
					z1min[minr[pmax-1]+(H+pmax-1)+o1]--; // -pmin
				}else{
					z1max[maxr[pmax-1]-(H+pmax-1)+o1]++; // +pmax
				}
				pmax--;
			}
			while(pmin > 0 && minr[pmin-1] < minl[i]){
				if(pmin > pmax){
					z1max[maxr[pmin-1]-(H+pmin-1)+o1]--; // -pmax
				}else{
					z1min[minr[pmin-1]+(H+pmin-1)+o1]++; // +pmin
				}
				pmin--;
			}
			int p0 = Math.max(pmin, pmax);
			while(op0 > p0){
				op0--;
				z0[maxr[op0]-minr[op0]-(H+op0)+300000]++;
			}
//			tr(pmin, pmax, p0, op0);
//			trnz(z0);
//			trnz(z1max);
//			trnz(z1min);
			
			int l = H-1-i;
			// zone 0
			ret += z0[-l+300000];
//			tr("z0", z0[-l+300000]);
//			
			// zone 2
			int q0 = H+Math.min(pmin, pmax);
			// maxl[i]-minl[i]=k-i
			int col = maxl[i]-minl[i]+l;
//			tr("z2", H, col, q0);
			if(H <= col && col < q0)ret++;
			
			// zone 1
			if(pmin > pmax){
				// k+r-minl=r-l
				// k=minl-l
				ret += z1max[minl[i]-l+o1];
//				tr("z1max", z1max[minl[i]-l+o1]);
			}else{
				// maxl-(k-r)=r-l
				// k=maxl+l
				ret += z1min[maxl[i]+l+o1];
//				tr("z1min", z1min[maxl[i]+l+o1]);
			}
//			tr("ret",ret);
		}
//		
		int p0 = Math.max(pmin, pmax);
		while(p0 < nr){
			z0[maxr[p0]-minr[p0]-(H+p0)+300000]--;
			p0++;
		}
		while(pmax > pmin){
			z1min[minr[pmax-1]+(H+pmax-1)+o1]--; // -pmin
			pmax--;
		}
		while(pmin > pmax){
			z1max[maxr[pmin-1]-(H+pmin-1)+o1]--; // -pmax
			pmin--;
		}
		
//		for(int i = 0;i < z0.length;i++)assert z0[i] == 0;
//		for(int i = 0;i < z1min.length;i++)assert z1min[i] == 0;
//		for(int i = 0;i < z1max.length;i++)assert z1max[i] == 0;
		
//		tr(L, H, R, ret);
		dfs(L, H, a);
		dfs(H, R, a);
	}
	
	public static void trnz(int[] o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
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