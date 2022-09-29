//package test13;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int[] get(int[] x)
	{
		for(int v : x){
			out.print(v);
		}
		out.println();
		out.flush();
		return new int[]{ni(), ni()};
	}
	
	void solve()
	{
		List<int[]> cans = new ArrayList<>();
		int[] a = new int[4];
		outer:
		do{
			for(int i = 0;i < 4;i++){
				for(int j = i+1;j < 4;j++){
					if(a[i] == a[j])continue outer;
				}
			}
			cans.add(Arrays.copyOf(a, 4));
		}while(inc(a, 10));
		
		{
			List<int[]> ncans = new ArrayList<>();
			int[] res = get(new int[]{0, 1, 2, 3});
			if(res[0] == 4 && res[1] == 0)return;
			for(int[] can : cans){
				int[] g = guess(can, new int[]{0, 1, 2, 3});
				if(Arrays.equals(g, res)){
					ncans.add(can);
				}
			}
			cans = ncans;
		}
		if(cans.size() == 1){
			get(cans.get(0));
			return;
		}
		
		while(true){
			if(cans.size() == 1){
				get(cans.get(0));
				return;
			}
//			long S = System.nanoTime();
			int[] q = new int[4];
			int min = 9999999;
			int[] argmin = null;
			do{
				int[][] f = new int[5][5];
				for(int[] can : cans){
					int[] g = guess(can, q);
					f[g[0]][g[1]]++;
				}
				int lmax = 0;
				for(int i = 0;i < 5;i++){
					for(int j = 0;j < 5;j++){
						lmax = Math.max(lmax, f[i][j]);
					}
				}
				if(lmax < min){
					min = lmax;
					argmin = Arrays.copyOf(q, 4);
				}
			}while(inc(q, 10));
//			tr(System.nanoTime() - S);
			
			int[] res = get(argmin);
			if(res[0] == 4 && res[1] == 0)return;
			List<int[]> ncans = new ArrayList<>();
			for(int[] can : cans){
				int[] g = guess(can, argmin);
				if(Arrays.equals(g, res)){
					ncans.add(can);
				}
			}
			cans = ncans;
		}
	}
	
	public static boolean inc(int[] a, int base) {
		int n = a.length;
		int i;
		for (i = n - 1; i >= 0 && a[i] == base - 1; i--)
			;
		if (i == -1)
			return false;

		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}

	int[] guess(int[] a, int[] q)
	{
		int[] fa = new int[10];
		int[] fq = new int[10];
		for(int v : a)fa[v]++;
		for(int v : q)fq[v]++;
		int blow = 0;
		for(int i = 0;i < 10;i++)blow += Math.min(fa[i], fq[i]);
		int hit = 0;
		for(int i = 0;i < 4;i++){
			if(a[i] == q[i])hit++;
		}
		return new int[]{hit, blow-hit};
	}
//	
//	public static class GuessResult
//	{
//		int[] guess;
//		int hit, blow;
//		public GuessResult(int[] guess, int hit, int blow) {
//			this.guess = guess;
//			this.hit = hit;
//			this.blow = blow;
//		}
//	}
	
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = true;//System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}