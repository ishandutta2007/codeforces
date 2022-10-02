//package round21;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "mike@codeforces.com";
//	private String INPUT = "j_s@c.r/c_i";
//	private String INPUT = "007@a.b.c.d.e./contest";
	private String INPUT = "";
	
	public void solve()
	{
		String s = in.next();
		int uh = s.indexOf('@');
		if(uh == -1){
			out.println("NO"); return;
		}
		int hr = s.indexOf('/', uh);
		
		if(!checkUser(s.substring(0, uh))){
			out.println("NO"); return;
		}
		
		int last = hr != -1 ? hr : s.length();
		String host = s.substring(uh + 1, last);
		if(host.indexOf("..") > -1 || host.endsWith(".") || host.startsWith(".")){
			out.println("NO"); return;
		}
		
		if(host.length() == 0 || host.length() > 32){
			out.println("NO"); return;
		}
		String[] hosts = host.split("\\.");
		for(String sh : hosts){
			if(!checkUser(sh)){
				out.println("NO"); return;
			}
		}
		
		if(hr != -1){
			String resource = s.substring(hr + 1);
			if(!checkUser(resource)){
				out.println("NO"); return;
			}
		}
		
		out.println("YES");
	}
	
	private boolean checkUser(String s)
	{
		if(s.length() == 0 || s.length() > 16){
			return false;
		}
		for(int i = 0;i < s.length();i++){
			char c = s.charAt(i);
			if(!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '_' || (c >= '0' && c <= '9'))){
				return false;
			}
		}
		return true;
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}