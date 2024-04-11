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

	static String base = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String str = nextToken();
		String hour = str.substring(0, str.indexOf(":"));
		String min = str.substring(str.indexOf(":")+1);
		TreeSet<Integer> set = new TreeSet<Integer>();
		for(int base = 2; base <= 1000; base++)	{
			if(valid(hour,min,base))	{
				set.add(base);
			}
		}
		if(set.size() > 100)	{
			pw.println(-1);
		}
		else if(set.isEmpty())	{
			pw.println(0);
		}
		else	{
			StringBuilder sb = new StringBuilder();
			for(int out: set)
				sb.append(out + " ");
			pw.println(sb.toString().trim());
		}
		pw.close(); 
	}

	public static boolean valid(String h, String m, int b)	{
		return is(h,b,24) && is(m,b,60);
	}
	
	public static boolean is(String s, int b, int max)	{
		int curr = 0;
		for(int i = 0; i < s.length(); i++)	{
			curr *= b;
			if(curr >= max)
				return false;
			int next = base.indexOf(String.valueOf(s.charAt(i)));
			if(next >= b)
				return false;
			curr += next;
		}
		return curr < max;
	}
	
	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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