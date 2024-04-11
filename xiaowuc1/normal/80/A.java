import java.io.*;
import java.util.*;
public class A80 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = a;
		while(!prime(++c));
		System.out.println(b==c ? "YES" : "NO");
	}
	public static boolean prime(int x)	{
		for(int d = 2; d*d <= x; d++)
			if(x%d == 0)
				return false;
		return true;
	}
}