import java.awt.*;
import java.awt.event.*;
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

public class B {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;
	
	static final BigInteger MAX = BigInteger.valueOf(1100000000); 
	static final BigInteger TWO = BigInteger.valueOf(2);
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			long t = readLong();
			BigInteger n = BigInteger.valueOf(t);
			TreeSet<BigInteger> ret = new TreeSet<BigInteger>();
			for(int a = 0; (1L << a) - 1 <= t; a++)	{
				BigInteger minB = BigInteger.ZERO;
				BigInteger maxB = MAX;
				if(a != 0)	{
					BigInteger temp = n.divide(BigInteger.ONE.shiftLeft(a).subtract(BigInteger.ONE));
					if(temp.compareTo(maxB) < 0)	{
						maxB = temp;
					}
				}
				BigInteger ans = BigInteger.valueOf(-1);
				while(minB.compareTo(maxB) <= 0)	{
					BigInteger b = (minB.add(maxB)).divide(TWO);
					BigInteger x = b.shiftLeft(1).add(BigInteger.ONE);
					BigInteger curr = compute(a,x);
					if(curr.equals(n))	{
						ans = x;
						break;
					}
					if(curr.compareTo(n) > 0)	{
						maxB = b.subtract(BigInteger.ONE);
					}
					else	{
						minB = b.add(BigInteger.ONE);
					}
				}
				//System.out.println(n + " " + a + " " + minB + " " + maxB);
				if(ans.compareTo(BigInteger.ZERO) >= 0)	{
					ret.add(ans.shiftLeft(a));
				}
			}
			if(ret.isEmpty())	{
				ret.add(BigInteger.valueOf(-1));
			}
			for(BigInteger out: ret)	{
				pw.println(out);
			}
		}
		pw.close();
	}

	public static BigInteger compute(int a, BigInteger b)	{
		BigInteger l = b.multiply(b.subtract(BigInteger.ONE)).shiftRight(1);
		BigInteger r = b.multiply(BigInteger.ONE.shiftLeft(a).subtract(BigInteger.ONE));
		return l.add(r);
	}
	
	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}