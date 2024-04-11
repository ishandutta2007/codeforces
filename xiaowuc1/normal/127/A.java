import java.util.*;
public class A127 {
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		int scale = scan.nextInt();
		int[] x = new int[n];
		int[] y = new int[n];
		for(int i = 0; i < n; i++)	{
			x[i] = scan.nextInt();
			y[i] = scan.nextInt();
		}
		double ret = 0;
		for(int i = 0; i < n-1; i++)	{
			int j = i+1;
			j %= n;
			ret += Math.hypot(x[i]-x[j], y[i]-y[j]);
		}
		ret *= scale;
		ret /= 50;
		System.out.println(ret);
	}
}