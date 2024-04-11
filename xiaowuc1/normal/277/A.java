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
			int n = readInt();
			readInt();
			Set<Integer>[] sets = new Set[n];
			int numConnect = 0;
			int numEmpty = 0;
			for (int i = 0; i < sets.length; i++) {
				sets[i] = new HashSet<Integer>();
				int qqq = readInt();
				while(qqq-- > 0)	{
					sets[i].add(readInt());
				}
			}
			boolean[] seen = new boolean[n];
			for (int i = 0; i < seen.length; i++) {
				if(!seen[i])	{
					if(sets[i].isEmpty())	{
						numEmpty++;
					}
					else	{
						numConnect++;
						seen[i] = true;
						LinkedList<Integer> q = new LinkedList<Integer>();
						q.add(i);
						while(!q.isEmpty())	{
							int curr = q.removeFirst();
							for(int out = 0; out < n; out++)	{
								if(!seen[out])	{
									boolean win = false;
									for(int out2: sets[curr])	{
										if(sets[out].contains(out2))	{
											win = true;
											break;
										}
									}
									if(win)	{
										seen[out] = true;
										q.addLast(out);
									}
								}
							}
						}
					}
				}
			}
			pw.println(Math.max(0,numConnect-1) + numEmpty);
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