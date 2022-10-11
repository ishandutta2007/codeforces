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
			int group = readInt();
			long ret = 0;
			while(n-- > 0)	{
				int a = readInt();
				int b = readInt();
				ret += solve(b-a, readInt(), readInt(), group); 
			}
			pw.println(ret);
		}
		pw.close();
	}

	public static long solve(int maxNoPenalty, int penaltyPerOver, int busCost, int sizeOfGroup)		{
		if(maxNoPenalty <= 0)	{
			return busCost + sizeOfGroup * 1L * penaltyPerOver;
		}
		long min = 0;
		long max = sizeOfGroup / maxNoPenalty;
		if(max * maxNoPenalty != sizeOfGroup)	{
			max++;
		}
		long ret = Long.MAX_VALUE;
		ret = Math.min(ret, solve(maxNoPenalty, penaltyPerOver, busCost, sizeOfGroup, min));
		ret = Math.min(ret, solve(maxNoPenalty, penaltyPerOver, busCost, sizeOfGroup, max));
		ret = Math.min(ret, solve(maxNoPenalty, penaltyPerOver, busCost, sizeOfGroup, max-1));
		while(max - min > 15)	{
			long a = (2*min+max)/3;
			long b = (2*max+min)/3;
			long aCost = solve(maxNoPenalty, penaltyPerOver, busCost, sizeOfGroup, a);
			long bCost = solve(maxNoPenalty, penaltyPerOver, busCost, sizeOfGroup, b);
			if(aCost > bCost)	{
				min = a;
			}
			else	{
				max = b;
			}
		}
		for(long a = min; a <= max; a++)	{
			ret = Math.min(ret, solve(maxNoPenalty, penaltyPerOver, busCost, sizeOfGroup, a));
		}
		return ret;
	}
	
	public static long solve(int maxNoPenalty, int penaltyPerOver, int busCost, int sizeOfGroup, long exactBuses)		{
		long overflow = sizeOfGroup - exactBuses * maxNoPenalty;
		if(overflow <= maxNoPenalty)	{
			return busCost * (exactBuses+1);
		}
		return busCost * (exactBuses+1) + penaltyPerOver * overflow;
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