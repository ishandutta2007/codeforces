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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int qq = 1;
		//int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			int m = readInt();
			LinkedList<Integer>[] edges = new LinkedList[n];
			for (int i = 0; i < edges.length; i++) {
				edges[i] = new LinkedList<Integer>();
			}
			while(m-- > 0)	{
				int a = readInt();
				int b = readInt();
				a--;
				b--;
				edges[a].add(b);
				edges[b].add(a);
			}
			boolean[] seen = new boolean[n];
			ArrayList<Set<Integer>> list = new ArrayList<Set<Integer>>();
			for(int i = 0; i < n; i++)	{
				if(!seen[i])	{
					seen[i] = true;
					LinkedList<Integer> q = new LinkedList<Integer>();
					Set<Integer> ours = new HashSet<Integer>();
					q.add(i);
					while(!q.isEmpty())	{
						int curr = q.removeFirst();
						ours.add(curr);
						for(int out: edges[curr])	{
							if(!seen[out])	{
								seen[out] = true;
								q.addLast(out);
							}
						}
					}
					list.add(ours);
				}
			}
			Collections.sort(list, new Compare());
			ArrayList<Set<Integer>> ret = new ArrayList<Set<Integer>>();
			while(!list.isEmpty())	{
				if(list.get(list.size()-1).size() == 1)	{
					Set<Integer> set = new HashSet<Integer>();
					set.addAll(list.remove(list.size()-1));
					set.addAll(list.remove(list.size()-1));
					set.addAll(list.remove(list.size()-1));
					ret.add(set);
				}
				else if(list.get(list.size()-1).size() == 2)	{
					if(list.get(0).size() != 1)	{
						pw.println(-1);
						exitImmediately();
					}
					Set<Integer> set = new HashSet<Integer>();
					set.addAll(list.remove(list.size()-1));
					set.addAll(list.remove(0));
					ret.add(set);
				}
				else if(list.get(list.size()-1).size() == 3)	{
					ret.add(list.remove(list.size()-1));
				}
				else	{
					pw.println(-1);
					exitImmediately();
				}
			}
			while(!ret.isEmpty())	{
				Set<Integer> set = ret.remove(0);
				StringBuilder sb = new StringBuilder();
				for(int out: set)	{
					sb.append(++out + " ");
				}
				pw.println(sb.toString().trim());
			}
		}
		pw.close();
	}

	static class Compare implements Comparator<Set<Integer>>	{
		public int compare(Set<Integer> a, Set<Integer> b)	{
			return a.size() - b.size();
		}
	}

	public static boolean square(int x)	{
		int y = (int)Math.sqrt(x);
		while(y*y<x) y++;
		return y*y==x;
	}

	private static void exitImmediately()	{
		pw.close();
		System.exit(0);
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
				exitImmediately();
			}
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}