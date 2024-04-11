import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int R = Integer.parseInt(st.nextToken());
		int r = Integer.parseInt(st.nextToken());
		if(n == 1)	{
			System.out.println(r <= R ? "YES" : "NO");
		}
		else if(n == 2)	{
			System.out.println(2*r <= R ? "YES" : "NO");
		}
		else	{
			if(r >= R)	{
				System.out.println("NO");
			}
			else	{
				double x1 = (R-r);
				double y1 = 0;
				double x2 = (R-r) * Math.cos(2 * Math.PI / n);
				double y2 = (R-r) * Math.sin(2 * Math.PI / n);
				System.out.println(2*r <= Math.hypot(x1-x2,y1-y2) ? "YES" : "NO");
			}
		}
	}
}