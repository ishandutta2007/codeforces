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

	static byte[][] grid;

	static int row;
	static int n;
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		n = readInt();
		grid = new byte[62][n+1];
		long[] list = new long[n];
		loadArray(list);
		long finalxor = 0;
		for(long out: list)
			finalxor ^= out;
		row = 0;
		byte[] ret = new byte[n];
		for(int bit = 61; bit >= 0; bit--)	{
			if((finalxor & (1L << bit)) != 0)	{
				continue;
			}
			for(int k = 0; k < n; k++)	{
				if((list[k]&(1L<<bit)) != 0)	{
					grid[row][k] = 1;
				}
				else	{
					grid[row][k] = 0;
				}
			}
			grid[row][n] = 1;
			rref();
		}
		for(int bit = 61; bit >= 0; bit--)	{
			if((finalxor & (1L << bit)) == 0)	{
				continue;
			}
			for(int k = 0; k < n; k++)	{
				if((list[k]&(1L<<bit)) != 0)	{
					grid[row][k] = 1;
				}
				else	{
					grid[row][k] = 0;
				}
			}
			grid[row][n] = 0;
			rref();
		}
		Arrays.fill(ret, (byte)2);
		for(int i = 0; i < row; i++)	{
			if(grid[i][n] == 1)	{
				for(int j = 0; j < n; j++)	{
					if(grid[i][j] == 1)	{
						ret[j] = 1;
						break;
					}
				}
			}
		}
		pw.print(ret[0]);
		for(int i = 1; i < n; i++)	{
			pw.print(" " + ret[i]);
		}
		pw.println();
		pw.close();
	}

	public static void rref()	{
		int numRowsSeen = 0;
		boolean[] used = new boolean[row];
		for(int col = 0; col < n && numRowsSeen < row; col++)	{
			int myRow = -1;
			for(int i = 0; i < row; i++)	{
				if(grid[i][col] == 1 && !used[i])	{
					myRow = i;
					break;
				}
			}
			if(myRow == -1)
				continue;
			used[myRow] = true;
			for(int i = 0; i < row; i++)	{
				if(!used[i] && grid[i][col] == 1)	{
					throw new RuntimeException("WHAT");
				}
			}
			numRowsSeen++;
			if(grid[row][col] == 1)	{
				for(int k = 0; k <= n; k++)	{
					grid[row][k] ^= grid[myRow][k];
				}
			}
		}
		boolean nonZeroPresent = false;
		for(int i = 0; !nonZeroPresent && i < n; i++)	{
			nonZeroPresent = grid[row][i] == 1;
		}
		if(!nonZeroPresent)	{
			return;
		}
		int lowCol = 0;
		while(lowCol < grid[row].length && grid[row][lowCol] == 0)
			lowCol++;
		if(lowCol != grid[row].length)	{
			for(int i = 0; i < row; i++)	{
				if(grid[i][lowCol] == 1)	{
					for(int k = 0; k <= n; k++)	{
						grid[i][k] ^= grid[row][k];
					}
				}
			}
		}
		row++;
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