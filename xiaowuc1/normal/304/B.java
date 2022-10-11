import java.awt.*; 
import java.awt.event.*; 
import java.awt.geom.*; 
import java.io.*; 
import java.math.*; 
import java.text.*; 
import java.util.*; 

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

	public static void main(String[] args) throws IOException   { 
		br = new BufferedReader(new InputStreamReader(System.in)); 
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out))); 
		//int qq = 1; 
		int qq = Integer.MAX_VALUE; 
		//int qq = readInt(); 
		for(int casenum = 1; casenum <= qq; casenum++)   {
			Date[] list = new Date[2];
			for(int i = 0; i < 2; i++) {
				list[i] = extractDate(nextToken());
			}
			Arrays.sort(list);
			int ret = 0;
			while(!list[0].equals(list[1])) {
				list[0].inc();
				ret++;
			}
			pw.println(ret);
		} 
		pw.close(); 
	} 

	public static Date extractDate(String s) {
		int y = Integer.parseInt(s.substring(0,4));
		int m = Integer.parseInt(s.substring(5,7));
		int d = Integer.parseInt(s.substring(8,10));
		return new Date(y,m,d);
	}
	
	static class Date implements Comparable<Date> {
		public int y,m,d;

		public Date(int y, int m, int d) {
			super();
			this.y = y;
			this.m = m;
			this.d = d;
		}
		
		public void inc() {
			d++;
			if(pastMonth()) {
				d = 1; m++;
			}
			if(m == 13) {
				m = 1;
				y++;
			}
		}
		
		public boolean pastMonth() {
			if(m == 2) {
				if(y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
					return d == 30;
				return d == 29;
			}
			if(m == 4 || m == 6 || m == 9 || m == 11) return d == 31;
			return d == 32;
		}
		
		@Override
		public int hashCode() {
			final int prime = 31;
			int result = 1;
			result = prime * result + d;
			result = prime * result + m;
			result = prime * result + y;
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
			Date other = (Date) obj;
			if (d != other.d)
				return false;
			if (m != other.m)
				return false;
			if (y != other.y)
				return false;
			return true;
		}

		public int compareTo(Date s) {
			if(y != s.y) return y - s.y;
			if(m != s.m) return m - s.m;
			if(d != s.d) return d - s.d;
			return 0;
		}
	}
	
	private static void exitImmediately()   { 
		pw.close(); 
		System.exit(0); 
	} 

	private static long readLong() throws IOException   { 
		return Long.parseLong(nextToken()); 
	} 

	private static double readDouble() throws IOException   { 
		return Double.parseDouble(nextToken()); 
	} 

	private static int readInt() throws IOException { 
		return Integer.parseInt(nextToken()); 
	} 

	private static String nextToken() throws IOException    { 
		while(st == null || !st.hasMoreTokens())    { 
			if(!br.ready()) { 
				exitImmediately(); 
			} 
			st = new StringTokenizer(br.readLine().trim()); 
		} 
		return st.nextToken(); 
	} 
}