import java.util.*;
import java.io.*;
public class A127 {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		int k = readInt();
		int card = n/k;
		int unused = n - k*card;
		double max = 0;
		double min = 100;
		int[] list = new int[n];
		boolean[] used = new boolean[n];
		for(int i = 0; i < n; i++)
			list[i] = readInt();
		int qq = readInt();
		while(qq-- > 0)	{
			int curr = 0;
			for(int i = 0; i < card; i++)	{
				int now = readInt();
				now--;
				used[now] = true;
				curr += list[now];
			}
			double ret = curr*1.0/card;
			min = Math.min(min, ret);
			max = Math.max(max, ret);
		}
		int not = 0;
		for(boolean b: used)	{
			if(!b)	{
				not++;
			}
		}
		if(not != 0 && unused + (n-not) != n)	{
			int[] remain = new int[not];
			int c = 0;
			for(int i = 0; i < n; i++)	{
				if(!used[i])
					remain[c++] = list[i];
			}
			Arrays.sort(remain);
			int minmin = 0;
			for(int i = 0; i < card; i++)
				minmin += remain[i];
			min = Math.min(min, minmin * 1.0 / card);
			int maxmax = 0;
			for(int i = remain.length-1; i >= remain.length - card; i--)	{
				maxmax += remain[i];
			}
			max = Math.max(max, maxmax * 1.0 / card);
		}
		System.out.println(min + " " + max);
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}