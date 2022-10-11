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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		long max = readLong();
		if(max == 1)
			pw.println("1\n0");
		else	{
			boolean[] comp = new boolean[10000000];
			comp[0] = comp[1] = true;
			for(int i = 2; i * i < comp.length; i++)	{
				if(!comp[i])	{
					for(int j = i*i; j < comp.length; j += i)
						comp[j] = true;
				}
			}
			long now = -1;
			int num = 0;
			for(int i = 2; i < comp.length; i++)	{
				if(!comp[i])	{
					if(max%i==0)	{
						num++;
						if(now == -1)	{
							now = i;
						}
						else if(now * i != max){
							pw.println(1);
							pw.println(now * i);
							pw.close();
							return;
						}
					}
				}
			}
			if(num == 0)	{
				pw.println(1);
				pw.println(0);
			}
			else	{
				if(num > 1)	{
					pw.println(2);
				}
				else	{
					if(now == max)	{
						pw.println(1);
						pw.println(0);
					}
					else if(now * now == max || (max%(now*now)) != 0)	{
						pw.println(2);
					}
					else	{
						pw.println(1);
						pw.println(now * now);
					}
				}
			}
		}
		pw.close();
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