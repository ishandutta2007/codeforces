
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
 
public class A {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		final long HASH = 3137;
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		int n = readInt();
		long[][] hash = new long[n][];
		for(int i = 0; i < n; i++)	{
			String curr = nextToken();
			hash[i] = new long[curr.length()+1];
			for(int j = 1; j <= curr.length(); j++)
				hash[i][j] = hash[i][j-1] * HASH + curr.charAt(j-1);
		}
		int max = hash[0].length-1;
		outer: while(true)	{
			Set<Long> set = new HashSet<Long>();
			for(long[] a: hash)	{
				set.add(a[max]);
				if(set.size() > 1)	{
					max--;
					continue outer;
				}
			}
			pw.println(max);
			break;
		}
		pw.close();
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
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