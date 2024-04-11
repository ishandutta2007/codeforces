import java.io.*;
import java.util.*;
public class B68 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		double p = (100-k) / 100.;
		int[] list = new int[n];
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		double min = 0;
		double max = 10000;
		for(int i = 1; i < 50; i++)		{
			double mid = (min+max)/2;
			double need = 0;
			double give = 0;
			for(int x: list)		{
				if(x > mid)
					give += x-mid;
				else
					need += mid-x;
			}
			if(give * p >= need)
				min = mid;
			else
				max = mid;
		}
		System.out.println(min);
	}
}