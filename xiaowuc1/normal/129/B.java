import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int v = readInt();
		int e = readInt();
		ArrayList<Integer>[] edges = new ArrayList[v];
		for(int i = 0; i < v; i++)
			edges[i] = new ArrayList<Integer>();
		while(e-- > 0)	{
			int a = readInt();
			int b = readInt();
			a--;
			b--;
			edges[a].add(b);
			edges[b].add(a);
		}
		int ret = 0;
		while(true)	{
			boolean hasLeaf = false;
			boolean[] leaf = new boolean[v];
			for(int i = 0; i < leaf.length; i++)	{
				if(edges[i].size() == 1)	{
					leaf[i] = true;
					hasLeaf = true;
				}
			}
			if(!hasLeaf)
				break;
			ret++;
			for(int i = 0; i < v; i++)	{
				if(leaf[i])	{
					for(int j = 0; j < v; j++)	{
						for(int k = 0; k < edges[j].size(); k++)	{
							if(edges[j].get(k) == i)	{
								edges[j].remove(k);
								break;
							}
						}
					}
					edges[i].clear();
				}
			}
		}
		System.out.println(ret);
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}