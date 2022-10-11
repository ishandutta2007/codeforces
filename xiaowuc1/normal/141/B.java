import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int maxX, maxY;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int a = readInt();
		int x = readInt();
		int y = readInt();
		if(y%a==0)	{
			pw.println(-1);
		}
		else	{
			int min = 1;
			for(int row = 1; true; row++)	{
				if(y > a*(row-1) && y < a * row)	{
					if(row == 1 || row%2 == 0)	{
						double leftX = -a/2.;
						double rightX = a/2.;
						if(x > leftX && x < rightX)	{
							pw.println(min);
						}
						else	{
							pw.println(-1);
						}
					}
					else	{
						if(x > -a && x < 0)	{	
							pw.println(min);
						}
						else if(x > 0 && x < a)	{
							pw.println(min+1);
						}
						else	{
							pw.println(-1);
						}
					}
					break;
				}
				else	{
					if(row == 1 || row%2==0)
						min++;
					else
						min += 2;
				}
			}
		}
		pw.close();
	}

	public static boolean valid(long x, long y)	{
		return x >= 1 && x <= maxX && y >= 1 && y <= maxY;
	}
	
	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}