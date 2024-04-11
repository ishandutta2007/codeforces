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
			int[] orig = new int[n];
			for(int i = 0; i < n; i++) {
				orig[i] = readInt();
			}
			root = new Node();
			for(int i = 0; i < n; i++) {
				addInt(readInt());
			}
			for(int i = 0; i < n; i++) {
				pw.print(orig[i] ^ query(orig[i]));
				if(i == n-1) pw.println();
				else pw.print(" ");
			}
		}
		pw.close();
	}

	static Node root;
	public static int query(int x) {
		Node curr = root;
		curr.count--;
		int ret = 0;
		for(int i = 29; i >= 0; i--) {
			int want = 0;
			int val = 0;
			if((x&(1<<i)) != 0) {
				want = 1;
				val = 1 << i;
			}
			if(curr.child[want] != null && curr.child[want].count > 0) {
				curr = curr.child[want];
				ret |= val;
			}
			else {
				curr = curr.child[1-want];
				ret |= (val^(1<<i));
			}
			curr.count--;
		}
		return ret;
	}
	public static void addInt(int x) {
		Node curr = root;
		curr.count++;
		for(int i = 29; i >= 0; i--) {
			int want = 0;
			if((x&(1<<i)) != 0) {
				want = 1;
			}
			if(curr.child[want] == null) {
				curr.child[want] = new Node();
			}
		 	curr = curr.child[want];
		 	curr.count++;
		}
	}
	
	static class Node {
		public int count;
		public Node[] child;
		public Node() {
			count = 0;
			child = new Node[2];
		}
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