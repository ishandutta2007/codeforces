import java.awt.*;
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

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	static int[] dx = new int[]{-1,0,0,0,1};
	static int[] dy = new int[]{0,-1,0,1,0};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int k = readInt();
			if(n/k < 3)	{
				pw.println(-1);
			}
			else if(3*k == n)	{
				if(k%2 == 0)	{
					int[] ans = new int[n];
					for(int a = 0; a < k; a+=2)	{
						ans[3*a] = ans[3*a+2] = ans[3*a+5] = a+1;
						ans[3*a+1] = ans[3*a+3] = ans[3*a+4] = a+2;
					}
					StringBuilder sb = new StringBuilder();
					for (int i : ans) {
						sb.append(i + " ");
					}
					pw.println(sb.toString().trim());
				}
				else	{
					int[] ans = new int[n];
					ans[0] = 1;
					ans[1] = 1;
					ans[2] = 2;
					ans[3] = 1;
					ans[4] = 3;
					ans[5] = 2;
					ans[6] = 2;
					ans[7] = 3;
					ans[8] = 3;
					for(int a = 3; a < k; a+=2)	{
						ans[3*a] = ans[3*a+2] = ans[3*a+5] = a+1;
						ans[3*a+1] = ans[3*a+3] = ans[3*a+4] = a+2;
					}
					StringBuilder sb = new StringBuilder();
					for (int i : ans) {
						sb.append(i + " ");
					}
					pw.println(sb.toString().trim());
				}
			}
			else	{
				int[] ans = new int[n];
				Arrays.fill(ans, 1);
				int start = 0;
				int end = n-1;
				for(int a = 1; a <= k; a++)	{
					ans[start++] = a;
					ans[start++] = a;
					ans[end--] = a;
				}
				StringBuilder sb = new StringBuilder();
				for (int i : ans) {
					sb.append(i + " ");
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
	}

	public static boolean good(int curr)	{
		String ret = String.valueOf(curr);
		Set<Character> set = new HashSet<Character>();
		for(int i = 0; i < ret.length(); i++)	{
			set.add(ret.charAt(i));
		}
		return set.size() == ret.length();
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
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}