import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.LLOAD;


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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String str = nextToken();
			int[] lowercaseleft = new int[str.length()+1];
			int[] uppercaseright = new int[str.length()+1];
			for(int i = 0; i < str.length(); i++)	{
				lowercaseleft[i+1] = lowercaseleft[i];
				if(Character.isLowerCase(str.charAt(i))){
					lowercaseleft[i+1]++;
				}
				uppercaseright[i+1] = uppercaseright[i];
				if(Character.isUpperCase(str.charAt(str.length()-1-i))){
					uppercaseright[i+1]++;
				}
			}
			int ret = Integer.MAX_VALUE;
			for (int i = 0; i < uppercaseright.length; i++) {
				ret = Math.min(ret, uppercaseright[i] + lowercaseleft[str.length()-i]);
			}
			pw.println(ret);
		}
		pw.close();
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