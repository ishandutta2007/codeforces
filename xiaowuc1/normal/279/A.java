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

	static int[] dx = new int[]{1,0,-1,0};
	static int[] dy = new int[]{0,1,0,-1};
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			ArrayList<Line2D.Double> list = new ArrayList<Line2D.Double>();
			int currX = 0;
			int currY = 0;
			int dist = 0;
			while(dist < 400)	{
				for(int k = 0; k < dx.length; k++)	{
					if(k%2==0)	{
						dist++;
					}
					list.add(new Line2D.Double(currX, currY, currX + dist * dx[k], currY + dist* dy[k]));
					currX += dist * dx[k];
					currY += dist * dy[k];
				}
			}
			int a = readInt();
			int b = readInt();
			for(int i = 0; i < list.size(); i++)	{
				if(list.get(i).ptSegDist(a,b) == 0)	{
					pw.println(i);
					break;
				}
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