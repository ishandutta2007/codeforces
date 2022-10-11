import java.io.*;
import java.util.*;
public class E93 {
	static long orig;
	static int[] list;
	static long[][] ret;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		orig = Long.parseLong(st.nextToken());
		list = new int[Integer.parseInt(st.nextToken())];
		ret = new long[list.length][100000];
		for(int i = 0; i < ret.length; i++)
			Arrays.fill(ret[i], -1);
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < list.length; i++)
			list[i] = Integer.parseInt(st.nextToken());
		Arrays.sort(list);
		System.out.println(solve(orig, list.length-1));
	}
	public static long solve(long num, int point)	{
		if(point == -1)
			return num;
		if(num < 100000 && ret[point][(int)num] != -1)
			return ret[point][(int)num];
		long ans = solve(num, point-1) - solve(num/list[point], point-1);
		if(num < 100000)
			ret[point][(int)num] = ans;
		return ans;
	}
	static class State	{
		public long curr;
		public int index;
		public boolean flag;
		public State(long a, int b, boolean c)	{
			curr = a;
			index = b;
			flag = c;
		}
	}
}