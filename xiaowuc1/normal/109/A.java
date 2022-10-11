import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		while(n%7 != 0 && n > 0)	{
			sb.append(4);
			n -= 4;
		}
		if(n < 0)	{
			System.out.println(-1);
		}
		else	{
			while(n>0)	{
				sb.append(7);
				n-=7;
			}
			System.out.println(sb.toString());
		}
	}
}