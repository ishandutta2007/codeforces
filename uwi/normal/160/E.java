//package round111;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "4 3\r\n" + 
			"1 10 10\r\n" + 
			"5 6 2\r\n" + 
			"6 7 3\r\n" + 
			"5 7 4\r\n" + 
			"5 7 1\r\n" + 
			"1 2 1\r\n" + 
			"1 10 11";
//	String INPUT = "1 5\r\n" + 
//			"1 9 8\r\n" + 
//			"\r\n" + 
//			"3 9 9\r\n" + 
//			"1 9 1\r\n" + 
//			"2 6 3\r\n" + 
//			"1 9 3\r\n" + 
//			"2 8 10 \r\n" + 
//			"";
	
	void solve()
	{
		int n = ni(), m = ni();
		int[][] ev = new int[n+m][];
		for(int i = 0;i < n;i++){
			int s = ni(), f = ni(), t = ni();
			ev[i] = new int[]{s, f, t, i};
		}
		for(int i = 0;i < m;i++){
			int l = ni(), r = ni(), b = ni();
			ev[n+i] = new int[]{l, r, b, n+i};
		}
		
		int[][] sh = new int[m][];
		for(int i = 0;i < m;i++){
			sh[i] = new int[]{ev[n+i][1], i};
		}
		Arrays.sort(sh, new Comparator<int[]>(){
			public int compare(int[] a, int[] b){
				return a[0] - b[0];
			}
		});
		for(int i = 0;i < m;i++){
			ev[n+sh[i][1]][1] = i;
		}
		int[] ish = new int[m];
		for(int i = 0;i < m;i++){
			ish[i] = sh[i][0] * 2;
		}
		
		// 
		Arrays.sort(ev, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[2] - b[2] != 0)return a[2] - b[2];
				return -(a[3] - b[3]);
			}
		});
//		tr(sh);
		
		// 
		int[] ret = new int[m];
		Arrays.fill(ret, -1);
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(m);
		int[] map = new int[m];
		for(int i = 0;i < n+m;i++){
			if(ev[i][3] < n){
				// bus
				while(true){
					int start = -Arrays.binarySearch(ish, ev[i][0]*2-1)-1;
					int end = -Arrays.binarySearch(ish, ev[i][1]*2+1)-2;
					
					int[] mx = st.max(start, end);
//					tr(ev[i][0], ev[i][1], mx, start, end);
					if(mx[0] == 0)break;
					if(mx[0]-1 >= ev[i][0]){
						st.update(mx[1], 0);
						ret[map[mx[1]]] = ev[i][3]+1;
					}else{
						break;
					}
				}
			}else{
				// cus
//				tr(ev[i][1], ev[i][0]+1);
				st.update(ev[i][1], ev[i][0]+1);
				map[ev[i][1]] = ev[i][3]-n;
//				tr(st.st);
//				tr(st.pos);
			}
		}
		for(int i = 0;i < m;i++){
			if(i > 0)out.print(" ");
			out.print(ret[i]);
		}
		out.println();
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
			for(int i = H-1;i >= 1;i--){
				pos[i] = pos[2*i];
			}
		}
		
		public void update(int p, int x)
		{
			st[H+p] = x;
			for(int i = (H+p)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[i*2] >= st[i*2+1]){
				st[i] = st[i*2];
				pos[i] = pos[i*2];
			}else{
				st[i] = st[i*2+1];
				pos[i] = pos[i*2+1];
			}
		}
		
		public int[] max(int f, int t) { return f > t ? new int[2] : max(f, t, B); }
		
		public int[] max(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new int[]{st[(H|f)>>b], pos[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int[] l = max(f, w-1, b);
				int[] r = max(w, t, b);
				return l[0] >= r[0] ? l : r;
			}else{
				return max(f, t, b);
			}
		}
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
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
		new E3().run();
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