//package round668;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		if(n % 2 == 0){
			out.println("First");
			for(int i = 0;i < 2*n;i++){
				out.print(i%n+1 + " ");
			}
			out.println();
			out.flush();
		}else{
			out.println("Second");
			out.flush();
			int[] vs = new int[2*n];
			int[][] pos = new int[n][2];
			int[] pp = new int[n];
			for(int i = 0;i < 2*n;i++){
				int v = ni()-1;
				vs[i] = v;
				pos[v][pp[v]++] = i;
			}
			int[] from = new int[2*n];
			int[] to = new int[2*n];
			for(int i = 0;i < n;i++){
				from[i] = pos[i][0];
				to[i] = pos[i][1];
			}
			for(int i = 0;i  <n;i++){
				from[i+n] = i;
				to[i+n] = i+n;
			}
			int[][] g = packU(2*n, from, to);
			boolean[] ved = new boolean[2*n];
			int[] temp = new int[2*n];
			List<Integer> seled = new ArrayList<>();
			long t = 0;
			for(int i = 0;i < 2*n;i++){
				if(!ved[i]){
					int[] c = cycle(g, i, ved, temp);
					for(int j = 0;j < c.length;j+=2){
						t += c[j]+1;
						seled.add(c[j]);
					}
				}
			}
			if(t % (2*n) == n){
				seled.clear();
				Arrays.fill(ved, false);
				for(int i = 0;i < 2*n;i++){
					if(!ved[i]){
						int[] c = cycle(g, i, ved, temp);
						for(int j = 1;j < c.length;j+=2){
							seled.add(c[j]);
						}
					}
				}
			}

			int[] ret = new int[n];
			for(int v : seled){
//				out.print(v + 1 + " ");
				ret[vs[v]] = v + 1;
			}
			for(int v : ret){
				out.print(v + " ");
			}
			out.println();
			out.flush();
		}
	}

	int[] cycle(int[][] g, int start, boolean[] ved, int[] temp)
	{
		int p = 0;
		temp[p++] = start;
		ved[start] = true;
		for(int i = g[start][0], j = start;!ved[i];){
			ved[i] = true;
			temp[p++] = i;
			int nj = i;
			i = g[i][0] ^ g[i][1] ^ j;
			j = nj;
		}
		return Arrays.copyOf(temp, p);
	}

	public static int[][] packU(int n, int[] from, int[] to){ return packU(n, from, to, from.length); }
	public static int[][] packU(int n, int[] from, int[] to, int sup)
	{
		int[][] g = new int[n][];
		int[] p = new int[n];
		for(int i = 0;i < sup;i++)p[from[i]]++;
		for(int i = 0;i < sup;i++)p[to[i]]++;
		for(int i = 0;i < n;i++)g[i] = new int[p[i]];
		for(int i = 0;i < sup;i++){
			g[from[i]][--p[from[i]]] = to[i];
			g[to[i]][--p[to[i]]] = from[i];
		}
		return g;
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