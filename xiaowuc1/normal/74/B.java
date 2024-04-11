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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	static boolean[][] grid;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int curr = readInt();
			int rem = readInt();
			nextToken();
			boolean goingLeft = nextToken().equals("head");
			String trains = nextToken();
			Set<Integer> poss = new HashSet<Integer>();
			poss.add(curr);
			boolean win = true;
			for(int i = 0; win && i < trains.length(); i++)	{
				if(trains.charAt(i) == '0')	{
					Set<Integer> next = new HashSet<Integer>();
					for(int out: poss)	{
						if(out != 1)
							next.add(out-1);
						next.add(out);
						if(out != n)
							next.add(out+1);
					}
					next.remove(rem);
					if(goingLeft)	{
						next.remove(--rem);
						if(rem == 1)
							goingLeft = false;
					}
					else	{
						next.remove(++rem);
						if(rem == n)	{
							goingLeft = true;
						}
					}
					poss = next;
				}
				else	{
					if(goingLeft)	{
						if(--rem == 1)
							goingLeft = false;
					}
					else	{
						if(++rem == n)	{
							goingLeft = true;
						}
					}
					for(int a = 1; a <= n; a++)	{
						poss.add(a);
					}
					poss.remove(rem);
				}
				win = !poss.isEmpty();
				if(!win)	{
					pw.println("Controller " + (i+1));
				}
			}
			if(win)	{
				pw.println("Stowaway");
			}
		}
		pw.close();
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