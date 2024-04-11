
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int n = readInt();
		ArrayList<ArrayList<Integer>> ret = new ArrayList<ArrayList<Integer>>();
		for(int a = 0; 1 << a < n; a++)	{
			ArrayList<Integer> list = new ArrayList<Integer>();
			for(int k = 1; k <= n; k++)	{
				int temp = k-1;
				if((temp&(1<<a)) != 0)
					list.add(k);
			}
			ret.add(list);
		}
		pw.println(ret.size());
		for(ArrayList<Integer> out: ret)	{
			pw.print(out.size());
			for(int out2: out)
				pw.print(" " + out2);
			pw.println();
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int index,a,b,dist;
		public boolean lastA;
		public State(int x, int w, int e, int r, boolean t)	{
			index=x;
			a=w;
			b=e;
			dist=r;
			lastA = t;
		}
		public int hashCode()	{
			int ans = index;
			ans *= 3137;
			ans += a;
			ans *= 3137;
			ans += b;
			if(lastA)
				ans++;
			return ans;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return index == s.index && a == s.a && b == s.b && lastA == s.lastA;
		}
		public int compareTo(State out)	{
			return dist - out.dist;
		}
	}
	
	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
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