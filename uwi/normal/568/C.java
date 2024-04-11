//package round315;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] alp = ns().toCharArray();
		int A = alp.length;
		int n = ni(), m = ni();
		int[] from = new int[2*m];
		int[] to = new int[2*m];
		int p = 0;
		for(int i = 0;i < m;i++){
			int l = ni()-1;
			int lvc = nc() == 'C' ? 1 : 0;
			int r = ni()-1;
			int rvc = nc() == 'C' ? 1 : 0;
			lvc ^= 1;
			from[p] = l+(lvc^1)*n; to[p] = r+rvc*n; p++;
			from[p] = r+(rvc^1)*n; to[p] = l+lvc*n; p++;
		}
		int[][] g = packD(2*n, from, to, p);
		int[][] ig = packD(2*n, to, from, p);
		int[] clus = decomposeToSCCNoRec(g, ig);
		for(int k = 0;k < n;k++){
			if(clus[k] == clus[k+n]){
				out.println(-1);
				return;
			}
		}
		
		char[] s = ns().toCharArray();
		
		outer:
		for(int i = n;i >= 0;i--){
			int[] dec = new int[n];
			Arrays.fill(dec, -1);
			Queue<Integer> q = new ArrayDeque<Integer>();
			for(int j = 0;j < i;j++){
				dec[j] = alp[s[j]-'a'] == 'C' ? 1 : 0;
				q.add(j+dec[j]*n);
			}
			while(!q.isEmpty()){
				int cur = q.poll();
				for(int e : g[cur]){
					if(dec[e%n] == -1){
						dec[e%n] = e/n;
						q.add(e);
					}else{
						if(dec[e%n] != e/n){
							continue outer;
						}
					}
				}
			}
			char[] t = Arrays.copyOf(s, n);
			inner:
			for(int z = i;z < n;z++){
				if(dec[z] != -1){
					for(int k = z == i ? s[z]-'a'+1 : 0;k < A;k++){
						if(dec[z] == (alp[k] == 'C' ? 1 : 0)){
							t[z] = (char)(k+'a');
							continue inner;
						}
					}
					continue outer;
				}else{
					iinner:
					for(int k = z == i ? s[z]-'a'+1 : 0;k < A;k++){
						t[z] = (char)(k+'a');
						int[] ldec = Arrays.copyOf(dec, n);
						dec[z] = alp[k] == 'C' ? 1 : 0;
						q.add(z+dec[z]*n);
						while(!q.isEmpty()){
							int cur = q.poll();
							for(int e : g[cur]){
								if(dec[e%n] == -1){
									dec[e%n] = e/n;
									q.add(e);
								}else{
									if(dec[e%n] != e/n){
										dec = ldec;
										q.clear();
										continue iinner;
									}
								}
							}
						}
						continue inner;
					}
					continue outer;
				}
			}
			out.println(new String(t));
			return;
		}
		
		out.println(-1);
	}
	
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

	
	public static int[] decomposeToSCCNoRec(int[][] g, int[][] ig)
	{
		int n = g.length;
		boolean[] visited = new boolean[n];
		int[] po = new int[n];
		int pop = 0;
		
		int[] stack = new int[n];
		int[] sinds = new int[n];
		int sp = 0;
		for(int i = 0;i < n;i++){
			if(!visited[i]){
				sinds[sp] = 0;
				stack[sp++] = i;
				while(sp > 0){
					int cur = stack[sp-1];
					visited[cur] = true;
					while(sinds[sp-1] < g[cur].length && visited[g[cur][sinds[sp-1]]])sinds[sp-1]++;
					if(sinds[sp-1] == g[cur].length){
						po[pop++] = cur;
						sp--;
					}else{
						stack[sp] = g[cur][sinds[sp-1]];
						sinds[sp] = 0;
						sp++;
					}
				}
			}
		}
		
		int[] ret = new int[n];
		Arrays.fill(visited, false);
		int clus = 0;
		Queue<Integer> q = new ArrayDeque<Integer>();
		for(int i = n - 1;i >= 0;i--){
			if(!visited[po[i]]){
				q.add(po[i]);
				visited[po[i]] = true;
				while(!q.isEmpty()){
					int cur = q.poll();
					ret[cur] = clus;
					for(int k : ig[cur]){
						if(!visited[k]){
							q.add(k);
							visited[k] = true;
						}
					}
				}
				clus++;
			}
		}
		
		return ret;
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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