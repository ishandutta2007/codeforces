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

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			long zz = readInt();
			long zo = readInt();
			long oz = readInt();
			long oo = readInt();
			if(zz+zo+oz+oo == 0) {
				pw.println("1");
				continue;
			}
			if(zz == 0 && oo == 0) {
				if(zo == 1 && oz == 0) {
					pw.println("01");
				}
				else if(zo == 0 && oz == 1) {
					pw.println("10");
				}
				else {
					pw.println("Impossible");
				}
				continue;
			}
			long ones = revTri(oo);
			long zeroes = revTri(zz);
			if(ones < 0 || zeroes < 0) {
				pw.println("Impossible");
				continue;
			}
			long total = revTri(oo+zz+oz+zo);
			if(total != ones + zeroes) {
				if(zz == 0) {
					zeroes = 1;
				}
			}
			if(total != ones + zeroes) {
				if(oo == 0) {
					ones = 1;
				}
			}
			if(total != ones + zeroes) {
				pw.println("Impossible");
				continue;
			}
			long onesLeft = ones;
			long zeroesLeft = zeroes;
			while(onesLeft > 0 || zeroesLeft > 0) {
				if(onesLeft == 0) {
					pw.print(0);
					zeroesLeft--;
				}
				else if(zeroesLeft == 0) {
					pw.print(1);
					onesLeft--;
				}
				else if(oz >= zeroesLeft) {
					pw.print(1);
					onesLeft--;
					oz -= zeroesLeft;
				}
				else {
					pw.print(0);
					zeroesLeft--;
				}
			}
			pw.println();
		}
		pw.close();
	}
	
	public static long revTri(long n) {
		if(n==0) return 0;
		long a = 1;
		long b = n+1;
		while(a < b) {
			long c = (a+b+1)/2;
			if(c*(c-1)/2 > n) {
				b = c-1;
			}
			else {
				a = c;
			}
		}
		if(a*(a-1)/2 != n) return -1;
		return a;
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	private static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	private static String nextLine() throws IOException  {
		if(!br.ready()) {
			exitImmediately();
		}
		st = null;
		return br.readLine();
	}

	private static String nextToken() throws IOException  {
		while(st == null || !st.hasMoreTokens())  {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}