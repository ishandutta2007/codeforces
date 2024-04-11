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
		String str = nextToken();
		int[][] list = new int[4][str.length()+1];
		Arrays.fill(list[0], -1);
		Arrays.fill(list[1], -1);
		Arrays.fill(list[2], -1);
		Arrays.fill(list[3], -1);
		list[0][0] = 0;
		for(int a = 0; a < 3; a++)	{
			for(int i = 0; i < str.length(); i++)	{
				if(list[a][i] < 0)
					continue;
				for(int j = i+1; j <= str.length(); j++)	{
					if(str.charAt(i) == '0' && i+1 != j)
						break;
					int next = Integer.parseInt(str.substring(i,j));
					if(next > 1000000)
						break;
					list[a+1][j] = Math.max(list[a+1][j], list[a][i] + next);
				}
			}
		}
		pw.print(list[3][str.length()]);
		pw.close();
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