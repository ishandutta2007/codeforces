import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

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

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			boolean[] hGiven = new boolean[100];
			boolean[] aGiven = new boolean[100];
			int[] hYellow = new int[100];
			int[] aYellow = new int[100];
			String home = nextToken();
			String away = nextToken();
			int qqq = readInt();
			while(qqq-- > 0) {
				int time = readInt();
				String type = nextToken();
				int id = readInt();
				String card = nextToken();
				if(type.equals("h")) {
					if(hGiven[id]) continue;
					if(card.equals("r")) {
						pw.println(home + " " + id + " " + time);
						hGiven[id] = true;
					}
					else if(++hYellow[id] == 2) {
						pw.println(home + " " + id + " " + time);
						hGiven[id] = true;
					}
				}
				else {
					if(aGiven[id]) continue;
					if(card.equals("r")) {
						pw.println(away + " " + id + " " + time);
						aGiven[id] = true;
					}
					else if(++aYellow[id] == 2) {
						pw.println(away + " " + id + " " + time);
						aGiven[id] = true;
					}
				}
			}
		}
		exitImmediately();
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}