//package educational.round23;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int Q = ni();
		long[][] qs = new long[Q][];
		for(int i = 0;i < Q;i++){
			qs[i] = new long[]{ni(), nl(), nl()+1};
		}
		long[] xs = new long[2*Q+1];
		xs[2*Q] = 1;
		for(int i = 0;i < Q;i++){
			xs[2*i] = qs[i][1];
			xs[2*i+1] = qs[i][2];
		}
		xs = shuffle(xs, new Random());
		Arrays.sort(xs);
		xs = uniq(xs);
		
		SegmentTreeRXQSFC st = new SegmentTreeRXQSFC(xs.length+3);
		for(long[] q : qs){
			int l = Arrays.binarySearch(xs, q[1]);
			int r = Arrays.binarySearch(xs, q[2]);
			if(q[0] == 1){
				st.set(l, r, true);
			}else if(q[0] == 2){
				st.set(l, r, false);
			}else{
				st.flip(l, r);
			}
			int low = 0, high = xs.length+1;
			while(high - low > 1){
				int h = high+low>>1;
				if(st.count(0, h) == h){
					low = h;
				}else{
					high = h;
				}
			}
			out.println(xs[low]);
		}
	}
	
	public static class SegmentTreeRXQSFC {
		public int M, H, N;
		public boolean[] fix;
		public boolean[] flip; // if fix is false, flip cloud. if true, overwrite cloud.
		public int[] ct;
		
		public SegmentTreeRXQSFC(int n)
		{
			N = n;
			H = Integer.highestOneBit(Math.max(n,1))<<1;
			M = H<<1;
			fix = new boolean[H];
			flip = new boolean[H];
			ct = new int[M];
		}
		
		public SegmentTreeRXQSFC(int[] a)
		{
			N = a.length;
			H = Integer.highestOneBit(Math.max(N,1))<<1;
			M = H<<1;
			fix = new boolean[H];
			flip = new boolean[H];
			ct = new int[M];
			for(int v : a)if(v < 0 || v > 1)throw new RuntimeException();
			System.arraycopy(a, 0, ct, H, N);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		public SegmentTreeRXQSFC(boolean[] a)
		{
			N = a.length;
			H = Integer.highestOneBit(Math.max(N,1))<<1;
			M = H<<1;
			fix = new boolean[H];
			flip = new boolean[H];
			ct = new int[M];
			for(int i = 0;i < N;i++){
				ct[i] = a[i] ? 1 : 0;
			}
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int i)
		{
			if(fix[i]){
				ct[i] = 0;
			}else{
				ct[i] = ct[2*i] + ct[2*i+1];
			}
			if(flip[i]){
				ct[i] = H/Integer.highestOneBit(i) - ct[i];
			}
		}
		
		public void set(int l, int r, boolean v){ set(l, r, v, 0, H, 1); }
		
		private void set(int l, int r, boolean v, int cl, int cr, int cur)
		{
			if(cur >= H){
				ct[cur] = v?1:0;
			}else if(l <= cl && cr <= r){
				fix[cur] = true;
				flip[cur] = v;
				propagate(cur);
			}else{
				boolean bp = false;
				if(fix[cur]){
					if(2*cur >= H){
						ct[2*cur] = ct[2*cur+1] = flip[cur]?1:0;
					}else{
						fix[2*cur] = fix[2*cur+1] = true;
						flip[2*cur] = flip[2*cur+1] = flip[cur];
						bp = true;
					}
					fix[cur] = flip[cur] = false;
				}else if(flip[cur]){
					if(2*cur >= H){
						ct[2*cur] ^= 1;
						ct[2*cur+1] ^= 1;
					}else{
						flip[2*cur] ^= true;
						flip[2*cur+1] ^= true;
						bp = true;
					}
					flip[cur] = false;
				}
			
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					set(l, r, v, cl, mid, 2*cur);
				}else if(bp){
					propagate(2*cur);
				}
				if(mid < r && l < cr){
					set(l, r, v, mid, cr, 2*cur+1);
				}else if(bp){
					propagate(2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public void flip(int l, int r){ flip(l, r, 0, H, 1); }
		
		private void flip(int l, int r, int cl, int cr, int cur)
		{
			if(cur >= H){
				ct[cur] ^= 1;
			}else if(l <= cl && cr <= r){
				flip[cur] ^= true;
				propagate(cur);
			}else{
				boolean bp = false;
				if(fix[cur]){
					if(2*cur >= H){
						ct[2*cur] = ct[2*cur+1] = flip[cur]?1:0;
					}else{
						fix[2*cur] = fix[2*cur+1] = true;
						flip[2*cur] = flip[2*cur+1] = flip[cur];
						bp = true;
					}
					fix[cur] = flip[cur] = false;
				}else if(flip[cur]){
					if(2*cur >= H){
						ct[2*cur] ^= 1;
						ct[2*cur+1] ^= 1;
					}else{
						flip[2*cur] ^= true;
						flip[2*cur+1] ^= true;
						bp = true;
					}
					flip[cur] = false;
				}
			
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					flip(l, r, cl, mid, 2*cur);
				}else if(bp){
					propagate(2*cur);
				}
				if(mid < r && l < cr){
					flip(l, r, mid, cr, 2*cur+1);
				}else if(bp){
					propagate(2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int count(int l, int r) { return count(l, r, 0, H, 1); }
		
		private int count(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return ct[cur];
			}else{
				int len = Math.min(cr, r) - Math.max(cl, l);
				if(fix[cur]){
					return flip[cur] ? len : 0;
				}
			
				int mid = cl+cr>>>1;
				int ret = 0;
				if(cl < r && l < mid){
					ret += count(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					ret += count(l, r, mid, cr, 2*cur+1);
				}
				return flip[cur] ? len-ret : ret;
			}
		}
		
		public String toString()
		{
			StringBuilder sb = new StringBuilder();
			sb.append("[fix]\n");
			for(int i = 1;1<<i <= H;i++){
				for(int j = 1<<i-1;j < 1<<i;j++){
					sb.append(fix[j]?'T':'F');
				}
				sb.append("\n");
			}
			sb.append("[flip]\n");
			for(int i = 1;1<<i <= H;i++){
				for(int j = 1<<i-1;j < 1<<i;j++){
					sb.append(flip[j]?'T':'F');
				}
				sb.append("\n");
			}
			sb.append("[count]\n");
			for(int i = 1;1<<i <= M;i++){
				sb.append(Arrays.toString(Arrays.copyOfRange(ct, 1<<i-1, 1<<i)));
				sb.append("\n");
			}
			return sb.toString();
		}
	}

	
	public static long[] uniq(long[] a)
	{
		int n = a.length;
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || a[i] != a[i-1])a[p++] = a[i];
		}
		return Arrays.copyOf(a, p);
	}

	
	public static long[] shuffle(long[] a, Random gen){ for(int i = 0, n = a.length;i < n;i++){ int ind = gen.nextInt(n-i)+i; long d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
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