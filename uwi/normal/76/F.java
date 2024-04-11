//package ausoi;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.TreeSet;

public class F3 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "7\r\n" +
//			"\r\n" +
//			"-976754 20479\r\n" +
//			"\r\n" +
//			"79929143 911181\r\n" +
//			"\r\n" +
//			"9598220 82517\r\n" +
//			"\r\n" +
//			"-51609349 810257\r\n" +
//			"\r\n" +
//			"67416551 266544\r\n" +
//			"\r\n" +
//			"-14170975 307690\r\n" +
//			"\r\n" +
//			"-15476178 491195\r\n" +
//			"\r\n" +
//			"352";
//	String INPUT = "3\r\n" +
//			"-1 1\r\n" +
//			"42 7\r\n" +
//			"40 8\r\n" +
//			"2";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] x = new int[n];
		int[] t = new int[n];
		final long[] a = new long[n];
		final long[] b = new long[n];
		for(int i = 0;i < n;i++){
			x[i] = ni();
			t[i] = ni();
		}
		int v = ni();
		TreeSet<Long> aset = new TreeSet<Long>();
		TreeSet<Long> bset = new TreeSet<Long>();
		HashMap<Long, Integer> bmap = new HashMap<Long, Integer>();
		for(int i = 0;i < n;i++){
			a[i] = t[i] * v - x[i];
			b[i] = t[i] * v + x[i];
			aset.add(a[i]);
			bset.add(b[i]);
		}
		int nb = bset.size();
		int pb = 0;
		for(long bb : bset){
			bmap.put(bb, pb++);
		}
		
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++){
			ord[i] = i;
		}
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer x, Integer y)
			{
				if(a[x] - a[y] != 0)return Long.signum(a[x] - a[y]);
				return Long.signum(b[x] - b[y]);
			}
		});
		
		int m2 = 0;
		{
			SegmentTreeRMQ st = new SegmentTreeRMQ(nb);
			int[] dp = new int[n];
			for(int i = 0;i < n;i++){
				int bb = bmap.get(b[ord[i]]);
				dp[i] = st.max(0, bb) + 1;
				st.update(bb, dp[i]);
	//			tr(st.st);
				m2 = Math.max(m2, dp[i]);
			}
		}
//		tr(dp);
		
		int m1 = 0;
		{
			SegmentTreeRMQ st = new SegmentTreeRMQ(nb);
			int[] dp = new int[n];
			for(int i = 0;i < n;i++){
				if(a[ord[i]] >= 0 && b[ord[i]] >= 0){
					int bb = bmap.get(b[ord[i]]);
					dp[i] = st.max(0, bb) + 1;
					st.update(bb, dp[i]);
					m1 = Math.max(m1, dp[i]);
				}
			}
		}
		
		out.println(m1 + " " + m2);
	}
	
	public class SegmentTreeRMQ {
		public int M, H, N;
		public int[] st;
		
		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(n-1)<<2;
			H = M>>>1;
			st = new int[M];
		}
		
		public SegmentTreeRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(N-1)<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			build();
		}
		
		public void build()
		{
			Arrays.fill(st, H+N, M, 0);
			for(int i = (M>>1)-1;i >= 1;i--){
				st[i] = Math.max(st[i*2], st[i*2+1]);
			}
		}
		
		public void update(int pos, int x)
		{
			pos+=H;
			st[pos] = x;
			for(int i = pos>>>1;i >= 1;i >>>= 1){
				st[i] = Math.max(st[2*i], st[2*i+1]);
			}
		}
		
		public int max(int f, int t)
		{
			return max(f, t, H);
		}
		
		public int max(int f, int t, int b)
		{
			if((f&(b-1))==0 && (t&(b-1))==b-1){
				return st[(H|f)/b];
			}
			
			if(((f^t)&b) != 0){
				int w = t&~(b-1);
				return Math.max(max(f, w-1, b), max(w, t, b));
			}else{
				return max(f, t, b>>1);
			}
		}
	}
		
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new F3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}