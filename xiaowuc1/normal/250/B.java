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
		while(n-- > 0)	{
			solve(nextToken());
		}
		pw.close(); 
	}

	public static void solve(String str)	{
		ArrayList<String> list = new ArrayList<String>();
		while(str.length() > 0)	{
			if(str.length() >= 2 && str.charAt(0) == ':' && str.charAt(1) == ':')	{
				list.add("::");
				str=str.substring(2);
			}
			else if(str.indexOf(":") == -1)	{
				list.add(str);
				str = "";
			}
			else if(str.charAt(0) == ':'){
				str = str.substring(1);
			}
			else	{
				list.add(str.substring(0, str.indexOf(":")));
				str = str.substring(str.indexOf(":"));
			}
		}
		ArrayList<String> next = new ArrayList<String>();
		int numZero = 9 - list.size();
		for(int i = 0; i < list.size(); i++)	{
			if(list.get(i).equals("::")){
				while(numZero-- > 0)
					next.add("0000");
			}
			else	{
				next.add(list.get(i));
			}
		}
		pw.print(gen(next.get(0)));
		for(int i = 1; i < next.size(); i++)	{
			pw.print(":"+gen(next.get(i)));
		}
		pw.println();
	}

	public static String gen(String str)	{
		while(str.length() < 4)
			str = '0' + str;
		return str;
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