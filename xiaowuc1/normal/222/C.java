import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Math.max;
import static java.lang.Math.min;
import static java.util.Arrays.binarySearch;
import static java.util.Arrays.sort;
import static java.util.Collections.binarySearch;
import static java.util.Collections.shuffle;
import static java.util.Collections.sort;

public class C {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	static final int NUM_PRIMES = 664579;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int n = readInt();
		int m = readInt();
		boolean[] comp = new boolean[10000000];
		for(int i = 3; i * i < comp.length; i += 2)	{
			if(!comp[i])	{
				for(int j = i*i; j < comp.length; j += 2*i)	{
					comp[j] = true;
				}
			}
		}
		int[] p = new int[NUM_PRIMES];
		p[0] = 2;
		int c = 1;
		for(int i = 3; i < comp.length; i += 2)	{
			if(!comp[i])
				p[c++] = i;
		}
		int[] numP = new int[NUM_PRIMES];
		int[] demP = new int[NUM_PRIMES];
		int[] numFrac = new int[n];
		int[] demFrac = new int[m];
		ArrayList<Integer>[] indexN = new ArrayList[n];
		ArrayList<Integer>[] indexD = new ArrayList[m];
		for(int i = 0; i < n; i++)	{
			numFrac[i] = readInt();
			indexN[i] = new ArrayList<Integer>();
		}
		for(int i = 0; i < m; i++)	{
			demFrac[i] = readInt();
			indexD[i] = new ArrayList<Integer>();
		}
		for(int k = 0; k < n; k++)	{
			int temp = numFrac[k];
			for(int i = 0; i < NUM_PRIMES; i++)		{
				int curr = 0;
				while(temp % p[i] == 0)	{
					curr++;
					temp /= p[i];
				}
				numP[i] += curr;
				if(curr > 0)	{
					indexN[k].add(i);
				}
				if(p[i] * p[i] > temp)
					break;
			}
			if(temp != 1)	{
				int rel = binarySearch(p, temp);
				indexN[k].add(rel);
				numP[rel]++;
			}
		}
		for(int k = 0; k < m; k++)	{
			int temp = demFrac[k];
			for(int i = 0; i < NUM_PRIMES; i++)		{
				int curr = 0;
				while(temp % p[i] == 0)	{
					curr++;
					temp /= p[i];
				}
				demP[i] += curr;
				if(curr > 0)	{
					indexD[k].add(i);
				}
				if(p[i] * p[i] > temp)
					break;
			}
			if(temp != 1)	{
				int rel = binarySearch(p, temp);
				indexD[k].add(rel);
				demP[rel]++;
			}
		}
		int[] ret = new int[NUM_PRIMES];
		for(int i = 0; i < NUM_PRIMES; i++)
			ret[i] = Math.min(numP[i], demP[i]);
		StringBuilder sb = new StringBuilder();
		for(int k = 0; k < n; k++)	{
			for(int out: indexN[k])	{
				while(ret[out] > 0 && numFrac[k] % p[out] == 0)	{
					ret[out]--;
					numFrac[k] /= p[out];
				}
			}
			sb.append(numFrac[k] + " ");
		}
		for(int i = 0; i < NUM_PRIMES; i++)
			ret[i] = Math.min(numP[i], demP[i]);
		StringBuilder sc = new StringBuilder();
		for(int k = 0; k < m; k++)	{
			for(int out: indexD[k])	{
				while(ret[out] > 0 && demFrac[k] % p[out] == 0)	{
					ret[out]--;
					demFrac[k] /= p[out];
				}
			}
			sc.append(demFrac[k] + " ");
		}
		pw.println(n + " " + m);
		pw.println(sb.toString().trim());
		pw.println(sc.toString().trim());
		pw.close();
	}

	public static long readLong() throws IOException {
		return parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return parseInt(nextToken());
	}

	public static String nextToken() throws IOException {
		while (st == null || !st.hasMoreTokens()) {
			if (!br.ready()) {
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}