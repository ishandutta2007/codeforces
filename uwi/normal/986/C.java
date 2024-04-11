//package round485;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C7 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	boolean[] f;
	int D;
	
	void solve()
	{
		int n = ni(), m = ni();
		D = n;
		f = new boolean[1<<n];
		for(int i = 0;i < m;i++){
			f[ni()] = true;
		}
		
		int[] clus = decomposeToSCC(1<<n);
		boolean[] t = new boolean[1<<n];
		int ans = 0;
		for(int i = 0;i < 1<<n;i++){
			if(f[i] && !t[clus[i]]){
				ans++;
				t[clus[i]] = true;
			}
		}
		out.println(ans);
	}
	
	public static int[][] packD(int n, int[] from, int[] to){ return packD(n, from, to, from.length);}
	public static int[][] packD(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}
	
	public int[] decomposeToSCC(int n)
	{
		int[] stack = new int[n+1];
		int[] ind = new int[n+1];
		int[] ord = new int[n];
		Arrays.fill(ord, -1);
		int[] low = new int[n];
		Arrays.fill(low, -1);
		int sp = 0;
		int id = 0; // preorder
		int[] clus = new int[n];
		int cid = 0;
		int[] cstack = new int[n+1];
		int csp = 0;
		boolean[] incstack = new boolean[n];
		for(int i = 0;i < n;i++){
			if(ord[i] == -1){
				ind[sp] = 0;
				cstack[csp++] = i;
				stack[sp++] = i;
				incstack[i] = true;
				while(sp > 0){
					int cur = stack[sp-1];
					if(ind[sp-1] == 0){
						ord[cur] = low[cur] = id++;
					}
					if(ind[sp-1] < D+1){
						if(ind[sp-1] < D){
							if(cur<<~ind[sp-1]<0){
								int nex = cur&~(1<<ind[sp-1]);
								if(ord[nex] == -1){
									ind[sp-1]++;
									ind[sp] = 0;
									incstack[nex] = true;
									cstack[csp++] = nex;
									stack[sp++] = nex;
								}else{
									// shortcut
//									U.tr(cur, nex, incstack[nex], low[nex], stack);
									if(incstack[nex])low[cur] = Math.min(low[cur], ord[nex]);
									ind[sp-1]++;
								}
							}else{
								ind[sp-1]++;
							}
						}else{
							if(f[cur]){
								int nex = (1<<D)-1-cur;
								
								if(ord[nex] == -1){
									ind[sp-1]++;
									ind[sp] = 0;
									incstack[nex] = true;
									cstack[csp++] = nex;
									stack[sp++] = nex;
								}else{
									// shortcut
//									U.tr(cur, nex, incstack[nex], low[nex], stack);
									if(incstack[nex])low[cur] = Math.min(low[cur], ord[nex]);
									ind[sp-1]++;
								}
							}else{
								ind[sp-1]++;
							}
						}
					}else{
						if(ord[cur] == low[cur]){
							while(csp > 0){
								incstack[cstack[csp-1]] = false;
								clus[cstack[--csp]] = cid;
								if(cstack[csp] == cur)break;
							}
							cid++;
						}
						if(--sp >= 1)low[stack[sp-1]] = Math.min(low[stack[sp-1]], low[stack[sp]]);
					}
				}
			}
		}
		return clus;
	}


	
	void run() throws Exception
	{
//		int n = 22, m = 1<<22;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		sb.append(m + " ");
//		for (int i = 0; i < m; i++) {
//			sb.append(i + " ");
//		}
//		INPUT = sb.toString();

		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		Thread t = new Thread(null, null, "~", Runtime.getRuntime().maxMemory()/4*3){
			@Override
			public void run() {
				long s = System.currentTimeMillis();
				solve();
				out.flush();
				if(!INPUT.isEmpty())tr(System.currentTimeMillis()-s+"ms");
			}
		};
		t.start();
		t.join();

//		long s = System.currentTimeMillis();
//		solve();
//		out.flush();
//		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new C7().run(); }
	
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