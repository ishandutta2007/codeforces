import java.io.*;
import java.util.*;
public class B9 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int[] list = new int[Integer.parseInt(st.nextToken())];
		double[] bus = new double[list.length];
		double[] run = new double[list.length];
		int vb = Integer.parseInt(st.nextToken());
		int vr = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i = 0; i < list.length; i++)	{
			list[i] = Integer.parseInt(st.nextToken());
		}
		st = new StringTokenizer(br.readLine());
		int xx = Integer.parseInt(st.nextToken());
		int yy = Integer.parseInt(st.nextToken());
		bus[0] = 1 << 30;
		run[0] = 1 << 30;
		for(int i = 1; i < list.length; i++)	{
			bus[i] = dist(-list[i], 0) / vb;
			run[i] = dist(xx-list[i], yy) / vr;
		}
		int best = 1;
		for(int i = 2; i < list.length; i++)	{
			double given = bus[best] + run[best];
			double next = bus[i] + run[i];
			if(next < given || (next == given && run[i] < run[best]))
				best = i;
		}
		System.out.println(best+1);
	}
	public static double dist(int x, int y)	{
		double a = x;
		double b = y;
		return Math.sqrt(a*a+b*b);
	}
}