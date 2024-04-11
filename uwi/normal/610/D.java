//package round337;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] co = new int[n][];
		for(int i = 0;i < n;i++){
			co[i] = new int[]{ni(), ni(), ni(), ni()};
			if(co[i][0] > co[i][2]){
				int d = co[i][0]; co[i][0] = co[i][2]; co[i][2] = d;
			}
			if(co[i][1] > co[i][3]){
				int d = co[i][1]; co[i][1] = co[i][3]; co[i][3] = d;
			}
			co[i][2]++;
			co[i][3]++;
		}
		out.println(unionX(co));
	}
	
	public static long unionX(int[][] co)
	{
		int n = co.length;
		long[] es = new long[2*n];
		int[] ys = new int[2*n];
		int OFFSET = 1000000001;
		for(int i = 0;i < n;i++){
			es[2*i] = (long)(co[i][0]+OFFSET)<<32|i<<1|1;
			es[2*i+1] = (long)(co[i][2]+OFFSET)<<32|i<<1|0;
			ys[2*i] = co[i][1]+OFFSET;
			ys[2*i+1] = co[i][3]+OFFSET;
		}
		int[] imap = shrinkX(ys);
		for(int i = 0;i < n;i++){
			co[i][1] = ys[2*i];
			co[i][3] = ys[2*i+1];
		}
		
//		Arrays.sort(es);
		es = radixSort(es);
		
		long S = 0;
		int px = 0;
		SegmentTreeUnionS st = new SegmentTreeUnionS(imap);
		for(int i = 0;i < 2*n;i++){
			int cx = (int)(es[i]>>>32);
			S += (long)(cx-px)*st.count[1];
			int ind = ((int)es[i])>>>1;
			int plus = es[i]<<~0<0 ? 1 : -1;
			st.add(co[ind][1], co[ind][3], plus);
			px = cx;
		}
		return S;
	}
	
	public static int[] shrinkX(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
//		b = radixSort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i == 0 || (b[i]^b[i-1])>>32!=0)ret[p++] = (int)(b[i]>>32);
			a[(int)b[i]] = p-1;
		}
		return Arrays.copyOf(ret, p);
	}
	
	public static long[] radixSort(long[] f)
	{
		long[] to = new long[f.length];
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>16&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>16&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>32&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>32&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		{
			int[] b = new int[65537];
			for(int i = 0;i < f.length;i++)b[1+(int)(f[i]>>>48&0xffff)]++;
			for(int i = 1;i <= 65536;i++)b[i]+=b[i-1];
			for(int i = 0;i < f.length;i++)to[b[(int)(f[i]>>>48&0xffff)]++] = f[i];
			long[] d = f; f = to;to = d;
		}
		return f;
	}

	
	public static class SegmentTreeUnionS {
		public int M, H, N;
		public int[] st;
		public int[] count;
		public int[] ys;
		
		public SegmentTreeUnionS(int[] ys)
		{
			N = ys.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new int[M];
			count = new int[M];
			this.ys = ys;
		}
		
		private void propagate(int i)
		{
			if(st[i] > 0){
				int b = H/Integer.highestOneBit(i);
				int low = i*b-H;
				int high = Math.min((i+1)*b-H, ys.length-1);
				count[i] = ys[high]-ys[low];
			}else{
				count[i] = count[2*i] + count[2*i+1];
			}
		}
		
		public void add(int l, int r, int v){ add(l, r, v, 0, H, 1); }
		
		private void add(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				st[cur] += v;
				count[cur] = st[cur] > 0 ? ys[cur-H+1]-ys[cur-H] : 0;
			}else if(l <= cl && cr <= r){
				st[cur] += v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cl < r && l < mid){
					add(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					add(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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