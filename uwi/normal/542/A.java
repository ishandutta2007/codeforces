//package vk2015.r3;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.List;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] vs = new int[n][];
		for(int i = 0;i < n;i++){
			vs[i] = new int[]{ni(), ni(), i};
		}
		Arrays.sort(vs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[1] - b[1]);
//				return a[0] - b[0];
			}
		});
		int[][] chs = new int[m][];
		for(int i = 0;i < m;i++){
			chs[i] = new int[]{ni(), ni(), ni(), i};
		}
		Arrays.sort(chs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		
		int[][] rs = new int[2*n+2*m][];
		for(int i = 0;i < n;i++){
			rs[i] = new int[]{vs[i][0], 1, i};
			rs[i+n] = new int[]{vs[i][1], 3, i};
		}
		for(int i = 0;i < m;i++){
			rs[2*n+i] = new int[]{chs[i][0], 2, i};
			rs[2*n+i+m] = new int[]{chs[i][1], 4, i};
		}
		Arrays.sort(rs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0] != b[0])return a[0] - b[0];
				return a[1] - b[1];
			}
		});
		
		long ret = 0;
		int argv = -1, argc = -1;
		
		LST vlst = new LST(n);
		for(int[] r : rs){
			if(r[1] == 1){
				vlst.set(r[2]);
			}else if(r[1] == 3){
				vlst.unset(r[2]);
			}else if(r[1] == 2){
				int id = vlst.next(0);
				if(id != -1){
					long score = (long)chs[r[2]][2] * (Math.min(vs[id][1], chs[r[2]][1]) - r[0]);
					if(score > ret){
						ret = score;
						argv = vs[id][2];
						argc = chs[r[2]][3];
					}
				}
			}
		}
		
		SegmentTreeRMQPos2 st = new SegmentTreeRMQPos2(m);
		int[] heads = new int[m];
		for(int i = 0;i < m;i++){
			heads[i] = chs[i][0];
		}
		
		for(int[] r : rs){
			if(r[1] == 1){
			}else if(r[1] == 3){
				int start = vs[r[2]][0];
				int ind = upperBound(heads, start);
				if(ind >= 0){
					long min = st.min(0, ind+1);
					long score = (vs[r[2]][1]-vs[r[2]][0])*-min;
					if(score > ret){
						ret = score;
						argv = vs[r[2]][2];
						argc = chs[st.minpos][3];
					}
				}
			}else if(r[1] == 2){
				st.update(r[2], -chs[r[2]][2]);
			}else if(r[1] == 4){
				st.update(r[2], 0);
			}
		}
		
		for(int i = 0;i < n;i++){
			int n0 = 1000000000-vs[i][1];
			int n1 = 1000000000-vs[i][0];
			vs[i][0] = n0; vs[i][1] = n1;
		}
		Arrays.sort(vs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return -(a[1] - b[1]);
//				return a[0] - b[0];
			}
		});
		for(int i = 0;i < m;i++){
			int n0 = 1000000000-chs[i][1];
			int n1 = 1000000000-chs[i][0];
			chs[i][0] = n0; chs[i][1] = n1;
		}
		Arrays.sort(chs, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				return a[0] - b[0];
			}
		});
		{
			for(int i = 0;i < n;i++){
				rs[i] = new int[]{vs[i][0], 1, i};
				rs[i+n] = new int[]{vs[i][1], 3, i};
			}
			for(int i = 0;i < m;i++){
				rs[2*n+i] = new int[]{chs[i][0], 2, i};
				rs[2*n+i+m] = new int[]{chs[i][1], 4, i};
			}
			Arrays.sort(rs, new Comparator<int[]>() {
				public int compare(int[] a, int[] b) {
					if(a[0] != b[0])return a[0] - b[0];
					return a[1] - b[1];
				}
			});
			
			LST vlst2 = new LST(n);
			for(int[] r : rs){
				if(r[1] == 1){
					vlst2.set(r[2]);
				}else if(r[1] == 3){
					vlst2.unset(r[2]);
				}else if(r[1] == 2){
					int id = vlst2.next(0);
					if(id != -1){
						long score = (long)chs[r[2]][2] * (Math.min(vs[id][1], chs[r[2]][1]) - r[0]);
						if(score > ret){
							ret = score;
							argv = vs[id][2];
							argc = chs[r[2]][3];
						}
					}
				}
			}
		}
		
		out.println(ret);
		if(ret > 0){
			out.print(argv + 1 + " ");
			out.println(argc + 1);
		}
	}
	
	public static int upperBound(int[] a, int v)
	{
		int low = -1, high = a.length;
		while(high-low > 1){
			int h = high+low>>>1;
			if(a[h] <= v){
				low = h;
			}else{
				high = h;
			}
		}
		return low;
	}
	
	public static class SegmentTreeRMQPos2 {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos2(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++)pos[H+i] = i;
			Arrays.fill(st, 0, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public SegmentTreeRMQPos2(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int pos, int x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[2*i] <= st[2*i+1]){
				st[i] = st[2*i];
				pos[i] = pos[2*i];
			}else{
				st[i] = st[2*i+1];
				pos[i] = pos[2*i+1];
			}
		}
		
		public int minpos;
		public int minval;
		
		public int min(int l, int r){ 
			minpos = -1;
			minval = Integer.MAX_VALUE;
			min(l, r, 0, H, 1);
			return minval;
		}
		
		private void min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				if(st[cur] < minval){
					minval = st[cur];
					minpos = pos[cur];
				}
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid)min(l, r, cl, mid, 2*cur);
				if(mid < r && l < cr)min(l, r, mid, cr, 2*cur+1);
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
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new A().run(); }
	
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