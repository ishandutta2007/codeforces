//package round64;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
//	String INPUT = "132 10 35";
//	String INPUT = "100000 100000 1300000";
	String INPUT = "";
	
	void solve()
	{
		int mx = ni();
		int my = ni();
		final int[] num = new int[100001];
		final int[] den = new int[100001];
		for(int i = 1;i <= 100000;i++){
			int r = rev(i);
			int g = gcd(i, r);
			num[i] = i / g;
			den[i] = r / g;
		}
		Integer[] ord = new Integer[100000];
		for(int i = 0;i < 100000;i++)ord[i] = i+1;
		Arrays.sort(ord, new Comparator<Integer>(){
			public int compare(Integer x, Integer y)
			{
				return Long.signum((long)num[x] * den[y] - (long)num[y] * den[x]);
			}
		});
		
		int count = 0;
		int[][] ok = new int[100001][];
		for(int i = 0, j = 99999;i < 100000 && j >= 0;){
			long s = (long)num[ord[i]] * num[ord[j]] - (long)den[ord[j]] * den[ord[i]];
			if(s < 0){
				i++;
				continue;
			}else if(s > 0){
				j--;
				continue;
			}else{
				int k, l;
				for(k = i;k < 100000 && num[ord[i]] == num[ord[k]] && den[ord[i]] == den[ord[k]];k++);
				for(l = j;l >= 0 && num[ord[j]] == num[ord[l]] && den[ord[j]] == den[ord[l]];l--);
				int nj = j-l;
				int[] row = new int[nj];
				for(int n = j;n > l;n--){
					row[j-n] = ord[n];
				}
				Arrays.sort(row);
				for(int m = i;m < k;m++){
					ok[ord[m]] = row;
				}
				count += (k-i)*(j-l);
				i = k;
				j = l;
			}
		}
		
		int w = ni();
		long minxy = Long.MAX_VALUE;
		int ox = -1, oy = -1;
		int[] ft = new int[(1<<17)+1];
		int[] ss = new int[(1<<17)+1];
		
		for(int i = 1;i <= mx;i++){
			if(ok[i] == null)continue;
			for(int o : ok[i]){
				ss[o]++;
				ft[o]++;
				for(int j = 1;j < 1<<17;j<<=1){
					if((o&j)!=0){
						o += j;
						if(o <= 1<<17)ft[o]++;
					}
				}
			}
			
			int low = 0;
			int high = 100002;
			while(high - low > 1){
				int sum = 0;
				int mid = (low+high)/2;
				int t = mid;
				for(;t > 0;t &= t - 1){
					sum += ft[t];
				}
//				tr(mid, sum);
				if(sum >= w){
					high = mid;
				}else{
					low = mid;
				}
			}
			if(high == 100002)continue;
			for(;high >= 0 && ss[high] == 0;high--);
			
			int y = high;
			if(y > my)continue;
			long xy = (long)i*y;
			if(minxy > xy){
				minxy = xy;
				ox = i;
				oy = y;
			}
			
		}
		if(ox == -1){
			out.println(-1);
		}else{
			out.println(ox + " " + oy);
		}
	}
	
	public int[] ft;
	
	public class FenwickTree {
		public int[] a;
		public int[] ft;
		public int N;
		
		public FenwickTree(int[] a)
		{
			this.a = a;
			N = a.length;
			ft = new int[N];
			for(int i = 0;i < N;i++){
				ft[i] = a[i];
				for(int j = 1;(i&j) != 0;j<<=1){
					ft[i] += ft[i^j];
				}
			}
		}
		
		public int sum(int t)
		{
			int sum = 0;
			for(t++;t > 0;t &= t - 1){
				sum += ft[t-1];
			}
			return sum;
		}
	}
	
	public static int gcd(int a, int b) {
		while (b > 0){
			int c = a;
			a = b;
			b = c % b;
		}
		return a;
	}
	
	int rev(int n)
	{
		return Integer.parseInt(new StringBuilder(Integer.toString(n)).reverse().toString());
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}