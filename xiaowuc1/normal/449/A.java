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
			long r = readInt();
			long c = readInt();
			long k = readInt();
			if(r-1+c-1 < k) {
				pw.println(-1);
				continue;
			}
			long ret = 1;
			for(long i = 0; i <= 100000; i++) {
				long other = k - i;
				if(other < 0) continue;
				ret = Math.max(ret, (r/(i+1)) * (c / (other+1)));
			}
			for(long i = 1; i <= 100000; i++) {
				long rowCut = r / i - 1;
				if(rowCut < 0) continue;
				long colCut = k - rowCut;
				if(colCut < 0) continue;
				ret = Math.max(ret, (r/(rowCut+1)) * (c / (colCut+1)));
			}
			long t=r;
			r=c;
			c=t;
			for(long i = 0; i <= 100000; i++) {
				long other = k - i;
				if(other < 0) continue;
				ret = Math.max(ret, (r/(i+1)) * (c / (other+1)));
			}
			for(long i = 1; i <= 100000; i++) {
				long rowCut = r / i - 1;
				if(rowCut < 0) continue;
				long colCut = k - rowCut;
				if(colCut < 0) continue;
				ret = Math.max(ret, (r/(rowCut+1)) * (c / (colCut+1)));
			}
			pw.println(ret);
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