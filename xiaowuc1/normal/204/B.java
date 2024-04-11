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
		Set<Integer> set = new TreeSet<Integer>();
		TreeMap<Integer, Integer> guarantee = new TreeMap<Integer, Integer>();
		TreeMap<Integer, Integer> front = new TreeMap<Integer, Integer>();
		TreeMap<Integer, Integer> back = new TreeMap<Integer, Integer>();
		int n = readInt();
		for(int i = 0; i < n; i++)	{
			int f = readInt();
			int b = readInt();
			set.add(f);
			set.add(b);
			if(f == b)	{
				add(guarantee, f);
			}
			else	{
				add(front, f);
				add(back, b);
			}
		}
		int need = (n+1)/2;
		int ret = Integer.MAX_VALUE;
		for(int key: set)	{
			int know = get(guarantee, key);
			know += get(front, key);
			if(know >= need)	{
				ret = 0;
			}
			else	{
				int want = need - know;
				if(get(back, key) >= want){
					ret = Math.min(ret, want);
				}
			}
		}
		if(ret == Integer.MAX_VALUE)	{
			ret = -1;
		}
		pw.println(ret);
		pw.close();
	}

	public static void add(Map<Integer, Integer> map, int key)	{
		Integer ret = map.get(key);
		if(ret == null)	{
			ret = 0;
		}
		ret++;
		map.put(key, ret);
	}
	
	public static int get(Map<Integer, Integer> map, int key)	{
		Integer ret = map.get(key);
		if(ret == null)	{
			ret = 0;
		}
		return ret;
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