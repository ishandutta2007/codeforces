import java.awt.*;
import java.awt.event.*;
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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			switch(n) {
			case 1:
				pw.println("Washington");
				break;
			case 2:
				pw.println("Adams");
				break;
			case 3:
				pw.println("Jefferson");
				break;
			case 4:
				pw.println("Madison");
				break;
			case 5:
				pw.println("Monroe");
				break;
			case 6:
				pw.println("Adams");
				break;
			case 7:
				pw.println("Jackson");
				break;
			case 8:
				pw.println("Van Buren");
				break;
			case 9:
				pw.println("Harrison");
				break;
			case 10:
				pw.println("Tyler");
				break;
			case 11:
				pw.println("Polk");
				break;
			case 12:
				pw.println("Taylor");
				break;
			case 13:
				pw.println("Fillmore");
				break;
			case 14:
				pw.println("Pierce");
				break;
			case 15:
				pw.println("Buchanan");
				break;
			case 16:
				pw.println("Lincoln");
				break;
			case 17:
				pw.println("Johnson");
				break;
			case 18:
				pw.println("Grant");
				break;
			case 19:
				pw.println("Hayes");
				break;
			case 20:
				pw.println("Garfield");
				break;
			case 21:
				pw.println("Arthur");
				break;
			case 22:
				pw.println("Cleveland");
				break;
			case 23:
				pw.println("Harrison");
				break;
			case 24:
				pw.println("Cleveland");
				break;
			case 25:
				pw.println("McKinley");
				break;
			case 26:
				pw.println("Roosevelt");
				break;
			case 27:
				pw.println("Taft");
				break;
			case 28:
				pw.println("Wilson");
				break;
			case 29:
				pw.println("Harding");
				break;
			case 30:
				pw.println("Coolidge");
				break;
			case 31:
				pw.println("Hoover");
				break;
			case 32:
				pw.println("Roosevelt");
				break;
			case 33:
				pw.println("Truman");
				break;
			case 34:
				pw.println("Eisenhower");
				break;
			case 35:
				pw.println("Kennedy");
				break;
			case 36:
				pw.println("Johnson");
				break;
			case 37:
				pw.println("Nixon");
				break;
			case 38:
				pw.println("Ford");
				break;
			case 39:
				pw.println("Carter");
				break;
			case 40:
				pw.println("Reagan");
				break;
			}
		}
		pw.close();
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