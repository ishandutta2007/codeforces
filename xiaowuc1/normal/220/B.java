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
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		int n = readInt();
		int qq = readInt();
		int[] list = new int[n];
		int[] count = new int[n+1];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
			if(list[i] <= n)
				count[list[i]]++;
		}
		int[] l = new int[qq];
		int[] r = new int[qq];
		for(int i = 0; i < qq; i++)	{
			l[i] = readInt();
			r[i] = readInt();
		}
		int[] ret = new int[qq];
		for(int curr = 1; curr <= n; curr++)	{
			if(count[curr] >= curr)	{
				int[] seen = new int[n+1];
				for(int i = 0; i < n; i++)	{
					seen[i+1] = seen[i];
					if(list[i] == curr)
						seen[i+1]++;
				}
				for(int i = 0; i < qq; i++)		{
					if(seen[r[i]] - seen[l[i]-1] == curr)
						ret[i]++;
				}
			}
		}
		for(int out: ret)
			pw.println(out);
		pw.close(); 
	}

	public static int findMax(ArrayList<Integer> list, int want)	{
		int min = 0;
		int max = list.size()-1;
		while(min <= max)	{
			int mid = (min+max)/2;
			if(list.get(mid) == want)
				return mid;
			if(list.get(mid) > want)
				max = mid-1;
			else
				min = mid+1;
		}
		return max;
	}

	public static int findMin(ArrayList<Integer> list, int want)	{
		int min = 0;
		int max = list.size()-1;
		while(min <= max)	{
			int mid = (min+max)/2;
			if(list.get(mid) == want)
				return mid;
			if(list.get(mid) < want)
				min = mid+1;
			else
				max = mid-1;
		}
		return min;
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