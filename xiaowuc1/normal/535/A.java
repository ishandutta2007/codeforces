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
			int n = readInt();
			if(n < 20) {
				simple(n);
				continue;
			}
			int l = n/10;
			if(l == 2) pw.print("twenty");
			if(l == 3) pw.print("thirty");
			if(l == 4) pw.print("forty");
			if(l == 5) pw.print("fifty");
			if(l == 6) pw.print("sixty");
			if(l == 7) pw.print("seventy");
			if(l == 8) pw.print("eighty");
			if(l == 9) pw.print("ninety");
			l = n%10;
			if(l == 1) pw.print("-one");
			if(l == 2) pw.print("-two");
			if(l == 3) pw.print("-three");
			if(l == 4) pw.print("-four");
			if(l == 5) pw.print("-five");
			if(l == 6) pw.print("-six");
			if(l == 7) pw.print("-seven");
			if(l == 8) pw.print("-eight");
			if(l == 9) pw.print("-nine");
			pw.println();
		}
		exitImmediately();
	}

	public static void simple(int n) {
		if(n==0) pw.println("zero");
		if(n==1) pw.println("one");
		if(n==2) pw.println("two");
		if(n==3) pw.println("three");
		if(n==4) pw.println("four");
		if(n==5) pw.println("five");
		if(n==6) pw.println("six");
		if(n==7) pw.println("seven");
		if(n==8) pw.println("eight");
		if(n==9) pw.println("nine");
		if(n==10) pw.println("ten");
		if(n==11) pw.println("eleven");
		if(n==12) pw.println("twelve");
		if(n==13) pw.println("thirteen");
		if(n==14) pw.println("fourteen");
		if(n==15) pw.println("fifteen");
		if(n==16) pw.println("sixteen");
		if(n==17) pw.println("seventeen");
		if(n==18) pw.println("eighteen");
		if(n==19) pw.println("nineteen");
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