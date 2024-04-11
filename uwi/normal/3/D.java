//package round3;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String x = in.next();
		char[] str = x.toCharArray();
		int n = str.length;
		
		int[] a = new int[n];
		StringBuilder sb = new StringBuilder(x);
		Arrays.fill(a, 9999999);
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(a);
		int now = 0;
		long cost = 0;
		for(int i = 0;i < n;i++) {
			if(str[i] == '?') {
				int l = ni();
				int r = ni();
				cost += r;
				now--;
				st.update(i, l-r);
				sb.replace(i, i+1, ")");
			}else if(str[i] == '('){
				now++;
			}else{
				now--;
			}
			if(now < 0){
				int[] m = st.min(0, i);
				if(m[0] == 9999999){
					out.println(-1);
					return;
				}
				cost += m[0];
				st.update(m[1], 9999999);
				now += 2;
				sb.replace(m[1], m[1]+1, "(");
			}
		}
		if(now == 0){
			out.println(cost);
			out.println(sb);
		}else{
			out.println(-1);
		}
	}
	
	public class SegmentTreeRMQPos {
		public int M, H, N;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(n-1)<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < M;i++){
				int h = Integer.highestOneBit(i);
				pos[i] = (i ^ h) * (H / h);
			}
		}
		
		public SegmentTreeRMQPos(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(N-1)<<2;
			H = M>>>1;
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				pos[H+i] = i;
			}
			build();
		}
		
		public void build()
		{
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = (M>>1)-1;i >= 1;i--){
				if(st[i*2] < st[i*2+1]){
					st[i] = st[i*2];
					pos[i] = pos[i*2];
				}else{
					st[i] = st[i*2+1];
					pos[i] = pos[i*2+1];
				}
			}
		}
		
		public void update(int p, int x)
		{
			st[H+p] = x;
			for(int i = (H+p)>>>1;i >= 1;i >>>= 1){
				if(st[i*2] < st[i*2+1]){
					st[i] = st[i*2];
					pos[i] = pos[i*2];
				}else{
					st[i] = st[i*2+1];
					pos[i] = pos[i*2+1];
				}
			}
		}
		
		public int[] min(int f, int t)
		{
			return min(f, t, H);
		}
		
		public int[] min(int f, int t, int b)
		{
			if((f&(b-1))==0 && (t&(b-1))==b-1){
				return new int[]{st[(H|f)/b], pos[(H|f)/b]};
			}
			
			if(((f^t)&b) != 0){
				int w = t&~(b-1);
				int[] l = min(f, w-1, b);
				int[] r = min(w, t, b);
				return l[0] <= r[0] ? l : r;
			}else{
				return min(f, t, b>>1);
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
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}