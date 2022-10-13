import java.awt.*;
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

	static final long MAX = 1L << 50;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			BIT tree = new BIT(n+10);
			long manual = 0;
			long currSum = 0;
			LinkedList<Integer> q = new LinkedList<Integer>();
			q.add(0);
			while(n-- > 0)	{
				int op = readInt();
				switch(op)	{
				case 1:
					int num = readInt();
					long add = readLong();
					manual += num * add;
					tree.update(1, add);
					tree.update(1+num, -add);
					break;
				case 2:
					num = readInt();
					currSum += num;
					q.addLast(num);
					break;
				case 3:
					long change = tree.read(q.size()+1) - tree.read(q.size());
					tree.update(q.size(), change);
					tree.update(q.size()+1, -change);
					manual += change;
					currSum -= q.removeLast();
					break;
				}
				pw.println(1.0*(manual+currSum)/q.size());
			}
		}
		pw.close();
	}

	static class BIT {
		long[] tree;
		public BIT(int n)	{
			tree = new long[n+1];
		}
		public void update(int idx ,long val){
			while(idx < tree.length){
				tree[idx] += val;
				idx += (idx & -idx);
			}
		}
		public long read(int idx){
			long sum = 0;
			while(idx > 0){
				sum += tree[idx];
				idx -= (idx & -idx);
			}
			return sum;
		}
		public long readSingle(int idx){
			long sum = tree[idx];
			if(idx > 0){
				int z = idx - (idx & -idx);
				idx--;
				while(idx != z) {
					sum -= tree[idx]; 
					idx -= (idx & -idx);
				}
			}
			return sum;
		}
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