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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int[] l = new int[readInt()];
			for(int i = 0; i < l.length; i++) {
				l[i] = readInt();
			}
			if(valid(l)) {
				pw.println("YES");
				continue;
			}
			for(int i = 0; i < l.length-1-i; i++) {
				l[i] ^= l[l.length-1-i];
				l[l.length-1-i] ^= l[i];
				l[i] ^= l[l.length-1-i];
			}
			if(valid(l)) {
				pw.println("YES");
			}
			else {
				pw.println("NO");
			}
		}
		exitImmediately();
	}

	public static boolean valid(int[] l) {
		long s = 0;
		TreeMap<Long, Integer> appear = new TreeMap<>();
		for(long out: l) {
			if(!appear.containsKey(out)) {
				appear.put(out, 0);
			}
			appear.put(out, 1 + appear.get(out));
			s += out;
		}
		if(s%2 == 1) {
			return false;
		}
		long curr = 0;
		for(int i = 0; i < l.length && 2*curr <= s; i++) {
			long want = (s/2-curr);
			if(appear.containsKey(want)) {
				return true;
			}
			int nv = appear.get((long)l[i])-1;
			if(nv == 0) appear.remove((long)l[i]);
			else appear.put((long)l[i], nv);
			curr += l[i];
		}
		return false;
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}