import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	final static int MOD = 100000000;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new FileReader("input.txt")));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("output.txt")));
		int n = readInt();
		int total = readInt();
		PriorityQueue<Integer> q = new PriorityQueue<Integer>();
		int ret = 0;
		for(int i = n; i >= 1; i--)	{
			q.add(i*readInt());
		}
		while(!q.isEmpty())	{
			total -= q.poll();
			if(total >= 0)
				ret++;
			else
				break;
		}
		pw.println(ret);
		pw.close();
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}