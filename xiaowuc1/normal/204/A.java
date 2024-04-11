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

	static long[] tenPow;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		tenPow = new long[19];
		tenPow[0] = 1;
		for(int i = 1; i < tenPow.length; i++)	{
			tenPow[i] = tenPow[i-1] * 10;
		}
		long min = readLong();
		long max = readLong();
		pw.println(count(max) - count(min-1));
		pw.close();
	}

	public static long count(long max)	{
		long ret = 0;
		for(int i = 1; i <= 9; i++)	{
			if(i <= max)	{
				ret++;
			}
		}
		for(int i = 11; i <= 99; i += 11)	{
			if(i <= max)	{
				ret++;
			}
		}
		String str = Long.toString(max);
		for(int len = 3; len <= str.length(); len++)	{
			for(int d = 1; d <= 9; d++)	{
				if(len < str.length())	{
					ret += tenPow[len-2];
				}
				// len == str.length()
				else if(d > str.charAt(0) - '0'){
					break;
				}
				else if(d == str.charAt(0) - '0')	{
					ret += count(str.substring(1, str.length()-1));
					if(str.charAt(0) - '0' > (max%10))	{
						ret--;
					}
				}
				else	{
					ret += tenPow[len-2];
				}
			}
		}
		return ret;
	}

	public static long gen(int dig, int len)	{
		char[] list = new char[len];
		Arrays.fill(list, '0');
		list[0] = list[list.length-1] = (char)(dig + '0');
		return Long.parseLong(new String(list));
	}

	public static long count(String str)	{
		if(str.length() == 0)	{
			return 1;
		}
		long ret = 0;
		for(int d = 0; d < str.charAt(0) - '0'; d++)	{
			ret += tenPow[str.length()-1];
		}
		ret += count(str.substring(1));
		return ret;
	}

	/* NOTEBOOK CODE */

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