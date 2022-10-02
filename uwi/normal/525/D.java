//package round297;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] map = nm(n,m);
		
		Queue<Integer> q = new ArrayDeque<Integer>();
		boolean[] inq = new boolean[n*m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				if(map[i][j] == '.'){
					inq[i*m+j] = true;
					q.add(i*m+j);
				}
			}
		}
		
		int[] dr = { 1, 0, -1, 0 };
		int[] dc = { 0, 1, 0, -1 };
		while(!q.isEmpty()){
			int cur = q.poll();
			int r = cur/m, c = cur%m;
			inq[cur] = false;
			for(int k = 0, l = 1;k < 4;k++, l++){
				if(l == 4)l = 0;
				int nr = r + dr[k], nc = c + dc[k];
				if(nr >= 0 && nr < n && nc >= 0 && nc < m && map[nr][nc] == '.'){
					int mr = r + dr[l], mc = c + dc[l];
					if(mr >= 0 && mr < n && mc >= 0 && mc < m && map[mr][mc] == '.'){
						int ur = r + dr[k] + dr[l];
						int uc = c + dc[k] + dc[l];
						if(map[ur][uc] == '*'){
							map[ur][uc] = '.';
							if(!inq[ur*m+uc]){
								inq[ur*m+uc] = true;
								q.add(ur*m+uc);
							}
							for(int f = 0;f < 4;f++){
								int nnr = ur + dr[f], nnc = uc + dc[f];
								if(nnr >= 0 && nnr < n && nnc >= 0 && nnc < m && map[nnr][nnc] == '.'){
									if(!inq[nnr*m+nnc]){
										inq[nnr*m+nnc] = true;
										q.add(nnr*m+nnc);
									}
								}
							}
						}
					}
				}
			}
		}
		
		for(int i = 0;i < n;i++){
			out.println(new String(map[i]));
		}
	}
	
	public static class Q {
		public int[] q;
		protected int pt, ph;
		public Q(int n){ q = new int[n]; pt = ph = 0; }
		public void add(int x){ q[ph++] = x; }
		public void clear(){ pt = ph = 0; }
		public int poll(){ return q[pt++]; }
		public int size(){ return ph-pt; }
		public boolean isEmpty(){ return ph==pt; }
	}
	
	public static class SegmentTreeLST {
		public int M, H, N;
		public LST[] st;
		public int m;
		
		public SegmentTreeLST(int n, int m)
		{
			this.m = m;
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new LST[M];
			for(int i = 1;i < M;i++){
				st[i] = new LST(m*(H/Integer.highestOneBit(i)));
			}
		}
		
		public void set(int r, int c)
		{
			st[H+r].set(c);
			for(int i = (H+r)>>>1;i >= 1;i >>>= 1){
				int pos = (i-Integer.highestOneBit(i))*(H/Integer.highestOneBit(i));
				int len = H/Integer.highestOneBit(i);
				st[i].set(c*len+(r-pos));
			}
		}
		
		public void unset(int r, int c)
		{
			st[H+r].unset(c);
			for(int i = (H+r)>>>1;i >= 1;i >>>= 1){
				int pos = (i-Integer.highestOneBit(i))*(H/Integer.highestOneBit(i));
				int len = H/Integer.highestOneBit(i);
				st[i].unset(c*len+(r-pos));
			}
		}
		
		public int next(int rl, int rh, int cl, int ch){ return rl >= rh ? -1 : next(rl, rh, cl, ch, 0, H, 1);}
		
		private int next(int yl, int yh, int xl, int xh, int cl, int cr, int cur)
		{
			if(yl <= cl && cr <= yh){
//				int pos = (cur-Integer.highestOneBit(cur))*(H/Integer.highestOneBit(cur));
				int len = H/Integer.highestOneBit(cur);
				int nex = st[cur].next(xl*len);
				if(nex == -1 || nex >= xh*len)return -1;
				return (cl+nex%len)*m+nex/len;
			}else{
				int mid = cl+cr>>>1;
				if(cl < yh && yl < mid){
					int res = next(yl, yh, xl, xh, cl, mid, 2*cur);
					if(res != -1)return res;
				}
				if(mid < yh && yl < cr){
					int res = next(yl, yh, xl, xh, mid, cr, 2*cur+1);
					if(res != -1)return res;
				}
				return -1;
			}
		}
	}
	
	public static class LST {
		public long[][] set;
		public int n;
//		public int size;
		
		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);
			
			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//			size = 0;
		}
		
		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}
		
		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}
		
		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}
		
		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//				if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}
		
		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}
		
		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}
		
		private static int prev(long set, int n)
		{
			long h = Long.highestOneBit(set<<~n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)-(63-n);
		}
		
		private static int next(long set, int n)
		{
			long h = Long.lowestOneBit(set>>>n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}
		
		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
	}
	
	public static class DJSet {
		public int[] upper;
		public int[] minr;
		public int[] maxr;
		public int[] minc;
		public int[] maxc;

		public DJSet(int n, int m) {
			upper = new int[n*m];
			minr = new int[n*m];
			maxr = new int[n*m];
			minc = new int[n*m];
			maxc = new int[n*m];
			for(int i = 0;i < n;i++){
				for(int j = 0;j < m;j++){
					minr[i*m+j] = maxr[i*m+j] = i;
					minc[i*m+j] = maxc[i*m+j] = j;
				}
			}
			Arrays.fill(upper, -1);
		}

		public int root(int x) {
			return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
		}

		public boolean equiv(int x, int y) {
			return root(x) == root(y);
		}

		public boolean union(int x, int y) {
			x = root(x);
			y = root(y);
			if (x != y) {
				if (upper[y] < upper[x]) {
					int d = x;
					x = y;
					y = d;
				}
				minr[x] = Math.min(minr[x], minr[y]);
				maxr[x] = Math.max(maxr[x], maxr[y]);
				minc[x] = Math.min(minc[x], minc[y]);
				maxc[x] = Math.max(maxc[x], maxc[y]);
				upper[x] += upper[y];
				upper[y] = x;
			}
			return x == y;
		}

		public int count() {
			int ct = 0;
			for (int u : upper)
				if (u < 0)
					ct++;
			return ct;
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