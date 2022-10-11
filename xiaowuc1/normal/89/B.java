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
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++)	{
			int n = readInt();
			TreeMap<String, State> map = new TreeMap<String, Main.State>();
			while(n-- > 0)	{
				String line = br.readLine();
				if(line.startsWith("Widget"))		{
					st = new StringTokenizer(line);
					nextToken();
					String info = nextToken();
					String name = info.substring(0, info.indexOf("("));
					int width = Integer.parseInt(info.substring(1+info.indexOf("("), info.indexOf(",")));
					int height = Integer.parseInt(info.substring(1+info.indexOf(","), info.indexOf(")")));
					State curr = new State(name, width, height);
					curr.alone = true;
					map.put(name, curr);
				}
				else if(line.startsWith("VBox"))	{
					st = new StringTokenizer(line);
					nextToken();
					String name = nextToken();
					State curr = new State(name, 0, 0);
					curr.vertical = true;
					map.put(name, curr);
				}
				else if(line.startsWith("HBox"))	{
					st = new StringTokenizer(line);
					nextToken();
					String name = nextToken();
					State curr = new State(name, 0, 0);
					curr.horizontal = true;
					map.put(name, curr);
				}
				else	{
					String left = line.substring(0, line.indexOf("."));
					line = line.substring(line.indexOf(".")+1);
					String op = line.substring(0, line.indexOf("("));
					line = line.substring(line.indexOf("(")+1);
					line = line.substring(0, line.length()-1);
					if(op.equals("pack"))	{
						State curr = map.get(left);
						State insert = map.get(line);
						curr.add(insert);
						map.put(left, curr);
					}
					else if(op.equals("set_border"))	{
						State curr = map.get(left);
						curr.setBorder(Long.parseLong(line));
						map.put(left, curr);
					}
					else if(op.equals("set_spacing"))	{
						State curr = map.get(left);
						curr.setSpacing(Long.parseLong(line));
						map.put(left, curr);
					}
				}
			}
			for(String key: map.keySet())	{
				State curr = map.get(key);
				curr.compute();
				pw.println(curr);
			}
		}
		pw.close();
	}

	static class State {
		public String name;
		public long width, height;
		public boolean horizontal, vertical, alone;
		public ArrayList<State> list;
		public long border, spacing;
		public boolean computed;
		public State(String name, long width, long height) {
			super();
			this.name = name;
			this.width = width;
			this.height = height;
			computed = false;
			list = new ArrayList<Main.State>();
		}

		public void setBorder(long border)	{
			this.border = border;
		}

		public void setSpacing(long spacing)	{
			this.spacing = spacing;
		}

		public void add(State s)	{
			list.add(s);
		}

		public void compute()	{
			if(alone || computed)
				return;
			computed = true;
			width = 0;
			height = 0;
			for(State out: list)	{
				out.compute();
				if(horizontal)	{
					width += out.width;
					height = Math.max(height, out.height);
				}
				else if(vertical)	{
					height += out.height;
					width = Math.max(width, out.width);
				}
			}
			if(horizontal && !list.isEmpty())
				width += spacing * (list.size()-1);
			if(vertical && !list.isEmpty())
				height += spacing * (list.size()-1);
			if(!list.isEmpty())	{
				width += 2 * border;
				height += 2 * border;
			}
		}

		public String toString()	{
			return String.format("%s %d %d", name, width, height);
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