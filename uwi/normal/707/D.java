//package round368;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class D2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		n = ni();
		m = ni();
		Q = ni();
		qs = new int[Q][];
		int[] par = new int[Q+1];
		Arrays.fill(par, -1);
		for(int i = 0;i < Q;i++){
			int t = ni();
			par[i+1] = i;
			if(t == 1){
				qs[i] = new int[]{t, ni()-1, ni()-1};
			}else if(t == 2){
				qs[i] = new int[]{t, ni()-1, ni()-1};
			}else if(t == 3){
				qs[i] = new int[]{t, ni()-1};
			}else if(t == 4){
				qs[i] = new int[]{t, ni()};
				par[i+1] = qs[i][1];
			}
		}
		int[][] ch = parentToChildren(par);
		b = new boolean[n*m];
		flip = new boolean[n];
		bt = new int[n];
		rets = new int[Q];
		Arrays.fill(rets, -1);
		dfs(0, ch);
		for(int v : rets){
			out.println(v);
		}
	}
	
	int n, m, Q;
	int[][] qs;
	boolean[] b;
	boolean[] flip;
	int[] bt;
	int[] rets;
	int num;
	
	void dfs(int cur, int[][] ch)
	{
		boolean ched = false;
		
		int[] q = null;
		if(cur > 0){
			q = qs[cur-1];
			if(q[0] == 1){
				int sh = q[1], pos = q[2];
				if(!(b[sh*m+pos]^flip[sh])){
					b[sh*m+pos] ^= true;
					num++;
					bt[sh]++;
					ched = true;
				}
			}else if(q[0] == 2){
				int sh = q[1], pos = q[2];
				if((b[sh*m+pos]^flip[sh])){
					b[sh*m+pos] ^= true;
					num--;
					bt[sh]--;
					ched = true;
				}
			}else if(q[0] == 3){
				int sh = q[1];
				flip[sh] ^= true;
				num -= bt[sh];
				bt[sh] = m-bt[sh];
				num += bt[sh];
				ched = true;
			}
			rets[cur-1] = num;
		}
		
		for(int e : ch[cur]){
			dfs(e, ch);
		}
		
		if(cur > 0){
			if(q[0] == 1){
				int sh = q[1], pos = q[2];
				if(ched){
					b[sh*m+pos] ^= true;
					num--;
					bt[sh]--;
				}
			}else if(q[0] == 2){
				int sh = q[1], pos = q[2];
				if(ched){
					b[sh*m+pos] ^= true;
					num++;
					bt[sh]++;
				}
			}else if(q[0] == 3){
				int sh = q[1];
				if(ched){
					flip[sh] ^= true;
					num -= bt[sh];
					bt[sh] = m-bt[sh];
					num += bt[sh];
				}
			}
		}
	}
	
	public static int[][] parentToChildren(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[par[i]]++;
			}
		}
		int[][] g = new int[n][];
		for(int i = 0;i < n;i++){
			g[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				g[par[i]][--ct[par[i]]] = i;
			}
		}
		
		return g;
	}

	
	void run() throws Exception
	{
//		int n = 250000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(1000 + " ");
//		sb.append(1000 + " ");
//		sb.append(n + " ");
//		for (int i = 0; i < n; i++) {
//			int t = gen.nextInt(2)+1;
//			sb.append(t + " ");
//			sb.append(gen.nextInt(1000)+1 + " ");
//			sb.append(gen.nextInt(1000)+1 + " ");
//		}
//		INPUT = sb.toString();

		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D2().run(); }
	
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