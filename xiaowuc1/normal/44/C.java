import java.math.*;
import java.io.*;
import java.util.*;
public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static boolean[] win;
	static boolean[] seen;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int[] list = new int[n+1];
			list[0] = 1;
			int m = readInt();
			while(m-- > 0)	{
				int a = readInt();
				int b = readInt();
				for(int i = a; i <= b; i++)	{
					list[i]++;
				}
			}
			boolean win = true;
			int x = -1;
			int y = -1;
			for(int i = 1; win && i <= n; i++)	{
				if(list[i] != 1)	{
					win = false;
					x = i;
					y = list[i];
				}
			}
			if(win)	{
				pw.println("OK");
			}
			else	{
				pw.printf("%d %d\n", x, y);
			}
		}
		pw.close();
	}

	
	
	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}