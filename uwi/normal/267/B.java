//package test5;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class B {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[][] dom = new int[n][];
		for(int i = 0;i < n;i++){
			dom[i] = new int[]{ni(), ni()};
		}
		int[] dim = new int[7];
		for(int i = 0;i < n;i++){
			dim[dom[i][0]]++;
			dim[dom[i][1]]++;
		}
		int[] odds = new int[2];
		int p = 0;
		for(int i = 0;i < 7;i++){
			if(dim[i] % 2 == 1){
				if(p == 2){
					out.println("No solution");
					return;
				}
				odds[p++] = i;
			}
		}
		
//		if(!con(dom)){
//			out.println("No solution");
//			return;
//		}
		
		int[] from = new int[n];
		int[] to = new int[n];
		int[] w = new int[n];
		for(int i = 0;i < n;i++){
			from[i] = dom[i][0];
			to[i] = dom[i][1];
			w[i] = i;
		}
		int[][][] g = packWU(7, from, to, w);
		
		int start = p == 2 ? odds[0] : dom[0][0];
		List<int[]> path = new ArrayList<int[]>();
		eulerianPath(start, g, new boolean[n], path);
		if(path.size() != n){
			out.println("No solution");
		}else{
			for(int[] x : path){
				if(dom[x[2]][0] == x[0]){
					out.println(x[2]+1 + " +");
				}else{
					out.println(x[2]+1 + " -");
				}
			}
		}
	}
	
	void eulerianPath(int cur, int[][][] g, boolean[] ved, List<int[]> path)
	{
		for(int[] e : g[cur]){
			if(!ved[e[1]]){
				ved[e[1]] = true;
				eulerianPath(e[0], g, ved, path);
				path.add(new int[]{e[0], cur, e[1]});
			}
		}
	}
	
	public static int[][][] packWU(int n, int[] from, int[] to, int[] w) {
		int[][][] g = new int[n][][];
		int[] p = new int[n];
		for(int f : from)
			p[f]++;
		for(int t : to)
			p[t]++;
		for(int i = 0;i < n;i++)
			g[i] = new int[p[i]][2];
		for(int i = 0;i < from.length;i++){
			--p[from[i]];
			g[from[i]][p[from[i]]][0] = to[i];
			g[from[i]][p[from[i]]][1] = w[i];
			--p[to[i]];
			g[to[i]][p[to[i]]][0] = from[i];
			g[to[i]][p[to[i]]][1] = w[i];
		}
		return g;
	}
//
//	boolean con(int[][] dom)
//	{
//		int n = dom.length;
//		boolean[][] g = new boolean[6][6];
//		int al = 0;
//		for(int i = 0;i < n;i++){
//			g[dom[i][0]][dom[i][1]] = g[dom[i][1]][dom[i][0]] = true;
//			al |= 1<<dom[i][0];
//			al |= 1<<dom[i][1];
//		}
//		for(int i = 0;i < 6;i++)g[i][i] = true;
//		for(int k = 0;k < 6;k++){
//			for(int i = 0;i < 6;i++){
//				for(int j = 0;j < 6;j++){
//					g[i][j] |= g[i][k] && g[k][j];
//				}
//			}
//		}
//		int x = Integer.numberOfTrailingZeros(al);
//		for(int i = 0;i < 6;i++){
//			if(!g[x][i])return false;
//		}
//		return true;
//	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new B().run(); }
	
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}