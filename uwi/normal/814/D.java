//package round418;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.Queue;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		long[][] co = new long[n][];
		for(int i = 0;i < n;i++){
			co[i] = new long[]{ni(), ni(), ni()};
		}
		int[] par = new int[n];
		for(int i = 0;i < n;i++){
			int arg = -1;
			for(int j = 0;j < n;j++){
				if(i == j)continue;
				if(co[j][2] > co[i][2] && 
						(co[i][0]-co[j][0])*(co[i][0]-co[j][0]) + 
						(co[i][1]-co[j][1])*(co[i][1]-co[j][1]) <= co[j][2]*co[j][2]){
					if(arg == -1 || co[j][2] < co[arg][2]){
						arg = j;
					}
				}
			}
			par[i] = arg;
		}
		int[][] g = parentToG(par);
		int[] dep = new int[n];
		Arrays.fill(dep, 9999999);
		Queue<Integer> q = new ArrayDeque<>();
		for(int i = 0;i < n;i++){
			if(par[i] == -1){
				q.add(i);
				dep[i] = 0;
			}
		}
		while(!q.isEmpty()){
			int cur = q.poll();
			for(int e : g[cur]){
				if(dep[e] == 9999999){
					dep[e] = dep[cur] + 1;
					q.add(e);
				}
			}
		}
		
		double ret = 0;
		for(int i = 0;i < n;i++){
			if(dep[i] <= 1 || dep[i] % 2 == 1){
				ret += co[i][2]*co[i][2]*Math.PI;
			}else{
				ret -= co[i][2]*co[i][2]*Math.PI;
			}
		}
		out.printf("%.14f\n", ret);
	}
	
	public static int[][] parents3(int[][] g)
	{
		int n = g.length;
		int[] par = new int[n];
		Arrays.fill(par, -1);

		int[] depth = new int[n];
		int[] q = new int[n];
		int r = 0;
		for(int u = 0;u < n;u++){
			if(par[u] == -1){
				q[r] = u;
				depth[u] = 0;
				r++;
				for(int p = r-1;p < r;p++) {
					int cur = q[p];
					for(int nex : g[cur]){
						if(par[cur] != nex){
							q[r++] = nex;
							par[nex] = cur;
							depth[nex] = depth[cur] + 1;
						}
					}
				}
			}
		}
		return new int[][] {par, q, depth};
	}

	
	public static int[][] parentToG(int[] par)
	{
		int n = par.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(par[i] >= 0){
				ct[i]++;
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
				g[i][--ct[i]] = par[i];
			}
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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