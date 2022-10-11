import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int aa = Integer.parseInt(st.nextToken());
		String[] list = new String[n];
		for(int i = 0; i < n; i++)
			list[i] = br.readLine();
		Arrays.sort(list);
		boolean[][] bad = new boolean[n][n];
		while(aa-- > 0)	{
			st = new StringTokenizer(br.readLine());
			String a = st.nextToken();
			String b = st.nextToken();
			int i = Arrays.binarySearch(list, a);
			int j = Arrays.binarySearch(list, b);
			bad[i][j] = bad[j][i] = true;
		}
		int best = 0;
		outer: for(int i = 1; i < 1 << n; i++)	{
			if(Integer.bitCount(i) <= Integer.bitCount(best))
				continue;
			for(int j = 0; j < n; j++)	{
				if((i&(1<<j))==0)
					continue;
				for(int k = j+1; k < n; k++)	{
					if((i&(1<<k))==0)
						continue;
					if(bad[j][k])
						continue outer;
				}
			}
			best = i;
		}
		System.out.println(Integer.bitCount(best));
		for(int i = 0; i < n; i++)	{
			if((best&(1<<i)) != 0)
				System.out.println(list[i]);
		}
	}
}