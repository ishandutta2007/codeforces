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

	static int numFloor;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int k = readInt();
		char[] list = nextToken().toCharArray();
		if(k == 2)	{
			int leftRet = 0;
			int rightRet = 0;
			for(int i = 0; i < list.length; i++)	{
				if((i%2 == 0) == (list[i] == 'A'))
					rightRet++;
				else
					leftRet++;
			}
			if(leftRet < rightRet)	{
				pw.println(leftRet);
				for(int i = 0; i < list.length; i++)	{
					pw.print((char)('A' + (i%2)));
				}
			}
			else	{
				pw.println(rightRet);
				for(int i = 0; i < list.length; i++)	{
					pw.print((char)('A' + ((i+1)%2)));
				}
			}
		}
		else	{
			int ret = 0;
			for(int i = 1; i < list.length; i++)	{
				if(list[i] == list[i-1])	{
					for(char a = 'A'; a < 'A' + k; a++)	{
						boolean leftFine = list[i-1] != a;
						boolean rightFine = i+1 == list.length || list[i+1] != a;
						if(leftFine && rightFine)	{
							ret++;
							list[i] = a;
							break;
						}
					}
				}
			}
			pw.println(ret);
			pw.println(new String(list));
		}
		pw.close(); 
	}

	/* NOTEBOOK CODE */

	public static void loadArray(int[][] grid) throws IOException {
		for(int[] a: grid)
			loadArray(a);
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}

	public static void loadArray(long[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readLong();
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