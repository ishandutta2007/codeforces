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
		int v = readInt();
		int e = readInt();
		ColorSet<Integer>[] sets = new ColorSet[100001];
		LinkedList<Integer>[] edges = new LinkedList[v];
		int[] color = new int[v];
		for(int i = 0; i < v; i++)	{
			color[i] = readInt();
			if(sets[color[i]] == null)	{
				sets[color[i]] = new ColorSet<Integer>(color[i]);
			}
			edges[i] = new LinkedList<Integer>();
		}
		while(e-- > 0)	{
			int a = readInt();
			int b = readInt();
			a--;
			b--;
			edges[a].add(b);
			edges[b].add(a);
		}
		for(int i = 0; i < edges.length; i++)	{
			for(int j: edges[i])	{
				if(color[i] != color[j])	{
					sets[color[i]].add(color[j]);
					sets[color[j]].add(color[i]);
				}
			}
		}
		ColorSet<Integer> ret = new ColorSet<Integer>(1000000);
		for(ColorSet<Integer> out: sets)	{
			if(out != null && out.compareTo(ret) < 0)	{
				ret = out;
			}
		}
		pw.println(ret);
		pw.close();
	}

	static class ColorSet<E> extends HashSet<E> implements Comparable<ColorSet<E>> {
		public int color;
		public ColorSet(int colorIn)	{
			color = colorIn;
		}
		public int compareTo(ColorSet<E> set)	{
			if(size() != set.size())	{
				return set.size() - size();
			}
			return color - set.color;
		}
		public String toString()	{
			return String.valueOf(color);
		}
	}

	/* NOTEBOOK CODE */

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