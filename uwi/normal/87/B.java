//package round73;
import java.io.PrintWriter;
import java.util.Arrays;
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
		Map<String, Integer> map = new HashMap<String, Integer>();
		map.put("void", 0);
		map.put("errtype", -99);
		for(int i = 0;i < n;i++){
			String com = in.next();
			if(com.equals("typedef")){
				String A = in.next();
				String B = in.next();
				int amp, ast;
				for(amp = 0; amp < A.length() && A.charAt(amp) == '&';amp++);
				for(ast = A.length()-1; ast >= 0 && A.charAt(ast) == '*';ast--);
				String T = A.substring(amp, ast+1);
				ast = A.length() - 1 - ast;
				Integer rank = map.get(T);
				if(rank == null)rank = -99;
				if(rank > -99){
					rank -= amp;
					rank += ast;
					if(rank < 0)rank = -99;
				}
				map.put(B, rank);
			}else{
				String A = in.next();
				int amp, ast;
				for(amp = 0; amp < A.length() && A.charAt(amp) == '&';amp++);
				for(ast = A.length()-1; ast >= 0 && A.charAt(ast) == '*';ast--);
				String T = A.substring(amp, ast+1);
				ast = A.length() - 1 - ast;
				Integer rank = map.get(T);
				if(rank == null)rank = -99;
				if(rank > -99){
					rank -= amp;
					rank += ast;
					if(rank < 0)rank = -99;
				}
				
				if(rank < 0){
					out.println("errtype");
				}else{
					out.print("void");
					for(int j = 0;j < rank;j++){
						out.print("*");
					}
					out.println();
				}
			}
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