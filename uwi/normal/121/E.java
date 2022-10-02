//package round91;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;

public class E4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	static int[] E;
	static int[] lmap;
	
	public static int[] generateLucky(int n)
	{
		int[] lucky = new int[50];
		lucky[0] = 4;
		lucky[1] = 7;
		int r = 2;
		for(int p = 0;p < r;p++){
			if((long)lucky[p]*10+4 <= n){
				lucky[r++] = lucky[p]*10+4;
			}
			if((long)lucky[p]*10+7 <= n){
				lucky[r++] = lucky[p]*10+7;
			}
		}
		return Arrays.copyOf(lucky, r);
	}

	void solve()
	{
		int[] lucky = generateLucky(10000);
		lmap = new int[10001];
		int next = lucky.length;
		int INF = 99999999;
		for(int i = 10000;i >= 0;i--){
			if(next-1 >= 0 && lucky[next-1] == i){
				next--;
			}
			lmap[i] = next == lucky.length ? INF : lucky[next] - i;
		}
		
		int n = ni(), m = ni();
		int[] D = new int[n];
		E = new int[n];
		for(int i = 0;i < n;i++){
			int a = ni();
			D[i] = lmap[a];
			E[i] = a + D[i];
		}
		
		SegmentTreeRMQRange st = new SegmentTreeRMQRange(D);
		
		for(int i = 0;i < m;i++){
			char o = nc();
			skip();
			if(o == 'c'){
				int l = ni()-1, r = ni()-1;
				long mp = st.minCount2(l, r);
				if(mp>>32 == 0){
					out.println(mp);
				}else{
					out.println(0);
				}
			}else if(o == 'a'){
				int l = ni()-1, r = ni()-1, d = ni();
				st.addRange(l, r, -d);
			}
		}
	}
	
	public class SegmentTreeRMQRange {
		public int M, H, N, B;
		public int[] st;
		public int[] plus;
		public int[] count;
		
		public SegmentTreeRMQRange(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			B = Integer.numberOfTrailingZeros(H);
			st = new int[M];
			count = new int[M];
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
				count[H+i] = 1;
			}
			plus = new int[H];
			build();
		}
		
		public void build()
		{
			Arrays.fill(st, H+N, M, Integer.MAX_VALUE);
			for(int i = H-1;i >= 1;i--){
				st[i] = Math.min(st[2*i], st[2*i+1]);
				if(st[2*i] < st[2*i+1]){
					count[i] = count[2*i];
				}else if(st[2*i] > st[2*i+1]){
					count[i] = count[2*i+1];
				}else{
					count[i] = count[2*i] + count[2*i+1];
				}
			}
		}
		
