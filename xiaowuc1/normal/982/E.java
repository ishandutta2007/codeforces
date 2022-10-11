import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class E {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			int m = readInt();
			int x = readInt();
			int y = readInt();
			int vx = readInt();
			int vy = readInt();
			if(vx == 0) {
				// vy
				if(x != 0 && x != n) {
					pw.println(-1);
				}
				else if(vy < 0) {
					pw.println(x + " " + 0);
				}
				else {
					pw.println(x + " " + m);
				}
				continue;
			}
			if(vy == 0) {
				if(y != 0 && y != m) {
					pw.println(-1);
				}
				else if(vx > 0) {
					pw.println(n + " " + y);
				}
				else {
					pw.println(0 + " " + y);
				}
				continue;
			}
			if((vx > 0) == (vy > 0)) {
				// y_sol = x_sol + (y - x)
				long xSol = solve(n, -(y-x), m);
				if(xSol == -1) {
					pw.println(-1);
					continue;
				}
				long origGCD = gcd(n, m);
				if(vx > 0) {
					xSol -= m/origGCD;
					while(xSol * n <= x) {
						xSol += m/origGCD;
					}
				}
				else {
					xSol += m/origGCD;
					while(xSol * n >= x) {
						xSol -= m/origGCD;
					}
				}
				xSol *= n;
				long ySol = xSol + (y-x);
				pw.println(mod(xSol, 2*n) + " " + mod(ySol, 2*m));
			}
			else {
				// y_sol = -x_sol + (y + x)
				long xSol = solve(n, (y+x), m);
				if(xSol == -1) {
					pw.println(-1);
					continue;
				}
				long origGCD = gcd(n, m);
				if(vx > 0) {
					xSol -= m/origGCD;
					while(xSol * n <= x) {
						xSol += m/origGCD;
					}
				}
				else {
					xSol += m/origGCD;
					while(xSol * n >= x) {
						xSol -= m/origGCD;
					}
				}
				xSol *= n;
				long ySol = -xSol + (y+x);
				pw.println(mod(xSol, 2*n) + " " + mod(ySol, 2*m));
			}
		}
		pw.close();
	}

	public static long mod(long a, long m) {
		a %= m;
		if(a < 0) a += m;
		return a;
	}
	
	public static long gcd(long a, long b) {
		if(a==0) return b;
		if(b==0) return a;
		return gcd(b, a%b);
	}
	
	public static long solve(long a, long b, long m) {
		// return x such that a*x == b mod m, or -1 otherwise
		// note that on the original equation, for solution x_0, adding m / gcd(a, m) is always allowed
		b = mod(b, m);
		long g = gcd(Math.abs(a), Math.abs(m));
		if(b%g != 0) return -1;
		a /= g;
		b /= g;
		m /= g;
		long inv = modpow(a, phi(m)-1, m);
		return (inv*b)%m;
	}
	
	public static long phi(long n) {
		long r = n;
		for(int i = 2; i * i <= n; i++) {
			if(n%i==0) {
				r /= i;
				r *= i-1;
				while(n%i==0) {
					n /= i;
				}
			}
		}
		if(n > 1) {
			r /= n;
			r *= n-1;
		}
		return r;
	}
	
	public static long modpow(long b, long e, long m) {
		long r = 1;
		while(e > 0) {
			if(e%2==1) {
				r*=b;
				r%=m;
			}
			b*=b;
			b%=m;
			e/=2;
		}
		return r;
	}
	
	public static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextLine() throws IOException {
		st = null;
		if(!br.ready()) {
			exitImmediately();
		}
		return br.readLine();
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens()) {
			if(!br.ready()) {
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}