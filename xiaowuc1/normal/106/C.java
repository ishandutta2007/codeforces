import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int dough = Integer.parseInt(st.nextToken());
		int qq = Integer.parseInt(st.nextToken());
		int orig = Integer.parseInt(st.nextToken());
		int price = Integer.parseInt(st.nextToken());
		int[] best = new int[dough+1];
		for(int i = 0; i < best.length; i++)	{
			best[i] = (i/orig)*price;
		}
		while(qq-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int max = Integer.parseInt(st.nextToken())/Integer.parseInt(st.nextToken());
			int d = Integer.parseInt(st.nextToken());
			int p = Integer.parseInt(st.nextToken());
			for(int curr = dough; curr >= 0; curr--)	{
				for(int num = 1; num <= max && curr - num * d >= 0; num++)	{
					best[curr] = Math.max(best[curr], best[curr-num*d] + num*p);
				}
			}
		}
		int max = 0;
		for(int xx: best)	{
			if(xx > max)
				max = xx;
		}
		System.out.println(max);
	}
}