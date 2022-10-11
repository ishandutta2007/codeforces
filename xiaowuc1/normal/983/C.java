import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class C {
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
			ArrayList<Inside> in = new ArrayList<Inside>();
			Map<Inside, Integer> rev = new HashMap<Inside, Integer>();
			for(int a = -1; a <= 8; a++) {
				for(int b = -1; b <= 8; b++) {
					for(int c = -1; c <= 8; c++) {
						for(int d = -1; d <= 8; d++) {
							in.add(new Inside(a, b, c, d));
							rev.put(new Inside(a, b, c, d), in.size()-1);
						}
					}
				}
			}
			Map<State, Integer> dp = new HashMap<State, Integer>();
			int[] lhs = new int[n];
			int[] rhs = new int[n];
			for(int i = 0; i < n; i++) {
				lhs[i] = readInt()-1;
				rhs[i] = readInt()-1;
			}
			LinkedList<State> q = new LinkedList<State>();
			dp.put(new State(0, 0, 0), 0);
			q.add(new State(0, 0, 0));
			Inside now = new Inside(-1,-1,-1,-1);
			for(int i = 0; i < 4 && i < n && lhs[i] == 0; i++) {
				now.a = rhs[i];
				now.sort();
				dp.put(new State(1, 0, rev.get(now)), 0);
				q.add(new State(1, 0, rev.get(now)));
			}
			while(!q.isEmpty()) {
				State curr = q.removeFirst();
				if(curr.idx == n && curr.mask == 0) {
					pw.println(dp.get(curr) + 2*n);
					break;
				}
				int nowDist = dp.get(curr);
				for(int dir = -1; dir <= 1; dir += 2) {
					int nextLoc = curr.loc + dir;
					if(nextLoc < 0 || nextLoc >= 9) continue;
					now = new Inside(in.get(curr.mask));
					now.clean(nextLoc);
					int nextIdx = curr.idx;
					int nextMask = rev.get(now);
					State key = new State(nextIdx, nextLoc, nextMask);
					if(!dp.containsKey(key)) {
						dp.put(key, 1 + nowDist);
						q.add(key);
					}
					while(nextIdx < n && lhs[nextIdx] == nextLoc && now.a == -1) {
						now.a = rhs[nextIdx];
						nextIdx++;
						now.sort();
						nextMask = rev.get(now);
						key = new State(nextIdx, nextLoc, nextMask);
						if(!dp.containsKey(key)) {
							dp.put(key, 1 + nowDist);
							q.add(key);
						}
					}
				}
			}
		}
		pw.close();
	}

	static class Inside {
		public int a, b, c, d;

		public Inside(Inside i) {
			this(i.a,i.b,i.c,i.d);
		}
		
		@Override
		public String toString() {
			return "Inside [a=" + a + ", b=" + b + ", c=" + c + ", d=" + d + "]";
		}

		public Inside(int a, int b, int c, int d) {
			super();
			this.a = a;
			this.b = b;
			this.c = c;
			this.d = d;
			sort();
		}

		public void clean(int idx) {
			if(idx==a) a=-1;
			if(idx==b) b=-1;
			if(idx==c) c=-1;
			if(idx==d) d=-1;
			sort();
		}
		
		public void sort() {
			if(d<c) {
				d^=c;
				c^=d;
				d^=c;
			}
			if(c<b) {
				c^=b;
				b^=c;
				c^=b;
			}
			if(b<a) {
				b^=a;
				a^=b;
				b^=a;
			}
			if(d<c) {
				d^=c;
				c^=d;
				d^=c;
			}
			if(c<b) {
				c^=b;
				b^=c;
				c^=b;
			}
			if(b<a) {
				b^=a;
				a^=b;
				b^=a;
			}
			if(d<c) {
				d^=c;
				c^=d;
				d^=c;
			}
			if(c<b) {
				c^=b;
				b^=c;
				c^=b;
			}
			if(b<a) {
				b^=a;
				a^=b;
				b^=a;
			}
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + a;
			result = prime * result + b;
			result = prime * result + c;
			result = prime * result + d;
			return result;
		}

		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Inside other = (Inside) obj;
			if (a != other.a)
				return false;
			if (b != other.b)
				return false;
			if (c != other.c)
				return false;
			if (d != other.d)
				return false;
			return true;
		}
		
	}
	
	static class State {
		public int idx, loc, mask;

		
		
		@Override
		public String toString() {
			return "State [idx=" + idx + ", loc=" + loc + ", mask=" + mask + "]";
		}



		public State(int idx, int loc, int mask) {
			super();
			this.idx = idx;
			this.loc = loc;
			this.mask = mask;
		}



		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + idx;
			result = prime * result + loc;
			result = prime * result + mask;
			return result;
		}



		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			State other = (State) obj;
			if (idx != other.idx)
				return false;
			if (loc != other.loc)
				return false;
			if (mask != other.mask)
				return false;
			return true;
		}

		
		
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