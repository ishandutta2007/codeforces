
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
 
public class D {
	static StringTokenizer st;
	static BufferedReader br;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(
				System.out)));
		boolean[] composite = new boolean[10000];
		for(int i = 4; i < composite.length; i += 2)	{
			composite[i] = true;
		}
		for(int i = 3; i * i < composite.length; i += 2)	{
			if(!composite[i])	{
				for(int j = i*i; j < composite.length; j += i)
					composite[j] = true;
			}
		}
		int c = 1;
		int[] p = new int[1229];
		p[0] = 4;
		for(int i = 3; i < composite.length; i += 2)
			if(!composite[i])
				p[c++] = i*i;;
		long ret = 0;
		long[] full = new long[10000002];
		for(int i = 1; i < full.length; i++)
			full[i] = i;
		for(int out: p)	{
			for(int a = out; a < full.length; a += out)
				while(full[a]%out==0)
					full[a] /= out;
		}
		int a = readInt();
		int n = readInt();
		for(int i = 0; i < n; i++)	{
			ret += full[a+i];
		}
		pw.println(ret);
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