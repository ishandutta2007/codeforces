import java.io.*;
import java.util.*;
public class E24 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] x = new int[n];
		int[] v = new int[n];
		for(int i = 0; i < n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			x[i] = Integer.parseInt(st.nextToken());
			v[i] = Integer.parseInt(st.nextToken());
		}
		int lastNeg = n-1;
		while(lastNeg >= 0 && v[lastNeg] > 0)
			lastNeg--;
		if(lastNeg == -1)	{
			System.out.println(-1);
			return;
		}
		int firstPos = 0;
		while(firstPos < lastNeg && v[firstPos] < 0)
			firstPos++;
		if(firstPos == lastNeg)	{
			System.out.println(-1);
			return;
		}
		double minTime = 0;
		double maxTime = 2000000000;
		outer: for(int q = 0; q < 100; q++)	{
			double time = (minTime + maxTime)/2;
			double pos = -2000000000;
			for(int i = 0; i < x.length; i++)	{
				if(v[i] > 0)	{
					pos = Math.max(pos, x[i] + time * v[i]);
				}
				else	{
					if(x[i] < pos)	{
						maxTime = time;
						continue outer;
					}
					double now = x[i] + time * v[i];
					if(now < pos)	{
						maxTime = time;
						continue outer;
					}
				}
			}
			minTime = time;
		}
		System.out.println(minTime);
	}
}