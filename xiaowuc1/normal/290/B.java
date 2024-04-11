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

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			String[] str = {
					"111111101010101111100101001111111",
					"100000100000000001010110001000001",
					"101110100110110000011010001011101",
					"101110101011001001111101001011101",
					"101110101100011000111100101011101",
					"100000101010101011010000101000001",
					"111111101010101010101010101111111",
					"000000001111101111100111100000000",
					"100010111100100001011110111111001",
					"110111001111111100100001000101100",
					"011100111010000101000111010001010",
					"011110000110001111110101100000011",
					"111111111111111000111001001011000",
					"111000010111010011010011010100100",
					"101010100010110010110101010000010",
					"101100000101010001111101000000000",
					"000010100011001101000111101011010",
					"101001001111101111000101010001110",
					"101101111111000100100001110001000",
					"000010011000100110000011010000010",
					"001101101001101110010010011011000",
					"011101011010001000111101010100110",
					"111010100110011101001101000001110",
					"110001010010101111000101111111000",
					"001000111011100001010110111110000",
					"000000001110010110100010100010110",
					"111111101000101111000110101011010",
					"100000100111010101111100100011011",
					"101110101001010000101000111111000",
					"101110100011010010010111111011010",
					"101110100100011011110110101110000",
					"100000100110011001111100111100000",
					"111111101101000101001101110010001"
					};
			pw.println(str[readInt()].charAt(readInt()));
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