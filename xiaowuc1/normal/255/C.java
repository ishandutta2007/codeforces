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
		Set<Integer> exact = new TreeSet<Integer>();
		int n = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
			exact.add(list[i]);
		}
		int[] sorted = new int[exact.size()];
		int qq = 0;
		for(int out: exact)	{
			sorted[qq++] = out;
		}
		ArrayList<Integer>[] lists = new ArrayList[sorted.length];
		for(int i = 0; i < lists.length; i++)	{
			lists[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < n; i++)	{
			lists[Arrays.binarySearch(sorted, list[i])].add(i);
		}
		int ret = 1;
		for(int i = 0; i < lists.length; i++)	{
			for(int j = 0; j < lists.length; j++)	{
				int first = 0;
				int second = 0;
				int curr = 1;
				boolean firstGo = false;
				while(true)	{
					if(firstGo)	{
						while(first < lists[i].size() && lists[i].get(first) <= lists[j].get(second))
							first++;
						if(first == lists[i].size())
							break;
						curr++;
					}
					else	{
						while(second < lists[j].size() && lists[j].get(second) <= lists[i].get(first))
							second++;
						if(second == lists[j].size())
							break;
						curr++;
					}
					firstGo = !firstGo;
				}
				ret = Math.max(ret, curr);
			}
		}
		pw.println(ret);
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