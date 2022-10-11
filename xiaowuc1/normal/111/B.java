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

	public static void main(String[] args) throws IOException   { 
		br = new BufferedReader(new InputStreamReader(System.in)); 
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
		//int qq = 1; 
		int qq = Integer.MAX_VALUE; 
		//int qq = readInt(); 
		for(int casenum = 1; casenum <= qq; casenum++)   { 
			int n = readInt();
			int[] use = new int[100005];
			Arrays.fill(use, -1);
			for(int a = 0; a < n; a++) {
				int k = readInt();
				int back = readInt();
				ArrayList<Integer> fac = fact(k);
				int ret = 0;
				for(int out: fac) {
					if(use[out] < a - back) {
						ret++;
					}
					use[out] = a;
				}
				pw.println(ret);
			}
		} 
		pw.close(); 
	} 

	public static ArrayList<Integer> fact(int n) {
		ArrayList<Integer> ret = new ArrayList<Integer>();
		for(int i = 1; i*i <= n; i++) {
			if(n%i==0)	{
				ret.add(i);
				if(i*i!=n)
					ret.add(n/i);
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