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
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int[] costs = new int[n];
			componentsIndex = 0;
			indicesIndex = 0;
			edges = new ArrayList[n];
			components = new int[n];
			indices = new int[n];
			lowLink = new int[n];
			inStack = new boolean[n];
			Arrays.fill(indices, -1);
			tarjanStack = new Stack<TarjanState>();
			sccStack = new Stack<Integer>();
			for(int i = 0; i < n; i++) {
				costs[i] = readInt();
				edges[i] = new ArrayList<Integer>();
			}
			int m = readInt();
			while(m-- > 0) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
			}
			for(int i = 0; i < n; i++) {
				tarjan(i);
			}
			int[] minCost = new int[componentsIndex];
			int[] numAt = new int[componentsIndex];
			Arrays.fill(minCost, 1 << 30);
			for(int i = 0; i < n; i++) {
				if(costs[i] < minCost[components[i]]) {
					minCost[components[i]] = costs[i];
					numAt[components[i]] = 0;
				}
				if(costs[i] == minCost[components[i]]) {
					numAt[components[i]]++;
				}
			}
			long cost = 0;
			long right = 1;
			for(int i = 0; i < minCost.length; i++) {
				cost += minCost[i];
				right *= numAt[i];
				right %= 1000000007;
			}
			pw.println(cost + " " + right);
		}
		exitImmediately();
	}

	static ArrayList<Integer>[] edges;
	static int[] components;
	static int[] indices;
	static int[] lowLink;
	static int indicesIndex;
	static int componentsIndex;
	static Stack<TarjanState> tarjanStack;
	static Stack<Integer> sccStack;
	static boolean[] inStack;

	static class TarjanState {
		public int index;
		public int edgeNum;
		public boolean checkEarlier;
		public TarjanState(int index, int edgeNum, boolean checkEarlier) {
			super();
			this.index = index;
			this.edgeNum = edgeNum;
			this.checkEarlier = checkEarlier;
		}
	}

	public static void tarjan(int onlyUseThisVariableInTheFirstLine) {    
		tarjanStack.push(new TarjanState(onlyUseThisVariableInTheFirstLine, 0, false));
		while(!tarjanStack.isEmpty()) {
			TarjanState now = tarjanStack.pop();
			if(now.edgeNum == 0) {
				if(indices[now.index] >= 0) {
					continue;
				}
				inStack[now.index] = true;
				indices[now.index] = indicesIndex;
				lowLink[now.index] = indicesIndex;
				indicesIndex++;
				sccStack.push(now.index);
			}
			if(now.checkEarlier) {
				lowLink[now.index] = Math.min(lowLink[now.index], lowLink[edges[now.index].get(now.edgeNum-1)]);
			}
			if(now.edgeNum < edges[now.index].size()) {
				int next = edges[now.index].get(now.edgeNum);
				if(indices[next] == -1) {
					tarjanStack.push(new TarjanState(now.index, now.edgeNum + 1, true));
					tarjanStack.push(new TarjanState(next, 0, false));
				}
				else {
					tarjanStack.push(new TarjanState(now.index, now.edgeNum + 1, false));
					if(inStack[next]) {
						lowLink[now.index] = Math.min(lowLink[now.index], indices[next]);
					}
				}
			}
			else {
				if(lowLink[now.index] == indices[now.index]) {
					while(true) {
						int rem = sccStack.pop();
						inStack[rem] = false;
						components[rem] = componentsIndex;
						if(rem == now.index) {
							break;
						}
					}
					componentsIndex++;
				}
			}
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