import java.io.*;
import java.util.*;
public class C75 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int gcd = gcd(a,b);
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(1);
		for(int i = 2; i * i <= gcd; i++)		{
			if(gcd%i==0)		{
				list.add(i);
				if(i*i!=gcd)
					list.add(gcd/i);
			}
		}
		list.add(gcd);
		Collections.sort(list);
		int n = Integer.parseInt(br.readLine());
		outer: while(n-- > 0)	{
			st = new StringTokenizer(br.readLine());
			int low = Integer.parseInt(st.nextToken());
			int high = Integer.parseInt(st.nextToken());
			for(int i = list.size()-1; i >= 0; i--)		{
				int curr = list.get(i);
				if(curr >= low && curr <= high)	{
					System.out.println(curr);
					continue outer;
				}
				if(curr < low)
					break;
			}
			System.out.println(-1);
		}
	}
	public static int gcd(int a, int b)		{
		return a%b == 0 ? b : gcd(b,a%b);
	}
}