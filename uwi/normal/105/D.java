//package round81;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Queue;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
//	String INPUT = "5 5\r\n" + 
//			"9 0 1 1 0\r\n" + 
//			"0 0 3 2 0\r\n" + 
//			"1 1 1 3 0\r\n" + 
//			"1 1 1 3 0\r\n" + 
//			"0 1 2 0 3\r\n" + 
//			"-1 1 -1 3 -1\r\n" + 
//			"-1 -1 -1 0 -1\r\n" + 
//			"-1 -1 -1 -1 -1\r\n" + 
//			"-1 2 3 -1 -1\r\n" + 
//			"-1 -1 -1 -1 2\r\n" + 
//			"4 2";
//	String INPUT = "3 3 1 1 1 1 1 1 2 3 4 2 3 3 4 3 -1 -1 -1 -1 1 1";
	String INPUT = "3 3 1 1 1 1 1 1 2 3 4 2 3 2 3 4 -1 -1 -1 -1 1 1";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int z = n*m;
		int[] map = new int[z];
		for(int i = 0;i < z;i++)map[i] = ni();
		int[] sy = new int[z];
		for(int i = 0;i < z;i++)sy[i] = ni();
		int start = (ni()-1)*m+(ni()-1);
		
		// shrink
		int[] cs = new int[2*z+1];
		for(int i = 0;i < z;i++){
			cs[i] = map[i];
			cs[i+z] = Math.max(0, sy[i]);
		}
		cs[2*z] = 0;
		cs = shrink(cs);
		
		int ns = 0;
		int ncol = 0;
		for(int i = 0;i < z;i++){
			map[i] = cs[i];
			if(sy[i] != -1 && map[i] != 0){
				sy[i] = cs[i+z];
				ns++;
			}
			ncol = Math.max(ncol, cs[i]);
			ncol = Math.max(ncol, cs[i+z]);
		}
		
		int[] f = new int[ns];
		int[] t = new int[ns];
		int p = 0;
		for(int i = 0;i < z;i++){
			if(sy[i] != -1 && map[i] != 0){
				f[p] = map[i];
				t[p] = i;
				p++;
			}
		}
		
		int[] ccell = new int[ncol+1];
		for(int i = 0;i < z;i++){
			ccell[map[i]]++;
		}
		
		int[][] g = packD(ncol+1, f, t);
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(start);
		long rep = 0;
		BitSet ved = new BitSet();
		int now = map[start];
		int sames = 0;
		while(q.size() > 0){
			int cur = q.poll();
			int cr = cur / m, cc = cur % m;
			// now -> sy[cur]
			if(now != sy[cur] && now != 0){
				if(!ved.get(now)){
					ved.set(now);
					
					// pick up symbols
					int[][] d = new int[g[now].length][2];
					for(int i = 0;i < g[now].length;i++){
						int nex = g[now][i];
						int nr = nex / m, nc = nex % m;
						d[i][0] = nex;
						d[i][1] = ord(nr-cr, nc-cc);
					}
					Arrays.sort(d, new Comparator<int[]>(){
						public int compare(int[] a, int[] b)
						{
							return a[1] - b[1];
						}
					});
					for(int i = 0;i < d.length;i++){
						if(d[i][0] != cur){
							q.add(d[i][0]);
						}
					}
				}
				
				// repaint
				sames += ccell[now];
				ccell[now] = 0;
				rep += sames;
//				tr(rep);
				now = sy[cur];
			}
		}
		
		out.println(rep);
	}
	
	public static int[][] packD(int n, int[] from, int[] to)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int f : from)p[f]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < from.length;i++){
			g[from[i]][--p[from[i]]] = to[i];
		}
		return g;
	}
	
	public static int[] shrink(int[] a)
	{
		int n = a.length;
		long[] b = new long[n];
		for(int i = 0;i < n;i++)b[i] = (long)a[i]<<32|i;
		Arrays.sort(b);
		int[] ret = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++) {
			if(i>0 && (b[i]^b[i-1])>>32!=0)p++;
			ret[(int)b[i]] = p;
		}
		return ret;
	}
	
	int ord(int r, int c)
	{
		int g = Math.max(Math.abs(r), Math.abs(c));
		int b = (2*g+1)*(2*g+1);
		if(c == -g){
			return b-(g+r);
		}else if(r == g){
			return b-2*g-(g+c);
		}else if(c == g){
			return b-4*g-(g-r);
		}else{
			return b-6*g-(g-c);
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}