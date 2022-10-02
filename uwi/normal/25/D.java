//package round25;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;
import java.util.HashSet;
import java.util.Random;
import java.util.Scanner;

public class D {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "7 1 2 2 3 3 1 4 5 5 6 6 7";
//	private String INPUT = "2 1 2";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[][] r = new int[n][n];
		int[] p = new int[n];
		for(int i = 0;i < n - 1;i++){
			int a = ni() - 1;
			int b = ni() - 1;
			r[a][p[a]++] = b;
			r[b][p[b]++] = a;
		}
		
		for(int i = 0;i < n;i++){
			r[i] = Arrays.copyOf(r[i], p[i]);
		}
		
		int[] cl = new int[n];
		int cln = 1;
		int[] chead = new int[n];
		for(int i = 0;i < n;i++){
			if(cl[i] == 0){
				cl[i] = cln;
				chead[cln] = i;
				Deque<Integer> q = new ArrayDeque<Integer>();
				q.add(i);
				while(!q.isEmpty()){
					int x = q.pollFirst();
					for(int nex : r[x]){
						if(cl[nex] == 0){
							cl[nex] = cln;
							q.add(nex);
						}else if(cl[nex] != cln){
							throw new AssertionError();
						}
					}
				}
				cln++;
			}
		}
		
		out.println(cln - 2);
		int j = 1;
		ooo:
		for(int i = 1;i < cln - 1;i++){
			for(;j < cln;j++){
				int[] from = new int[n];
				Arrays.fill(from, -1);
				Deque<Integer> q = new ArrayDeque<Integer>();
				q.add(chead[j]);
				from[chead[j]] = 12345;
				while(!q.isEmpty()){
					int x = q.pollFirst();
					for(int nex : r[x]){
						if(nex == -1 || from[x] == nex)continue;
						if(from[nex] == -1){
							from[nex] = x;
							q.add(nex);
						}else{
							out.println((x+1) + " " + (nex+1) + " " + (chead[i]+1) + " " + (chead[i+1]+1));
							for(int w = 0;w < r[x].length;w++)if(r[x][w] == nex)r[x][w] = -1;
							for(int w = 0;w < r[nex].length;w++)if(r[nex][w] == x)r[nex][w] = -1;
							continue ooo;
						}
					}
				}
			}
		}
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("1000 ");
//		Random r = new Random();
//		int n = 1000;
//		HashSet<Integer> oo = new HashSet<Integer>();
//		for(int i = 0;i < n - 1;i++){
//			int a = 0, b = 0;
//			while(a == b || oo.contains(a * n + b)){
//				a = r.nextInt(n) + 1;
//				b = r.nextInt(n) + 1;
//			}
//			sb.append(a);
//			sb.append(' ');
//			sb.append(b);
//			sb.append(' ');
//			oo.add(n * a + b);
//			oo.add(n * b + a);
//		}
//		INPUT = sb.toString();
////		tr(INPUT);
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}