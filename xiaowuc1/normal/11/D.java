import java.io.*;
import java.util.*;
public class D11 {
	static HashMap<State, Integer> map;
	static long[][] ans;
	static boolean[][] connect;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		map = new HashMap<State, Integer>();
		connect = new boolean[n][n];
		ans = new long[n][1<<n];
		for(int i = 0; i < n; i++)
			Arrays.fill(ans[i], -1);
		int m = Integer.parseInt(st.nextToken());
		while(m-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			connect[a][b] = connect[b][a] = true;
		}
		long ret = 0;
		int mask = 1 << n;
		mask--;
		for(int i = 0; i < n; i++)	{
			for(int out = i+1; out < n; out++)	{
				if(connect[i][out])	{
					ret += solve(mask - (1<<out), out, true);
				}
			}
			mask -= (1<<i);
		}
		System.out.println(ret/2);
	}
	public static long solve(int mask, int start, boolean a)	{
		if(ans[start][mask] != -1)
			return ans[start][mask];
		int end = 0;
		while((mask & (1<<end)) == 0)
			end++;
		long ret = 0;
		for(int out = 0; out < connect.length; out++)	{
			if(connect[start][out] && (mask & (1 << out)) != 0)	{
				if(out == end)	{
					if(!a)
						ret++;
				}
				else
					ret += solve(mask - (1<<out), out, false);
			}
		}
		ans[start][mask] = ret;
		return ret;
	}
	static class State	{
		public byte start, go;
		public int mask;
		public State(byte a, byte b, int c)	{
			start = a;
			go = b;
			mask = c;
		}
		public int hashCode()	{
			return 10007*mask + 43 * start + go;
		}
		public boolean equals(Object o)	{
			State s = (State)o;
			return start == s.start && go == s.go && mask == s.mask;
		}
	}
}