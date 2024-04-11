import java.io.*;
import java.util.*;
public class C65 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		State[] list = new State[n+1];
		for(int i = 0; i <= n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			list[i] = new State(Integer.parseInt(st.nextToken()), Integer.parseInt(st.nextToken()),Integer.parseInt(st.nextToken()));
		}
		StringTokenizer st = new StringTokenizer(br.readLine());
		int vLarge = Integer.parseInt(st.nextToken());
		int vSmall = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int x = Integer.parseInt(st.nextToken());
		int y = Integer.parseInt(st.nextToken());
		int z = Integer.parseInt(st.nextToken());
		State start = new State(x,y,z);
		double timeSpent = 0;
		for(int i = 1; i <= n; i++)	{
			double time = dist(list[i-1], list[i]) / vSmall;
			double require = dist(start, list[i]);
			if(require / vLarge > (timeSpent+time))	{
				timeSpent += time;
				continue;
			}
			double min = 0;
			double max = time;
			for(int q = 0; q < 50; q++)	{
				double mid = (min+max)/2;
				double xx = list[i-1].x + (list[i].x - list[i-1].x) * mid / time;
				double yy = list[i-1].y + (list[i].y - list[i-1].y) * mid / time;
				double zz = list[i-1].z + (list[i].z - list[i-1].z) * mid / time;
				State now = new State(xx,yy,zz);
				require = dist(start, now);
				if(require / vLarge > (timeSpent + mid))
					min = mid;
				else
					max = mid;
			}
			System.out.println("YES");
			System.out.println(min + timeSpent);
			double xx = list[i-1].x + (list[i].x - list[i-1].x) * min / time;
			double yy = list[i-1].y + (list[i].y - list[i-1].y) * min / time;
			double zz = list[i-1].z + (list[i].z - list[i-1].z) * min / time;
			System.out.println(xx + " " + yy + " " + zz);
			return;
		}
		System.out.println("NO");
	}
	public static double dist(State a, State b)	{
		double x = a.x-b.x;
		double y = a.y-b.y;
		double z = a.z-b.z;
		return Math.sqrt(x*x+y*y+z*z);
	}
	static class State	{
		public double x,y,z;
		public State(double a, double b, double c)	{
			x=a;
			y=b;
			z=c;
		}
	}
}