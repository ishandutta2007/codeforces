import java.io.*;
import java.util.*;
public class D9 {
	static long[][] ans;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ans = new long[36][36];
		for(int i = 0; i < 36; i++)
			Arrays.fill(ans[i], -1);
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int h = Integer.parseInt(st.nextToken());
		long ret = 0;
		for(int a = h; a <= n; a++)
			ret += solve(n,a);
		System.out.println(ret);
	}
	public static long solve(int n, int h)	{
		if(n < h || n >= (1L << h))
			return 0;
		if(n == 0 && h == 0)
			return 1;
		if(n == h){
			return 1L << (h-1);
		}
		if(ans[n][h] != -1)
			return ans[n][h];
		long ret = 0;
		for(int left = 0; left < n; left++)	{
			int right = n-1-left;
			for(int leftH = 0; leftH < h-1; leftH++)
				ret += solve(left, leftH) * solve(right, h-1);
			for(int rightH = 0; rightH < h-1; rightH++)
				ret += solve(left, h-1) * solve(right, rightH);
			ret += solve(left, h-1) * solve(right, h-1);
		}
		ans[n][h] = ret;
		return ret;
	}
}
// 27 11 should return 61162698256896
// initial returned    167110392320