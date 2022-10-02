//package round56;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int m = ni();
		int[][] gcd = new int[n][n];
		int[][] lcm = new int[n][n];
		final int[][] conn = new int[n][n];
		for(int i = 0;i < n;i++){
			Arrays.fill(conn[i], Integer.MAX_VALUE / 3);
		}
		for(int i = 0;i < m;i++){
			int f = ni() - 1;
			int t = ni() - 1;
			gcd[f][t] = gcd[t][f] = ni();
			lcm[f][t] = lcm[t][f] = ni();
			if(lcm[f][t] % gcd[f][t] != 0){
				out.println("NO");
				return;
			}
			conn[f][t] = conn[t][f] = 1;
		}
		for(int i = 0;i < n;i++){
			conn[i][i] = 0;
		}
		
		for(int k = 0;k < n;k++){
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					conn[i][j] = Math.min(conn[i][j], conn[i][k] + conn[k][j]);
				}
			}
		}
		
		int[] ret = new int[n];
		
		BitSet aned = new BitSet();
		ooo:
		for(int i = aned.nextClearBit(0);i < n;i = aned.nextClearBit(i + 1)){
			int ll = 0;
			int gg = 0;
			aned.set(i);
			for(int j = 0;j < n;j++){
				if(lcm[i][j] != 0){
					aned.set(j);
					if(ll == 0){
						ll = lcm[i][j];
					}else{
						ll = gcd(ll, lcm[i][j]);
					}
				}
				if(gcd[i][j] != 0){
					if(gg == 0){
						gg = gcd[i][j];
					}else{
						gg = lcm(gg, gcd[i][j]);
					}
				}
			}
			if(ll == 0){
				ret[i] = 1;
				continue;
			}
			
			if(ll % gg != 0){
				out.println("NO");
				return;
			}
			
			final int iii = i;
			Integer[] ord = new Integer[n];
			for(int j = 0;j < n;j++)ord[j] = j;
			Arrays.sort(ord, new Comparator<Integer>(){
				public int compare(Integer x, Integer y){
					return conn[iii][x] - conn[iii][y];
				}
			});
			
			int u = ll/gg;
			boolean ok = false;
			outer:
			for(int p = 1;p*p <= u;p++){
				if(u%p==0){
					for(int j = 0;j < n;j++){
						if(conn[i][j] < Integer.MAX_VALUE / 3){
							ret[j] = 0;
						}
					}
					ret[i] = gg*p;
					
					int p0 = 0;
					int p1 = 1;
					while(true){
						int p2;
						for(p2 = p1;p2 < n && conn[i][ord[p2]] == conn[i][ord[p0]]+1;p2++);
						for(int j = p0;j < p1;j++){
							for(int k = j+1;k < p2;k++){
								if(lcm[ord[j]][ord[k]] > 0){
									if(conn[i][ord[j]] < conn[i][ord[k]]){
										ret[ord[k]] = (int)((long)gcd[ord[j]][ord[k]]*lcm[ord[j]][ord[k]]/ret[ord[j]]);
									}
									if(gcd(ret[ord[j]], ret[ord[k]]) != gcd[ord[j]][ord[k]]){
										continue outer;
									}
									if(lcm(ret[ord[j]], ret[ord[k]]) != lcm[ord[j]][ord[k]]){
										continue outer;
									}
								}
							}
						}
						if(p1 == n || conn[i][ord[p1]] == Integer.MAX_VALUE / 3){
							break;
						}
						p0 = p1;
						p1 = p2;
					}
					ok = true;
					break outer;
				}
			}
			
			if(ok){
				continue ooo;
			}
			
			outer2:
			for(int p = 1;p*p<=u;p++){
				if(u%p==0){
					for(int j = 0;j < n;j++){
						if(conn[i][j] < Integer.MAX_VALUE / 3){
							ret[j] = 0;
						}
					}
					ret[i] = gg*(u/p);
					
					int p0 = 0;
					int p1 = 1;
					while(true){
						int p2;
						for(p2 = p1;p2 < n && conn[i][ord[p2]] == conn[i][ord[p0]]+1;p2++);
						for(int j = p0;j < p1;j++){
							for(int k = j+1;k < p2;k++){
								if(lcm[ord[j]][ord[k]] > 0){
									if(conn[i][ord[j]] < conn[i][ord[k]]){
										ret[ord[k]] = (int)((long)gcd[ord[j]][ord[k]]*lcm[ord[j]][ord[k]]/ret[ord[j]]);
									}
									if(gcd(ret[ord[j]], ret[ord[k]]) != gcd[ord[j]][ord[k]]){
										continue outer2;
									}
									if(lcm(ret[ord[j]], ret[ord[k]]) != lcm[ord[j]][ord[k]]){
										continue outer2;
									}
								}
							}
						}
						if(p1 == n || conn[i][ord[p1]] == Integer.MAX_VALUE / 3){
							break;
						}
						p0 = p1;
						p1 = p2;
					}
					ok = true;
					break outer2;
				}
			}
			if(ok){
				continue ooo;
			}
			out.println("NO");
			return;
		}
		
		out.println("YES");
		for(int i = 0;i < n;i++){
			out.print(ret[i] + " ");
		}
		out.println();
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	public static int lcm(int a, int b) {
		return (int)((long)a*b/gcd(a,b));
	}
	
	
	void run() throws Exception
	{
//		int n = 100;
//		StringBuilder sb = new StringBuilder(n + " " + n*(n-1)/2 + " ");
//		for(int i = 0;i < n;i++){
//			for(int j = i+1;j < n;j++){
//				sb.append((i+1) + " " + (j+1) + " 1 "+(2*3*5*7*11*13*17) + " ");
//			}
//		}
//		INPUT = sb.toString();
//
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}