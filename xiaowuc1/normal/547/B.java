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

public class B {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int[] list = new int[n];
			TreeMap<Integer, ArrayList<Integer>> map = new TreeMap<Integer, ArrayList<Integer>>();
			int[] size = new int[n];
			for(int i = 0; i < n; i++) {
				list[i] = readInt();
				if(!map.containsKey(list[i])) {
					map.put(list[i], new ArrayList<Integer>());
				}
				map.get(list[i]).add(i);
			}
			int lastPlace = 0;
			int[] ret = new int[n+1];
			while(!map.isEmpty()) {
				int lastKey = map.lastKey();
				ArrayList<Integer> indices = map.remove(lastKey);
				for(int out: indices) {
					boolean toLeft = false;
					boolean toRight = false;
					toLeft = out > 0 && size[out-1] > 0;
					toRight = out < n-1 && size[out+1] > 0;
					if(toLeft && toRight) {
						int leftPlace = out-1 - (size[out-1] - 1);
						int rightPlace = (out+1) + (size[out+1] - 1);
						int actualSize = 1 + size[out-1] + size[out+1];
						size[leftPlace] = size[rightPlace] = actualSize;
						for(int a = lastPlace+1; a <= actualSize; a++) {
							ret[a] = lastKey;
						}
						lastPlace = Math.max(lastPlace, actualSize);
					}
					else if(toLeft) {
						int leftPlace = out-1 - (size[out-1] - 1);
						int actualSize = 1 + size[out-1];
						size[leftPlace] = size[out] = actualSize;
						for(int a = lastPlace+1; a <= actualSize; a++) {
							ret[a] = lastKey;
						}
						lastPlace = Math.max(lastPlace, actualSize);
					}
					else if(toRight) {
						int rightPlace = (out+1) + (size[out+1] - 1);
						int actualSize = 1 + size[out+1];
						size[out] = size[rightPlace] = actualSize;
						for(int a = lastPlace+1; a <= actualSize; a++) {
							ret[a] = lastKey;
						}
						lastPlace = Math.max(lastPlace, actualSize);
					}
					else {
						size[out] = 1;
						int actualSize = 1;
						for(int a = lastPlace+1; a <= actualSize; a++) {
							ret[a] = lastKey;
						}
						lastPlace = Math.max(lastPlace, actualSize);
					}
				}
			}
			for(int i = 1; i < n; i++) {
				pw.print(ret[i]);
				pw.print(" ");
			}
			pw.println(ret[n]);
		}
		pw.close();
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