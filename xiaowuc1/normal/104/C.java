import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static LinkedList<Integer>[] edges;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int m = Integer.parseInt(st.nextToken());
		int n = Integer.parseInt(st.nextToken());
		if(m != n)	{
			System.out.println("NO");
			return;
		}
		edges = new LinkedList[n];
		for(int i = 0; i < n; i++)
			edges[i] = new LinkedList<Integer>();
		while(m-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			edges[a].add(b);
			edges[b].add(a);
		}
		LinkedList<Integer> q = new LinkedList<Integer>();
		q.add(0);
		boolean[] visit = new boolean[n];
		visit[0] = true;
		while(!q.isEmpty())	{
			int curr = q.removeFirst();
			for(int out: edges[curr]){
				if(!visit[out])	{
					visit[out] = true;
					q.addLast(out);
				}
			}
		}
		boolean win = true;
		for(boolean b: visit)
			if(!b)	{
				win = false;
				break;
			}
		System.out.println(win ? "FHTAGN!" : "NO");
	}
}