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
			TreeSet<Integer> ret = new TreeSet<Integer>();
			int a = readInt();
			int b = readInt();
			int c = readInt();
			for(int i = 1; true; i++) {
				long claim = b * pow(i, a) + c;
				if(claim >= 1000000000) break;
				else if(a == 1 && i > 10000) break;
				else if(claim > 0 && sum(claim) == i) {
					ret.add((int)claim);
				}
			}
			pw.println(ret.size());
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}

	public static long pow(long b, long e) {
		if(e==0) return 1;
		if(e%2==0) {
			long r = pow(b, e/2);
			return r*r;
		}
		return b * pow(b, e-1);
	}
	
	public static int sum(long x) {
		int ret = 0;
		while(x > 0) {
			ret += x%10;
			x /= 10;
		}
		return ret;
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