
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class A {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new FileReader("input.txt"));
		pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int n = readInt();
		int k = readInt();
		Set<Integer> known = new HashSet<Integer>();
		for(int i = 0; i < k; i++){
			known.add(readInt());
		}
		int num = readInt();
		int[] best = new int[num];
		int[] worst = new int[num];
		for(int i = 0; i < num; i++)	{
			br.readLine();
			int a = readInt();
			int good = 0;
			int bad = 0;
			int zero = 0;
			while(a-- > 0)	{
				int curr = readInt();
				if(known.contains(curr))	{
					good++;
				}
				else if(curr == 0)	{
					zero++;
				}
				else	{
					bad++;
				}
			}
			best[i] = Math.min(k, good + zero);
			worst[i] = good + Math.max(0, zero-((n-k)-bad));
		}
		for(int i = 0; i < num; i++)	{
			boolean mustWin = true;
			boolean mustLose = true;
			int lowestMax = 0;
			for(int j = 0; j < num; j++)	{
				if(i==j)
					continue;
				if(worst[i] < best[j])	{
					mustWin = false;
				}
				lowestMax = Math.max(lowestMax, worst[j]);
			}
			if(best[i] >= lowestMax)
				mustLose = false;
			if(mustWin)
				pw.println(0);
			else if(mustLose)
				pw.println(1);
			else
				pw.println(2);
		}
		pw.close();
	}

	public static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}
	public static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}
	public static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}
	public static short readShort() throws IOException	{
		return Short.parseShort(nextToken());
	}
	public static String nextToken() throws IOException	{
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