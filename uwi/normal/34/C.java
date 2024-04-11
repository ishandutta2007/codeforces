//package round34;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "1,2,3,1,1,2,6,6,2";
	private String INPUT = "";
	
	public void solve()
	{
		String[] seq = in.next().split(",");
		BitSet used = new BitSet();
		for(String t : seq){
			used.set(Integer.parseInt(t));
		}
		StringBuilder sb = new StringBuilder();
		boolean f = true;
		for(int i = used.nextSetBit(0);i != -1;i = used.nextSetBit(i+1)){
			if(f){
				f = false;
			}else{
				sb.append(',');
			}
			int j = used.nextClearBit(i);
			if(j > i + 1){
				sb.append(i + "-" + (j-1));
				i = j;
			}else{
				sb.append(i);
			}
		}
		out.println(sb);
	}
	
	public void run() throws Exception
	{
//		StringBuilder sb = new StringBuilder();
//		for(int i = 0;i < 100;i++){
//			sb.append("1000");
//			if(i < 99)sb.append(',');
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new C().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}