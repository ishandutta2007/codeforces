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

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		int n = readInt();
		int k = readInt();
		Cart[] cart = new Cart[k];
		for(int i = 0; i < k; i++)	{
			cart[i] = new Cart();
		}
		Item[] list = new Item[n];
		for(int i = 0; i < n; i++)	{
			list[i] = new Item(readInt(), readInt(), i+1);
		}
		Arrays.sort(list);
		for(int i = 0; i < n; i++)		{
			cart[Math.max(0, k-1-i)].add(list[i]);
		}
		double ret = 0;
		for(Cart out: cart)	{
			ret += out.cost();
		}
		pw.printf("%.1f\n", ret);
		for(Cart out: cart)	{
			pw.println(out);
		}
		pw.close();
	}

	static class Cart	{
		public ArrayList<Item> list;
		public Cart()	{
			list = new ArrayList<Item>();
		}
		public void add(Item i)	{
			list.add(i);
		}
		private boolean hasStool()	{
			for(Item i: list)	{
				if(i.id == 1)
					return true;
			}
			return false;
		}
		private int lowestPrice()	{
			int ret = Integer.MAX_VALUE;
			for(Item i: list)	{
				ret = Math.min(ret, i.price);
			}
			return ret;
		}
		public double cost()	{
			double ret = 0;
			for(Item i: list)	{
				ret += i.price;
			}
			if(hasStool())	{
				ret -= lowestPrice() / 2.;
			}
			return ret;
		}
		public String toString()	{
			StringBuilder sb = new StringBuilder();
			sb.append(list.size());
			for(Item i: list)	{
				sb.append(" " + i.index);
			}
			return sb.toString();
		}
	}
	
	static class Item implements Comparable<Item> {
		public int price, id, index;
		public Item(int a, int b, int c)	{
			price = a;
			id = b;
			index = c;
		}
		public int compareTo(Item i)	{
			if(i.id != id)	{
				return id - i.id;
			}
			return i.price - price;
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