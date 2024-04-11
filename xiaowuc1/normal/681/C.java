import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			ArrayList<String> ret = new ArrayList<String>();
			PriorityQueue<Integer> q = new PriorityQueue<Integer>();
			while(n-- > 0) {
				String type = nextToken();
				if(type.equals("removeMin")) {
					if(q.isEmpty()) {
						ret.add("insert 1");
					}
					else {
						q.poll();
					}
					ret.add("removeMin");
				}
				else if(type.equals("insert")) {
					int curr = readInt();
					q.add(curr);
					ret.add("insert " + curr);
				}
				else {
					int want = readInt();
					while(!q.isEmpty() && q.peek() < want) {
						ret.add("removeMin");
						q.poll();
					}
					if(q.isEmpty() || q.peek() != want) {
						ret.add("insert " + want);
						q.add(want);
					}
					ret.add("getMin " + want);
				}
			}
			pw.println(ret.size());
			for(String out: ret) {
				pw.println(out);
			}
		}
		exitImmediately();
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