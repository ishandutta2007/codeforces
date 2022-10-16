import java.io.*;
import java.util.*;

public class B {
	
	int MAX = 250_000;
	
	List<Pair> removeKs(int[] a, int k) {
		List<Pair> stack = new ArrayList<>();
		for (int i = 0; i < a.length; i++) {
			int val = a[i % a.length];
			if (stack.size() == 0 || stack.get(stack.size() - 1).val != val) {
				stack.add(new Pair(val, 1));
			} else {
				Pair p = stack.remove(stack.size() - 1);
				Pair newP = new Pair(p.val, p.cnt + 1);
				if (newP.cnt < k) {
					stack.add(newP);
				}
			}
		}		
		return stack;
	}
	
	class Array {
		List<Pair> whole;
		List<Pair> pref, suf;
		long mid;
		
		public Array(List<Pair> whole) {
			this.whole = whole;
			mid = 0;
		}
		
		public Array(List<Pair> p, List<Pair> s, long mid) {
			this.pref = p;
			this.suf = s;
			this.mid = mid;
		}
	}
	
	long getSize(List<Pair> x) {
		return count(x);
	}
	
	Array combine(Array a, Array b) {
		if (a.whole == null && b.whole == null) {
			long mid1 = a.mid + b.mid + getInterSize(a.suf, b.pref);
			return new Array(a.pref, b.suf, mid1);
		} else if (a.whole != null && b.whole != null) {
			List<Pair> res = combine(a.whole, b.whole);
			if (res.size() < 2 * MAX) {
				return new Array(res);
			} else {
				long mid = 0;
				for (int i = MAX; i < res.size() - MAX; i++) {
					mid += res.get(i).cnt;
				}
				return new Array(res.subList(0, MAX), res.subList(res.size() - MAX, res.size()), mid);
			}
		} else {
			if (a.whole == null) {
				Array tmp = a;
				a = b;
				b = tmp;
			}
			long mid = b.mid;
			List<Pair> res = combine(a.whole, b.pref);
			for (int i = MAX; i < res.size(); i++) {
				mid += res.get(i).cnt;
			}
			return new Array(res.subList(0, MAX), b.suf, mid);
		}
	}
	
	private long getInterSize(List<Pair> pref, List<Pair> suf) {
		List<Pair> x = combine(pref, suf);
		return count(x);
	}

	private long count(List<Pair> x) {
		long result = 0;
		for (int i = 0; i < x.size(); i++) {
			result += x.get(i).cnt;
		}
		return result;
	}
	
	Map<Long, List<Pair>> memo = new HashMap<>();
	int k;
	
	private List<Pair> combine(List<Pair> whole, List<Pair> pref) {
		long hash = whole.hashCode();
		hash = (hash << 30) + pref.hashCode();
		if (memo.containsKey(hash)) {
			return memo.get(hash);
		}
		
		List<Pair> stack = new ArrayList<>(whole);
		for (Pair p : pref) {
			if (stack.size() == 0 || stack.get(stack.size() - 1).val != p.val) {
				stack.add(p);
			} else {
				Pair top = stack.remove(stack.size() - 1);
				int sz = p.cnt + top.cnt;
				if (sz >= k) {
					sz -= k;
				}
				if (sz > 0) {
					stack.add(new Pair(p.val, sz));
				}
			}
		}
		memo.put(hash, stack);
		return stack;
	}

	void solve() {
		int n = in.nextInt();
		k = in.nextInt();
		int m = in.nextInt();
		int[] a = in.nextIntArray(n);
		Array ar = new Array(removeKs(a, k));
		
		Array res = new Array(new ArrayList<>());
		while (m > 0) {
			if ((m & 1) == 1) {
				res = combine(res, ar);
			}
			ar = combine(ar, ar);
			m /= 2;
		}
		
		long result = 0;
		if (res.whole != null) {
			result = count(res.whole);
		} else {
			result = count(res.pref) + count(res.suf) + res.mid;
		}
		out.println(result);
	}
	
	class Pair {
		final int val, cnt;

		public Pair(int val, int cnt) {
			super();
			this.val = val;
			this.cnt = cnt;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + getOuterType().hashCode();
			result = prime * result + cnt;
			result = prime * result + val;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Pair other = (Pair) obj;
			if (!getOuterType().equals(other.getOuterType()))
				return false;
			if (cnt != other.cnt)
				return false;
			if (val != other.val)
				return false;
			return true;
		}

		private B getOuterType() {
			return B.this;
		}
		
		
		
	}
	
	FastScanner in;
	PrintWriter out;

	void run() {
		in = new FastScanner();
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	class FastScanner {
		BufferedReader br;
		StringTokenizer st;

		public FastScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		public FastScanner(String file) {
			try {
				br = new BufferedReader(new FileReader(file));
			} catch (FileNotFoundException e) {
				e.printStackTrace();
			}
		}

		public String nextToken() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		public boolean hasMoreTokens() {
			while (st == null || !st.hasMoreElements()) {
				try {
					String line = br.readLine();
					if (line == null) {
						return false;
					}
					st = new StringTokenizer(line);
				} catch (IOException e) {
					return false;
				}
			}
			return true;
		}

		public int nextInt() {
			return Integer.parseInt(nextToken());
		}

		public long nextLong() {
			return Long.parseLong(nextToken());
		}

		public double nextDouble() {
			return Double.parseDouble(nextToken());
		}

		public int[] nextIntArray(int length) {
			int[] array = new int[length];
			for (int i = 0; i < length; i++) {
				array[i] = nextInt();
			}
			return array;
		}
	}

	public static void main(String[] args) {
		new B().run();
	}
}