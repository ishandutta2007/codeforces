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
		int pSpeed = readInt();
		int dSpeed = readInt();
		if(pSpeed >= dSpeed)	{
			pw.println(0);
		}
		else	{
			int time = readInt();
			int wait = readInt();
			int dist = readInt();
			double maxTime = dist * 1.0 / pSpeed;
			int min = 0;
			int max = 1000000000;
			while(min != max)	{
				int mid = min;
				double curr = time;
				for(int qq = 0; qq < mid && curr < maxTime; qq++)	{
					// a + b*t = c*t
					// t = a / (c-b)
					double inc = curr*pSpeed / (dSpeed - pSpeed);
					double loc = inc * dSpeed;
					curr += inc + wait + loc / dSpeed;
				}
				curr += curr*pSpeed / (dSpeed - pSpeed);
				if(curr >= maxTime)
					max = mid;
				else
					min = mid+1;
			}
			pw.println(min);
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