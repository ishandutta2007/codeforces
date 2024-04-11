//package round48;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class B2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		StringBuilder sb = new StringBuilder();
		while(in.hasNext()){
			sb.append(in.next());
		}
		hstr = sb.toString();
		html = sb.toString().toCharArray();
		ret = new ArrayList<Integer>();
		pos = 0;
		table();
		Collections.sort(ret);
		for(int q : ret){
			out.print(q + " ");
		}
		out.println();
	}
	
	String hstr;
	char[] html;
	List<Integer> ret;
	int pos;
	
	void table()
	{
		pos += 7;
		int d = rows();
		ret.add(d);
		pos += 8;
	}
	
	int rows()
	{
		int ct = 0;
		while(true){
			int d = row();
			ct += d;
			if(hstr.substring(pos, pos + 8).equals("</table>")){
				return ct;
			}
		}
	}
	
	int row()
	{
		pos += 4;
		int d = cells();
		pos += 5;
		return d;
	}
	
	int cells()
	{
		int ct = 0;
		while(true){
			cell();
			ct++;
			if(hstr.substring(pos, pos + 5).equals("</tr>")){
				return ct;
			}
		}
	}
	
	void cell()
	{
		if(hstr.substring(pos + 4, pos + 9).equals("</td>")){
			pos += 9;
		}else{
			pos += 4;
			table();
			pos += 5;
		}
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
		new B2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}