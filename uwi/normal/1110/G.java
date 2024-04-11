//package global001;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class G {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String W = "White";
		String D = "Draw";
		outer:
		for(int T = ni();T > 0;T--){
			int n = ni();
			int[] from = new int[n - 1];
			int[] to = new int[n - 1];
			for (int i = 0; i < n - 1; i++) {
				from[i] = ni() - 1;
				to[i] = ni() - 1;
			}
			int[][] g = packU(n, from, to);
			char[] ini = ns(n);
			if(n <= 2){
				out.println(D);
				continue outer;
			}
			
			int n3 = 0;
			for(int i = 0;i < n;i++){
				if(g[i].length >= 4){
					out.println(W);
					continue outer;
				}
				if(g[i].length == 3){
					n3++;
					int d = 0;
					for(int e : g[i]){
						if(g[e].length >= 2)d++;
					}
					if(d >= 2){
						out.println(W);
						continue outer;
					}
				}
			}
			
			if(n3 > 2)throw new RuntimeException();
			if(n3 == 0){
				// path
				int win = 0, wend = 0;
				for(int i = 0;i < n;i++){
					if(ini[i] == 'W'){
						if(g[i].length == 2){
							win++;
						}else{
							wend++;
						}
					}
				}
				if(n >= 4){
					if(win > 0){
						out.println(W);
						continue outer;
					}
					if(wend <= 1){
						out.println(D);
						continue outer;
					}
					if(n % 2 == 1){
						out.println(W);
					}else{
						out.println(D);
					}
				}else{
					if(win + wend >= 2){
						out.println(W);
					}else{
						out.println(D);
					}
				}
			}else if(n3 == 1){
				// 3-star
				if(n == 4){
					for(int i = 0;i < n;i++){
						if(ini[i] == 'W'){
							out.println(W);
							continue outer;
						}
					}
					out.println(D);
					continue outer;
				}
				
				// 2-2-2-..-3
				
				int z = -1;
				for(int i = 0;i < n;i++){
					if(g[i].length == 1 && g[g[i][0]].length == 2){
						z = i;
						break;
					}
				}
				for(int i = 0;i < n;i++){
					if(ini[i] == 'W' && i != z){
						out.println(W);
						continue outer;
					}
				}
				if(ini[z] == 'W'){
					if(n % 2 == 0){
						out.println(W);
					}else{
						out.println(D);
					}
				}else{
					out.println(D);
				}
			}else if(n3 == 2){
				// 3-2-2-..-3
				if(n % 2 == 1){
					out.println(W); continue outer;
				}
				for(char c : ini){
					if(c == 'W'){
						out.println(W); continue outer;
					}
				}
				out.println(D);
			}
		}
	}
	
	public static int[][] parents3(int[][] g, int root) {
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		depth[0] = 0;

		int[] q = new int[n];
		q[0] = root;
		for (int p = 0, r = 1; p < r; p++) {
			int cur = q[p];
			for (int nex : g[cur]) {
				if (par[cur] != nex) {
					q[r++] = nex;
					par[nex] = cur;
					depth[nex] = depth[cur] + 1;
				}
			}
		}
		return new int[][] { par, q, depth };
	}

	static int[][] packU(int n, int[] from, int[] to) {
		int[][] g = new int[n][];
		int[] p = new int[n];
		for (int f : from)
			p[f]++;
		for (int t : to)
			p[t]++;
		for (int i = 0; i < n; i++)
			g[i] = new int[p[i]];
		for (int i = 0; i < from.length; i++) {
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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
	
	public static void main(String[] args) throws Exception { new G().run(); }
	
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