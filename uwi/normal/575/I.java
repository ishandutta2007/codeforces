//package bubble8;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class I4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[][] qs = new int[Q][];
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int dir = ni();
				qs[i] = new int[]{1, ni(), ni(), dir, ni()};
			}else{
				qs[i] = new int[]{2, ni(), ni()};
			}
		}
		
		int[] rets = new int[Q];
		count(qs, 1, rets);
		for(int i = 0;i < Q;i++){
			qs[i][2] = n+1 - qs[i][2];
		}
		count(qs, 2, rets);
		for(int i = 0;i < Q;i++){
			qs[i][1] = n+1 - qs[i][1];
		}
		count(qs, 4, rets);
		for(int i = 0;i < Q;i++){
			qs[i][2] = n+1 - qs[i][2];
		}
		count(qs, 3, rets);
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 2){
				out.println(rets[i]);
			}
		}
	}
	
	SegmentTreeSeqCount st = new SegmentTreeSeqCount(5002);
	
	void count(int[][] qs, int xdir, int[] rets)
	{
		int Q = qs.length;
		st.clear();
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 1){
				if(qs[i][3] == xdir){
					st.updatex(qs[i][1], qs[i][1]+qs[i][4]+1, qs[i][2]);
				}
			}else{
				rets[i] += st.count(qs[i][1], qs[i][2]);
			}
		}
		st.clear();
		for(int i = 0;i < Q;i++){
			if(qs[i][0] == 1){
				if(qs[i][3] == xdir){
					st.update2x(qs[i][1], qs[i][1]+qs[i][4]+1, qs[i][2]);
				}
			}else{
				rets[i] += st.count2(qs[i][1], qs[i][2]);
			}
		}
	}
	
	public static class SegmentTreeSeqCount {
		public int M, H, N;
		public int[][] sups;
//		public int[] zs;
		
		public SegmentTreeSeqCount(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			sups = new int[M][];
//			zs = new int[M];
			for(int i = 0;i < H;i++){
				if(i < N){
					sups[H+i] = new int[N+2];
				}
			}
			for(int i = H-1;i >= 1;i--){
				sups[i] = new int[N+2];
			}
		}
		
		public void clear() {
			for(int[] s : sups){
				if(s != null)Arrays.fill(s, 0);
			}
//			Arrays.fill(zs, 0);
		}
		
		public void updatex(int l, int r, int w){
			if(l >= r)return;
			int br = r;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				
				int cur = (H+l)/f;
				int cl = cur*(H/Integer.highestOneBit(cur))-H;
//				zs[cur]++;
				addFenwick(sups[cur], w+(br-cl), -1);
				
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				
				int cur = (H+r)/f-1;
				int cl = cur*(H/Integer.highestOneBit(cur))-H;
//				zs[cur]++;
				addFenwick(sups[cur], w+(br-cl), -1);
				
				r -= f;
			}
		}
		
		public int count(int x, int y){
			int ret = 0;
			for(int i = H+x;i >= 1;i>>>=1){
				int left = i*(H/Integer.highestOneBit(i))-H;
//				ret += zs[i];
				ret += sumFenwick(sups[i], Math.min(sups[i].length-2, y+(x-left)));
			}
			return ret;
		}
		
		public void update2x(int l, int r, int w){
			if(l >= r)return;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				
				int cur = (H+l)/f;
//				zs[cur]++;
				addFenwick(sups[cur], w, -1);
				
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				
				int cur = (H+r)/f-1;
//				zs[cur]++;
				addFenwick(sups[cur], w, -1);
				
				r -= f;
			}
		}
		
		public int count2(int x, int y){
			int ret = 0;
			for(int i = H+x;i >= 1;i>>>=1){
//				ret -= zs[i];
				ret -= sumFenwick(sups[i], y);
			}
			return ret;
		}
		
		
		public static int sumFenwick(int[] ft, int i) {
			int sum = 0;
			for (i++; i > 0; i -= i & -i)
				sum += ft[i];
			return sum;
		}

		public static void addFenwick(int[] ft, int i, int v) {
			if (v == 0 || i < 0)
				return;
			int n = ft.length;
			for (i++; i < n; i += i & -i)
				ft[i] += v;
		}

		public static int findGFenwick(int[] ft, int v) {
			int i = 0;
			int n = ft.length;
			for (int b = Integer.highestOneBit(n); b != 0 && i < n; b >>= 1) {
				if (i + b < n) {
					int t = i + b;
					if (v >= ft[t]) {
						i = t;
						v -= ft[t];
					}
				}
			}
			return v != 0 ? -(i + 1) : i - 1;
		}

		public static int valFenwick(int[] ft, int i) {
			return sumFenwick(ft, i) - sumFenwick(ft, i - 1);
		}

		public static int[] restoreFenwick(int[] ft) {
			int n = ft.length - 1;
			int[] ret = new int[n];
			for (int i = 0; i < n; i++)
				ret[i] = sumFenwick(ft, i);
			for (int i = n - 1; i >= 1; i--)
				ret[i] -= ret[i - 1];
			return ret;
		}

		public static int[] buildFenwick(int[] a) {
			int n = a.length;
			int[] ft = new int[n + 1];
			System.arraycopy(a, 0, ft, 1, n);
			for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
				for (int i = k; i <= n; i += k) {
					ft[i] += ft[i - h];
				}
			}
			return ft;
		}

		public static int[] buildFenwick(int n, int v) {
			int[] ft = new int[n + 1];
			Arrays.fill(ft, 1, n + 1, v);
			for (int k = 2, h = 1; k <= n; k *= 2, h *= 2) {
				for (int i = k; i <= n; i += k) {
					ft[i] += ft[i - h];
				}
			}
			return ft;
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
	
	public static void main(String[] args) throws Exception { new I4().run(); }
	
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