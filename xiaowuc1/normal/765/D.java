import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class D {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int[] l = new int[n+1];
			Set<Integer> set = new HashSet<Integer>();
			Map<Integer, ArrayList<Integer>> appear = new HashMap<Integer, ArrayList<Integer>>();
			for(int i = 1; i <= n; i++) {
				l[i] = readInt();
				if(!appear.containsKey(l[i])) {
					appear.put(l[i], new ArrayList<Integer>());
				}
				appear.get(l[i]).add(i);
			}
			boolean valid = true;
			for(int out: appear.keySet()) {
				if(l[out] != out) {
					valid = false;
					break;
				}
			}
			if(!valid) {
				pw.println(-1);
				continue;
			}
			pw.println(appear.size());
			int m = appear.size();
			int[] one = new int[n];
			int[] two = new int[m];
			int index = 1;
			for(int out: appear.keySet()) {
				two[index-1] = out;
				for(int out2: appear.get(out)) {
					one[out2-1] = index;
				}
				index++;
			}
			for(int i = 0; i < n; i++) {
				pw.print(one[i]);
				if(i == n-1) pw.println();
				else pw.print(" ");
			}
			for(int i = 0; i < m; i++) {
				pw.print(two[i]);
				if(i == m-1) pw.println();
				else pw.print(" ");
			}
			
		}
		pw.close();
	}

	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}