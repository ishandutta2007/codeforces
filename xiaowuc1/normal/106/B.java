import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] a = new int[n];
		int[] b = new int[n];
		int[] c = new int[n];
		int[] d = new int[n];
		for(int i = 0; i < n; i++)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			a[i] = Integer.parseInt(st.nextToken());
			b[i] = Integer.parseInt(st.nextToken());
			c[i] = Integer.parseInt(st.nextToken());
			d[i] = Integer.parseInt(st.nextToken());
		}
		boolean[] bad = new boolean[n];
		for(int i = 0; i < n; i++)	{
			for(int j = 0; j < n; j++)	{
				if(a[i] < a[j] && b[i] < b[j] && c[i] < c[j])	{
					bad[i] = true;
				}
			}
		}
		int index = -1;
		int bestCost = Integer.MAX_VALUE;
		for(int i = 0; i < n; i++)	{
			if(!bad[i] && d[i] < bestCost)	{
				bestCost = d[i];
				index = i;
			}
		}
		System.out.println(index+1);
	}
}