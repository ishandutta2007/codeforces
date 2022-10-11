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
		int n = readInt();
		long k = readLong();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		for(int qq = 0; qq < 100; qq++)	{ // Arrays.sort must run in O(N log N)!
			int a = (int)(n*Math.random());
			int b = (int)(n*Math.random());
			if(a != b)	{
				list[a] ^= list[b];
				list[b] ^= list[a];
				list[a] ^= list[b];
			}
		}
		Arrays.sort(list);
		int left = 0;
		int dec = 0;
		for(int i = 0; i < n;)	{
			int j = i+1;
			while(j < list.length && list[i] == list[j])	{
				j++;
			}
			if((j-i)*1L*n >= k)	{
				left = list[i];
				dec = j-i;
				break;
			}
			k -= (j-i)*1L*n;
			i = j;
		}
		for(int i = 0; i < n; i++)	{
			if(k <= dec)	{
				pw.println(left + " " + list[i]);
				break;
			}
			k -= dec;
		}
		pw.close();
	}

	public static String replace(String ret, char dig)	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < ret.length();)	{
			if(i+2 < ret.length() && ret.substring(i, i+3).equals(". " + dig))	{
				sb.append("." + dig);
				i += 3;
			}
			else	{
				sb.append(ret.charAt(i++));
			}
		}
		return sb.toString();
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