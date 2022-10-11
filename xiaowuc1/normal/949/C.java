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
			int m = readInt();
			int h = readInt();
			int[] hours = new int[n];
			for(int i = 0; i < n; i++) {
				hours[i] = readInt();
			}
			init(n);
			while(m-- > 0) {
				int id1 = readInt()-1;
				int id2 = readInt()-1;
				if((hours[id1]+1)%h == hours[id2]) {
					addEdge(id1, id2);
				}
				if((hours[id2]+1)%h == hours[id1]) {
					addEdge(id2, id1);
				}
			}
			for(int i = 0; i < n; i++) {
				if(components[i] == -1) tarjan(i);
			}
			int bestComp = -1;
			int maxSize = Integer.MAX_VALUE;
			Set<Integer> considered = new HashSet<Integer>();
			ArrayList<Integer>[] allComps = new ArrayList[componentsIndex];
			for(int i = 0; i < allComps.length; i++) {
				allComps[i] = new ArrayList<Integer>();
			}
			for(int i = 0; i < n; i++) {
				allComps[components[i]].add(i);
			}
			for(int i = 0; i < allComps.length; i++) {
				if(allComps[i].size() >= maxSize) continue;
				boolean good = true;
				for(int out: allComps[i]) {
					for(int out2: edges[out]) {
						if(components[out2] != components[out]) {
							good = false;
							break;
						}
					}
					if(!good) break;
				}
				if(good) {
					bestComp = i;
					maxSize = allComps[i].size();
				}
			}
			pw.println(maxSize);
			for(int i = 0; i < maxSize; i++) {
				pw.print(allComps[bestComp].get(i)+1);
				if(i == maxSize-1) pw.println();
				else pw.print(" ");
			}
		}
		pw.close();
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

	public static void init(int n) {
		components = new int[n]; Arrays.fill(components, -1);
		indices = new int[n]; Arrays.fill(indices, -1);
		lowLink = new int[n]; Arrays.fill(lowLink, -1);
		indicesIndex = 0;
		componentsIndex = 0;
		tarjanStack = new Stack<TarjanState>();
		sccStack = new Stack<Integer>();
		inStack = new boolean[n];
		edges = new ArrayList[n];
		for(int i = 0; i < n; i++) {
			edges[i] = new ArrayList<Integer>();
		}
	}
	public static void addEdge(int x, int y) {
		edges[x].add(y);
	}
	
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