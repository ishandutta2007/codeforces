//package round448;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni();
		int[] a = na(n);
		SegmentTreeRSQ st = new SegmentTreeRSQ(a);
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int l1 = ni()-1, r1 = ni()-1;
				int l2 = ni()-1, r2 = ni()-1;
				double s1 = st.sum(l1, r1+1);
				double s2 = st.sum(l2, r2+1);
				// a0*(n-1)/n + 1/n*(sum b)/m
				int len1 = r1-l1+1;
				int len2 = r2-l2+1;
				st.mul(l1, r1+1, (double)(len1-1)/len1);
				st.add(l1, r1+1, s2/len1/len2);
				st.mul(l2, r2+1, (double)(len2-1)/len2);
				st.add(l2, r2+1, s1/len1/len2);
			}else{
				int l = ni()-1, r = ni()-1;
				out.printf("%.14f\n", st.sum(l, r+1));
			}
		}
	}
	
	public static class SegmentTreeRSQ {
		public int M, H, N;
		public double[] st;
		public double[] plus;
		public double[] muls;
		
		public SegmentTreeRSQ(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new double[M];
			plus = new double[H];
		}
		
		public SegmentTreeRSQ(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new double[M];
			plus = new double[H];
			muls = new double[H];
			Arrays.fill(muls, 1.);
			for(int i = 0;i < N;i++){
				st[H+i] = a[i];
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i)
		{
			int count = H/Integer.highestOneBit(i);
			st[i] = (st[2*i]+st[2*i+1])*muls[i]+plus[i]*count;
		}
		
		void fall(int i)
		{
			if(2*i >= H){
				st[2*i] = st[2*i] * muls[i] + plus[i];
				st[2*i+1] = st[2*i+1] * muls[i] + plus[i];
			}else{
				for(int j = 2*i;j < 2*i+2;j++){
					muls[j] *= muls[i];
					plus[j] = plus[j] * muls[i] + plus[i];
					propagate(j);
				}
			}
			muls[i] = 1; plus[i] = 0;
		}
		
		public void add(int l, int r, double v) { if(l < r)add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, double v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v;
			}else if(l <= cl && cr <= r){
				plus[cur] += v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				fall(cur);
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public void mul(int l, int r, double v) { if(l < r)mul(l, r, v, 0, H, 1); }
		
		private void mul(int l, int r, double v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] *= v;
			}else if(l <= cl && cr <= r){
				muls[cur] *= v;
				plus[cur] *= v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				fall(cur);
				if(cl < r && l < mid){
					mul(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					mul(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public double sum(int l, int r) { 
			return sum(l, r, 0, H, 1);
		}
		
		private double sum(int l, int r, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				return st[cur];
			}else{
				int mid = cl+cr>>>1;
				double res = 0;
				if(cl < r && l < mid){
					res += sum(l, r, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					res += sum(l, r, mid, cr, 2*cur+1);
				}
				return res * muls[cur] + plus[cur]*(Math.min(r,cr)-Math.max(l,cl));
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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