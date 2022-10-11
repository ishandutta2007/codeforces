import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int amt = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int must = Integer.parseInt(st.nextToken());
		int[] list = new int[m];
		must--;
		st = new StringTokenizer(br.readLine());
		int sum = 0;
		for(int i = 0; i < m; i++)	{
			list[i] = Integer.parseInt(st.nextToken());
			sum += list[i];
		}
		if(sum < amt)	{
			System.out.println(-1);
			return;
		}
		double ret = 1;
		int other = sum - list[must];
		int total = sum - 1;
		for(int i = 1; i < amt; i++)	{
			ret *= other;
			ret /= total;
			other--;
			total--;
		}
		System.out.println(1 - ret);
	}
}