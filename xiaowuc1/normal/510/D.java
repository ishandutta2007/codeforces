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
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] d = new int[n];
			int[] c = new int[n];
			for(int i = 0; i < n; i++) {
				d[i] = readInt();
			}
			for(int i = 0; i < n; i++) {
				c[i] = readInt();
			}
			Map<Integer, Integer> dp = new HashMap<>();
			dp.put(0, 0);
			PriorityQueue<Vertex> q = new PriorityQueue<>();
			q.add(new Vertex(0, 0));
			while(!q.isEmpty()) {
				Vertex curr = q.poll();
				for(int i = 0; i < n; i++) {
					int nv = gcd(curr.v, d[i]);
					int nc = curr.w + c[i];
					if(nc < dp.getOrDefault(nv, 1 << 30)) {
						dp.put(nv, nc);
						q.add(new Vertex(nv, nc));
					}
				}
			}
			if(dp.containsKey(1)) {
				pw.println(dp.get(1));
			}
			else {
				pw.println(-1);
			}
		}
		exitImmediately();
	}

	public static int gcd(int a, int b) {
		if(a==0) return b;
		if(b==0) return a;
		return gcd(b, a%b);
	}
	
	static class Vertex implements Comparable<Vertex> {
		public int v, w;
		public Vertex(int a, int b) {
			v=a;
			w=b;
		}
		public int compareTo(Vertex vv) {
			return w - vv.w;
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
		String s = br.readLine();
		if(s == null) {
			exitImmediately();
		}
		st = null;
		return s;
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			st = new StringTokenizer(nextLine().trim());
		}
		return st.nextToken();
	}
}