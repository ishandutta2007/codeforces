import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
import java.util.Queue;

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
			int n = readInt();
			int[] list = new int[n];
			int[] sorted = new int[n];
			for(int i = 0; i < n; i++)	{
				list[i] = sorted[i] = readInt();
			}
			for(int k = 0; k < 25; k++)	{
				int i = (int)(n*Math.random());
				int j = (int)(n*Math.random());
				if(i != j)	{	
					sorted[i] ^= sorted[j];
					sorted[j] ^= sorted[i];
					sorted[i] ^= sorted[j];
				}
			}
			Arrays.sort(sorted);
			long ret = 0;
			BIT bit = new BIT(n+10);
			int count = 0;
			for(int out: list)	{
				int index = Arrays.binarySearch(sorted, out) + 1;
				int numBefore = bit.read(index);
				int numAfter = count - numBefore;
				int numValid = index - numBefore - 1;
				ret += numValid * 1L * numAfter;
				//pw.printf("For %d we get %d %d %d\n", out, numBefore, numAfter, numValid);
				bit.update(index, 1);
				count++;
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class BIT {
		int[] tree;
		public BIT(int n)	{
			tree = new int[n+1];
		}
		public void update(int idx ,int val){
			while(idx < tree.length){
				tree[idx] += val;
				idx += (idx & -idx);
			}
		}
		public int read(int idx){
			int sum = 0;
			while(idx > 0){
				sum += tree[idx];
				idx -= (idx & -idx);
			}
			return sum;
		}
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