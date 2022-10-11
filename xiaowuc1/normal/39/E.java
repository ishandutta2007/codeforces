import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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

	static Set<State> seen, win;

	static BigInteger n;

	static boolean draw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int a = readInt();
			draw = false;
			int b = readInt();
			n = new BigInteger(nextToken());
			if(a == 1 && BigInteger.valueOf(a+1).pow(b).compareTo(n) >= 0)	{
				pw.println("Missing");
			}
			else	{
				seen = new HashSet<Main.State>();
				win = new HashSet<Main.State>();
				boolean ret = win(a,b,0);
				if(draw && !ret)	{
					pw.println("Missing");
				}
				else	{
					pw.println(ret ? "Masha" : "Stas");
				}
			}
		}
		pw.close();
	}

	private static boolean win(int a, int b, int d) {
		if(seen.add(new State(a,b)))	{
			if(BigInteger.valueOf(a).pow(b).compareTo(n) >= 0)		{
				return true;
			}
			else if(b == 1 && BigInteger.valueOf(a).pow(b+1).compareTo(n) >= 0)	{
				if(a%2 == n.intValue()%2)	{
					win.add(new State(a,b));
					return true;
				}
				else	{
					return false;
				}
			}
			else if(a == 1 && BigInteger.valueOf(a+1).pow(b).compareTo(n) >= 0)	{	
				if(d%2 == 0)	{
					draw = true;
					return false;
				}
				win.add(new State(a,b));
				return true;
			}
			else if(!win(a,b+1,d+1) || !win(a+1,b,d+1))	{
				win.add(new State(a,b));
				return true;
			}
			return false;
		}
		return win.contains(new State(a,b));
	}

	static class State	{
		public int x,y;

		public State(int x, int y) {
			super();
			this.x = x;
			this.y = y;
		}

		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + x;
			result = prime * result + y;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (x != other.x)
				return false;
			if (y != other.y)
				return false;
			return true;
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
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}