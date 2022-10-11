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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			// a of sand to b of lead
			// c of lead to d of gold
			// e of gold to f is sand
			long a = readInt();
			long b = readInt();
			long c = readInt();
			long d = readInt();
			long e = readInt();
			long f = readInt();
			boolean canLead = b != 0;
			boolean canGold = d != 0;
			boolean canSand = f != 0;
			if(!canGold)	{
				pw.println("Hermione");
			}
			else	{
				boolean infSand = e == 0;
				boolean infLead = a == 0;
				boolean infGold = c == 0;
				if(infGold)	{
					pw.println("Ron");
				}
				else if(canLead && infLead)	{
					pw.println("Ron");
				}
				else if(canSand && infSand && canLead)	{
					pw.println("Ron");
				}
				else if(b*d*f>a*c*e){
					pw.println("Ron");
				}
				else	{
					pw.println("Hermione");
				}
			}
		}
		pw.close();
	}

	static class Vertex	implements Comparable<Vertex> {
		public int x,y,w;

		public Vertex(int x, int y, int w) {
			super();
			this.x = x;
			this.y = y;
			this.w = w;
		}

		public int compareTo(Vertex curr)	{
			return w - curr.w;
		}

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