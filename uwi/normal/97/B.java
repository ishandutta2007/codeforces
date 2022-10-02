//package yandex2011.finals;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "2 1 1 2 2";
	
	void solve()
	{
		int n = ni();
		int[][] c = new int[n][3];
		for(int i = 0;i < n;i++){
			c[i][0] = ni();
			c[i][1] = ni();
		}
		
		Arrays.sort(c, new Comparator<int[]>(){
			public int compare(int[] a, int[] b)
			{
				return a[0] - b[0];
			}
		});
		
		TreeSet<int[]> ts = new TreeSet<int[]>(new Comparator<int[]>(){
			public int compare(int[] a, int[] b)
			{
				return a[1] - b[1];
			}
		});
		
		for(int i = 0;i < n;i++){
			c[i][2] = i;
		}
		
		long M = 2000000000+1;
		long F = 1000000000;
		Set<Long> u = new HashSet<Long>();
		for(int i = 0;i < n;i++){
			u.add((c[i][0]+F)*M+c[i][1]+F);
			if(i >= 1){
				int[] fl = ts.lower(c[i]);
				int[] ce = ts.higher(c[i]);
				if(fl == null){
					int max = (int)(F+1);
					int ind = ts.first()[2];
					for(int j = i-1;j >= ind;j--){
						if(c[i][1] < c[j][1] && c[j][1] < max){
							max = c[j][1];
							u.add((c[j][0]+F)*M+c[i][1]+F);
						}
					}
//					for(int j = ts.first()[2];j <= i;j++){
//						u.add((c[j][0]+F)*M+c[i][1]+F);
//					}
				}else if(ce == null){
					int min = (int)(-F-1);
					int ind = ts.last()[2];
					for(int j = i-1;j >= ind;j--){
						if(c[i][1] > c[j][1] && c[j][1] > min){
							min = c[j][1];
							u.add((c[j][0]+F)*M+c[i][1]+F);
						}
					}
//					for(int j = ts.last()[2];j <= i;j++){
//						u.add((c[j][0]+F)*M+c[i][1]+F);
//					}
				}else{
					int min = (int)(-F-1);
					for(int j = i-1;j >= fl[2];j--){
						if(c[i][1] > c[j][1] && c[j][1] > min){
							min = c[j][1];
							u.add((c[j][0]+F)*M+c[i][1]+F);
						}
					}
					int max = (int)(F+1);
					for(int j = i-1;j >= ce[2];j--){
						if(c[i][1] < c[j][1] && c[j][1] < max){
							max = c[j][1];
							u.add((c[j][0]+F)*M+c[i][1]+F);
						}
					}
				}
			}
			ts.add(c[i]);
		}
		
		out.println(u.size());
		for(long z : u){
			long x = z / M - F;
			long y = z % M - F;
			out.println(x + " " + y);
		}
	}
	
	void run() throws Exception
	{
//		int n = 10000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		Random r = new Random();
//		for(int i = 0;i < n;i++){
//			sb.append(i + " ");
//			sb.append(i*(i%2==0?-1:1) + " ");
////			sb.append(i + " ");
////			sb.append(r.nextInt(2000000000)-1000000000 + " ");
////			sb.append(r.nextInt(2000000000)-1000000000 + " ");
////			sb.append(r.nextInt(10) + " ");
////			sb.append(r.nextInt(10) + " ");
//		}
//		INPUT = sb.toString();
////		tr(INPUT);
		
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
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}