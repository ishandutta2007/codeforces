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

	static int[][] dp;

	static LinkedList<Integer>[] edges;

	static int[] dist;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int[] list = new int[10];
		while(n-- > 0)	{
			list[readInt()]++;
		}
		if(list[0] == 0)	{
			pw.println(-1);
		}
		else	{
			int numOne = list[1] + list[4] + list[7];
			int numTwo = list[2] + list[5] + list[8];
			int mod = 0;
			for(int i = 0; i < list.length; i++)	{
				mod += i * list[i];
				mod %= 3;
			}
			if(mod == 0)	{
				gen(list);
			}
			else if(mod == 1)	{
				if(numOne < 1 && numTwo < 2)	{
					pw.println(-1);
				}
				else if(numOne >= 1)	{
					numOne = 1;
					for(int i = 1; i < 8; i += 3)	{
						if(numOne == 0)	{
							break;
						}
						if(list[i] > 0)	{
							list[i]--;
							numOne--;
							i -= 3;
						}
					}
					gen(list);
				}
				else	{
					numTwo = 2;
					for(int i = 2; i <= 8; i += 3)	{
						if(numTwo == 0)	{
							break;
						}
						if(list[i] > 0)	{
							list[i]--;
							numTwo--;
							i -= 3;
						}
					}
					gen(list);
				}
			}
			else	{
				if(numOne < 2 && numTwo < 1)	{
					pw.println(-1);
				}
				else if(numTwo >= 1)	{
					numTwo = 1;
					for(int i = 2; i <= 8; i += 3)	{
						if(numTwo == 0)	{
							break;
						}
						if(list[i] > 0)	{
							list[i]--;
							numTwo--;
							i -= 3;
						}
					}
					gen(list);
				}
				else	{
					numOne = 2;
					for(int i = 1; i <= 8; i += 3)	{
						if(numOne == 0)	{
							break;
						}
						if(list[i] > 0)	{
							list[i]--;
							numOne--;
							i -= 3;
						}
					}
					gen(list);
				}
			}
		}
		pw.close(); 
	}

	public static void gen(int[] list)	{
		StringBuilder sb = new StringBuilder();
		for(int i = 9; i >= 0; i--)	{
			while(list[i]-- > 0)	{
				if(i == 0 && sb.length() == 0)	{
					list[i] = 0;
				}
				sb.append(i);
			}
		}
		pw.println(sb.toString());
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