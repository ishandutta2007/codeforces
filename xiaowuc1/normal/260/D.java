
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int[] last = new int[]{-1,-1};
		PriorityQueue<Vertex>[] queues = new PriorityQueue[2];
		queues[0] = new PriorityQueue<Vertex>();
		queues[1] = new PriorityQueue<Vertex>();
		for(int i = 0; i < n; i++)	{
			int color = readInt();
			int sum = readInt();
			queues[color].add(new Vertex(i+1,sum,0));
		}
		for(int qq = 1; qq < n; qq++)	{
			if(queues[0].isEmpty())	{
				pw.println(last[0] + " " + queues[1].poll().v + " 0");
			}
			else if(queues[1].isEmpty())	{
				pw.println(last[1] + " " + queues[0].poll().v + " 0");
			}
			else	{
				Vertex zero = queues[0].poll();
				Vertex one = queues[1].poll();
				zero.ttl = qq;
				one.ttl = qq;
				last[0] = zero.v;
				last[1] = one.v;
				int diff = Math.min(zero.w, one.w);
				zero.w -= diff;
				one.w -= diff;
				pw.println(zero.v + " " + one.v + " " + diff);
				if(zero.w > one.w)	{
					queues[0].add(zero);
				}
				else	{
					queues[1].add(one);
				}
			}
		}
		pw.close();
	}
	
	static class Vertex implements Comparable<Vertex> {
		public int v,w,ttl;
		public Vertex(int a, int b, int c)	{
			v=a;
			w=b;
			ttl=c;
		}
		public int compareTo(Vertex curr)	{
			if(curr.w != w)
				return curr.w - w;
			return ttl - curr.ttl;
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