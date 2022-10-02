//package round19;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C2 {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "6 1 2 3 1 2 3";
//	private String INPUT = "7 4 5 6 5 6 7 7";
//	private String INPUT = "";
	String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
//		int[] rank = doLarssonSadakane(a);
//		tr(rank);
//		int[] irank = new int[n];
//		for(int i = 0;i < n;i++)irank[rank[i]] = i;
		
		int cut = 0;
		for(int x = 1;x <= n / 2;x++){
			whi:
			while(true){
				for(int i = cut + x-1;i + x < n;i += x){
					if(a[i] == a[i + x]){
						int start = -1;
						int ct = 0;
						for(int j = i-(x-1);j < i+x && x+j<n;j++){
							if(a[j] == a[x+j]){
								if(ct == 0)start = j;
								ct++;
								if(ct == x)break;
							}else{
								ct = 0;
							}
						}
						if(ct == x){
							cut = start + x;
							continue whi;
						}
					}
				}
				break;
			}
//			tr(x, cut);
		}
		
		out.println(n - cut);
		StringBuilder sb = new StringBuilder();
		for(int i = cut;i < n;i++){
			sb.append(a[i]);
			sb.append(' ');
		}
		out.println(sb);
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder("100000 ");
////		for(int i = 0;i < 100000;i++){
////			sb.append(i + " ");
////		}
//		for(int i = 0;i < 100000;i++){
//			sb.append((i % 33334) + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static int[] doLarssonSadakane(final int[] str)
	{
		int n = str.length;
		Integer[] irank = new Integer[n];
		for(int i = 0;i < n;i++)irank[i] = i;
		Arrays.sort(irank, new Comparator<Integer>(){
			public int compare(Integer a, Integer b)
			{
				return str[a] - str[b];
			}
		});
		int[] rank = new int[n];
		for(int j = 1;j < n;j++){
			rank[irank[j]] = rank[irank[j-1]] + (str[irank[j - 1]] == str[irank[j]] ? 0 : 1);
		}
		
		for(int i = 1;i < n;i *= 2){
			Comp comp = new Comp(rank, i, n);
			Arrays.sort(irank, comp);
			for(int j = 1;j < n;j++){
				rank[irank[j]] = rank[irank[j-1]] + (comp.compare(irank[j - 1], irank[j]) == 0 ? 0 : 1);
			}
		}
		
		return rank;
	}
	
	public static class Comp implements Comparator<Integer>
	{
		public int[] rank;
		public int[] rank2;
		
		public Comp(int[] rank, int len, int n)
		{
			this.rank = rank;
			rank2 = new int[n];
			for(int i = 0;i + len < n;i++){
				rank2[i] = rank[i + len];
			}
			Arrays.fill(rank2, n - len, n, -1);
		}
		
		public int compare(Integer a, Integer b)
		{
			if(rank[a] != rank[b])return rank[a] - rank[b];
			return rank2[a] - rank2[b];
		}
	}
	
	public static void main(String[] args) throws Exception
	{
		new C2().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}