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

	static int[][] dp;

	static LinkedList<Integer>[] edges;

	static int[] dist;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int k = readInt();
		if(k == 0)	{
			pw.println(n-1);
		}
		else	{
			dp = new int[n][k+1];
			edges = new LinkedList[n];
			for(int i = 0; i < n; i++)	{
				edges[i] = new LinkedList<Integer>();
			}
			for(int qq = 1; qq < n; qq++)	{
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			dist = new int[n];
			Arrays.fill(dist, 1 << 25);
			dist[0] = 0;
			LinkedList<Integer> q = new LinkedList<Integer>();
			LinkedList<Integer> topoSort = new LinkedList<Integer>();
			q.add(0);
			while(!q.isEmpty())	{
				int curr = q.removeFirst();
				topoSort.addFirst(curr);
				for(int out: edges[curr])	{
					if(dist[out] > 1 + dist[curr])	{
						dist[out] = 1 + dist[curr];
						q.addLast(out);
					}
				}
			}
			while(!topoSort.isEmpty())	{
				int curr = topoSort.removeFirst();
				dp[curr][0] = 1;
				for(int out: edges[curr])	{
					if(dist[out] > dist[curr])	{
						for(int i = 0; i < k; i++)	{
							dp[curr][i+1] += dp[out][i];
						}
					}
				}
			}
			long ret = 0;
			for(int i = 0; i < n; i++)	{
				ret += 2*dp[i][k];
				for(int out: edges[i])	{
					if(dist[out] > dist[i])	{
						for(int l = 0; l < k; l++)	{
							if(k-2-l < 0)	{
								ret += dp[out][l] * 1L * (dp[i][k-1-l] - 1);
							}
							else	{
								ret += dp[out][l] * 1L * (dp[i][k-1-l] - dp[out][k-2-l]);
							}
						}
					}
				}
			}
			pw.println(ret/2);
		}
		pw.close(); 
	}

	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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