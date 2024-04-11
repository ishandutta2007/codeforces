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

	static Person[] list;
	
	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int k = readInt();
		list = new Person[n];
		for(int i = 0; i < n; i++)	{
			list[i] = new Person(readInt(), i+1);
		}
		Arrays.sort(list);
		Group go = new Group(n-1);
		while(k-- > 0)	{
			go.next();
			pw.println(go);
		}
		pw.close();
	}

	static class Group	{
		public ArrayList<Integer> use;
		public int max;
		public Group(int in)	{
			max = in;
			use = new ArrayList<Integer>();
		}
		public void next()	{
			if(use.isEmpty())	{
				use.add(0);
			}
			else if(use.size() == 1)	{
				if(use.get(0) == max)	{
					use.add(0);
				}
				else	{
					use.set(0, use.get(0)+1);
				}
			}
			else	{
				if(use.get(use.size()-1)+1 == use.get(use.size()-2))	{
					use.add(0);
				}
				else	{
					use.set(use.size()-1, use.get(use.size()-1)+1);
				}
			}
		}
		public String toString()	{
			StringBuilder sb = new StringBuilder();
			sb.append(use.size());
			for(int out: use)	{
				sb.append(" " + list[out].val);
			}
			return sb.toString();
		}
	}
	
	static class Person	implements Comparable<Person> {
		public int val, index;
		public Person(int a, int b)	{
			val = a;
			index = b;
		}
		public int compareTo(Person p)	{
			return val - p.val;
		}
	}
	
	/* NOTEBOOK CODE */

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