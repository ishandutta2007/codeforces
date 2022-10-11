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
		int[] list = new int[n];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			list[i] = Integer.parseInt(st.nextToken());
		long ret = 0;
		for(int i = 0; i < n; i++)	{
			if(i + 1 != n)	
				ret += (list[i] - 1L) * (i+1);
			else
				ret += (list[i]) * (long)(i+1);
		}
		System.out.println(ret);
	}
}