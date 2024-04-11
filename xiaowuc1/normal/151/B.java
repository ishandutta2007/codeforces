import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		String[][] grid = new String[n][];
		String[] name = new String[n];
		int[] total = new int[n];
		for(int i = 0; i < n; i++)	{
			total[i] = readInt();
			name[i] = nextToken();
			grid[i] = new String[total[i]];
			for(int a = 0; a < grid[i].length; a++)
				grid[i][a] = nextToken();
		}
		int taxi = 0;
		int pizza = 0;
		int cafe = 0;
		for(int i = 0; i < n; i++)	{
			int a = 0;
			int b = 0;
			int c = 0;
			for(String out: grid[i])	{
				if(taxi(out))
					a++;
				else if(pizza(out))
					b++;
				else
					c++;
			}
			taxi = Math.max(taxi, a);
			pizza = Math.max(pizza, b);
			cafe = Math.max(cafe, c);
		}
		ArrayList<String> ret = new ArrayList<String>();
		for(int i = 0; i < n; i++)	{
			int a = 0;
			for(String out: grid[i])	{
				if(taxi(out))
					a++;
			}
			if(a == taxi)
				ret.add(name[i]);
		}
		pw.print("If you want to call a taxi, you should call: ");
		for(int i = 0; i < ret.size()-1; i++)
			pw.print(ret.get(i) + ", ");
		pw.println(ret.get(ret.size()-1) + ".");
		ret = new ArrayList<String>();
		for(int i = 0; i < n; i++)	{
			int a = 0;
			for(String out: grid[i])	{
				if(pizza(out))
					a++;
			}
			if(a == pizza)
				ret.add(name[i]);
		}
		pw.print("If you want to order a pizza, you should call: ");
		for(int i = 0; i < ret.size()-1; i++)
			pw.print(ret.get(i) + ", ");
		pw.println(ret.get(ret.size()-1) + ".");
		ret = new ArrayList<String>();
		for(int i = 0; i < n; i++)	{
			int a = 0;
			for(String out: grid[i])	{
				if(!taxi(out) && !pizza(out))
					a++;
			}
			if(a == cafe)
				ret.add(name[i]);
		}
		pw.print("If you want to go to a cafe with a wonderful girl, you should call: ");
		for(int i = 0; i < ret.size()-1; i++)
			pw.print(ret.get(i) + ", ");
		pw.println(ret.get(ret.size()-1) + ".");
		
		pw.close();
	}

	
	public static boolean pizza(String a)	{
		if(a.charAt(0) <= a.charAt(1))
			return false;
		if(a.charAt(1) <= a.charAt(3))
			return false;
		if(a.charAt(3) <= a.charAt(4))
			return false;
		if(a.charAt(4) <= a.charAt(6))
			return false;
		if(a.charAt(6) <= a.charAt(7))
			return false;
		return true;
	}
	
	public static boolean taxi(String a)	{
		Set<Character> set = new HashSet<Character>();
		set.add(a.charAt(0));
		set.add(a.charAt(1));
		set.add(a.charAt(3));
		set.add(a.charAt(4));
		set.add(a.charAt(6));
		set.add(a.charAt(7));
		return set.size()==1;
	}
	
	
	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}