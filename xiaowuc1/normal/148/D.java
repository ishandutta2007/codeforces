import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

import com.sun.org.apache.bcel.internal.generic.LLOAD;


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

	static int[] dx = new int[]{-1,0,1,0};
	static int[] dy = new int[]{0,1,0,-1};

	static double[][] dragon, princess;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		final int MOD = 1000000007;
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int w = readInt();
			int b = readInt();
			dragon = new double[w+1][b+1];
			princess = new double[w+1][b+1];
			for(int i = 0; i <= w; i++)	{
				Arrays.fill(dragon[i], -1);
				Arrays.fill(princess[i], -1);
			}
			pw.println(princess(w,b));
		}
		pw.close();
	}

	private static double princess(int w, int b) {
		if(w+b==0)	{
			return 0;
		}
		if(princess[w][b] >= 0)	{
			return princess[w][b];
		}
		if(b == 0)	{
			return princess[w][b] = 1;
		}
		return princess[w][b] = 1.0*w/(w+b) + dragon(w,b-1) * b / (w+b);
	}

	private static double dragon(int w, int b) {
		if(b==0)
			return 0;
		if(dragon[w][b] >= 0)	{
			return dragon[w][b];
		}
		double ret = 0;
		double probCont = b * 1.0 / (w+b);
		b--;
		if(b != 0)	{
			ret += b * 1.0 / (w+b) * princess(w, b-1); 
		}
		if(w != 0)	{
			ret += w * (1.0) / (w+b) * princess(w-1, b);
		}
		ret *= probCont;
		dragon[w][b] = ret;
		return dragon[w][b];
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