//package round646;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class D {
	Scanner in;
	PrintWriter out;
	// 4 2 1 3 9
	String INPUT = "";
	
	void solve()
	{
		for(int T = ni();T > 0;T--)go();
	}
	
	int get(int l, int r, int[] clus)
	{
		StringBuilder sb = new StringBuilder();
		int ct = 0;
		for(int i = 0;i < clus.length;i++){
			if(l <= clus[i] && clus[i] < r){
				sb.append(" " + (i+1));
				ct++;
			}
		}
		if(ct == 0){
			return -2;
		}
		out.println("? " + ct + sb);
		out.flush();
		return ni();
	}
	
	int getout(int ng, int[] clus)
	{
		StringBuilder sb = new StringBuilder();
		int ct = 0;
		for(int i = 0;i < clus.length;i++){
			if(clus[i] != ng){
				sb.append(" " + (i+1));
				ct++;
			}
		}
		if(ct == 0){
			return -2;
		}
		out.println("? " + ct + sb);
		out.flush();
		return ni();
	}
	
	void go()
	{
		int n = ni(), K = ni();
		int[] clus = new int[n];
		for(int i = 1;i <= K;i++){
			int t = ni();
			for(int j = 0;j < t;j++){
				clus[ni()-1] = i;
			}
		}
		
		int amax = get(0, K+1, clus);
		int l = 0, r = K+1;
		while(r-l > 1){
			int h = l+r>>1;
			if(get(l, h, clus) == amax){
				r = h;
			}else{
				l = h;
			}
		}
		
		int pmax = getout(l, clus);
		
		out.print("!");
		for(int i = 1;i <= K;i++){
			if(i == l){
				out.print(" " + pmax);
			}else{
				out.print(" " + amax);
			}
		}
		out.println();
		out.flush();
		in.next();
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