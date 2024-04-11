import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class C {
	static int MOD = 1000000007;
	static int[][] choose;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());		
		choose = new int[1001][1001];
		for(int i = 0; i <= 1000; i++)
			choose(1000, i);
		long p = choose(r-1, 2*m);
		p *= choose(c-1, 2*m);
		p %= MOD;
		System.out.println(p);
	}
	public static int choose(int a, int b)	{
		if(b > a)
			return 0;
		if(choose[a][b] != 0)
			return choose[a][b];
		if(a == b || b == 0)
			return 1;
		int now = choose(a-1,b) + choose(a-1,b-1);
		now %= MOD;
		choose[a][b] = now;
		return now;
	}
}