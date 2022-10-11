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

	static final long HASH = 3137;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		long[] pow = new long[1000010];
		pow[0] = 1;
		for(int i = 1; i < pow.length; i++)	{
			pow[i] = pow[i-1] * HASH;
		}
		String str = nextToken();
		long[] hash = new long[str.length()+1];
		for(int i = 0; i < str.length(); i++)	{
			hash[i+1] = hash[i] * HASH + str.charAt(i);
		}
		ArrayList<Integer> valid = new ArrayList<Integer>();
		for(int len = 1; len <= str.length()-2; len++)	{
			long prefix = hash[len];
			long suffix = hash[str.length()] - hash[str.length()-len] * pow[len];
			if(prefix == suffix)	{
				valid.add(len);
			}
		}
		int min = -1;
		int max = valid.size()-1;
		while(min != max)		{
			int mid = (min+max)/2;
			if(min == mid)	{
				mid++;
			}
			int len = valid.get(mid);
			boolean can = false;
			for(int k = 1; !can && k + len < str.length(); k++)	{
				long curr = hash[k+len] - hash[k] * pow[len];
				can = curr == hash[len];
			}
			if(can)	{
				min = mid;
			}
			else	{
				max = mid-1;
			}
		}
		if(min == -1)
			pw.println("Just a legend");
		else
			pw.println(str.substring(0,valid.get(min)));
		pw.close();
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