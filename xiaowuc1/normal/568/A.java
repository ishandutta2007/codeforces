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

public class ASlow {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		boolean[] comp = new boolean[2000000];
		for(int i = 2; i * i < comp.length; i++) {
			if(!comp[i]) {
				for(int j = i*i; j < comp.length; j += i) {
					comp[j] = true;
				}
			}
		}
		comp[0] = comp[1] = true;
		int palin = 0;
		int prime = 0;
		long p = readInt();
		long q = readInt();
		int ret = 0;
		for(int i = 1; i < comp.length; i++) {
			if(palin(i)) {
				palin++;
			}
			if(!comp[i]) {
				prime++;
			}
			if(q * prime <= p * palin) {
				ret = i;
			}
		}
		pw.println(ret);
		pw.close();
	}

	public static boolean palin(int x) {
		String s = Integer.toString(x);
		for(int i = 0; i < s.length()-1-i; i++) {
			if(s.charAt(i) != s.charAt(s.length()-1-i)) return false;
		}
		return true;
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