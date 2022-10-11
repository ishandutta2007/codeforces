
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
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int lastDrop = readInt()-1;
		long[] list = new long[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		long min = Long.MAX_VALUE;
		int last = -1;
		for(int k = lastDrop+n; k > lastDrop; k--)	{
			if(list[k%n] < min)	{
				min = list[k%n];
				last = k%n;
			}
		}
		int numRem = (lastDrop+n-last)%n;
		long numDiv = list[last];
		long orig = 0;
		for(int k = 1; k <= numRem; k++)	{
			list[(last+k)%n]--;
			orig++;
		}
		for(int i = 0; i < n; i++)	{
			list[i] -= numDiv;
			orig += numDiv;
		}
		list[last] = orig;
		StringBuilder sb = new StringBuilder();
		for(long out: list)	{
			sb.append(out + " ");
		}
		pw.println(sb.toString().trim());
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