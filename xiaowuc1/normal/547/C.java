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

public class C {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	
	static int[] amt;
	static boolean[] bad;
	static ArrayList<Integer>[] num;
	static int[] numsIn;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		bad = new boolean[500001];
		for(int i = 2; i * i < bad.length; i++) {
			for(int a = 1; a * i * i < bad.length; a++) {
				bad[a*i*i] = true;
			}
		}
		num = new ArrayList[500001];
		numsIn = new int[500001];
		for(int a = 1; a < num.length; a++) {
			if(!bad[a]) {
				num[a] = new ArrayList<Integer>();
				num[a].add(1);
			}
		}
		for(int i = 2; i < num.length; i++) {
			if(bad[i] || num[i].size() > 1) continue;
			for(int a = 1; i * a < num.length; a++) {
				if(!bad[i*a]) {
					num[i*a] = expand(num[i*a], i);
					numsIn[i*a]++;
				}
			}
		}
		amt = new int[500001];
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int qqq = readInt();
			int[] list = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				for(int a = 2; bad[list[i]]; a++) {
					while(list[i] % (a*a) == 0) {
						list[i] /= a;
					}
				}
			}
			boolean[] present = new boolean[n];
			long ret = 0;
			int exist = 0;
			while(qqq-- > 0) {
				int index = readInt()-1;
				if(present[index]) {
					for(int out: num[list[index]]) {
						amt[out]--;
					}
					exist--;
					ret -= count(list[index], exist);
					present[index] = false;
				}
				else {
					ret += count(list[index], exist);
					for(int out: num[list[index]]) {
						amt[out]++;
					}
					exist++;
					present[index] = true;
				}
				pw.println(ret);
			}
		}
		pw.close();
	}

	public static int count(int curr, int exist) {
		int ret = 0;
		for(int out: num[curr]) {
			if(out == 1) continue;
			if(numsIn[out] % 2 == 1) {
				ret += amt[out];
			}
			else {
				ret -= amt[out];
			}
		}
		return exist - ret;
	}
	
	public static ArrayList<Integer> expand(ArrayList<Integer> l, int p) {
		ArrayList<Integer> r = new ArrayList<Integer>();
		for(int out: l) {
			r.add(out);
			r.add(out * p);
		}
		return r;
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