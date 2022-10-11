import java.math.*;
import java.io.*;
import java.util.*;
public class Main {
	static BufferedReader br;
	static StringTokenizer st;
	static PrintWriter pw;

	public static void main(String[] args) throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		//int qq = 1;
		int qq = Integer.MAX_VALUE;
		//int qq = readInt();
		for(int casenum = 1; casenum <= qq; casenum++) {
			int n = readInt();
			boolean[][] graph = new boolean[n][n];
			boolean[][] save = new boolean[n][n];
			ArrayList<Integer> root = new ArrayList<Integer>();
			for(int a = 1; a < n; a++)	{
				int x = readInt();
				int y = readInt();
				x--;
				y--;
				graph[Math.min(x,y)][Math.max(x,y)] = true;
			}
			boolean[] seen = new boolean[n];
			for(int i = 0; i < n; i++)	{
				if(seen[i])	{
					continue;
				}
				seen[i] = true;
				LinkedList<Integer> q = new LinkedList<Integer>();
				q.add(i);
				root.add(i);
				while(!q.isEmpty())		{
					int curr = q.removeFirst();
					for(int k = 0; k < graph[curr].length; k++)	{
						if(graph[Math.min(curr,k)][Math.max(curr,k)] && !seen[k])	{
							seen[k] = true;
							q.addLast(k);
							save[Math.min(curr,k)][Math.max(curr,k)] = true;
						}
					}
				}
			}
			ArrayList<State> remove = new ArrayList<State>();
			for(int i = 0; i < n; i++)	{
				for(int j = i+1; j < n; j++)	{
					if(graph[i][j] && !save[i][j])	{
						remove.add(new State(i,j));
					}
				}
			}
			pw.println(remove.size());
			for(int i = 0; i < remove.size(); i++)	{
				pw.printf("%d %d %d %d\n", 1+remove.get(i).a, 1+remove.get(i).b, 1+root.get(i), 1+root.get(i+1));
			}
		}
		pw.close();
	}

	static class State {
		public int a,b;

		public State(int a, int b) {
			super();
			this.a = a;
			this.b = b;
		}
		
	}
	
	public static double readDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}

	public static int readInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	public static long readLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	public static String nextToken() throws IOException {
		while(st == null || !st.hasMoreTokens())	{
			if(!br.ready())	{
				pw.close();
				System.exit(0);
			}
			st = new StringTokenizer(br.readLine());
		}
		return st.nextToken();
	}
}