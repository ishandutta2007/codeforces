//package round726;

import java.io.*;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class E2 {
	InputStream is;
	FastWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), K = ni();
		char[] s = ns(n);
		int[] z = Z(s);
		int ans = n;
		int[] sa = StringAlgorithm.suffixArray(s);
		int[] lcp = StringAlgorithm.lcpArray(s, sa);
		int[] isa = new int[n];
		for(int i = 0;i < n;i++){
			isa[sa[i]] = i;
		}

		int[] lcp0 = new int[n];
		int q = Integer.MAX_VALUE;
		for(int i = isa[0]-1;i >= 0;i--){
			q = Math.min(q, lcp[i]);
			lcp0[i] = q;
		}
		q = Integer.MAX_VALUE;
		for(int i = isa[0]+1;i < n;i++){
			q = Math.min(q, lcp[i-1]);
			lcp0[i] = q;
		}


		int[][] st = build(lcp);
		outer:
		for(int i = n-1;i >= 1;i--){
			int g = gcd(i, ans);
			if(z[g] >= ans-g){
				// same
				ans = i;
				continue;
			}
			int L = i, R = 0;
			while(true){
				int len = Math.min(ans - L, i - R);
				if(R == 0){
					if(lcp0[isa[L]] < len){
						if(isa[L] > isa[R]){
							ans = i;
						}
						continue outer;
					}
				}else{
					if(lcp0[isa[R]] < len){
						if(isa[L] > isa[R]){
							ans = i;
						}
						continue outer;
					}
				}
				L += len;
				R += len;
				if(L == ans)L = 0;
				if(R == i)R = 0;
			}
		}

		StringBuilder sb = new StringBuilder(new String(s, 0, ans));
		while(sb.length() <= K){
			sb.append(sb);
		}
		String T = sb.substring(0, K);
		out.println(T);
	}

	public static int[][] build(int[] a)
	{
		int n = a.length;
		int b = 32-Integer.numberOfLeadingZeros(n);
		int[][] ret = new int[b][];
		for(int i = 0, l = 1;i < b;i++, l*=2) {
			if(i == 0) {
				ret[i] = a;
			}else {
				ret[i] = new int[n-l+1];
				for(int j = 0;j < n-l+1;j++) {
					ret[i][j] = Math.min(ret[i-1][j], ret[i-1][j+l/2]);
				}
			}
		}
		return ret;
	}

	// [a,b)
	public static int rmq(int[][] or, int l, int r)
	{
		assert l <= r;
		if(l >= r)return Integer.MAX_VALUE;
		// 1:0, 2:1, 3:1, 4:2, 5:2, 6:2, 7:2, 8:3
		int t = 31-Integer.numberOfLeadingZeros(r-l);
		return Math.min(or[t][l], or[t][r-(1<<t)]);
	}




	static class StringAlgorithm {
		private static int[] saNaive(int[] s) {
			int n = s.length;
			int[] sa = new int[n];
			for(int i = 0;i < n;i++){
				sa[i] = i;
			}
			insertionsortUsingComparator(sa, (l, r) -> {
				while (l < n && r < n) {
					if (s[l] != s[r]) return s[l] - s[r];
					l++;
					r++;
				}
				return -(l - r);
			});
			return sa;
		}

		private static int[] saDoubling(int[] s) {
			int n = s.length;
			int[] sa = new int[n];
			for(int i = 0;i < n;i++){
				sa[i] = i;
			}
			int[] rnk = java.util.Arrays.copyOf(s, n);
			int[] tmp = new int[n];

			for (int k = 1; k < n; k *= 2) {
				final int _k = k;
				final int[] _rnk = rnk;
				java.util.function.IntBinaryOperator cmp = (x, y) -> {
					if (_rnk[x] != _rnk[y]) return _rnk[x] - _rnk[y];
					int rx = x + _k < n ? _rnk[x + _k] : -1;
					int ry = y + _k < n ? _rnk[y + _k] : -1;
					return rx - ry;
				};
				mergesortUsingComparator(sa, cmp);
				tmp[sa[0]] = 0;
				for (int i = 1; i < n; i++) {
					tmp[sa[i]] = tmp[sa[i - 1]] + (cmp.applyAsInt(sa[i - 1], sa[i]) < 0 ? 1 : 0);
				}
				int[] buf = tmp;
				tmp = rnk;
				rnk = buf;
			}
			return sa;
		}

		private static void insertionsortUsingComparator(int[] a, java.util.function.IntBinaryOperator comparator) {
			final int n = a.length;
			for (int i = 1; i < n; i++) {
				final int tmp = a[i];
				if (comparator.applyAsInt(a[i - 1], tmp) > 0) {
					int j = i;
					do {
						a[j] = a[j - 1];
						j--;
					} while (j > 0 && comparator.applyAsInt(a[j - 1], tmp) > 0);
					a[j] = tmp;
				}
			}
		}

		private static void mergesortUsingComparator(int[] a, java.util.function.IntBinaryOperator comparator) {
			final int n = a.length;
			final int[] work = new int[n];
			for (int block = 1; block <= n; block <<= 1) {
				final int block2 = block << 1;
				for (int l = 0, max = n - block; l < max; l += block2) {
					int m = l + block;
					int r = Math.min(l + block2, n);
					System.arraycopy(a, l, work, 0, block);
					for (int i = l, wi = 0, ti = m;; i++) {
						if (ti == r) {
							System.arraycopy(work, wi, a, i, block - wi);
							break;
						}
						if (comparator.applyAsInt(work[wi], a[ti]) > 0) {
							a[i] = a[ti++];
						} else {
							a[i] = work[wi++];
							if (wi == block) break;
						}
					}
				}
			}
		}

		private static final int THRESHOLD_NAIVE = 50;
		private static final int THRESHOLD_DOUBLING = 0;

		private static int[] sais(int[] s, int upper) {
			int n = s.length;
			if (n == 0) return new int[0];
			if (n == 1) return new int[]{0};
			if (n == 2) {
				if (s[0] < s[1]) {
					return new int[]{0, 1};
				} else {
					return new int[]{1, 0};
				}
			}
			if (n < THRESHOLD_NAIVE) {
				return saNaive(s);
			}
			//		if (n < THRESHOLD_DOUBLING) {
			//			return saDoubling(s);
			//		}

			int[] sa = new int[n];
			boolean[] ls = new boolean[n];
			for (int i = n - 2; i >= 0; i--) {
				ls[i] = s[i] == s[i + 1] ? ls[i + 1] : s[i] < s[i + 1];
			}

			int[] sumL = new int[upper + 1];
			int[] sumS = new int[upper + 1];

			for (int i = 0; i < n; i++) {
				if (ls[i]) {
					sumL[s[i] + 1]++;
				} else {
					sumS[s[i]]++;
				}
			}

			for (int i = 0; i <= upper; i++) {
				sumS[i] += sumL[i];
				if (i < upper) sumL[i + 1] += sumS[i];
			}

			java.util.function.Consumer<int[]> induce = lms -> {
				java.util.Arrays.fill(sa, -1);
				int[] buf = new int[upper + 1];
				System.arraycopy(sumS, 0, buf, 0, upper + 1);
				for (int d : lms) {
					if (d == n) continue;
					sa[buf[s[d]]++] = d;
				}
				System.arraycopy(sumL, 0, buf, 0, upper + 1);
				sa[buf[s[n - 1]]++] = n - 1;
				for (int i = 0; i < n; i++) {
					int v = sa[i];
					if (v >= 1 && !ls[v - 1]) {
						sa[buf[s[v - 1]]++] = v - 1;
					}
				}
				System.arraycopy(sumL, 0, buf, 0, upper + 1);
				for (int i = n - 1; i >= 0; i--) {
					int v = sa[i];
					if (v >= 1 && ls[v - 1]) {
						sa[--buf[s[v - 1] + 1]] = v - 1;
					}
				}
			};

			int[] lmsMap = new int[n + 1];
			java.util.Arrays.fill(lmsMap, -1);
			int m = 0;
			for (int i = 1; i < n; i++) {
				if (!ls[i - 1] && ls[i]) {
					lmsMap[i] = m++;
				}
			}

			int[] lms = new int[m];
			{
				int p = 0;
				for (int i = 1; i < n; i++) {
					if (!ls[i - 1] && ls[i]) {
						lms[p++] = i;
					}
				}
			}

			induce.accept(lms);

			if (m > 0) {
				int[] sortedLms = new int[m];
				{
					int p = 0;
					for (int v : sa) {
						if (lmsMap[v] != -1) {
							sortedLms[p++] = v;
						}
					}
				}
				int[] recS = new int[m];
				int recUpper = 0;
				recS[lmsMap[sortedLms[0]]] = 0;
				for (int i = 1; i < m; i++) {
					int l = sortedLms[i - 1], r = sortedLms[i];
					int endL = (lmsMap[l] + 1 < m) ? lms[lmsMap[l] + 1] : n;
					int endR = (lmsMap[r] + 1 < m) ? lms[lmsMap[r] + 1] : n;
					boolean same = true;
					if (endL - l != endR - r) {
						same = false;
					} else {
						while (l < endL && s[l] == s[r]) {
							l++;
							r++;
						}
						if (l == n || s[l] != s[r]) same = false;
					}
					if (!same) {
						recUpper++;
					}
					recS[lmsMap[sortedLms[i]]] = recUpper;
				}

				int[] recSA = sais(recS, recUpper);

				for (int i = 0; i < m; i++) {
					sortedLms[i] = lms[recSA[i]];
				}
				induce.accept(sortedLms);
			}
			return sa;
		}

		public static int[] suffixArray(int[] s, int upper) {
			assert (0 <= upper);
			for (int d : s) {
				assert (0 <= d && d <= upper);
			}
			return sais(s, upper);
		}

		public static int[] suffixArray(int[] s)
		{
			int n = s.length;
			int[] vals = Arrays.copyOf(s, n);
			java.util.Arrays.sort(vals);
			int p = 1;
			for(int i = 1;i < n;i++){
				if(vals[i] != vals[i-1]){
					vals[p++] = vals[i];
				}
			}
			int[] s2 = new int[n];
			for(int i = 0;i < n;i++){
				s2[i] = java.util.Arrays.binarySearch(vals, 0, p, s[i]);
			}
			return sais(s2, p);
		}

		public static int[] suffixArray(char[] s) {
			int n = s.length;
			int[] s2 = new int[n];
			for (int i = 0; i < n; i++) {
				s2[i] = s[i];
			}
			return sais(s2, 255);
		}

		public static int[] suffixArray(java.lang.String s) {
			return suffixArray(s.toCharArray());
		}

		public static int[] lcpArray(int[] s, int[] sa) {
			int n = s.length;
			assert (n >= 1);
			int[] rnk = new int[n];
			for (int i = 0; i < n; i++) {
				rnk[sa[i]] = i;
			}
			int[] lcp = new int[n - 1];
			int h = 0;
			for (int i = 0; i < n; i++) {
				if (h > 0) h--;
				if (rnk[i] == 0) {
					continue;
				}
				int j = sa[rnk[i] - 1];
				for (; j + h < n && i + h < n; h++) {
					if (s[j + h] != s[i + h]) break;
				}
				lcp[rnk[i] - 1] = h;
			}
			return lcp;
		}

		public static int[] lcpArray(char[] s, int[] sa) {
			int n = s.length;
			int[] s2 = new int[n];
			for (int i = 0; i < n; i++) {
				s2[i] = s[i];
			}
			return lcpArray(s2, sa);
		}

		public static int[] lcpArray(java.lang.String s, int[] sa) {
			return lcpArray(s.toCharArray(), sa);
		}

		public static int[] zAlgorithm(int[] s) {
			int n = s.length;
			if (n == 0) return new int[0];
			int[] z = new int[n];
			for (int i = 1, j = 0; i < n; i++) {
				int k = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
				while (i + k < n && s[k] == s[i + k]) k++;
				z[i] = k;
				if (j + z[j] < i + z[i]) j = i;
			}
			z[0] = n;
			return z;
		}

		public static int[] zAlgorithm(char[] s) {
			int n = s.length;
			if (n == 0) return new int[0];
			int[] z = new int[n];
			for (int i = 1, j = 0; i < n; i++) {
				int k = j + z[j] <= i ? 0 : Math.min(j + z[j] - i, z[i - j]);
				while (i + k < n && s[k] == s[i + k]) k++;
				z[i] = k;
				if (j + z[j] < i + z[i]) j = i;
			}
			z[0] = n;
			return z;
		}

		public static int[] zAlgorithm(String s) {
			return zAlgorithm(s.toCharArray());
		}
	}


	public static int gcd(int a, int b) {
		while (b > 0) {
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}


	public static int[] Z(char[] str)
	{
		int n = str.length;
		int[] z = new int[n];
		if(n == 0)return z;
		z[0] = n;
		int l = 0, r = 0;
		for(int i = 1;i < n;i++){
			if(i > r){
				l = r = i;
				while(r < n && str[r-l] == str[r])r++;
				z[i] = r-l; r--;
			}else{
				if(z[i-l] < r-i+1){
					z[i] = z[i-l];
				}else{
					l = i;
					while(r < n && str[r-l] == str[r])r++;
					z[i] = r-l; r--;
				}
			}
		}

		return z;
	}


	void run() throws Exception
	{
//		int n = 500000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(n + " ");
//		sb.append("b");
//		for (int i = 0; i < n-1; i++) {
//			sb.append("ab".charAt(gen.nextInt(2)));
//		}
//		INPUT = sb.toString();


		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new FastWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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

	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}

	private long[] nal(int n)
	{
		long[] a = new long[n];
		for(int i = 0;i < n;i++)a[i] = nl();
		return a;
	}

	private char[][] nm(int n, int m) {
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}

	private int[][] nmi(int n, int m) {
		int[][] map = new int[n][];
		for(int i = 0;i < n;i++)map[i] = na(m);
		return map;
	}

	private int ni() { return (int)nl(); }

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

	public static class FastWriter
	{
		private static final int BUF_SIZE = 1<<13;
		private final byte[] buf = new byte[BUF_SIZE];
		private final OutputStream out;
		private int ptr = 0;

		private FastWriter(){out = null;}

		public FastWriter(OutputStream os)
		{
			this.out = os;
		}

		public FastWriter(String path)
		{
			try {
				this.out = new FileOutputStream(path);
			} catch (FileNotFoundException e) {
				throw new RuntimeException("FastWriter");
			}
		}

		public FastWriter write(byte b)
		{
			buf[ptr++] = b;
			if(ptr == BUF_SIZE)innerflush();
			return this;
		}

		public FastWriter write(char c)
		{
			return write((byte)c);
		}

		public FastWriter write(char[] s)
		{
			for(char c : s){
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			}
			return this;
		}

		public FastWriter write(String s)
		{
			s.chars().forEach(c -> {
				buf[ptr++] = (byte)c;
				if(ptr == BUF_SIZE)innerflush();
			});
			return this;
		}

		private static int countDigits(int l) {
			if (l >= 1000000000) return 10;
			if (l >= 100000000) return 9;
			if (l >= 10000000) return 8;
			if (l >= 1000000) return 7;
			if (l >= 100000) return 6;
			if (l >= 10000) return 5;
			if (l >= 1000) return 4;
			if (l >= 100) return 3;
			if (l >= 10) return 2;
			return 1;
		}

		public FastWriter write(int x)
		{
			if(x == Integer.MIN_VALUE){
				return write((long)x);
			}
			if(ptr + 12 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		private static int countDigits(long l) {
			if (l >= 1000000000000000000L) return 19;
			if (l >= 100000000000000000L) return 18;
			if (l >= 10000000000000000L) return 17;
			if (l >= 1000000000000000L) return 16;
			if (l >= 100000000000000L) return 15;
			if (l >= 10000000000000L) return 14;
			if (l >= 1000000000000L) return 13;
			if (l >= 100000000000L) return 12;
			if (l >= 10000000000L) return 11;
			if (l >= 1000000000L) return 10;
			if (l >= 100000000L) return 9;
			if (l >= 10000000L) return 8;
			if (l >= 1000000L) return 7;
			if (l >= 100000L) return 6;
			if (l >= 10000L) return 5;
			if (l >= 1000L) return 4;
			if (l >= 100L) return 3;
			if (l >= 10L) return 2;
			return 1;
		}

		public FastWriter write(long x)
		{
			if(x == Long.MIN_VALUE){
				return write("" + x);
			}
			if(ptr + 21 >= BUF_SIZE)innerflush();
			if(x < 0){
				write((byte)'-');
				x = -x;
			}
			int d = countDigits(x);
			for(int i = ptr + d - 1;i >= ptr;i--){
				buf[i] = (byte)('0'+x%10);
				x /= 10;
			}
			ptr += d;
			return this;
		}

		public FastWriter write(double x, int precision)
		{
			if(x < 0){
				write('-');
				x = -x;
			}
			x += Math.pow(10, -precision)/2;
			//		if(x < 0){ x = 0; }
			write((long)x).write(".");
			x -= (long)x;
			for(int i = 0;i < precision;i++){
				x *= 10;
				write((char)('0'+(int)x));
				x -= (int)x;
			}
			return this;
		}

		public FastWriter writeln(char c){
			return write(c).writeln();
		}

		public FastWriter writeln(int x){
			return write(x).writeln();
		}

		public FastWriter writeln(long x){
			return write(x).writeln();
		}

		public FastWriter writeln(double x, int precision){
			return write(x, precision).writeln();
		}

		public FastWriter write(int... xs)
		{
			boolean first = true;
			for(int x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter write(long... xs)
		{
			boolean first = true;
			for(long x : xs) {
				if (!first) write(' ');
				first = false;
				write(x);
			}
			return this;
		}

		public FastWriter writeln()
		{
			return write((byte)'\n');
		}

		public FastWriter writeln(int... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(long... xs)
		{
			return write(xs).writeln();
		}

		public FastWriter writeln(char[] line)
		{
			return write(line).writeln();
		}

		public FastWriter writeln(char[]... map)
		{
			for(char[] line : map)write(line).writeln();
			return this;
		}

		public FastWriter writeln(String s)
		{
			return write(s).writeln();
		}

		private void innerflush()
		{
			try {
				out.write(buf, 0, ptr);
				ptr = 0;
			} catch (IOException e) {
				throw new RuntimeException("innerflush");
			}
		}

		public void flush()
		{
			innerflush();
			try {
				out.flush();
			} catch (IOException e) {
				throw new RuntimeException("flush");
			}
		}

		public FastWriter print(byte b) { return write(b); }
		public FastWriter print(char c) { return write(c); }
		public FastWriter print(char[] s) { return write(s); }
		public FastWriter print(String s) { return write(s); }
		public FastWriter print(int x) { return write(x); }
		public FastWriter print(long x) { return write(x); }
		public FastWriter print(double x, int precision) { return write(x, precision); }
		public FastWriter println(char c){ return writeln(c); }
		public FastWriter println(int x){ return writeln(x); }
		public FastWriter println(long x){ return writeln(x); }
		public FastWriter println(double x, int precision){ return writeln(x, precision); }
		public FastWriter print(int... xs) { return write(xs); }
		public FastWriter print(long... xs) { return write(xs); }
		public FastWriter println(int... xs) { return writeln(xs); }
		public FastWriter println(long... xs) { return writeln(xs); }
		public FastWriter println(char[] line) { return writeln(line); }
		public FastWriter println(char[]... map) { return writeln(map); }
		public FastWriter println(String s) { return writeln(s); }
		public FastWriter println() { return writeln(); }
	}

	public void trnz(int... o)
	{
		for(int i = 0;i < o.length;i++)if(o[i] != 0)System.out.print(i+":"+o[i]+" ");
		System.out.println();
	}

	// print ids which are 1
	public void trt(long... o)
	{
		Queue<Integer> stands = new ArrayDeque<>();
		for(int i = 0;i < o.length;i++){
			for(long x = o[i];x != 0;x &= x-1)stands.add(i<<6|Long.numberOfTrailingZeros(x));
		}
		System.out.println(stands);
	}

	public void tf(boolean... r)
	{
		for(boolean x : r)System.out.print(x?'#':'.');
		System.out.println();
	}

	public void tf(boolean[]... b)
	{
		for(boolean[] r : b) {
			for(boolean x : r)System.out.print(x?'#':'.');
			System.out.println();
		}
		System.out.println();
	}

	public void tf(long[]... b)
	{
		if(INPUT.length() != 0) {
			for (long[] r : b) {
				for (long x : r) {
					for (int i = 0; i < 64; i++) {
						System.out.print(x << ~i < 0 ? '#' : '.');
					}
				}
				System.out.println();
			}
			System.out.println();
		}
	}

	public void tf(long... b)
	{
		if(INPUT.length() != 0) {
			for (long x : b) {
				for (int i = 0; i < 64; i++) {
					System.out.print(x << ~i < 0 ? '#' : '.');
				}
			}
			System.out.println();
		}
	}

	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}