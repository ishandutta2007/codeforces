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
			int m = readInt();
			int k = readInt();
			LinkedList<Integer>[] edges = new LinkedList[n];
			for (int i = 0; i < edges.length; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int i = 0; i + k <= n; i++)	{
				for(int j = 0; j < k; j++)	{
					edges[i+j].add(i+(k-1-j));
				}
			}
			int connect = 0;
			boolean[] seen = new boolean[n];
			for (int i = 0; i < seen.length; i++) {
				if(!seen[i])	{
					seen[i] = true;
					LinkedList<Integer> q = new LinkedList<Integer>();
					q.add(i);
					connect++;
					while(!q.isEmpty())	{
						int curr = q.removeFirst();
						for(int out: edges[curr])	{
							if(!seen[out])	{
								seen[out] = true;
								q.addLast(out);
							}
						}
					}
				}
			}
			long ret = 1;
			while(connect-- > 0)	{
				ret *= m;
				ret %= 1000000007;
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class State	{
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
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