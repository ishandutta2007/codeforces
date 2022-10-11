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

	static Set<Integer>[] edges;

	static int k;

	static boolean[] seen;
	static boolean[] used;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			edges = new Set[n];
			for (int i = 0; i < edges.length; i++) {
				edges[i] = new HashSet<Integer>();
			}
			int m = readInt();
			k = readInt();
			while(m-- > 0)	{
				int a = readInt();
				int b = readInt();
				a--;
				b--;
				edges[a].add(b);
				edges[b].add(a);
			}
			int[] go = new int[n];
			boolean[] used = new boolean[n];
			used[0] = true;
			int curr = 0;
			for(int i = 1; true; i++)	{
				boolean found = false;
				for(int out: edges[curr])	{
					if(!used[out])	{
						used[out] = true;
						go[i] = out;
						curr = out;
						found = true;
						break;
					}
				}
				if(!found)	{
					for(int a = 0; i-a >= k; a++)	{
						if(edges[go[a]].contains(curr))	{
							pw.println(i-a);
							StringBuilder sb = new StringBuilder();
							for(int b = a; b < i; b++)	{
								sb.append((go[b] + 1) + " ");
							}
							pw.println(sb.toString().trim());
							break;
						}
					}
					break;
				}
			}
		}
		pw.close();
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