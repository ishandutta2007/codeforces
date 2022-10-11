import java.io.*;
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
			int m = readInt();
			ArrayList<State>[] all = new ArrayList[m];
			for(int i = 0; i < m; i++) {
				all[i] = new ArrayList<State>();
			}
			while(n-- > 0) {
				String a = nextToken();
				int id = readInt()-1;
				int b = readInt();
				all[id].add(new State(a, b));
			}
			for(ArrayList<State> out: all) {
				Collections.sort(out);
				if(out.size() > 2 && out.get(1).score == out.get(2).score) {
					pw.println("?");
				}
				else {
					pw.println(out.get(0) + " " + out.get(1));
				}
			}
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public String name;
		public int score;
		public String toString() {
			return name;
		}
		public State(String a, int b) {
			name=a;
			score=b;
		}
		public int compareTo(State s) {
			return s.score - score;
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