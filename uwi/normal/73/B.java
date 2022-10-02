//package round66;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Map<String, Integer> teamind = new HashMap<String, Integer>();
		final int[] a = new int[n];
		final String[] tn = new String[n];
		for(int i = 0;i < n;i++){
			String name = in.next();
			tn[i] = name;
			teamind.put(name, i);
			a[i] = ni();
		}
		int m = ni();
		int[] b = new int[m];
		int max = 0;
		int min = 9999999;
		for(int i = 0;i < m;i++){
			b[i] = ni();
			max = Math.max(max, b[i]);
			min = Math.min(min, b[i]);
		}
		Arrays.sort(b);
		if(m == 0)min = 0;
		String vn = in.next();
		int vind = teamind.get(vn);
		
		int vlow = a[vind] + (m < n ? 0 : min);
		int vhigh = a[vind] + max;
		
		Integer[] ord = new Integer[n];
		for(int i = 0;i < n;i++)ord[i] = i;
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer x, Integer y)
			{
				if(a[x] != a[y])return -(a[x] - a[y]);
				return tn[x].compareTo(tn[y]);
			}
		});
		
		int rankhigh = 1;
		int u = 0, v = 0;
		for(u = 0;u < n;u++){
			if(ord[u] == vind){
				continue;
			}
			int es = a[ord[u]];
			String en = tn[ord[u]];
			if(vhigh < es || vhigh == es && en.compareTo(vn) < 0){
				rankhigh++;
				v++;
			}else{
				break;
			}
		}
		for(int i = n-1, j = m-2;i >= u;i--){
			if(ord[i] == vind){
				continue;
			}
			int es = a[ord[i]] + (j >= v ? b[j] : 0);
			String en = tn[ord[i]];
			j--;
			if(vhigh < es || vhigh == es && en.compareTo(vn) < 0){
				rankhigh++;
			}
		}
		
		int ranklow = 1;
		for(int i = 0, j = (m==n ? 1 : 0);i < n;i++){
			if(ord[i] == vind){
				continue;
			}
			int es = a[ord[i]];
			String en = tn[ord[i]];
			if(vlow < es || vlow == es && en.compareTo(vn) < 0){
				ranklow++;
			}else{
				while(j < m){
					int nes = es + b[j];
					j++;
					if(vlow < nes || vlow == nes && en.compareTo(vn) < 0){
						ranklow++;
						break;
					}
				}
			}
		}
		out.println(rankhigh+ " " + ranklow);
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}