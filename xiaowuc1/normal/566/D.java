import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*; 
import java.util.*;
import java.util.regex.*;

public class MainFastIO {
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		InputReader br = new InputReader(System.in);
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = br.readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = br.readInt();
			int qqq = br.readInt();
			p = new int[n];
			TreeSet<Integer> cands = new TreeSet<Integer>();
			for(int i = 0; i < n; i++) {
				p[i] = i;
				cands.add(i);
			}
			while(qqq-- > 0) {
				int type = br.readInt();
				int a = br.readInt()-1;
				int b = br.readInt()-1;
				if(type == 1) {
					merge(a, b);
				}
				else if(type == 2) {
					if(cands.isEmpty() || cands.last() < a || cands.ceiling(a) > b) continue;
					int curr = cands.ceiling(a);
					int last = curr;
					while(!cands.isEmpty() && cands.last() > a && cands.higher(a) <= b) {
						int next = cands.higher(a);
						cands.remove(next);
						merge(curr, next);
						last = next;
					}
					cands.add(last);
				}
				else {
					pw.println(find(a) == find(b) ? "YES" : "NO");
				}
			}
		}
		exitImmediately();
	}

	static int[] p;
	
	public static int find(int x) {
		if(p[x] == x) return x;
		return p[x] = find(p[x]);
	}
	
	public static void merge(int x, int y) {
		p[find(x)] = find(y);
	}
	
	private static void exitImmediately() {
		pw.close();
		System.exit(0);
	}

	static class InputReader {

		private InputStream stream;
		private byte[] buf = new byte[102400];
		private int curChar;
		private int numChars;

		public InputReader(InputStream stream) {
			this.stream = stream;
		}

		public int read() {
			if (numChars == -1) {
				exitImmediately();
				throw new InputMismatchException();
			}
			if (curChar >= numChars) {
				curChar = 0;
				try {
					numChars = stream.read(buf);
				} catch (IOException e) {
					throw new InputMismatchException();
				}
				if (numChars <= 0)
					return -1;
			}
			return buf[curChar++];
		}

		public int readInt() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			int res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public long readLong() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			int sgn = 1;
			if (c == '-') {
				sgn = -1;
				c = read();
			}
			long res = 0;
			do {
				if (c < '0' || c > '9')
					throw new InputMismatchException();
				res *= 10;
				res += c - '0';
				c = read();
			} while (!isSpaceChar(c));
			return res * sgn;
		}

		public String readString() {
			int c = read();
			while (isSpaceChar(c))
				c = read();
			StringBuilder res = new StringBuilder();
			do {
				res.appendCodePoint(c);
				c = read();
			} while (!isSpaceChar(c));
			return res.toString();
		}

		public boolean isSpaceChar(int c) {
			return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
		}

		public String next() {
			return readString();
		}
	}
}