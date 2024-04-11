//package manthan2017;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";

	void solve()
	{
		int Z = 100005;
		JiDriverSegmentTree stu = new JiDriverSegmentTree(Z);
		JiDriverSegmentTree std = new JiDriverSegmentTree(Z);
		LST su = new LST(Z);
		LST sd = new LST(Z);
		su.setRange(Z-2);
		sd.setRange(Z-2);
		for(int Q = ni();Q > 0;Q--){
			int type = ni();
			if(type == 1){
				int l = ni(), r = ni(), k = ni();
				if(k > 0){
					stu.minimize(l, r, k);
					while(true){
						int ind = su.next(l);
						if(ind == -1 || ind >= r){
							break;
						}
						su.unset(ind);
						if(!sd.get(ind)){
							stu.stand(ind);
							std.stand(ind);
						}
					}
				}else{
					std.minimize(l, r, -k);
					while(true){
						int ind = sd.next(l);
						if(ind == -1 || ind >= r){
							break;
						}
						sd.unset(ind);
						if(!su.get(ind)){
							stu.stand(ind);
							std.stand(ind);
						}
					}
				}
			}else{
				int l = ni(), r = ni();
				out.println(stu.sum(l, r) + std.sum(l, r));
			}
		}
	}

	public static class LST {
		public long[][] set;
		public int n;
//	public int size;

		public LST(int n) {
			this.n = n;
			int d = 1;
			for(int m = n;m > 1;m>>>=6, d++);

			set = new long[d][];
			for(int i = 0, m = n>>>6;i < d;i++, m>>>=6){
				set[i] = new long[m+1];
			}
//		size = 0;
		}

		// [0,r)
		public LST setRange(int r)
		{
			for(int i = 0;i < set.length;i++, r=r+63>>>6){
				for(int j = 0;j < r>>>6;j++){
					set[i][j] = -1L;
				}
				if((r&63) != 0)set[i][r>>>6] |= (1L<<r)-1;
			}
			return this;
		}

		// [0,r)
		public LST unsetRange(int r)
		{
			if(r >= 0){
				for(int i = 0;i < set.length;i++, r=r+63>>>6){
					for(int j = 0;j < r+63>>>6;j++){
						set[i][j] = 0;
					}
					if((r&63) != 0)set[i][r>>>6] &= ~((1L<<r)-1);
				}
			}
			return this;
		}

		public LST set(int pos)
		{
			if(pos >= 0 && pos < n){
//			if(!get(pos))size++;
				for(int i = 0;i < set.length;i++, pos>>>=6){
					set[i][pos>>>6] |= 1L<<pos;
				}
			}
			return this;
		}

		public LST unset(int pos)
		{
			if(pos >= 0 && pos < n){
//			if(get(pos))size--;
				for(int i = 0;i < set.length && (i == 0 || set[i-1][pos] == 0L);i++, pos>>>=6){
					set[i][pos>>>6] &= ~(1L<<pos);
				}
			}
			return this;
		}

		public boolean get(int pos)
		{
			return pos >= 0 && pos < n && set[0][pos>>>6]<<~pos<0;
		}

		public int prev(int pos)
		{
			for(int i = 0;i < set.length && pos >= 0;i++, pos>>>=6, pos--){
				int pre = prev(set[i][pos>>>6], pos&63);
				if(pre != -1){
					pos = pos>>>6<<6|pre;
					while(i > 0)pos = pos<<6|63-Long.numberOfLeadingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}

		public int next(int pos)
		{
			for(int i = 0;i < set.length && pos>>>6 < set[i].length;i++, pos>>>=6, pos++){
				int nex = next(set[i][pos>>>6], pos&63);
				if(nex != -1){
					pos = pos>>>6<<6|nex;
					while(i > 0)pos = pos<<6|Long.numberOfTrailingZeros(set[--i][pos]);
					return pos;
				}
			}
			return -1;
		}

		private static int prev(long set, int n)
		{
			long h = Long.highestOneBit(set<<~n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)-(63-n);
		}

		private static int next(long set, int n)
		{
			long h = Long.lowestOneBit(set>>>n);
			if(h == 0L)return -1;
			return Long.numberOfTrailingZeros(h)+n;
		}

		@Override
		public String toString()
		{
			List<Integer> list = new ArrayList<Integer>();
			for(int pos = next(0);pos != -1;pos = next(pos+1)){
				list.add(pos);
			}
			return list.toString();
		}
	}

	public static class JiDriverSegmentTree {
		public int M, H, N;
		public long[] maxs;
		public long[] vmaxs;
		public long[] sums;
		public boolean[] stands;
		public long[] clouds;
		public int[] unfixed; // number of unfixed elements in node
		public int[] vunfixed; // number of unfixed elements in node
		private long I = Long.MIN_VALUE;
		private long BI = Long.MAX_VALUE;

		public JiDriverSegmentTree(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;

			maxs = new long[M];
			Arrays.fill(maxs, BI);
			vmaxs = new long[M];
			Arrays.fill(vmaxs, BI);
			sums = new long[M];
			Arrays.fill(maxs, BI);
			clouds = new long[H];
			Arrays.fill(clouds, I);
			unfixed = new int[M];
			vunfixed = new int[M];
			stands = new boolean[N];
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		public JiDriverSegmentTree(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;

			maxs = new long[M];
			Arrays.fill(maxs, BI);
			vmaxs = new long[M];
			Arrays.fill(vmaxs, BI);
			sums = new long[M];
			Arrays.fill(maxs, BI);
			clouds = new long[H];
			Arrays.fill(clouds, I);
			unfixed = new int[M];
			vunfixed = new int[M];
			stands = new boolean[N];
			for(int i = 0;i < N;i++){
				vmaxs[H+i] = a[i];
				reflect(H+i);
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}

		private void propagate(int i)
		{
			if(clouds[i] == I || vunfixed[2*i] + vunfixed[2*i+1] == 0){
				maxs[i] = Math.max(maxs[2*i], maxs[2*i+1]);
				vmaxs[i] = Math.max(vmaxs[2*i], vmaxs[2*i+1]);
				sums[i] = sums[2*i] + sums[2*i+1];
				unfixed[i] = unfixed[2*i] + unfixed[2*i+1];
				vunfixed[i] = vunfixed[2*i] + vunfixed[2*i+1];
			}else{
				vmaxs[i] = maxs[i] = clouds[i];
				sums[i] = sums[2*i] + sums[2*i+1] + (unfixed[2*i] + unfixed[2*i+1]) * clouds[i];
				vunfixed[i] = unfixed[i] = 0;
			}
		}

		private void fix(int cur, long v)
		{
			if(v >= vmaxs[cur])return;
			if(cur < H){
				if(clouds[cur] >= v)clouds[cur] = I;
				fix(2*cur, v);
				fix(2*cur+1, v);
				propagate(cur);
			}else{
				vmaxs[cur] = I;
				reflect(cur);
			}
		}

		public void stand(int pos)
		{
			stands[pos] = true;
			reflect(H+pos);
			for(int i = H+pos>>>1;i > 0;i>>=1)propagate(i);
		}

		private void reflect(int i)
		{
			assert i >= H;
			if(stands[i-H]){
				if(vmaxs[i] == I){
					maxs[i] = I;
					sums[i] = 0;
					vunfixed[i] = unfixed[i] = 1;
				}else{
					maxs[i] = sums[i] = vmaxs[i];
					vunfixed[i] = unfixed[i] = 0;
				}
			}else{
				maxs[i] = I;
				sums[i] = 0;
				vunfixed[i] = 1;
				unfixed[i] = 0;
			}
		}

		public void minimize(int l, int r, long v){ minimize(l, r, v, 0, H, 1); }

		private void minimize(int l, int r, long v, int cl, int cr, int cur)
		{
//			System.err.println(l + " " + r + " " + cl + " " + cr + " " + v + " " + vmaxs[cur] + " " + (cur < H ? clouds[cur] : ""));
			if(v >= vmaxs[cur])return;
			if(l <= cl && cr <= r){
				if(cr == cl+1){
					vmaxs[cur] = v;
					reflect(cur);
				}else{
					fix(2*cur, v);
					fix(2*cur+1, v);
					clouds[cur] = v;
					propagate(cur);
				}
			}else{
				int mid = cl+cr>>>1;
				fall(cur);
				if(cl < r && l < mid){
					minimize(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					minimize(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}

		public void fall(int i)
		{
			if(clouds[i] == I)return;
			if(2*i < H){
				for(int j = 2*i;j < 2*i+2;j++){
					if(clouds[j] == I || clouds[j] >= clouds[i]){
						clouds[j] = clouds[i];
						propagate(j);
					}
				}
			}else{
				for(int j = 2*i;j < 2*i+2;j++){
					if(vmaxs[j] == I || vmaxs[j] >= clouds[i]){
						vmaxs[j] = clouds[i];
						reflect(j);
					}
				}
			}
			clouds[i] = I;
		}

		public long sum(int l, int r){
			gsum = 0;
			sum(l, r, 0, H, 1);
			return gsum;
		}

		long gsum = 0;

		// unfixed
		private int sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				gsum += sums[cur];
				return unfixed[cur];
			}else{
				int mid = cl+cr>>>1;
				int nunfixed = 0;
				if(cl < r && l < mid){
					nunfixed += sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					nunfixed += sum(l, r, mid, cr, 2*cur+1);
				}
				if(clouds[cur] != I){
					gsum += clouds[cur] * nunfixed;
					return 0;
				}else{
					return nunfixed;
				}
			}
		}

		public long max(int l, int r){
			gmax = I;
			max(l, r, 0, H, 1);
			return gmax;
		}

		private long gmax;

		private int max(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				gmax = Math.max(gmax, maxs[cur]);
				return unfixed[cur];
			}else{
				int mid = cl+cr>>>1;
				int nunfixed = 0;
				if(cl < r && l < mid){
					nunfixed += max(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					nunfixed += max(l, r, mid, cr, 2*cur+1);
				}
				if(nunfixed > 0 && clouds[cur] != I){
					gmax = Math.max(gmax, clouds[cur]);
					nunfixed = 0;
				}
				return nunfixed;
			}
		}

//	public long[] toArray() { return toArray(1, 0, H, new long[H]); }
//
//	private long[] toArray(int cur, int l, int r, long[] ret)
//	{
//		if(r-l == 1){
//			ret[cur-H] = st[cur];
//		}else if(cover[cur] != I){
//			Arrays.fill(ret, l, r, cover[cur]);
//		}else{
//			toArray(2*cur, l, l+r>>>1, ret);
//			toArray(2*cur+1, l+r>>>1, r, ret);
//		}
//		return ret;
//	}

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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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