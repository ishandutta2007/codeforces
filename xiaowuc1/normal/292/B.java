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

	static LinkedList<Integer>[] edges;

	static int n,m;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			n = readInt();
			m = readInt();
			edges = new LinkedList[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			for(int i = 0; i < m; i++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			if(isBus()) {
				pw.println("bus topology");
			}
			else if(isRing()) {
				pw.println("ring topology");
			}
			else if(isStar()) {
				pw.println("star topology");
			}
			else {
				pw.println("unknown topology");
			}
		}
		pw.close();
	}

	public static boolean isBus() {
		if(m+1 != n) return false;
		int one = 0;
		int two = 0;
		for(int i = 0; i < n; i++) {
			if(edges[i].size() == 1) {
				one++;
			}
			else if(edges[i].size() == 2) {
				two++;
			}
		}
		if(one != 2) return false;
		if(two != n-2) return false;
		return isConnected();
	}
	
	public static boolean isRing() {
		if(m != n) return false;
		int two = 0;
		for(int i = 0; i < n; i++) {
			if(edges[i].size() == 2) {
				two++;
			}
		}
		if(two != n) return false;
		return isConnected();
	}

	public static boolean isStar() {
		if(m+1 != n) return false;
		int one = 0;
		int other = 0;
		for(int i = 0; i < n; i++) {
			if(edges[i].size() == 1) {
				one++;
			}
			else if(edges[i].size() == n-1) {
				other++;
			}
		}
		if(one != n-1) return false;
		if(other != 1) return false;
		return isConnected();
	}

	
	public static boolean isConnected() {
		boolean[] visit = new boolean[n];
		visit[0] = true;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(0);
		while(!q.isEmpty()) {
			int curr = q.removeFirst();
			for(int out: edges[curr]) {
				if(!visit[out]) {
					visit[out] = true;
					q.add(out);
				}
			}
		}
		for(boolean out: visit) {
			if(!out) {
				return false;
			}
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