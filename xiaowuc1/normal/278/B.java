import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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

	static Set<String> seen;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			seen = new HashSet<String>();
			while(n-- > 0)	{
				String str = nextToken();
				for(int i = 0; i < str.length(); i++)	{
					for(int j = i+1; j <= str.length(); j++)	{
						seen.add(str.substring(i,j));
					}
				}
			}
			for(int l = 1; l <= 30; l++)	{
				if(can("", l))	{
					break;
				}
			}
		}
		pw.close();
	}

	public static boolean can(String go, int len)	{
		if(go.length() == len)	{
			if(seen.contains(go))	{
				return false;
			}
			pw.println(go);
			return true;
		}
		for(char ch = 'a'; ch <= 'z'; ch++)	{
			if(can(go+ch,len))	{
				return true;
			}
		}
		return false;
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