import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int w = readInt();
			int a = readInt()-1;
			int b = readInt()-1;
			if(b == n-1)	{
				b -= b%w;
				b += w-1;
			}
			if(a%w==0 && b%w == w-1){
				pw.println(1);
			}
			else if(w == 1)	{
				pw.println(1);
			}
			else if(a/w == b/w)	{
				pw.println(1);
			}
			else if(a/w+1 == b/w)	{
				pw.println(2);
			}
			else {
				int ret = 3;
				if(a%w==0)	{
					ret--;
				}
				else if(b%w==w-1)	{
					ret--;
				}
				else if((a+w-1)%w == b%w)	{
					ret--;
				}
				pw.println(ret);
			}
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