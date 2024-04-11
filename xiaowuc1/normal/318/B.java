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
			String str = nextToken();
			LinkedList<Integer> a = new LinkedList<Integer>();
			LinkedList<Integer> b = new LinkedList<Integer>();
			for(int i = 0; i + 5 <= str.length(); i++)	{
				if(str.substring(i,i+5).equals("heavy")) {
					a.addLast(i);
				}
				if(str.substring(i,i+5).equals("metal")) {
					b.addLast(i);
				}
			}
			long ret = 0;
			while(!a.isEmpty())	{
				int curr = a.removeFirst();
				while(!b.isEmpty() && b.peekFirst() < curr) {
					b.removeFirst();
				}
				ret += b.size();
			}
			pw.println(ret);
		}
		pw.close(); 
	} 

	public static long inv(long a)	{
		return modpow(a, MOD-2, MOD);
	}
	
	public static long modpow(long b, long e, long m)	{
		long r = 1;
		while(e > 0)	{
			if(e%2==1)	{
				r *= b;
				r %= m;
			}
			b *= b;
			b %= m;
			e >>= 1;
		}
		return r;
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