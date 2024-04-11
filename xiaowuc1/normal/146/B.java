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
		int a = readInt();
		String b = nextToken();
		while(!contains(++a,b));
		pw.println(a);
		pw.close();
	}
	
	public static boolean contains(int x, String b)	{
		int j = 0;
		LinkedList<Character> list = new LinkedList<Character>();
		while(x > 0)	{
			if(x%10 == 4 || x % 10 == 7)	{
				list.addFirst((char)('0' + (x%10)));
			}
			x /= 10;
		}
		if(list.size() != b.length())
			return false;
		int i = 0;
		for(char out: list)
			if(out != b.charAt(i++))
				return false;
		return true;
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