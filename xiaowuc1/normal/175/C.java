import java.math.*;
import java.io.*;
import java.util.*;
public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	static int[] list;
	
	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			PriorityQueue<State> q = new PriorityQueue<State>();
			while(n-- > 0)	{
				q.add(new State(readInt(), readInt()));
			}
			ArrayList<Long> count = new ArrayList<Long>();
			count.add(0L);
			int qqq = readInt();
			while(qqq-- > 0)	{
				count.add(readLong());
			}
			count.add(1L << 60);
			int curr = 0;
			long amt = 0;
			long ret = 0;
			while(!q.isEmpty())	{
				State now = q.poll();
				long need = count.get(curr+1) - amt;
				if(need <= now.num)	{
					ret += now.val * 1L * need * (curr+1);
					amt += need;
					curr++;
					now.num -= need;
					q.add(new State(now.num, now.val));
				}
				else	{
					ret += now.num * 1L * now.val * (curr+1);
					amt += now.num;
				}
			}
			pw.println(ret);
		}
		pw.close();
	}

	static class State implements Comparable<State> {
		public int num;
		public int val;
		public State(int num, int val) {
			super();
			this.num = num;
			this.val = val;
		}
		public int compareTo(State s)	{
			return val - s.val;
		}
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