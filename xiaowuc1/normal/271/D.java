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
			String token = nextToken();
			String good = nextToken();
			int max = readInt();
			Node root = new Node();
			for(int i = 0; i < token.length(); i++)	{
				int bad = 0;
				Node curr = root;
				for(int j = i; j < token.length(); j++)	{
					if(good.charAt(token.charAt(j)-'a') == '0')	{
						bad++;
					}
					if(bad <= max)	{
						if(curr.list[token.charAt(j)-'a'] == null)	{
							curr.list[token.charAt(j)-'a'] = new Node();
						}
						curr = curr.list[token.charAt(j)-'a'];
					}
				}
			}
			pw.println(root.count()-1);
		}
		pw.close();
	}

	static class Node	{
		public Node[] list;
		public Node()	{
			list = new Node[26];
		}
		public int count()	{
			int ret = 1;
			for(Node out: list)	{
				if(out != null)	{
					ret += out.count();
				}
			}
			return ret;
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