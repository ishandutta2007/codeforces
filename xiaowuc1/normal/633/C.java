import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

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
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			String s = nextToken();
			String lowerS = s.toLowerCase();
			root = new Node();
			Map<String, String> rev = new HashMap<String, String>();
			{
				int qqq = readInt();
				while(qqq-- > 0) {
					String ss = nextToken();
					addWord(root, ss);
					rev.put(ss.toLowerCase(), ss);
				}
			}
			int[] dp = new int[n+1];
			Arrays.fill(dp, -1);
			dp[n] = n;
			for(int i = n; i > 0; i--) {
				if(dp[i] < 0) continue;
				Node curr = root;
				for(int a = i-1; a >= 0 && curr != null; a--) {
					curr = curr.child[lowerS.charAt(a) - 'a'];
					if(curr != null && curr.word != null) {
						dp[a] = i;
					}
				}
			}
			StringBuilder sb = new StringBuilder();
			{
				int now = 0;
				while(now < n) {
					int len = dp[now] - now;
					sb.append(rev.get(new StringBuilder(s.substring(now, now+len)).reverse().toString()));
					sb.append(" ");
					now += len;
				}
			}
			pw.println(sb.toString().trim());
		}
		pw.close();
	}

	static Node root;
	
	public static void addWord(Node n, String s) {
		String t = s.toLowerCase();
		for(int i = 0; i < t.length(); i++) {
			int next = t.charAt(i) - 'a';
			if(n.child[next] == null) {
				n.child[next] = new Node();
			}
			n = n.child[next];
		}
		n.word = s;
	}
	
	static class Node {
		String word;
		Node[] child;
		public Node() {
			child = new Node[26];
		}
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