//		public void update(int ind, int x)
//		{
//			st[H+ind] = x;
//			for(int i = (H+ind)>>>1;i >= 1;i >>>= 1){
//				if(st[2*i] <= st[2*i+1]){
//					st[i] = st[2*i] + plus[i];
//					pos[i] = pos[2*i];
//					if(st[2*i] < st[2*i+1]){
//						count[i] = count[2*i];
//					}else{
//						count[i] = count[2*i] + count[2*i+1];
//					}
//				}else{
//					st[i] = st[2*i+1] + plus[i];
//					pos[i] = pos[2*i+1];
//					count[i] = count[2*i+1];
//				}
//			}
//		}
		
		public void add(int ind, int x, int carry)
		{
			st[H+ind] += x;
			if(carry + st[H+ind] < 0){
				int cur = E[ind]-(carry + st[H+ind]);
				st[H+ind] = lmap[cur] - carry;
				E[ind] = lmap[cur] + cur;
			}
			for(int i = (H+ind)>>>1;i >= 1;i >>>= 1){
				if(st[2*i] <= st[2*i+1]){
					st[i] = st[2*i] + plus[i];
					if(st[2*i] < st[2*i+1]){
						count[i] = count[2*i];
					}else{
						count[i] = count[2*i] + count[2*i+1];
					}
				}else{
					st[i] = st[2*i+1] + plus[i];
					count[i] = count[2*i+1];
				}
			}
		}
		
		public void dig(int f, int t, int b, int carry)
		{
//			tr(f, t, b, carry, st[(H|f)>>b], carry + st[(H|f)>>b]);
			if(b == 0){
				add(f, 0, carry);
			}else if(carry + st[(H|f)>>b] < 0){
				b--;
				int w = t>>b<<b;
				carry += plus[(H|f)>>b+1];
				dig(f, w-1, b, carry);
				dig(w, t, b, carry);
			}
		}
		
		public void addRange(int f, int t, int v){ addRange(f, t, v, B, 0); }
		
		public void addRange(int f, int t, int v, int b, int carry)
		{
			if(b == 0){
				add(f, v, carry);
//				update(f, st[H|f]+v);
			}else if(f>>b<<b==f && t+1>>b<<b==t+1){
				plus[(H|f)>>b] += v;
//				tr(f, t, b, v, carry, st[(H|f)>>b], v + carry + st[(H|f)>>b]);
				if(v + carry + st[(H|f)>>b] < 0){
					b--;
					int w = t>>b<<b;
					carry += plus[(H|f)>>b+1];
					dig(f, w-1, b, carry);
					dig(w, t, b, carry);
					b++;
				}else{
					for(int i = (H|f)>>b;i >= 1;i >>>= 1){
						if(st[2*i] <= st[2*i+1]){
							st[i] = st[2*i] + plus[i];
							if(st[2*i] < st[2*i+1]){
								count[i] = count[2*i];
							}else{
								count[i] = count[2*i] + count[2*i+1];
							}
						}else{
							st[i] = st[2*i+1] + plus[i];
							count[i] = count[2*i+1];
						}
					}
				}
			}else{
				b--;
				carry += plus[(H|f)>>b+1];
				if((f^t)<<31-b<0){
					int w = t>>b<<b;
					addRange(f, w-1, v, b, carry);
					addRange(w, t, v, b, carry);
				}else{
					addRange(f, t, v, b, carry);
				}
			}
		}
		
		public int[] minCount(int f, int t) { return minCount(f, t, B); }
		
		public int[] minCount(int f, int t, int b)
		{
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return new int[]{st[(H|f)>>b], count[(H|f)>>b]};
			}
			
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				int[] l = minCount(f, w-1, b);
				int[] r = minCount(w, t, b);
				int[] ret = l[0] <= r[0] ? l : r;
				if(l[0] == r[0]){
					ret[1] = l[1] + r[1];
				}
				ret[0] += plus[(H|f)>>b+1];
				return ret;
			}else{
				int[] ret = minCount(f, t, b);
				ret[0] += plus[(H|f)>>b+1];
				return ret;
			}
		}
		
		public long minCount2(int f, int t) { return minCount2(f, t, B, 0); }
		
		public long minCount2(int f, int t, int b, int carry)
		{
			if(carry + st[(H|f)>>b] > 0){
				return 99999999L<<32;
			}
			if(f>>b<<b==f && t+1>>b<<b==t+1){
				return (long)st[(H|f)>>b]<<32|count[(H|f)>>b];
			}
			
			carry += plus[(H|f)>>b];
			b--;
			if((f^t)<<31-b<0){
				int w = t>>b<<b;
				long l = minCount2(f, w-1, b, carry);
				long r = minCount2(w, t, b, carry);
				long ret = l>>32 <= r>>32 ? l : r;
				if(l>>32 == r>>32)ret += (int)r;
				ret += (long)plus[(H|f)>>b+1]<<32;
				return ret;
			}else{
				long ret = minCount2(f, t, b, carry);
				ret += (long)plus[(H|f)>>b+1]<<32;
				return ret;
			}
		}
	}
	
	char nc()
	{
		try {
			int b;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return 0;
			return (char)b;
		} catch (IOException e) {
		}
		return 0;
	}
	
	void skip()
	{
		try {
			int b;
			while((b = is.read()) != -1 && !(b == ' ' || b == '\r' || b == '\n'));
		} catch (IOException e) {
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
		new E4().run();
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
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}