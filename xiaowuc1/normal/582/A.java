import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.security.*;
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

	public static void main(String[] args) throws Exception {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			TreeMap<Integer, Integer> last = new TreeMap<Integer, Integer>();
			for(int i = 0; i < n*n; i++) {
				int curr = readInt();
				if(!last.containsKey(curr)) {
					last.put(curr, 0);
				}
				last.put(curr, 1 + last.get(curr));
			}
			ArrayList<Integer> list = new ArrayList<Integer>();
			while(list.size() < n) {
				int largest = last.lastKey();
				int need = last.get(largest);
				int cont = 0;
				for(int out: list) {
					if(gcd(out, largest) == largest) {
						cont++;
					}
				}
				int add = 0;
				while(add*(add+2*cont) < need) {
					add++;
				}
				for(int out: list) {
					int key = gcd(out, largest);
					int dec = 2*add;
					if(last.get(key) == dec) last.remove(key);
					else last.put(key, last.get(key) - dec);
				}
				last.remove(largest);
				while(add-- > 0) {
					list.add(largest);
				}
			}
			StringBuilder sb = new StringBuilder();
			for(int out: list) {
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}	
		exitImmediately();
	}

	public static int gcd(int a, int b) {
		return a%b==0 ? b : gcd(b, a%b);
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