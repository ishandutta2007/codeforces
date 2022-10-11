import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int[] list = new int[readInt()];
		ArrayList<Integer> go = new ArrayList<Integer>();
		for(int i = 0; i < list.length; i++)	{
			go.add(i+1);
		}
		for(int qq = 0; qq < 1000; qq++)	{
			Collections.shuffle(go);
			for(int i = 0; i < list.length; i++)
				list[i] = go.get(i);
			for(int i = 0; i < list.length-1; i++)	{
				for(int j = i; j < list.length-1; j++)	{
					if(list[j] > list[j+1])	{
						list[j] ^= list[j+1];
						list[j+1] ^= list[j];
						list[j] ^= list[j+1];
					}
				}
			}
			boolean sorted = true;
			for(int i = 0; sorted && i < list.length-1; i++)
				sorted = list[i] < list[i+1];
			if(!sorted) {
				StringBuilder sb = new StringBuilder();
				for(int out: go)
					sb.append(out + " ");
				pw.println(sb.toString().trim());
				pw.close();
				return;
			}
		}
		pw.println(-1);
		pw.close();
	}

	static class State	{
		public int x,y;
		public State(int a, int b)	{
			x=a;
			y=b;
		}
		public int hashCode()		{
			return 3137*x+y;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return x == s.x && y == s.y;
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}