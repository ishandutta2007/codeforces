//package round71;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C4 {
	Scanner in;
	PrintWriter out;
//	String INPUT = "abcabcabcabc 3 abcabca bcab cabc";
//	String INPUT = "ThankYouForParticipatingRound71\r\n" + 
//			"\r\n" + 
//			"6\r\n" + 
//			"\r\n" + 
//			"ForP\r\n" + 
//			"\r\n" + 
//			"oun\r\n" + 
//			"\r\n" + 
//			"nkYouForP\r\n" + 
//			"\r\n" + 
//			"Tha\r\n" + 
//			"\r\n" + 
//			"ouForP\r\n" + 
//			"\r\n" + 
//			"ound7";
//	String INPUT = "Z 1 b";
//	String INPUT = "Go_straight_along_this_street\r\n" + 
//			"5\r\n" + 
//			"str\r\n" + 
//			"long\r\n" + 
//			"tree\r\n" + 
//			"biginteger\r\n" + 
//			"ellipse";
//	String INPUT = "alones 2 lo es";
//	String INPUT = "aaaay 5 aa aa ay aaa aaay";
	String INPUT = "";
	
	void solve()
	{
		char[] line = in.next().toCharArray();
		int m = line.length;
		int n = ni();
		char[][] ng = new char[n][];
		for(int i = 0;i < n;i++) {
			ng[i] = in.next().toCharArray();
		}
		
		int p = 0;
		int max = 0;
		int pos = 0;
		for(int q = 0;q < m;q++) {
			for(int i = 0;i < n;i++) {
				if(eq(line, q-ng[i].length+1, ng[i])) {
					p = Math.max(p, q-ng[i].length+2);
				}
			}
			if(max < q-p+1) {
				max = q-p+1;
				pos = p;
			}
		}
		out.println(max + " " + pos);
	}
	
	boolean eq(char[] str, int start, char[] ng)
	{
		int n = str.length;
		if(start < 0 || start + ng.length > n)return false;
		for(int i = 0;i < ng.length;i++) {
			if(ng[i] != str[start+i])return false;
		}
//		tr("oh", new String(ng), start);
		return true;
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
		new C4().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}