import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int t = n;
		Set<Integer> contain = new HashSet<Integer>();
		while(t > 0)	{
			contain.add(t%10);
			t/=10;
		}
		int ret = 0;
		for(int i = 1; i * i <= n; i++)	{
			if(n%i==0)	{
				boolean win = false;
				t = i;
				while(t>0)	{
					if(win = contain.contains(t%10))
						break;
					t/=10;
				}
				if(win)
					ret++;
				if(i*i!=n)	{
					win = false;
					t = n/i;
					while(t>0)	{
						if(win = contain.contains(t%10))
							break;
						t/=10;
					}
					if(win)
						ret++;
				}
			}
		}
		pw.println(ret);
		pw.close();
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
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
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}