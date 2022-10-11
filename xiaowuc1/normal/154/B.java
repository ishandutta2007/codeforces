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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int qq = readInt();
		boolean[] comp = new boolean[n+1];
		comp[0] = comp[1] = true;
		for(int i = 2; i * i < comp.length; i++)	{
			if(!comp[i])	{
				for(int j = i*i; j < comp.length; j += 2*i)	{
					comp[j] = true;
				}
			}
		}
		ArrayList<Integer> primes = new ArrayList<Integer>();
		for(int i = 2; i < comp.length; i++)	{
			if(!comp[i])	{
				primes.add(i);
			}
		}
		Set<Integer>[] cert = new HashSet[n+1];
		ArrayList<Integer>[] primeDiv = new ArrayList[n+1];
		for(int i = 1; i < primeDiv.length; i++)	{
			primeDiv[i] = new ArrayList<Integer>();
		}
		for(int prime: primes)	{
			for(int k = 1; k * prime < primeDiv.length; k++)	{
				primeDiv[k*prime].add(prime);
			}
		}
		for(int i = 0; i < cert.length; i++)	{
			cert[i] = new HashSet<Integer>();
		}
		boolean[] on = new boolean[n+1];
		while(qq-- > 0)	{
			String state = nextToken();
			int num = readInt();
			if(state.equals("-"))	{
				if(on[num])	{
					pw.println("Success");
					on[num] = false;
					for(int out: primeDiv[num])
						cert[out].remove(num);
				}
				else	{
					pw.println("Already off");
				}
			}
			else	{
				if(on[num])	{
					pw.println("Already on");
				}
				else	{
					boolean can = true;
					int certf = -1;
					for(int factor: primeDiv[num])	{
						if(!cert[factor].isEmpty())	{
							for(int out: cert[factor])	{
								certf = out;
								can = false;
								break;
							}
							break;
						}
					}
					if(!can)	{
						pw.println("Conflict with " + certf);
					}
					else	{
						pw.println("Success");
						on[num] = true;
						for(int out: primeDiv[num])	{
							cert[out].add(num);
						}
					}
				}
			}
		}
		pw.close(); 
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