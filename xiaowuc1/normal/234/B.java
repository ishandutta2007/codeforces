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
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int n = readInt();
		int k = readInt();
		int[] list = new int[n];
		loadArray(list);
		boolean[] used = new boolean[n];
		int max = 100;
		TreeSet<Integer> ret = new TreeSet<Integer>();
		while(k-- > 0)	{
			int curr = -1;
			int index = -1;
			for(int i = 0; i < n; i++)	{
				if(!used[i] && list[i] > curr)	{
					curr = list[i];
					index = i;
				}
			}
			max = curr;
			ret.add(index+1);
			used[index] = true;
		}
		pw.println(max);
		StringBuilder sb = new StringBuilder();
		for(int out: ret)
			sb.append(out + " ");
		pw.println(sb.toString().trim());
		pw.close();
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
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