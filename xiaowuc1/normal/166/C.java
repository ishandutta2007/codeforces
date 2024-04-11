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
		int want = readInt();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0; i < n; i++)
			list.add(readInt());
		int ret = 0;
		while(median(list) != want){
			if(!list.contains(want))	{
				list.add(want);
				ret++;
			}
			else	{
				int now = median(list);
				if(now < want)
					list.add(Integer.MAX_VALUE);
				else
					list.add(0);
				ret++;
			}
		}
		pw.println(ret);
		pw.close();
	}

	public static int median(ArrayList<Integer> list)	{
		Collections.sort(list);
		return list.get((list.size()-1)/2);
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