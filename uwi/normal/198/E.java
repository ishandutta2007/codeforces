//package round125;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		long x = ni(), y = ni();
		int p = ni(), r = ni();
		int n = ni();
		long[][] gr = new long[n][];
		for(int i = 0;i < n;i++){
			long xx = ni(), yy = ni();
			gr[i] = new long[]{
					ni(), (xx-x)*(xx-x)+(yy-y)*(yy-y), ni(), ni()
			};
			// m R p r
		}
		Arrays.sort(gr, new Comparator<long[]>() {
			public int compare(long[] a, long[] b) {
				return a[1] < b[1] ? -1 : 1;
			}
		});
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(gr);
		long[] rs = new long[n];
		for(int i = 0;i < n;i++)rs[i] = gr[i][1];
		
		int I = Integer.MAX_VALUE / 2;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{p, r});
		int ct = 0;
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int P = cur[0];
			long R2 = (long)cur[1] * cur[1];
			int ind = Arrays.binarySearch(rs, R2);
			if(ind < 0)ind = -ind-2;
			if(ind < 0)continue;
			while(true){
				int[] m = st.min(0, ind);
				if(m[0] > P)break;
				st.update(m[1], I);
				q.add(new int[]{(int)gr[m[1]][2], (int)gr[m[1]][3]});
				ct++;
			}
		}
		out.println(ct);
	}
	
	public class SegmentTreeRMQPos {
		public int M, H, N, B;
		public int[] st;
		public int[] pos;
		
		public SegmentTreeRMQPos(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			pos = new int[M];
			for(int i = M-1;i >= H;i--)pos[i] = i-H;
			for(int i = H-1;i >= 0;i--){
				pos[i] = pos[2*i];
			}
		}
		
		public SegmentTreeRMQPos(long[][] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			pos = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = (int)a[i][0];
				pos[H+i] = i;
			}
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = (M>>1)-1;i >= 1;i--)propagate(i);
		}
		
		public void update(int p, int x)
		{
			st[H+p] = x;
			for(int i = (H+p)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[i*2] <= st[i*2+1]){
				st[i] = st[i*2];
				pos[i] = pos[i*2];
			}else{
				st[i] = st[i*2+1];
				pos[i] = pos[i*2+1];
			}
		}
		
		public int[] min(int f, int t) { return min(f, t, B); }
		
		public int[] min(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new int[]{st[(H|f)>>b], pos[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int[] l = min(f, w-1, b);
				int[] r = min(w, t, b);
				return l[0] <= r[0] ? l : r;
			}else{
				return min(f, t, b);
			}
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
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}