//package round12;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		String sm = in.next();
		int m = Integer.parseInt(sm);
		char[] s = Integer.toString(n).toCharArray();
		if(s.length != sm.length()){
			out.println("WRONG_ANSWER");
			return;
		}
		
		Arrays.sort(s);
		for(int i = 0;i < s.length;i++){
			if(s[i] != '0'){
				char d = s[i];s[i] = s[0];s[0] = d;
				break;
			}
		}
		int sn = Integer.parseInt(new String(s));
		if(sn == m){
			out.println("OK");
		}else{
			out.println("WRONG_ANSWER");
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
		new B().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}