//package round75;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeSet;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		
		TreeSet<Integer> set = new TreeSet<Integer>();
		for(int i = 0;i < n;i++){
			set.add(a[i]);
		}
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		int p = 0;
		for(int u : set){
			map.put(u, p++);
		}
		
		SegmentTreeRMQ st = new SegmentTreeRMQ(p);
		int[] dis = new int[n];
		for(int i = n-1;i >= 0;i--){
			int c = map.get(a[i]);
			int m = c == 0 ? 0 : st.min(0, c-1);
			if(m == 0){
				dis[i] = -1;
			}else{
				dis[i] = -m-i-1;
			}
			if(st.st[st.H+c] == 0){
				st.update(c, -i);
			}
		}
		
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			sb.append(" ");
			sb.append(dis[i]);
		}
		out.println(sb.substring(1));
	}
	
	public class SegmentTreeRMQ {
		public int M, H, N;
		public int[] st;
		
		public SegmentTreeRMQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n, 1))<<2;
			H = M>>>1;
			st = new int[M];
		}
		
		public SegmentTreeRMQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N, 1))<<2;
			H = M>>>1;
			st = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			build();
		}
		
		public void build()
		{
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = (M>>1)-1;i >= 1;i--){
				st[i] = Math.min(st[i*2], st[i*2+1]);
			}
		}
		
		public void update(int pos, int x)
		{
			st[H+pos] = x;
			for(int i = (H+pos)>>>1;i >= 1;i >>>= 1){
				st[i] = Math.min(st[2*i], st[2*i+1]);
			}
		}
		
		public int min(int f, int t)
		{
			return min(f, t, H);
		}
		
		public int min(int f, int t, int b)
		{
			if((f&(b-1))==0 && (t&(b-1))==b-1){
				return st[(H|f)/b];
			}
			
			if(((f^t)&b) != 0){
				int w = t&~(b-1);
				return Math.min(min(f, w-1, b), min(w, t, b));
			}else{
				return min(f, t, b>>1);
			}
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}