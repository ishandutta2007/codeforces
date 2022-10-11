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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	static boolean[][] grid;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int qqq = readInt();
			String s = nextToken();
			while(qqq-- > 0)	{
				int[] ret = new int[10];
				int a = readInt()-1;
				int b = readInt();
				String program = s.substring(a,b);
				int cp = 0;
				boolean right = true;
				while(cp >= 0 && cp < program.length())	{
					if(Character.isDigit(program.charAt(cp)))	{
						ret[program.charAt(cp)-'0']++;
						int orig = cp;
						if(right)	{
							cp++;
						}
						else	{
							cp--;
						}
						if(program.charAt(orig) == '0')	{
							program = program.substring(0,orig) + program.substring(orig+1);
							if(right)	{
								cp--;
							}
						}
						else	{
							program = program.substring(0,orig) + (program.charAt(orig) - '1') + program.substring(orig+1);
						}
						
					}
					else	{
						int orig = cp;
						if(program.charAt(cp) == '<')	{
							right = false;
						}
						else	{
							right = true;
						}
						if(right)	{
							cp++;
						}
						else	{
							cp--;
						}
						if(cp >= 0 && cp < program.length())	{
							if(program.charAt(cp) == '<' || program.charAt(cp) == '>')	{
								program = program.substring(0,orig) + program.substring(orig+1);
								if(right)	{
									cp--;
								}
							}
						}
					}
				}
				StringBuilder sb = new StringBuilder();
				for(int out: ret)	{
					sb.append(out + " ");
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
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