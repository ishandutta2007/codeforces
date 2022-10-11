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
		LinkedList<Integer>[] list = new LinkedList[5000];
		for(int i = 0; i < list.length; i++)
			list[i] = new LinkedList<Integer>();
		int n = readInt();
		for(int i = 1; i <= 2*n; i++)	{
			list[readInt()-1].add(i);
		}
		boolean win = true;
		for(LinkedList<Integer> out: list)	{
			if(out.size()%2==1)	{
				win = false;
				break;
			}
		}
		if(!win)	{
			pw.println(-1);
		}
		else	{
			for(LinkedList<Integer> out: list)	{
				while(!out.isEmpty())	{
					pw.println(out.removeFirst() + " " + out.removeFirst());
				}
			}
		}
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