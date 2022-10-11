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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			int leftX = readInt();
			int rightX = readInt();
			int[] leftY = new int[n];
			TreeSet<State> set = new TreeSet<State>();
			for (int i = 0; i < leftY.length; i++) {
				leftY[i] = readInt();
				set.add(new State(leftY[i], i));
			}
			int[] rightY = new int[m];
			int[] bestLeftMatch = new int[m];
			double[] dist = new double[m];
			for (int i = 0; i < rightY.length; i++) {
				rightY[i] = readInt();
				State currDown = set.floor(new State(rightY[i] * 1.0 * leftX / rightX, 0));
				State currUp = set.ceiling(new State(rightY[i] * 1.0 * leftX / rightX, 0));
				if(currDown == null)	{
					bestLeftMatch[i] = currUp.index;
					dist[i] = Math.hypot(leftX, currUp.y) + Math.hypot(rightX - leftX, currUp.y - rightY[i]);
				}
				else if(currUp == null)	{
					bestLeftMatch[i] = currDown.index;
					dist[i] = Math.hypot(leftX, currDown.y) + Math.hypot(rightX - leftX, currDown.y - rightY[i]);
				}
				else	{
					double bottomDist = Math.hypot(leftX, currDown.y) + Math.hypot(rightX - leftX, currDown.y - rightY[i]);
					double topDist = Math.hypot(leftX, currUp.y) + Math.hypot(rightX - leftX, currUp.y - rightY[i]);
					if(bottomDist < topDist)	{
						bestLeftMatch[i] = currDown.index;
					}
					else	{
						bestLeftMatch[i] = currUp.index;
					}
					dist[i] = Math.min(bottomDist, topDist);
				}
			}
			for(int i = 0; i < m; i++)	{
				dist[i] += readInt();
			}
			int bestX = -1;
			double ret = Double.MAX_VALUE;
			for(int i = 0; i < m; i++)	{
				if(dist[i] < ret)	{
					ret = dist[i];
					bestX = i;
				}
			}
			pw.printf("%d %d\n", 1 + bestLeftMatch[bestX], bestX+1);
		}
		pw.close();
	}

	static class State implements Comparable<State>	{
		public double y;
		public int index;
		public State(double y, int index) {
			super();
			this.y = y;
			this.index = index;
		}
		public int compareTo(State s)	{
			if(y < s.y)
				return -1;
			if(y > s.y)
				return 1;
			return 0;
		}
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