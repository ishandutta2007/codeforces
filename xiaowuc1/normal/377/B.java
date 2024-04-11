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
			int m = readInt();
			int maxCost = readInt();
			Bug[] bugs = new Bug[m];
			for(int i = 0; i < m; i++) {
				bugs[i] = new Bug(i, readInt());
			}
			Arrays.sort(bugs);
			State[] people = getPeople(n);
			int min = 1;
			int max = m+1;
			int[] ret = null;
			while(min != max) {
				int mid = (min+max)/2;
				int lastBug = m-1;
				int lastPerson = n-1;
				PriorityQueue<State> q = new PriorityQueue<State>(n, new CostComp());
				int have = 0;
				int[] next = new int[m];
				while(lastBug >= 0) {
					while(lastPerson >= 0 && people[lastPerson].skill >= bugs[lastBug].skill) {
						q.add(people[lastPerson--]);
					}
					if(q.isEmpty() || have + q.peek().cost > maxCost) {
						break;
					}
					State curr = q.poll();
					have += curr.cost;
					for(int i = 0; i < mid; i++) {
						if(lastBug >= 0) {
							next[bugs[lastBug--].index] = curr.index+1;
						}
					}
				}
				if(lastBug < 0) {
					max = mid;
					ret = next;
				}
				else {
					min = mid+1;
				}
			}
			if(min == m+1) {
				pw.println("NO");
				continue;
			}
			pw.println("YES");
			StringBuilder sb = new StringBuilder();
			for(int out: ret) {
				sb.append(out + " ");
			}
			pw.println(sb.toString().trim());
		}
		exitImmediately();
	}

	public static State[] getPeople(int n) throws IOException {
		int[] skill = new int[n];
		int[] cost = new int[n];
		for(int i = 0; i < n; i++) {
			skill[i] = readInt();
		}
		for(int i = 0; i < n; i++) {
			cost[i] = readInt();
		}
		State[] ret = new State[n];
		for(int i = 0; i < n; i++) {
			ret[i] = new State(skill[i], cost[i], i);
		}
		Arrays.sort(ret, new SkillComp());
		return ret;
	}

	static class Bug implements Comparable<Bug> {
		public int index, skill;

		public Bug(int index, int skill) {
			super();
			this.index = index;
			this.skill = skill;
		}
		public int compareTo(Bug b) {
			return skill - b.skill;
		}
	}

	static class State {
		public int skill, cost, index;

		public State(int skill, int cost, int index) {
			super();
			this.skill = skill;
			this.cost = cost;
			this.index = index;
		}
	}

	static class SkillComp implements Comparator<State> {
		public int compare(State a, State b) {
			return a.skill - b.skill;
		}
	}

	static class CostComp implements Comparator<State> {
		public int compare(State a, State b) {
			return a.cost - b.cost;
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