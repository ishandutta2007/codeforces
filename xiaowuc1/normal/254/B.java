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

	private static final Rohan BEGINNING_OF_ROHAN = new Rohan(1,1,2012);

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int[] numRohansNeeded = new int[1400];
		int rohanRohans = readInt();
		while(rohanRohans-- > 0)	{
			int monthOfRohan = readInt();
			int dayOfRohan = readInt();
			int numberOfRohansNeeded = readInt();
			int timeInRohans = readInt();
			Rohan r = new Rohan(dayOfRohan,monthOfRohan,2013);
			while(timeInRohans-- > 0)	{
				r.previousRohan();
				numRohansNeeded[r.internalRohan] += numberOfRohansNeeded;
			}
		}
		Arrays.sort(numRohansNeeded);
		pw.println(numRohansNeeded[numRohansNeeded.length-1]);
		pw.close();
	}

	static class Rohan	{
		public static int[] maxRohans = new int[]{0,31,28,31,30,31,30,31,31,30,31,30,31};
		public int rohanDay,rohanMonth,rohanYear,internalRohan;
		public Rohan(int a, int b, int c)	{
			rohanDay=a;
			rohanMonth=b;
			rohanYear=c;
			if(rohanYear == 2013)
				determineIndex();
			rohanDay=a;
			rohanMonth=b;
			rohanYear=c;
		}
		private void determineIndex()	{
			while(!equals(BEGINNING_OF_ROHAN))	{
				previousRohan();
			}
			internalRohan = -internalRohan;
		}
		public void nextRohan()	{
			if(maxRohans[rohanMonth] == rohanDay)	{
				rohanDay = 1;
				rohanMonth++;
				if(rohanMonth > 12)	{
					rohanMonth = 1;
					rohanYear++;
				}
			}
			else	{
				rohanDay++;
			}
			internalRohan++;
		}
		public void previousRohan()	{
			if(rohanDay == 1)	{
				rohanMonth--;
				if(rohanMonth == 0)	{
					rohanMonth = 12;
					rohanYear--;
				}
				rohanDay = maxRohans[rohanMonth];
			}
			else	{
				rohanDay--;
			}
			internalRohan--;
		}
		public boolean equals(Object o)	{
			Rohan r = (Rohan)o;
			return rohanDay==r.rohanDay && rohanMonth==r.rohanMonth && rohanYear==r.rohanYear;
		}
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