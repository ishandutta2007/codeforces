import java.math.*;
import java.io.*;
import java.util.*;
public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int[] list;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			list = new int[n];
			for (int i = 0; i < list.length; i++) {
				list[i] = readInt();
			}
			int min = getMin();
			int max = getMax();
			if(min == max)	{
				pw.printf("unique\n%d\n", min);
			}
			else	{
				pw.println("not unique");
			}
		}
		pw.close();
	}

	public static int getMin()	{
		double min = 10;
		double max = 1e8;
		outer: for(int qq = 0; qq < 100; qq++)	{
			double mid = (min+max)/2;
			int currLoc = 0;
			double curr = 0;
			for(int i = 0; i < list.length; i++)	{
				curr += mid;
				int shift = (int)(curr/10);
				if(currLoc + shift > list[i])	{
					max = mid;
					continue outer;
				}
				else if(currLoc + shift < list[i])	{
					min = mid;
					continue outer;
				}
				currLoc += shift;
				curr -= shift * 10;
			}
			max = mid;
		}
		int currLoc = 0;
		double curr = 0;
		for(int i = 0; i < list.length; i++)	{
			curr += max;
			int shift = (int)(curr/10);
			currLoc += shift;
			curr -= shift * 10;
		}
		curr += max;
		return currLoc + (int)(curr/10);
	}
	
	public static int getMax()	{
		double min = 10;
		double max = 1e8;
		outer: for(int qq = 0; qq < 100; qq++)	{
			double mid = (min+max)/2;
			int currLoc = 0;
			double curr = 0;
			for(int i = 0; i < list.length; i++)	{
				curr += mid;
				int shift = (int)(curr/10);
				if(currLoc + shift > list[i])	{
					max = mid;
					continue outer;
				}
				else if(currLoc + shift < list[i])	{
					min = mid;
					continue outer;
				}
				currLoc += shift;
				curr -= shift * 10;
			}
			min = mid;
		}
		int currLoc = 0;
		double curr = 0;
		for(int i = 0; i < list.length; i++)	{
			curr += min;
			int shift = (int)(curr/10);
			currLoc += shift;
			curr -= shift * 10;
		}
		curr += min;
		return currLoc + (int)(curr/10);
	}
	
	
	
	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}