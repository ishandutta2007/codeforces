import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	final static int MOD = 100000000;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int v = readInt();
		int a = readInt();
		int b = readInt();
		LinkedList<Integer>[] edges = new LinkedList[v];
		for(int i = 0; i < v; i++)
			edges[i] = new LinkedList<Integer>();
		for(int i = 1; i <= v; i++)	{
			if(i == a)
				continue;
			int curr = readInt();
			curr--;
			edges[i-1].add(curr);
			edges[curr].add(i-1);
		}
		int[] dist = new int[v];
		Arrays.fill(dist, 1<<29);
		dist[b-1] = 0;
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(b-1);
		while(!q.isEmpty())	{
			int curr = q.removeFirst();
			for(int out: edges[curr])	{
				if(dist[out] > 1 + dist[curr])	{
					dist[out] = 1 + dist[curr];
					q.addLast(out);
				}
			}
		}
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < v; i++)	{
			if(dist[i] == 0)
				continue;
			for(int out: edges[i])		{
				if(dist[out] + 1 == dist[i])	{
					sb.append((out+1) + " ");
					break;
				}
			}
		}
		System.out.println(sb.toString().trim());
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}