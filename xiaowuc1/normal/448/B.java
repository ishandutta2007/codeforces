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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String a = br.readLine();
			String b = br.readLine();
			int[] count = new int[256];
			for(int i = 0; i < a.length(); i++) {
				count[a.charAt(i)]++;
			}
			for(int i = 0; i < b.length(); i++) {
				count[b.charAt(i)]--;
			}
			int nonzero = 0;
			for(int out: count) {
				if(out != 0) {
					nonzero++;
				}
			}
			if(nonzero == 0) {
				pw.println("array");
			}
			else {
				int curr = 0;
				for(int i = 0; i < a.length() && curr < b.length(); i++) {
					if(b.charAt(curr) == a.charAt(i)) {
						curr++;
					}
				}
				if(curr == b.length()) {
					pw.println("automaton");
				}
				else {
					int neg = 0;
					for(int out: count) {
						if(out < 0) {
							neg++;
						}
					}
					if(neg == 0) {
						pw.println("both");
					}
					else {
						pw.println("need tree");
					}
				}
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