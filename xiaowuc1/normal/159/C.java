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
		int rep = readInt();
		String token = nextToken();
		ArrayList<Integer>[] list = new ArrayList[26];
		for(int i = 0; i < 26; i++)	{
			list[i] = new ArrayList<Integer>();
		}
		int c = 0;
		for(int qq = 0; qq < rep; qq++)	{
			for(int i = 0; i < token.length(); i++)	{
				list[token.charAt(i)-'a'].add(c++);
			}
		}
		int qqq = readInt();
		while(qqq-- > 0)	{
			int num = readInt()-1;
			int row = nextToken().charAt(0) - 'a';
			list[row].remove(num);
		}
		PriorityQueue<State> q = new PriorityQueue<State>();
		for(int i = 0; i < list.length; i++)	{
			for(int out: list[i])	{
				q.add(new State(out, (char)('a'+i)));
			}
		}
		while(!q.isEmpty())	{
			pw.print(q.poll().b);
		}
		pw.println();
		pw.close();
	}
	
	static class State implements Comparable<State>  {
		public int a;
		public char b;
		public State(int x, char y)	{
			a=x;
			b=y;
		}
		public int compareTo(State curr)	{
			return a - curr.a;
		}
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