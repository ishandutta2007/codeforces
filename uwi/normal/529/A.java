//package vk2015.r1;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int n = s.length;
		int[] h = new int[2*n+1];
		for(int i = 0;i < 2*n;i++){
			h[i+1] = h[i] + (s[i%n] == '(' ? 1 : -1);
		}
		SegmentTreeRMQ st = new SegmentTreeRMQ(h);
		
		char[] t = new char[2*n];
		for(int i = 0;i < n;i++){
			t[i+n] = t[i] = s[i];
		}
		int[] sa = sa(t);
		tr(h);
		tr(sa);
		for(int i = 0;i < 2*n;i++){
			if(sa[i] < n){
				tr(sa[i], st.min(sa[i], sa[i]+n+1), h[sa[i]+n]);
			}
			if(sa[i] < n && (st.min(sa[i], sa[i]+n+1) == h[sa[i]+n] || st.min(sa[i], sa[i]+n+1) == h[sa[i]])){
				for(int j = 0;j < -h[n];j++){
					out.print("(");
				}
				out.print(new String(t, sa[i], n));
				for(int j = 0;j < h[n];j++){
					out.print(")");
				}
				out.println();
				return;
			}
		}
	}
	
	
	private static interface BaseArray {
		public int get(int i);

		public void set(int i, int val);

		public int update(int i, int val);
	}

	private static class CharArray implements BaseArray {
		private char[] m_A = null;
		private int m_pos = 0;

		CharArray(char[] A, int pos) {
			m_A = A;
			m_pos = pos;
		}

		public int get(int i) {
			return m_A[m_pos + i] & 0xffff;
		}

		public void set(int i, int val) {
			m_A[m_pos + i] = (char) (val & 0xffff);
		}

		public int update(int i, int val) {
			return m_A[m_pos + i] += val & 0xffff;
		}
	}
	
	public static class SegmentTreeRMQ {
		public int M, H, N;
		public int[] st;
		
		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			Arrays.fill(st, 0, M, Integer.MAX_VALUE);
		}
		
		public SegmentTreeRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
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
			st[i] = Math.min(st[2*i], st[2*i+1]);
		}
		
		public int min(int l, int r){ return l >= r ? 0 : min(l, r, 0, H, 1);}
		
		private int min(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				int ret = Integer.MAX_VALUE;
				if(cl < r && l < mid){
					ret = Math.min(ret, min(l, r, cl, mid, 2*cur));
				}
				if(mid < r && l < cr){
					ret = Math.min(ret, min(l, r, mid, cr, 2*cur+1));
				}
				return ret;
			}
		}
		
		public int firstle(int l, int v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur;
					}else{
						return cur-H;
					}
				}else{
					cur++;
					if((cur&cur-1) == 0)return -1;
					if((cur&1)==0)cur>>>=1;
				}
			}
		}
		
		public int lastle(int l, int v) {
			int cur = H+l;
			while(true){
				if(st[cur] <= v){
					if(cur < H){
						cur = 2*cur+1;
					}else{
						return cur-H;
					}
				}else{
					if((cur&cur-1) == 0)return -1;
					cur--;
					if((cur&1)==1)cur>>>=1;
				}
			}
		}
	}

	private static class IntArray implements BaseArray {
		private int[] m_A = null;
		private int m_pos = 0;

		IntArray(int[] A, int pos) {
			m_A = A;
			m_pos = pos;
		}

		public int get(int i) {
			return m_A[m_pos + i];
		}

		public void set(int i, int val) {
			m_A[m_pos + i] = val;
		}

		public int update(int i, int val) {
			return m_A[m_pos + i] += val;
		}
	}

	/* find the start or end of each bucket */
	private static void getCounts(BaseArray T, BaseArray C, int n, int k) {
		int i;
		for(i = 0;i < k;++i){
			C.set(i, 0);
		}
		for(i = 0;i < n;++i){
			C.update(T.get(i), 1);
		}
	}

	private static void getBuckets(BaseArray C, BaseArray B, int k, boolean end) {
		int i, sum = 0;
		if(end != false){
			for(i = 0;i < k;++i){
				sum += C.get(i);
				B.set(i, sum);
			}
		}else{
			for(i = 0;i < k;++i){
				sum += C.get(i);
				B.set(i, sum - C.get(i));
			}
		}
	}

	/* sort all type LMS suffixes */
	private static void LMSsort(BaseArray T, int[] SA, BaseArray C,
			BaseArray B, int n, int k) {
		int b, i, j;
		int c0, c1;
		/* compute SAl */
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, false); /* find starts of buckets */
		j = n - 1;
		b = B.get(c1 = T.get(j));
		--j;
		SA[b++] = (T.get(j) < c1) ? ~j : j;
		for(i = 0;i < n;++i){
			if(0 < (j = SA[i])){
				if((c0 = T.get(j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				--j;
				SA[b++] = (T.get(j) < c1) ? ~j : j;
				SA[i] = 0;
			}else if(j < 0){
				SA[i] = ~j;
			}
		}
		/* compute SAs */
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, true); /* find ends of buckets */
		for(i = n - 1, b = B.get(c1 = 0);0 <= i;--i){
			if(0 < (j = SA[i])){
				if((c0 = T.get(j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				--j;
				SA[--b] = (T.get(j) > c1) ? ~(j + 1) : j;
				SA[i] = 0;
			}
		}
	}

	private static int LMSpostproc(BaseArray T, int[] SA, int n, int m) {
		int i, j, p, q, plen, qlen, name;
		int c0, c1;
		boolean diff;

		/*
		 * compact all the sorted substrings into the first m items of SA 2*m
		 * must be not larger than n (proveable)
		 */
		for(i = 0;(p = SA[i]) < 0;++i){
			SA[i] = ~p;
		}
		if(i < m){
			for(j = i, ++i;;++i){
				if((p = SA[i]) < 0){
					SA[j++] = ~p;
					SA[i] = 0;
					if(j == m){
						break;
					}
				}
			}
		}

		/* store the length of all substrings */
		i = n - 1;
		j = n - 1;
		c0 = T.get(n - 1);
		do{
			c1 = c0;
		}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
		for(;0 <= i;){
			do{
				c1 = c0;
			}while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
			if(0 <= i){
				SA[m + ((i + 1) >> 1)] = j - i;
				j = i + 1;
				do{
					c1 = c0;
				}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
			}
		}

		/* find the lexicographic names of all substrings */
		for(i = 0, name = 0, q = n, qlen = 0;i < m;++i){
			p = SA[i];
			plen = SA[m + (p >> 1)];
			diff = true;
			if((plen == qlen) && ((q + plen) < n)){
				for(j = 0;(j < plen) && (T.get(p + j) == T.get(q + j));++j){
				}
				if(j == plen){
					diff = false;
				}
			}
			if(diff != false){
				++name;
				q = p;
				qlen = plen;
			}
			SA[m + (p >> 1)] = name;
		}

		return name;
	}

	/* compute SA and BWT */
	private static void induceSA(BaseArray T, int[] SA, BaseArray C,
			BaseArray B, int n, int k) {
		int b, i, j;
		int c0, c1;
		/* compute SAl */
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, false); /* find starts of buckets */
		j = n - 1;
		b = B.get(c1 = T.get(j));
		SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
		for(i = 0;i < n;++i){
			j = SA[i];
			SA[i] = ~j;
			if(0 < j){
				if((c0 = T.get(--j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				SA[b++] = ((0 < j) && (T.get(j - 1) < c1)) ? ~j : j;
			}
		}
		/* compute SAs */
		if(C == B){
			getCounts(T, C, n, k);
		}
		getBuckets(C, B, k, true); /* find ends of buckets */
		for(i = n - 1, b = B.get(c1 = 0);0 <= i;--i){
			if(0 < (j = SA[i])){
				if((c0 = T.get(--j)) != c1){
					B.set(c1, b);
					b = B.get(c1 = c0);
				}
				SA[--b] = ((j == 0) || (T.get(j - 1) > c1)) ? ~j : j;
			}else{
				SA[i] = ~j;
			}
		}
	}

	/*
	 * find the suffix array SA of T[0..n-1] in {0..k-1}^n use a working space
	 * (excluding T and SA) of at most 2n+O(1) for a constant alphabet
	 */
	private static void SA_IS(BaseArray T, int[] SA, int fs, int n, int k) {
		BaseArray C, B, RA;
		int i, j, b, m, p, q, name, newfs;
		int c0, c1;
		int flags = 0;

		if(k <= 256){
			C = new IntArray(new int[k], 0);
			if(k <= fs){
				B = new IntArray(SA, n + fs - k);
				flags = 1;
			}else{
				B = new IntArray(new int[k], 0);
				flags = 3;
			}
		}else if(k <= fs){
			C = new IntArray(SA, n + fs - k);
			if(k <= (fs - k)){
				B = new IntArray(SA, n + fs - k * 2);
				flags = 0;
			}else if(k <= 1024){
				B = new IntArray(new int[k], 0);
				flags = 2;
			}else{
				B = C;
				flags = 8;
			}
		}else{
			C = B = new IntArray(new int[k], 0);
			flags = 4 | 8;
		}

		/*
		 * stage 1: reduce the problem by at least 1/2 sort all the
		 * LMS-substrings
		 */
		getCounts(T, C, n, k);
		getBuckets(C, B, k, true); /* find ends of buckets */
		for(i = 0;i < n;++i){
			SA[i] = 0;
		}
		b = -1;
		i = n - 1;
		j = n;
		m = 0;
		c0 = T.get(n - 1);
		do{
			c1 = c0;
		}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
		for(;0 <= i;){
			do{
				c1 = c0;
			}while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
			if(0 <= i){
				if(0 <= b){
					SA[b] = j;
				}
				b = B.update(c1, -1);
				j = i;
				++m;
				do{
					c1 = c0;
				}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
			}
		}
		if(1 < m){
			LMSsort(T, SA, C, B, n, k);
			name = LMSpostproc(T, SA, n, m);
		}else if(m == 1){
			SA[b] = j + 1;
			name = 1;
		}else{
			name = 0;
		}

		/*
		 * stage 2: solve the reduced problem recurse if names are not yet
		 * unique
		 */
		if(name < m){
			if((flags & 4) != 0){
				C = null;
				B = null;
			}
			if((flags & 2) != 0){
				B = null;
			}
			newfs = (n + fs) - (m * 2);
			if((flags & (1 | 4 | 8)) == 0){
				if((k + name) <= newfs){
					newfs -= k;
				}else{
					flags |= 8;
				}
			}
			for(i = m + (n >> 1) - 1, j = m * 2 + newfs - 1;m <= i;--i){
				if(SA[i] != 0){
					SA[j--] = SA[i] - 1;
				}
			}
			RA = new IntArray(SA, m + newfs);
			SA_IS(RA, SA, newfs, m, name);
			RA = null;

			i = n - 1;
			j = m * 2 - 1;
			c0 = T.get(n - 1);
			do{
				c1 = c0;
			}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
			for(;0 <= i;){
				do{
					c1 = c0;
				}while ((0 <= --i) && ((c0 = T.get(i)) <= c1));
				if(0 <= i){
					SA[j--] = i + 1;
					do{
						c1 = c0;
					}while ((0 <= --i) && ((c0 = T.get(i)) >= c1));
				}
			}

			for(i = 0;i < m;++i){
				SA[i] = SA[m + SA[i]];
			}
			if((flags & 4) != 0){
				C = B = new IntArray(new int[k], 0);
			}
			if((flags & 2) != 0){
				B = new IntArray(new int[k], 0);
			}
		}

		/* stage 3: induce the result for the original problem */
		if((flags & 8) != 0){
			getCounts(T, C, n, k);
		}
		/* put all left-most S characters into their buckets */
		if(1 < m){
			getBuckets(C, B, k, true); /* find ends of buckets */
			i = m - 1;
			j = n;
			p = SA[m - 1];
			c1 = T.get(p);
			do{
				q = B.get(c0 = c1);
				while (q < j){
					SA[--j] = 0;
				}
				do{
					SA[--j] = p;
					if(--i < 0){
						break;
					}
					p = SA[i];
				}while ((c1 = T.get(p)) == c0);
			}while (0 <= i);
			while (0 < j){
				SA[--j] = 0;
			}
		}
		induceSA(T, SA, C, B, n, k);
		C = null;
		B = null;
	}

	/* char */
	public static void suffixsort(char[] T, int[] SA, int n) {
		if((T == null) || (SA == null) || (T.length < n) || (SA.length < n)){
			return;
		}
		if(n <= 1){
			if(n == 1){
				SA[0] = 0;
			}
			return;
		}
		SA_IS(new CharArray(T, 0), SA, 0, n, 128);
	}
	
	public static int[] sa(char[] T)
	{
		int n = T.length;
		int[] sa = new int[n];
		suffixsort(T, sa, n);
		return sa;
	}
	
	public static int[] buildLCP(char[] str, int[] sa)
	{
		int n = str.length;
		int h = 0;
		int[] lcp = new int[n];
		int[] isa = new int[n];
		for(int i = 0;i < n;i++)isa[sa[i]] = i;
		for(int i = 0;i < n;i++){
			if(isa[i] > 0){
				for(int j = sa[isa[i]-1]; j+h<n && i+h<n && str[j+h] == str[i+h]; h++);
				lcp[isa[i]] = h;
			}else{
				lcp[isa[i]] = 0;
			}
			if(h > 0)h--;
		}
		return lcp;
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