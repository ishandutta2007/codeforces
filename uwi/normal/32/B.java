//package round32;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = ".-.--";
//	private String INPUT = "-..-.--";
	private String INPUT = "";
	
	public void solve()
	{
		char[] code = in.next().toCharArray();
		StringBuilder sb = new StringBuilder();
		
		int p = 0;
		while(p < code.length){
			if(code[p++] == '.'){
				sb.append('0');
			}else if(code[p++] == '.'){
				sb.append('1');
			}else{
				sb.append('2');
			}
		}
		out.println(sb.toString());
	}
	
	public void run() throws Exception
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
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}