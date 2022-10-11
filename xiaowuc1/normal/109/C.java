import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static boolean[] seen;
	static LinkedList<Integer>[] edges;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		seen = new boolean[n];
		edges = new LinkedList[n];
		for(int i = 0; i < edges.length; i++)	{
			edges[i] = new LinkedList<Integer>();
		}
		for(int i = 1; i < n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			int w = Integer.parseInt(st.nextToken());
			if(!luck(w)){
				edges[--a].add(--b);
				edges[b].add(a);
			}
		}
		long ret = 0;
		for(int i = 0; i < seen.length; i++)	{
			if(!seen[i])	{
				int num = dfs(i);
				long other = n - num;
				ret += other * (other-1) * num;
			}
		}
		System.out.println(ret);
	}
	public static int dfs(int x)	{
		if(seen[x])
			return 0;
		seen[x] = true;
		int ret = 1;
		for(int y: edges[x])	{
			ret += dfs(y);
		}
		return ret;
	}
	public static boolean luck(int x)	{
		while(x>0)		{
			if(x%10 != 4 && x%10 != 7)
				return false;
			x /= 10;
		}
		return true;
	}
}