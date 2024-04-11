
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class B {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int n = readInt();
		int a = readInt();
		int b = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		PriorityQueue<State> q = new PriorityQueue<State>();
		int ret = Integer.MAX_VALUE;
		if(a >= list[0])	{
			q.add(new State(1, list[0], 0, 0, true));
		}
		if(b >= list[0])	{
			q.add(new State(1, 0, list[0], 0, false));
		}
		Set<State> seen = new HashSet<State>();
		while(!q.isEmpty())	{
			State curr = q.poll();
			if(curr.index == n)	{
				ret = curr.dist;
				break;
			}
			if(!seen.add(curr))
				continue;
			if(curr.a + list[curr.index] <= a)	{
				q.add(new State(curr.index+1, curr.a + list[curr.index], curr.b, curr.lastA ? curr.dist : curr.dist + Math.min(list[curr.index], list[curr.index-1]), true));
			}
			if(curr.b + list[curr.index] <= b)	{
				q.add(new State(curr.index+1, curr.a, curr.b + list[curr.index], !curr.lastA ? curr.dist : curr.dist + Math.min(list[curr.index], list[curr.index-1]), false));
			}
		}
		if(ret == Integer.MAX_VALUE)
			ret = -1;
		pw.println(ret);
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