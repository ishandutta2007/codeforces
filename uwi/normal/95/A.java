//package round77;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		String[] fb = new String[n];
		for(int i = 0;i < n;i++){
			fb[i] = in.next().toLowerCase();
		}
		String s = in.next();
		String sl = s.toLowerCase();
		char T = in.next().toLowerCase().charAt(0);
		char U = 'a';
		if(U == T)U = 'b';
		BitSet bs = new BitSet();
		for(int i = 0;i < n;i++){
			int ind = -1;
			while((ind = sl.indexOf(fb[i], ind+1)) != -1){
				bs.set(ind, ind+fb[i].length());
			}
		}
		char[] sc = s.toCharArray();
		for(int i = bs.nextSetBit(0);i != -1;i = bs.nextSetBit(i + 1)){
			if(sl.charAt(i) != T){
				if(Character.isUpperCase(sc[i])){
					sc[i] = (char)(T-'a'+'A');
				}else{
					sc[i] = T;
				}
			}else{
				if(Character.isUpperCase(sc[i])){
					sc[i] = (char)(U-'a'+'A');
				}else{
					sc[i] = U;
				}
			}
		}
		out.println(new String(sc));
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}