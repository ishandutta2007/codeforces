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

	static int[] list;

	static final long MOD = 1000000007;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		list = new int[n];
		while(n-- > 0)	{
			q.add(readInt());
		}
		for(int i = 0; i < list.length; i++)	{
			list[i] = q.poll();
		}
		long ret = 0;
		for(int i = 1; i <= list[list.length-1]; i++)	{
			ret += solve(i);
			ret %= MOD;
		}
		pw.println(ret);
		pw.close(); 
	}

	public static long solve(int curr)	{
		long ret = 1;
		ArrayList<Integer> factors = new ArrayList<Integer>();
		for(int i = 1; i * i <= curr; i++)	{
			if(curr%i==0)	{
				factors.add(i);
				if(i*i!=curr)	{
					factors.add(curr/i);
				}
			}
		}
		Collections.sort(factors);
		int lastIndex = 0;
		for(int i = 1; i < factors.size(); i++)	{
			int min = 0;
			int max = list.length-1;
			while(min != max)	{
				int mid = (min+max)/2;
				if(list[mid] < factors.get(i))		{
					min = mid+1;
				}
				else	{
					max = mid;
				}
			}
			ret *= pow(i, max - lastIndex);
			ret %= MOD;
			lastIndex = max;
		}
		int numLeft = list.length - lastIndex;
		long other = pow(factors.size(), numLeft) - pow(factors.size()-1, numLeft);
		while(other < 0)
			other += MOD;
		other %= MOD;
		ret *= other;
		ret %= MOD;
		return ret;
	}

	public static long pow(int b, int e)	{
		if(e == 0)	{
			return 1;
		}
		if(e%2==0)	{
			long r = pow(b,e/2);
			return (r*r)%MOD;
		}
		return (b*pow(b,e-1))%MOD;
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