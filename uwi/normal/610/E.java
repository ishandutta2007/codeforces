//package round337;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Random;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), Q = ni(), K = ni();
		char[] s = ns(n);
		if(n == 1){
			for(int i = 0;i < Q;i++){
				int t = ni();
				if(t == 1){
					int l = ni()-1, r = ni()-1;
					char c = nc();
					s[l] = c;
				}else{
					char[] p = ns(K);
					out.println(1);
				}
			}
			return;
		}
		
		int[] a = new int[n-1];
		for(int i = 0;i < n-1;i++){
			int v = (s[i]-'a')*K+(s[i+1]-'a');
			a[i] = v;
		}
		SegmentTreeArrayPlus st = new SegmentTreeArrayPlus(a);
		int[] si = new int[n];
		for(int i = 0;i < n;i++){
			si[i] = s[i]-'a';
		}
		SegmentTreeOverwrite sto = new SegmentTreeOverwrite(si);
		for(int i = 0;i < Q;i++){
			int t = ni();
			if(t == 1){
				int l = ni()-1, r = ni()-1;
				if(l > r){
					int d = l; l = r; r = d;
				}
				char c = nc();
				sto.update(l, r+1, c-'a');
				st.update(l, r, (c-'a')*K+(c-'a'));
				if(l-1 >= 0){
					int ll = sto.get(l-1);
					st.update(l-1, l, ll*K+(c-'a'));
				}
				if(r+1 < n){
					int rr = sto.get(r+1);
					st.update(r, r+1, (c-'a')*K+rr);
				}
			}else{
				char[] p = ns(K);
				int ret = 1;
				for(int j = 0;j < K;j++){
					for(int k = 0;k <= j;k++){
						ret += st.node[1][(p[j]-'a')*K+(p[k]-'a')];
					}
				}
				out.println(ret);
			}
		}
	}
	
	public static class SegmentTreeOverwrite {
		public int M, H, N;
		public int[] cover;
		public int I = Integer.MAX_VALUE;
		
		public SegmentTreeOverwrite(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			cover = new int[M];
			Arrays.fill(cover, I);
			for(int i = 0;i < N;i++){
				cover[H+i] = a[i];
			}
			for(int i = H-1;i >= 1;i--){
				propagate(i);
			}
		}
		
		private void propagate(int i){}
		
		public void update(int l, int r, int v){ update(l, r, v, 0, H, 1); }
		
		private void update(int l, int r, int v, int cl, int cr, int cur)
		{
			if(l <= cl && cr <= r){
				cover[cur] = v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != I){ // back-propagate
					cover[2*cur] = cover[2*cur+1] = cover[cur];
					cover[cur] = I;
					propagate(2*cur);
					propagate(2*cur+1);
				}
				if(cl < r && l < mid){
					update(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
		
		public int get(int x){ 
			int val = I;
			for(int i = H+x;i >= 1;i>>>=1){
				if(cover[i] != I)val = cover[i];
			}
			return val;
		}
	}

	
	public static class SegmentTreeArrayPlus {
		public int M, H, N;
		public int[][] node;
		public int[] cover;
		public int K = 100;
		
		public SegmentTreeArrayPlus(int[] a)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			
			node = new int[M][];
			cover = new int[H];
			for(int i = 0;i < N;i++){
				node[H+i] = new int[K];
				node[H+i][a[i]] = 1;
			}
			Arrays.fill(cover, -1);
			for(int i = H-1;i >= 1;i--)propagate(i);
		}
		
		private void propagate(int cur)
		{
			node[cur] = prop2(node[2*cur], node[2*cur+1], cover[cur], node[cur], H/Integer.highestOneBit(cur));
		}
		
		private int[] prop2(int[] L, int[] R, int cover, int[] C, int len)
		{
			if(L != null && R != null){
				if(C == null)C = new int[K];
				Arrays.fill(C, 0);
				if(cover != -1){
					C[cover] = len;
				}else{
					for(int i = 0;i < K;i++){
						C[i] = L[i] + R[i];
					}
				}
				return C;
			}else if(L != null){
				return prop1(L, cover, C, cover, len);
			}else if(R != null){
				return prop1(R, cover, C, cover, len);
			}else{
				return null;
			}
		}
		
		private int[] prop1(int[] L, int plus, int[] C, int cover, int len)
		{
			if(C == null)C = new int[K];
			Arrays.fill(C, 0);
			if(cover != -1){
				C[cover] = len;
			}else{
				for(int i = 0;i < K;i++){
					C[i] = L[i];
				}
			}
			return C;
		}
		
		public void update(int l, int r, int v) { if(l < r)update(l, r, v, 0, H, 1); }
		
		protected void update(int l, int r, int v, int cl, int cr, int cur)
		{
			if(cur >= H){
				Arrays.fill(node[cur], 0);
				node[cur][v] = 1;
			}else if(l <= cl && cr <= r){
				cover[cur] = v;
				propagate(cur);
			}else{
				int mid = cl+cr>>>1;
				if(cover[cur] != -1){
					if(2*cur < H){
						cover[2*cur] = cover[cur];
						cover[2*cur+1] = cover[cur];
						cover[cur] = -1;
						propagate(2*cur);
						propagate(2*cur+1);
					}else{
						Arrays.fill(node[2*cur], 0);
						node[2*cur][cover[cur]] = 1;
						Arrays.fill(node[2*cur+1], 0);
						node[2*cur+1][cover[cur]] = 1;
						cover[cur] = -1;
					}
				}
				if(cl < r && l < mid){
					update(l, r, v, cl, mid, 2*cur);
				}
				if(mid < r && l < cr){
					update(l, r, v, mid, cr, 2*cur+1);
				}
				propagate(cur);
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 200000, m = 20000, k = 10;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		sb.append(k + " ");
//		for (int i = 0; i < n; i++) {
//			sb.append((char)(gen.nextInt(k)+'a'));
//		}
//		sb.append("\n");
//		for(int i = 0;i < m;i++){
//			int t = gen.nextInt(2)+1;
//			sb.append(t + " ");
//			if(t == 1){
//				int v1 = gen.nextInt(n);
//				int v2 = gen.nextInt(n);
//				sb.append(Math.min(v1, v2) + 1 + " ");
//				sb.append(Math.max(v1, v2) + 1 + " ");
//				sb.append((char)(gen.nextInt(k)+'a'));
//			}else{
//				int[] u = shuffle(k, gen);
//				for(int j = 0;j < k;j++){
//					sb.append((char)('a'+u[j]));
//				}
//			}
//			sb.append("\n");
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static int[] shuffle(int n, Random gen){ int[] a = new int[n]; for(int i = 0;i < n;i++)a[i] = i; for(int i = 0;i < n;i++){ int ind = gen.nextInt(n-i)+i; int d = a[i]; a[i] = a[ind]; a[ind] = d; } return a; }

	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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