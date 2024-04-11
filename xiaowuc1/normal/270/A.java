import java.awt.*;
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

	static int[] dx = new int[]{-1,0,0,0,1};
	static int[] dy = new int[]{0,-1,0,1,0};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		//int qq = Integer.MAX_VALUE;
		int qq = readInt();
		Set<Integer> set = new HashSet<Integer>();
		for(int i = 3; i <= 10000; i++)	{
			int num = 180 * (i-2);
			if(num % i == 0)	{
				set.add(num/i);
			}
		}
		for(int casenum = 1; casenum <= qq; casenum++)	{
			pw.println(set.contains(readInt()) ? "YES" : "NO");
		}
		pw.close();
	}

	public static boolean good(int curr)	{
		String ret = String.valueOf(curr);
		Set<Character> set = new HashSet<Character>();
		for(int i = 0; i < ret.length(); i++)	{
			set.add(ret.charAt(i));
		}
		return set.size() == ret.length();
	}
	
	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}