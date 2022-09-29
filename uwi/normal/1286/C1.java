//package round612;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class C1 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Map<String, Integer> whole = new HashMap<>();
		out.println("? 1 " + n);
		out.flush();
		String[] ws = new String[n*(n+1)/2];
		for(int i = 0;i < n*(n+1)/2;i++) {
			char[] s = in.next().toCharArray();
			Arrays.sort(s);
			ws[i] = new String(s);
		}
		if(n == 1) {
			out.println("! " + ws[0]);
			out.flush();
			return;
		}
		for(String w : ws) {
			if(whole.containsKey(w)) {
				whole.put(w, whole.get(w) + 1);
			}else {
				whole.put(w, 1);
			}
		}
		
		out.println("? 2 " + n);
		out.flush();
		String[] mws = new String[n*(n-1)/2];
		for(int i = 0;i < n*(n-1)/2;i++) {
			char[] s = in.next().toCharArray();
			Arrays.sort(s);
			mws[i] = new String(s);
		}
		for(String w : mws) {
			whole.put(w, whole.get(w) - 1);
		}
		
		String[] pre = new String[n+1];
		for(String k : whole.keySet()) {
			if(whole.get(k) > 0) {
				pre[k.length()] = k;
			}
		}
		char[] ans = new char[n];
		ans[0] = pre[1].charAt(0);
		for(int i = 1;i <= n-1;i++) {
			int x = 0;
			for(char c : pre[i].toCharArray()) x ^= c;
			for(char c : pre[i+1].toCharArray()) x ^= c;
			ans[i] = (char)x;
		}
		out.println("! " + new String(ans));
		out.flush();
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
		new C1().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}