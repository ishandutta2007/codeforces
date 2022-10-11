import java.io.*;
import java.util.*;
public class C10 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		long[] go = gen(n);
		long ret = 0;
		for(int a = 1; a <= n; a++)	{
			int b = n/a;
			long[] next = gen(b);
			for(int i = 0; i < 9; i++)	{
				ret += (go[((a%9)*(i%9))%9]-1) * next[i%9];
				ret += (go[((a%9)*(i%9))%9]) * (go[i%9] - next[i%9]);
			}
		}
		System.out.println(ret);
	}
	public static long[] gen(int x)	{
		long[] ret = new long[9];
		Arrays.fill(ret, x/9);
		for(int i = 1; i <= x%9; i++)
			ret[i]++;
		return ret;
	}
}