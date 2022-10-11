import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
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
			int[] deg = new int[n];
			for(int a = 0; a < n-1; a++) {
				int x = readInt()-1;
				int y = readInt()-1;
				deg[x]++;
				deg[y]++;
			}
			if(n == 2) {
				pw.println("Yes");
				pw.println("1");
				pw.println("1 2");
				continue;
			}
			int numTwo = 0;
			for(int out: deg) {
				if(out > 2) {
					numTwo++;
				}
			}
			if(numTwo > 1) {
				pw.println("No");
				continue;
			}
			int root = 0;
			for(int i = 1; i < n; i++) {
				if(deg[i] > deg[root]) {
					root = i;
				}
			}
			ArrayList<Integer> ret = new ArrayList<>();
			for(int i = 0; i < n; i++) {
				if(deg[i] == 1) {
					ret.add(i);
				}
			}
			pw.println("Yes");
			pw.println(ret.size());
			for(int i = 0; i < ret.size(); i++) {
				pw.print(ret.get(i)+1);
				pw.print(" ");
				pw.println(root+1);
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