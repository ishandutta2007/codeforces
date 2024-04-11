import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		boolean curr = true;
		while(c != 0)	{
			if(curr)
				c -= gcd(c,a);
			else
				c -= gcd(c,b);
			curr = !curr;
		}
		System.out.println(curr ? 1 : 0);
	}
	public static int gcd(int a, int b)	{
		return a%b==0 ? b : gcd(b,a%b);
	}
}