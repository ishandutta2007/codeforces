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
			int n = readInt();
			if(n%4==2 || n%4==3)	{
				pw.println(-1);
			}
			else if(n == 1)	{
				pw.println(1);
			}
			else	{
				int[] list = new int[n];
				if(n%4==1)	{
					int curr = 2;
					for(int i = 0; i < list.length/2; i += 2)	{
						list[i] = curr;
						list[i+1] = (n+1)-(curr-1);
						list[list.length-2-i] = curr-1;
						list[list.length-1-i] = n+1-curr;
						curr += 2;
					}
					list[list.length/2] = (n+1)/2;
				}
				else	{
					int curr = 2;
					for(int i = 0; i < list.length/2; i += 2)	{
						list[i] = curr;
						list[i+1] = n+2-curr;
						curr += 2;
					}
					curr = 1;
					for(int i = list.length-2; i >= list.length/2; i -= 2)	{
						list[i] = curr;
						list[i+1] = n-curr;
						curr += 2;
					}
				}
				StringBuilder sb = new StringBuilder();
				for(int out: list)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
	}

	public static boolean lucky(int[] list)	{
		for (int i = 0; i < list.length; i++) {
			if(list[list[i]-1] != list.length-i)	{
				return false;
			}
		}
		return true;
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