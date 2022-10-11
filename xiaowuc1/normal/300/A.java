import java.awt.*;
import java.awt.event.*;
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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			ArrayList<Integer> list = new ArrayList<Integer>();
			int n = readInt();
			while(n-- > 0)	{
				list.add(readInt());
			}
			ArrayList<Integer> negative = new ArrayList<Integer>();
			ArrayList<Integer> positive = new ArrayList<Integer>();
			ArrayList<Integer> zero = new ArrayList<Integer>();
			while(!list.isEmpty())	{
				int curr = list.remove(0);
				if(curr < 0)	{
					if(negative.isEmpty())	{
						negative.add(curr);
					}
					else	{
						zero.add(curr);
					}
				}
				else if(curr > 0)	{
					if(positive.isEmpty())	{
						positive.add(curr);
					}
					else	{
						zero.add(curr);
					}
				}
				else	{
					zero.add(curr);
				}
			}
			if(positive.size() == 0)	{
				for(int k = 0; positive.size() != 2; k++)	{
					if(zero.get(k) < 0)	{
						positive.add(zero.remove(k--));
					}
				}
			}
			print(negative);
			print(positive);
			print(zero);
		}
		pw.close();
	}

	public static void print(ArrayList<Integer> list)	{
		pw.print(list.size());
		for(int out: list)	{
			pw.print(" " + out);
		}
		pw.println();
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}