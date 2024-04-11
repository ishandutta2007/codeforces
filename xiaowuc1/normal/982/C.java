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
			edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int i = 1; i < n; i++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			if(n % 2 == 1) {
				pw.println(-1);
				continue;
			}
			size = new int[n];
			pw.println(dfs(0, -1));
		}
		pw.close();
	}
	
	static LinkedList<Integer>[] edges;
	static int[] size;
	public static int dfs(int curr, int par) {
		size[curr]++;
		int ret = 0;
		for(int out: edges[curr]) {
			if(out == par) continue;
			ret += dfs(out, curr);
			size[curr] += size[out];
		}
		if(size[curr]%2 == 0 && par >= 0) {
			ret++;
		}
		return ret;
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