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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		outer: for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			ArrayList<Integer> same = new ArrayList<Integer>();
			ArrayList<Integer> dif = new ArrayList<Integer>();
			String a = nextToken();
			String b = nextToken();
			for(int i = 0; i < a.length(); i++) {
				if(a.charAt(i) == b.charAt(i)) {
					same.add(i);
				}
				else {
					dif.add(i);
				}
			}
			char[] ret = new char[n];
			while(dif.size() >= 2) {
				if(k == 0) {
					pw.println(-1);
					continue outer;
				}
				if(dif.size() <= k) {
					ret[dif.get(dif.size()-1)] = gen(a.charAt(dif.get(dif.size()-1)), b.charAt(dif.get(dif.size()-1)));
					dif.remove(dif.size()-1);
					k--;
					ret[dif.get(dif.size()-1)] = gen(a.charAt(dif.get(dif.size()-1)), b.charAt(dif.get(dif.size()-1)));
					dif.remove(dif.size()-1);
					k--;
				}
				else {
					ret[dif.get(dif.size()-1)] = a.charAt(dif.get(dif.size()-1));
					dif.remove(dif.size()-1);
					k--;
					ret[dif.get(dif.size()-1)] = b.charAt(dif.get(dif.size()-1));
					dif.remove(dif.size()-1);
				}
			}
			while(!dif.isEmpty()) {
				if(k == 0) {
					pw.println(-1);
					continue outer;
				}
				ret[dif.get(dif.size()-1)] = gen(a.charAt(dif.get(dif.size()-1)), b.charAt(dif.get(dif.size()-1)));
				dif.remove(dif.size()-1);
				k--;
			}
			while(!same.isEmpty()) {
				if(k == 0) {
					ret[same.get(same.size()-1)] = a.charAt(same.get(same.size()-1));
				}
				else {
					ret[same.get(same.size()-1)] = gen(a.charAt(same.get(same.size()-1)), b.charAt(same.get(same.size()-1)));
					k--;
				}
				same.remove(same.size()-1);
			}
			pw.println(new String(ret));
		}
		pw.close();
	}

	public static char gen(char a, char b) {
		while(true) {
			char ret = (char)('a' + 26 * Math.random());
			if(a != ret && b != ret) return ret;
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