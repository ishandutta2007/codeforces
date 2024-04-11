import java.io.*;
import java.util.*;
public class AMain	{
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException	{
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		int[] from = new int[n];
		int[] to = new int[n];
		TreeSet<Integer> set = new TreeSet<Integer>();
		for(int i = 0; i < n; i++)	{
			from[i] = readInt();
			to[i] = readInt();
			set.add(from[i]);
			set.add(to[i]);
		}
		int[] list = new int[set.size()];
		int c = 0;
		for(int out: set)
			list[c++] = out;
		int[] deg = new int[list.length];
		ArrayList<Integer>[] edges = new ArrayList[deg.length];
		for(int i = 0; i < edges.length; i++)
			edges[i] = new ArrayList<Integer>();
		for(int i = 0; i < n; i++)	{
			int f = Arrays.binarySearch(list, from[i]);
			int t = Arrays.binarySearch(list, to[i]);
			deg[f]++;
			deg[t]++;
			edges[f].add(t);
			edges[t].add(f);
		}
		boolean[] seen = new boolean[list.length];
		int start = -1;
		for(int i = 0; i < n; i++)	{
			if(deg[i] == 1)	{
				seen[i] = true;
				start = i;
				break;
			}
		}
		System.out.print(list[start] + " ");
		for(int qqq = 1; qqq < list.length; qqq++)	{
			for(int out: edges[start])	{
				if(!seen[out])	{
					seen[out] = true;
					System.out.print(list[out] + " ");
					start = out;
					break;
				}
			}
		}
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}