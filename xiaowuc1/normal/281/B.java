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

	static int[] dx = new int[]{1,0,-1,0};
	static int[] dy = new int[]{0,1,0,-1};
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			Fraction ret = new Fraction(0,1);
			long a = readInt();
			long b = readInt();
			long n = readInt();
			Fraction diff = new Fraction(a,b).subtract(ret).abs();
			for(int i = 1; i <= n; i++)	{
				long chooseN = i * a / b;
				chooseN--;
				for(int k = 0; k < 4; k++)	{
					Fraction go = new Fraction(chooseN, i);
					Fraction ourDiff = go.subtract(new Fraction(a,b)).abs();
					if(ourDiff.compareTo(diff) < 0)	{
						diff = ourDiff;
						ret = go;
					}
					chooseN++;
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class Fraction implements Comparable<Fraction> {
		public long n,d;
		public Fraction(long a, long b)	{
			n=a;
			d=b;
			long g = gcd(n,d);
			n /= g;
			d /= g;
			if(d < 0)	{
				d = -d;
				n = -n;
			}
		}
		public Fraction add(Fraction f)	{
			return new Fraction(n*f.d + d*f.n, d * f.d);
		}
		public Fraction subtract(Fraction f)	{
			return new Fraction(n*f.d - d*f.n, d * f.d);
		}
		public Fraction multiply(Fraction f)	{
			return new Fraction(n*f.n, d * f.d);
		}
		public Fraction divide(Fraction f)	{
			return new Fraction(n*f.d, d * f.n);
		}
		public Fraction abs()	{
			return new Fraction(Math.abs(n), Math.abs(d));
		}
		private long gcd(long a, long b)	{
			if(a == 0)
				return b;
			if(b == 0)
				return a;
			return gcd(b,a%b);
		}
		public int compareTo(Fraction f)	{
			long a = n * f.d;
			long b = d * f.n;
			if(a < b)	{
				return -1;
			}
			if(a > b)	{
				return 1;
			}
			return 0;
		}
		public String toString()	{
			return n+"/"+d;
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