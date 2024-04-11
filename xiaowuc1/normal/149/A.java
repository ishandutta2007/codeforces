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
	static int MOD;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int sum = readInt();
		if(sum == 0)	{
			pw.println(0);
		}
		else	{
			int[] list = new int[12];
			for(int i = 0; i < list.length; i++)
				list[i] = readInt();
			Arrays.sort(list);
			int add = 0;
			for(int i = 11; i >= 0; i--)	{
				sum -= list[i];
				add++;
				if(sum <= 0)
					break;
			}
			if(sum > 0)
				pw.println(-1);
			else
				pw.println(add);
		}
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