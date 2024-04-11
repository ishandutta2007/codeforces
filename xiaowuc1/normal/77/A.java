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
			Map<String, Integer> map = new HashMap<String, Integer>();
			map.put("Anka", 0);
			map.put("Chapay", 1);
			map.put("Cleo", 2);
			map.put("Troll", 3);
			map.put("Dracul", 4);
			map.put("Snowy", 5);
			map.put("Hexadecimal", 6);
			boolean[][] grid = new boolean[7][7];
			int n = readInt();
			while(n-- > 0) {
				int a = map.get(nextToken());
				nextToken();
				int b = map.get(nextToken());
				grid[a][b] = true;
			}
			int[] list = new int[3];
			for(int i = 0; i < 3; i++) {
				list[i] = readInt();
			}
			int minDiff = Integer.MAX_VALUE;
			int maxLike = 0;
			for(int mask = 0; mask < 3*3*3*3*3*3*3; mask++) {
				int curr = mask;
				int[] amt = new int[7];
				int[] seen = new int[3];
				for(int i = 0; i < amt.length; i++) {
					amt[i] = curr % 3;
					curr /= 3;
					seen[amt[i]]++;
				}
				if(seen[0] == 0) continue;
				if(seen[1] == 0) continue;
				if(seen[2] == 0) continue;
				int max = 0;
				int min = Integer.MAX_VALUE;
				for(int i = 0; i < list.length; i++) {
					int now = list[i] / seen[i];
					max = Math.max(max, now);
					min = Math.min(min, now);
				}
				if(max-min < minDiff) {
					minDiff = Math.min(minDiff, max-min);
					maxLike = 0;
				}
				if(minDiff == max-min) {
					int like = 0;
					for(int i = 0; i < 7; i++) {
						for(int j = 0; j < 7; j++) {
							if(amt[i] == amt[j] && grid[i][j]) {
								like++;
							}
						}
					}
					maxLike = Math.max(maxLike, like);
				}
			}
			pw.println(minDiff + " " + maxLike);
		}
		exitImmediately();
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