//package round31;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class B {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "a@aa@a";
//	private String INPUT = "a@a@a@a@a@a";
//	private String INPUT = "ab@abc@abc";
//	private String INPUT = "a@aa@a";
	private String INPUT = "";
	
	public void solve()
	{
		char[] str = in.next().toCharArray();
		StringBuilder sb = new StringBuilder();
		int state = -1; // 012 a@a
		int len = 0;
		for(int i = 0;i < str.length;i++){
			if(state == -1){
				if(str[i] == '@'){ out.println("No solution"); return;}
				state = 0;
			}else if(state == 0){
				if(str[i] == '@'){
					state = 1;
				}
			}else if(state == 1){
				if(str[i] == '@'){ out.println("No solution"); return;}
				state = 2;
			}else if(state == 2){
				if(str[i] == '@'){ out.println("No solution"); return;}
				int j;
				for(j = i;j < str.length;j++){
					if(str[j] == '@'){
						sb.append(',');
						state = 0;
						break;
					}
				}
			}
			sb.append(str[i]);
		}
		if(state != 2){
			out.println("No solution"); return;
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