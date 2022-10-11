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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		TreeSet<Integer>[] sets = new TreeSet[26];
		for(int i = 0; i < sets.length; i++)	{
			sets[i] = new TreeSet<Integer>();
		}
		String str = nextToken();
		for(int i = 0; i < str.length(); i++)	{
			sets[str.charAt(i)-'a'].add(i);
		}
		String goal = nextToken();
		int last = Integer.MAX_VALUE;
		int ret = 0;
		for(int i = 0; i < goal.length(); i++)	{
			if(sets[goal.charAt(i)-'a'].higher(last) == null) {
				ret++;
				last = -1;
				if(sets[goal.charAt(i)-'a'].higher(last) == null) {
					ret = -1;
					break;
				}
				else	{
					last = sets[goal.charAt(i)-'a'].higher(last);
				}
			}
			else	{
				last = sets[goal.charAt(i)-'a'].higher(last);
			}
		}
		pw.println(ret);
		pw.close();
	}

	
	/* NOTEBOOK CODE */

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