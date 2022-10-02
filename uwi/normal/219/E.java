//package round135;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		SegmentTreeRMQPos st = new SegmentTreeRMQPos(n);
		int[] ft = new int[n+1];
		st.update(n, n);
		int[] park = new int[1000001];
		int num = 0;
		int left = n+2, right = -1;
		for(int i = 0;i < m;i++){
			int com = ni();
			int id = ni();
			if(com == 1){
				int pos = -1;
				if(num == 0){
					pos = 0;
				}else{
					int maxd = 0;
					pos = 0;
					if(left > maxd){
						pos = 0;
						maxd = left;
					}
					if(st.st[1] / 2 > maxd){
						maxd = st.st[1] / 2;
						pos = st.pos[1];
					}
					if(n-1-right > maxd){
						maxd = n-1-right;
						pos = n-1;
					}
//					tr(st.st[1] / 2, maxd, pos);
				}
				int a = after(ft, pos, num);
				int b = before(ft, pos);
				st.update(pos, pos-b);
				st.update(a, a - pos);
				out.println(pos+1);
				addFenwick(ft, pos, 1);
				num++;
				left = Math.min(left, pos);
				right = Math.max(right, pos);
				park[id] = pos;
			}else{
				int pos = park[id];
				int a = after(ft, pos, num);
				int b = before(ft, pos);
				if(a >= n){
					right = b;
				}
				if(b == -1){
					left = a;
				}
				st.update(pos, 0);
				st.update(a, a-b);
				addFenwick(ft, pos, -1);
				num--;
			}
		}
	}
	
	public int before(int[] ft, int x)
	{
		int u = sumFenwick(ft, x-1);
		if(u == 0)return -1;
		return findGFenwick(ft, u-1)+1;
	}
	
	public int after(int[] ft, int x, int num)
	{
		int u = sumFenwick(ft, x);
		if(u == num)return ft.length-1;
		return findGFenwick(ft, u)+1;
	}
		
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int findGFenwick(int[] ft, int v)
	{
		int i = 0;
		int n = ft.length;
		for(int b = Integer.highestOneBit(n);b != 0 && i < n;b >>= 1){
			if(i + b < n){
				int t = i + b;
				if(v >= ft[t]){
					i = t;
					v -= ft[t];
				}
			}
		}
		return v != 0 ? -(i+1) : i-1;
	}
		
	public static class SegmentTreeRMQPos {
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
				pos[i] = 0;
			}
		}
		
		public void update(int p, int x)
		{
			st[H+p] = x;
			pos[H+p] = p-(x+1)/2;
			for(int i = (H+p)>>>1;i >= 1;i >>>= 1)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(st[i*2]/2 >= st[i*2+1]/2){
				st[i] = st[i*2];
				pos[i] = pos[i*2];
			}else{
				st[i] = st[i*2+1];
				pos[i] = pos[i*2+1];
			}
		}
		
//		
//		public int[] min(int f, int t) { return min(f, t, B); }
//		
//		public int[] min(int f, int t, int b)
//		{
//			if(f>>b<<b==f && t+1>>b<<b==t+1){
//				return new int[]{st[(H|f)>>b], pos[(H|f)>>b]};
//			}
//			
//			b--;
//			if((f^t)<<31-b<0){
//				int w = t>>b<<b;
//				int[] l = min(f, w-1, b);
//				int[] r = min(w, t, b);
//				return l[0] <= r[0] ? l : r;
//			}else{
//				return min(f, t, b);
//			}
//		}
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