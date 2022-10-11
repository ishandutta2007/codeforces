import java.io.*;
import java.util.*;
public class C78 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		if(n % 2 == 0)	{
			System.out.println("Marsel");
			return;
		}
		int m = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		boolean can = false;
		if(prime(m))
			can = k == 1;
		else
			for(int p = 2; m / p >= k; p++)	{
				if(m%p==0)	{
					can = true;
					break;
				}
			}
		System.out.println(can ? "Timur" : "Marsel");
	}
	public static boolean prime(int x)	{
		if(x==1)
			return false;
		if(x<=3)
			return true;
		if(x%2==0 || x%3==0)
			return false;
		for(int d = 5; d * d <= x; d += 6)
			if(x%d==0)
				return false;
		for(int d = 7; d * d <= x; d += 6)
			if(x%d==0)
				return false;
		return true;
	}
}