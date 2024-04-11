//package croc2013.q;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class B {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	void solve() throws Exception
	{
		char[] line = br.readLine().toCharArray();
		int dep = 0;
		StringBuilder sb = new StringBuilder();
		List<String> l = new ArrayList<String>();
		for(char c : line){
			if(c == ' ' && dep == 0){
				if(sb.length() > 0){
					l.add(sb.toString());
					sb = new StringBuilder();
				}
				continue;
			}
			
			if(c == '"'){
				dep ^= 1;
			}
			sb.append(c);
		}
		if(sb.length() > 0){
			l.add(sb.toString());
		}
		
		for(String s : l){
			if(s.length() >= 1 && s.charAt(0) == '"'){
				out.println("<" + s.substring(1, s.length()-1) + ">");
			}else{
				out.println("<" + s + ">");
			}
		}
	}
	
	void run() throws Exception
	{
		long S = System.currentTimeMillis();
		br = new BufferedReader(INPUT.isEmpty() ? new InputStreamReader(System.in) : new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
		long G = System.currentTimeMillis();
		tr(G-S+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new B().run();
	}
	
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}