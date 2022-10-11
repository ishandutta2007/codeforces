import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class E {
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
			Set<Integer>[] edges = new Set[n];
			for(int i = 0; i < n; i++) {
				edges[i] = new HashSet<Integer>();
			}
			for(int i = 1; i < n; i++) {
				int a = readInt()-1;
				int b = readInt()-1;
				edges[a].add(b);
				edges[b].add(a);
			}
			Map<Integer, Map<Integer, Integer>> existent = new HashMap<Integer, Map<Integer, Integer>>();
			for(int i = 0; i < n; i++) {
				if(edges[i].size() != 1) continue;
				int current = i;
				int length = 0;
				int parent = -1;
				while(true) {
					while(true) {
						if(edges[current].size() > 2) {
							break;
						}
						if(edges[current].size() == 1 && parent != -1) {
							break;
						}
						for(int out: edges[current]) {
							if(out != parent){
								parent = current;
								current = out;
								length++;
								break;
							}
						}
					}
					if(edges[current].size() == 1) {
						break;
					}
					if(!existent.containsKey(current)) {
						existent.put(current, new HashMap<Integer, Integer>());
					}
					Map<Integer, Integer> distanceToVertex = existent.get(current);
					if(!distanceToVertex.containsKey(length)) {
						distanceToVertex.put(length, parent);
						break;
					}
					else {
						kill(edges, distanceToVertex.get(length), current);
						distanceToVertex.remove(length);
					}
				}
			}
			int numV = 0;
			boolean good = true;
			for(int i = 0; i < n; i++) {
				if(edges[i].size() > 0) {
					numV++;
				}
				if(edges[i].size() > 2) {
					good = false;
				}
			}
			if(!good) {
				pw.println(-1);
				continue;
			}
			numV--;
			while(numV%2 == 0) {
				numV /= 2;
			}
			pw.println(numV);
		}
		pw.close();
	}

	public static void kill(Set<Integer>[] edges, int curr, int stop) {
		edges[stop].remove(curr);
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(curr);
		while(!q.isEmpty()) {
			curr = q.removeFirst();
			for(int out: edges[curr]) {
				if(out != stop) {
					q.add(out);
				}
			}
			edges[curr] = new HashSet<Integer>();
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