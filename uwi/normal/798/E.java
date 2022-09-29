//package round410;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] from = new int[29000000];
		int[] to = new int[29000000];
		int p = 0;
		boolean[] mark = new boolean[n];
		int H = Integer.highestOneBit(Math.max(n-1, 1))<<1;
		for(int v : a){
			if(v >= 1){
				mark[v-1] = true;
			}
		}
		int idgen = n;
		int[] ids = new int[2*H];
		Arrays.fill(ids, -1);
//		for(int i = 1;i < H+n;i++){
//			ids[i] = idgen++;
//		}
		for(int i = 0;i < n;i++){
			if(!mark[i]){
				if(ids[H+i] == -1)ids[H+i] = idgen++;
				from[p] = i; to[p] = ids[H+i]; p++;
			}
		}
		for(int i = H+n-1;i >= 2;i--){
			if(ids[i] == -1)continue;
			if(ids[i/2] == -1)ids[i/2] = idgen++;
			from[p] = ids[i]; to[p] = ids[i/2]; p++;
		}
		for(int i = n-1;i >= 0;i--){
			int r = a[i] == -1 ? n : a[i]-1;
			if(r < i){
				while(0 < r){
					int f = r&-r;
					
					if(ids[(H+r)/f-1] != -1){
						from[p] = ids[(H+r)/f-1]; to[p] = i; p++;
					}
					r -= f;
				}
			}else{
				int rr = i;
				while(0 < rr){
					int f = rr&-rr;
					if(ids[(H+rr)/f-1] != -1){
						from[p] = ids[(H+rr)/f-1]; to[p] = i; p++;
					}
					rr -= f;
				}
				int l = i+1;
				if(l < r){
					while(l != 0){
						int f = l&-l;
						if(l+f > r)break;
						if(ids[(H+l)/f] != -1){
							from[p] = ids[(H+l)/f]; to[p] = i; p++;
						}
						l += f;
					}
					while(l < r){
						int f = r&-r;
						if(ids[(H+r)/f-1] != -1){
							from[p] = ids[(H+r)/f-1]; to[p] = i; p++;
						}
						r -= f;
					}
				}
			}
			if(a[i] > 0){
				int w = a[i]-1;
				from[p] = i; to[p] = w; p++;
				ids[H+w] = w;//idgen++;
//				from[p] = w; to[p] = ids[H+w]; p++;
				for(int cur = H+w;cur > 1;cur>>>=1){
					int par = cur>>>1;
					int nid = idgen++;
					if(ids[par] != -1){
						from[p] = ids[par]; to[p] = nid; p++;
					}
					if(ids[cur] != -1){
						from[p] = ids[cur]; to[p] = nid; p++;
					}
					ids[par] = nid;
				}
			}
//			{
//				int[][] g = packD(idgen, from, to, p);
//				int[] ord = sortTopologically(g);
//				tr(g);
//				tr(ord);
//			}
		}
//		tr(idgen, p);
		int[][] g = packX(idgen, from, to, p);
		int[] ord = sortTopologically(g);
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		int gen = 0;
		for(int v : ord){
			if(v < n){
				ans[v] = gen++;
			}
		}
		for(int i = 0;i < n;i++){
			out.print(ans[i]+1 + " ");
		}
	}
	
	public static int[] sortTopologically(int[][] gs)
	{
		int[] g = gs[0], offset = gs[1];
		int n = offset.length-1;
		int[] ec = new int[n];
		for(int i = 0;i < g.length;i++){
			ec[g[i]]++;
		}
		int[] ret = new int[n];
		int q = 0;
		
		// sources
		for(int i = 0;i < n;i++){
			if(ec[i] == 0)ret[q++] = i;
		}
		
		for(int p = 0;p < q;p++){
			for(int i = offset[ret[p]];i < offset[ret[p]+1];i++){
				if(--ec[g[i]] == 0)ret[q++] = g[i];
			}
		}
		// loop
		for(int i = 0;i < n;i++){
			if(ec[i] > 0)return null;
		}
		return ret;
	}

	
	public static int[][] packX(int n, int[] from, int[] to, int sup)
	{
		int[] g = new int[sup];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		int[] offset = new int[n+1];
		for(int i = 1;i <= n;i++){
			offset[i] = offset[i-1] + p[i-1];
		}
		for(int i = 0;i < sup;i++){
			g[offset[from[i]] + (--p[from[i]])] = to[i];
		}
		return new int[][]{g, offset};
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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