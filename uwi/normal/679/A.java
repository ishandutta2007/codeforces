//package round356;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class AT {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "yes no no no no no no no no no no no no no no no";
	
	void solve()
	{
		boolean[] cur = new boolean[101];
		for(int i = 2;i <= 100;i++){
			cur[i] = true;
		}
		long[] isp = isp(100);
		
		int step = 0;
		while(true){
			last = -1;
			boolean res = dfs(cur, isp, step);
			assert res;
			if(last == -1){
				out.println(hasnp ? "composite" : "prime");
				break;
			}
			out.println(last);
			out.flush();
			String judge = in.next();
			if(judge.equals("yes")){
				for(int j = 2;j <= 100;j++){
					if(cur[j]){
						if(j % last == 0){
							cur[j] = true;
						}else{
							cur[j] = false;
						}
					}
				}
			}else{
				for(int j = 2;j <= 100;j++){
					if(cur[j]){
						if(j % last == 0){
							cur[j] = false;
						}else{
							cur[j] = true;
						}
					}
				}
			}
			step++;
		}
	}
	
	int last = -1;
	boolean hasp = false, hasnp = false;
	
	boolean dfs(boolean[] a, long[] isp, int count)
	{
		if(count > 20)return false;
		int nt = 0;
		hasp = false;
		hasnp = false;
		for(int i = 2;i <= 100;i++){
			if(a[i]){
				nt++;
				if(isp[i>>>6]<<~i<0){
					hasp = true;
				}else{
					hasnp = true;
				}
			}
			
		}
		if(hasp && !hasnp)return true;
		if(!hasp && hasnp)return true;
		
		for(int i = 2;i <= 100;i++){
			boolean[] ok = new boolean[101];
			boolean[] ng = new boolean[101];
			boolean pok = false, png = false;
			for(int j = 2;j <= 100;j++){
				if(a[j]){
					if(j % i == 0){
						ok[j] = true;
						pok = true;
					}else{
						ng[j] = true;
						png = true;
					}
				}
			}
			if(pok && png){
				if(dfs(ok, isp, count+1) && dfs(ng, isp, count+1)){
					last = i;
					return true;
				}
			}
		}
		return false;
	}
	
	
	public static long[] isp(int n)
	{
		int[] tprimes = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61};
		if(n <= 64){
			long ptn = 0;
			for(int p : tprimes)if(p <= n)ptn |= 1L<<p;
			return new long[]{ptn};
		}
		
		long[] isnp = new long[(n+1)/64+1];
		int sup = (n+1)/64+1;
		
		isnp[0] |= 1<<1;
		for(int tp : tprimes){
			long[] ptn = new long[tp];
			for(int i = 0;i < tp<<6;i+=tp)ptn[i>>>6] |= 1L<<i;
			for(int j = 0;j < sup;j += tp){
				for(int i = 0;i < tp && i+j < sup;i++){
					isnp[j+i] |= ptn[i];
				}
			}
		}
		
		final int[] magic = {0, 1, 2, 53, 3, 7, 54, 27, 4, 38, 41, 8, 34, 55, 48, 28, 62, 5, 39, 46, 44, 42, 22, 9, 24, 35, 59, 56, 49, 18, 29, 11, 63, 52, 6, 26, 37, 40, 33, 47, 61, 45, 43, 21, 23, 58, 17, 10, 51, 25, 36, 32,
	              60, 20, 57, 16, 50, 31, 19, 15, 30, 14, 13, 12};
		out:
		for(int i = 0;i < sup;i++){
			for(long j = ~isnp[i];j != 0;j &= j-1){
				int p = i<<6|magic[(int)((j&-j)*0x022fdd63cc95386dL>>>58)];
				if((long)p*p > n)break out;
				for(int q = p*p;q <= n;q += p)isnp[q>>6] |= 1L<<q;
			}
		}
		
		for(int i = 0;i < isnp.length;i++)isnp[i] = ~isnp[i];
		for(int tp : tprimes)isnp[0] |= 1L<<tp;
		isnp[isnp.length-1] &= (1L<<n+1)-1;
		
		return isnp;
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
		new AT().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}