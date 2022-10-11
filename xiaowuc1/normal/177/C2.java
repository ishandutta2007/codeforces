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
		int n = readInt();
		int m = readInt();
		LinkedList<Integer>[] edges = new LinkedList[n];
		for(int i = 0; i < n; i++)	{
			edges[i] = new LinkedList<Integer>();
		}
		while(m-- > 0)	{
			int a = readInt()-1;
			int b = readInt()-1;
			edges[a].add(b);
			edges[b].add(a);
		}
		boolean[][] bad = new boolean[n][n];
		m = readInt();
		while(m-- > 0)	{
			int a = readInt()-1;
			int b = readInt()-1;
			bad[a][b] = bad[b][a] = true;
		}
		int ret = 0;
		boolean[] seen = new boolean[n];
		for(int i = 0; i < n; i++)	{
			if(!seen[i])	{
				ArrayList<Integer> list = new ArrayList<Integer>();
				list.add(i);
				seen[i] = true;
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(i);
				while(!q.isEmpty())	{
					int curr = q.removeFirst();
					for(int out: edges[curr])	{
						if(!seen[out])	{
							seen[out] = true;
							q.addLast(out);
							list.add(out);
						}
					}
				}
				boolean win = true;
				for(int a = 0; win && a < list.size(); a++)	{
					for(int b = 0; win && b < a; b++)	{
						win = !bad[list.get(a)][list.get(b)];
					}
				}
				if(win)
					ret = Math.max(ret, list.size());
			}
		}
		pw.println(ret);
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