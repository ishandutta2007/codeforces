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

	static int numFloor;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		numFloor = readInt();
		while(n-- > 0)	{
			int s = readInt();
			int f = readInt();
			int t = readInt();
			solve(s,f,t);
		}
		pw.close(); 
	}

	public static void solve(int start, int finish, int arrive)	{
		int numCycle = arrive / (2*(numFloor-1));
		int now = numCycle * (2*(numFloor-1));
		if(start == finish)	{
			pw.println(arrive);
		}
		else if(start == 1){
			if(now < arrive)	{
				now += 2 * numFloor-2;
			}
			pw.println(now + finish-start);
		}
		else if(start == numFloor)	{
			now += numFloor-1;
			if(now < arrive)	{
				now += 2 * numFloor-2;
			}
			pw.println(now + start-finish);
		}
		else	{
			while(true)	{
				if(now + start-1 >= arrive)	{
					int timeArrive = now + start-1;
					if(finish > start)	{
						pw.println(timeArrive + finish-start);
					}
					else	{
						pw.println(now + numFloor - 1 + numFloor - 1 - (finish-1));
					}
					break;
				}
				else if(now + numFloor-1 + numFloor-start >= arrive) {
					now += numFloor - 1;
					if(finish < start)	{
						pw.println(now + numFloor - finish);
					}
					else	{
						pw.println(now + numFloor - 1 + finish-1);
					}
					break;
				}
				else	{
					now += 2 * numFloor - 2;
				}
			}
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