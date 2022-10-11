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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			ArrayList<Integer> end = new ArrayList<Integer>();
			ArrayList<Integer> begin = new ArrayList<Integer>();
			int n = readInt();
			int qqq = readInt();
			int[] list = new int[n];
			for (int i = 0; i < list.length; i++) {
				list[i] = readInt();
			}
			for(int start = 1; start < n-1; )	{
				while(start > 0 && list[start-1] == list[start])
					start--;
				int curr = start+1;
				while(curr < n && list[curr] >= list[curr-1])	{
					curr++;
				}
				while(curr < n && list[curr] <= list[curr-1])	{
					curr++;
				}
				begin.add(start);
				end.add(curr-1);
				start = curr-1;
			}
			while(qqq-- > 0)	{
				int a = readInt()-1;
				int b = readInt()-1;
				if(n == 1 || a == b || a+1 == b)	{
					pw.println("Yes");
				}
				else	{
					int index = binSearch(begin, a);
					pw.println(end.get(index) >= b ? "Yes" : "No");
				}
			}
		}
		pw.close();
	}

	public static int binSearch(ArrayList<Integer> list, int want)	{
		int min = 0;
		int max = list.size()-1;
		while(min != max)	{
			int mid = (min+max)/2;
			if(min == mid)
				mid++;
			if(list.get(mid) <= want)	{
				min = mid;
			}
			else	{
				max = mid-1;
			}
		}
		return min;
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