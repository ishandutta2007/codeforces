//package goodbye2016;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class F3 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int[][] g = new int[128][];
	int access = 0;
	
	int[] get(int x)
	{
		if(g[x] != null)return g[x];
		if(++access == 17){
			out.println("! " + (x+1));
			out.flush();
			throw new RuntimeException();
		}
		out.println("? " + (x+1));
		out.flush();
		int n = ni();
		int[] ret = new int[n];
		for(int i = 0;i < n;i++){
			ret[i] = ni()-1;
		}
		if(ret.length == 2){
			out.println("! " + (x+1));
			out.flush();
			throw new RuntimeException();
		}
		return g[x] = ret;
	}
	
	int[] fall(int cur, int pre, int lim)
	{
		int step = 0;
		while(true){
			int[] ne = get(cur);
			step++;
			if(ne.length == 1)return new int[]{-1, step};
			if(--lim <= 0)return new int[]{-2, step};
			for(int x : ne){
				if(x != pre){
					pre = cur;
					cur = x;
					break;
				}
			}
		}
	}
	
	void solve()
	{
		for(int T = ni();T > 0;T--){
			g = new int[128][];
			access = 0;
			
			try{
				int h = ni();
				int[] f = get(0);
				int pre = -1, cur = -1, d = 0;
				if(f.length == 1){
					pre = 0;
					cur = f[0];
					d = 1;
				}else{
					int[] s0 = fall(f[0], 0, 99);
					int[] s1 = fall(f[1], 0, 99);
					d = Math.min(s0[1], s1[1]);
					pre = 0;
					if(s0[1] == d && s1[1] == d){
						cur = f[2];
					}else if(s0[1] == d){
						cur = f[1];
					}else{
						cur = f[0];
					}
					d++;
//					tr(cur, f, s0, s1);
				}
				
				int ste = 0;
				while(true){
//					tr("cur", cur);
					if(++ste == 20)throw new RuntimeException();
					int[] ne = get(cur);
					boolean ok = false;
					if(d < (h+1)/2){
						for(int x : ne){
							if(x != pre){
								if(ok){
									pre = cur;
									cur = x;
									d++;
//									tr("endd", cur, x);
									break;
								}else{
									int[] res = fall(x, cur, d);
//									tr(res, cur, x);
									if(res[0] == -1){
										ok = true;
									}else{
										pre = cur;
										cur = x;
										d++;
//										tr("end", res, cur, x);
										break;
									}
								}
							}
						}
					}else{
						// BFS
						int[] q = new int[128];
						int p = 0;
						q[p++] = cur;
						int[] ds = new int[128];
						Arrays.fill(ds, 99999);
						ds[cur] = d;
						for(int r = 0;r < p;r++){
							int[] nex = get(q[r]);
							if(ds[q[r]] <= h-1){
								for(int e : nex){
									if(e == pre)continue;
									if(ds[e] > ds[q[r]] + 1){
										ds[e] = ds[q[r]] + 1;
										q[p++] = e;
									}
								}
							}
						}
					}
				}
			}catch(Exception e){
//				e.printStackTrace();
			}
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
		new F3().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = true;//System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
//	void tr(Object... o) { System.out.println(Arrays.deepToString(o)); }
}