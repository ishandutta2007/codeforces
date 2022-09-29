//package avito2018;
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
		QuerySegmentTree qst = new QuerySegmentTree(n);
		for(int i = 0;i < Q;i++){
			qst.put(ni()-1, ni(), ni());
		}
		
		int m = (n+1>>>6)+1;
		int h = Integer.bitCount(qst.M-1);
		long[][] dps = new long[h+1][];
		long[] dp = new long[m];
		dp[0] |= 1L<<0;
		dps[h] = dp;
		
		long[] last = new long[m];
		for(int i = 0;i < n;i++){
			
			int upd = Integer.bitCount((i^i-1)&(qst.M-1));
			for(int j = upd-1;j >= 0;j--){
				// push
				L node = qst.st[qst.H+i>>>j];
				long[] ndp = Arrays.copyOf(dps[j+1], m);
				if(node != null){
					for(int k = 0;k < node.size();k++){
						long[] temp = Arrays.copyOf(ndp, m);
						or2(temp, 0, n+1-node.a[k], ndp, node.a[k]);
					}
				}
				dps[j] = ndp;
			}
			
			or2(dps[0], 0, n+1, last, 0);
		}
		
		out.println(size(last)-1);
		for(int i = 1;i <= n;i++){
			if(last[i>>>6]<<~i<0){
				out.print(i + " ");
			}
		}
		out.println();
	}
	
	public static int size(long[] a)
	{
		int ret = 0;
		for(long v : a)ret += Long.bitCount(v);
		return ret;
	}

	
	public static void or2(long[] from, int fl, int fr, long[] to, int tl)
	{
		if(fl >= fr)return;
		if(!(fl >= 0 && fl < from.length<<6))throw new RuntimeException();
		if(!(fr >= 0 && fr <= from.length<<6))throw new RuntimeException();
		if(!(tl >= 0 && tl < to.length<<6))throw new RuntimeException();
		if(!(tl+(fr-fl) >= 0 && tl+(fr-fl) <= to.length<<6))throw new RuntimeException();
		
		int tr = tl+(fr-fl);
		if(tl>>>6 == tr-1>>>6){
			if(fl>>>6 == fr-1>>>6){
				to[tl>>>6] |= from[fl>>>6]<<-fr>>>fl-fr<<tl;
			}else{
				to[tl>>>6] |= from[fl>>>6]>>>fl<<tl | from[(fl>>>6)+1]<<-fr>>>-fr<<tr-fr;
			}
		}else if((fl&63) < (tl&63)){
			to[tl>>>6] |= from[fl>>>6]>>>fl<<tl;
			for(int i = (tl>>>6)+1, j = (fl>>>6);i <= (tr-1>>>6)-1;i++,j++){
				to[i] |= from[j]>>>fl-tl | from[j+1]<<-(fl-tl);
			}
			if((fr-1&63) < (tr-1&63)){
				to[tr-1>>>6] |= from[(fr-1>>>6)-1]>>>fl-tl | from[fr-1>>>6]<<-fr>>>-tr;
			}else{
				to[tr-1>>>6] |= from[fr-1>>>6]<<-fr>>>-tr;
			}
		}else if((fl&63) > (tl&63)){
			to[tl>>>6] |= from[fl>>>6]>>>fl<<tl | from[(fl>>>6)+1]<<-(fl-tl);
			for(int i = (tl>>>6)+1, j = (fl>>>6)+1;i <= (tr-1>>>6)-1;i++,j++){
				to[i] |= from[j]>>>fl-tl | from[j+1]<<-(fl-tl);
			}
			if((fr-1&63) > (tr-1&63)){
				to[tr-1>>>6] |= from[fr-1>>>6]<<-fr>>>-tr;
			}else{
				to[tr-1>>>6] |= from[(fr-1>>>6)-1]>>>fl-tl | from[fr-1>>>6]<<-fr>>>-tr;
			}
		}else{
			to[tl>>>6] |= from[fl>>>6]>>>fl<<tl;
			for(int i = (tl>>>6)+1, j = (fl>>>6)+1;i <= (tr-1>>>6)-1;i++,j++){
				to[i] |= from[j];
			}
			to[tr-1>>>6] |= from[fr-1>>>6]<<-fr>>>-tr;
		}
	}

	
	public static class L {
		public int[] a;
		public int p = 0;
		
		public L(int n) { a = new int[n]; }
		public L add(int n)
		{
			if(p >= a.length)a = Arrays.copyOf(a, a.length*3/2+1);
			a[p++] = n;
			return this;
		}
		public int size() { return p; }
		public L clear() { p = 0; return this; }
		public int[] toArray() { return Arrays.copyOf(a, p); }
		@Override
		public String toString() {return Arrays.toString(toArray());}
	}

	
	public static class QuerySegmentTree
	{
		public int M, H, N;
		public L[] st;
		
		public QuerySegmentTree(int n)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			st = new L[M];
		}
		
		public void put(int l, int r, int qid){
			if(l >= r)return;
			while(l != 0){
				int f = l&-l;
				if(l+f > r)break;
				L q = st[(H+l)/f];
				if(q == null)q = st[(H+l)/f] = new L(1);
				q.add(qid);
				l += f;
			}
			
			while(l < r){
				int f = r&-r;
				L q = st[(H+r)/f-1];
				if(q == null)q = st[(H+r)/f-1] = new L(1);
				q.add(qid);
				r -= f;
			}
		}
		
	}

	
	void run() throws Exception
	{
//		int n = 10000, q = 1;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(q + " ");
//		for (int i = 0; i < q; i++) {
//			int v1 = gen.nextInt(n);
//			int v2 = gen.nextInt(n);
//			sb.append(Math.min(v1, v2) + 1 + " ");
//			sb.append(Math.max(v1, v2) + 1 + " ");
//			sb.append(gen.nextInt(n) + 1 + " ");
//		}
//		INPUT = sb.toString();

		
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