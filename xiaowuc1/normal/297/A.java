import java.awt.*; 
import java.awt.event.*; 
import java.awt.geom.*; 
import java.io.*; 
import java.math.*; 
import java.text.*; 
import java.util.*; 

/* 
br = new BufferedReader(new FileReader("input.txt")); 
pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt"))); 
br = new BufferedReader(new InputStreamReader(System.in)); 
pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
 */

public class Main { 
	private static BufferedReader br; 
	private static StringTokenizer st; 
	private static PrintWriter pw;

	static final long MOD = 1000000007;
	
	public static void main(String[] args) throws IOException   { 
		br = new BufferedReader(new InputStreamReader(System.in)); 
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
		//int qq = 1; 
		int qq = Integer.MAX_VALUE; 
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)   {
			String a = nextToken();
			String b = nextToken();
			a += count(a)%2;
			if(count(a) >= count(b)) {
				pw.println("YES");
			}
			else	{
				pw.println("NO");
			}
		}
		pw.close(); 
	} 

	public static int count(String str)	{
		int ret = 0;
		for(int i = 0; i < str.length(); i++)	{
			if(str.charAt(i) == '1') {
				ret++;
			}
		}
		return ret;
	}
	
	private static void exitImmediately()   { 
		pw.close(); 
		System.exit(0); 
	} 

	private static long readLong() throws IOException   { 
		return Long.parseLong(nextToken()); 
	} 

	private static double readDouble() throws IOException   { 
		return Double.parseDouble(nextToken()); 
	} 

	private static int readInt() throws IOException { 
		return Integer.parseInt(nextToken()); 
	} 

	private static String nextToken() throws IOException    { 
		while(st == null || !st.hasMoreTokens())    { 
			if(!br.ready()) { 
				exitImmediately(); 
			} 
			st = new StringTokenizer(br.readLine().trim()); 
		} 
		return st.nextToken(); 
	} 
}