import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class E {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int x1 = Integer.parseInt(st.nextToken());
		int y1 = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int x2 = Integer.parseInt(st.nextToken());
		int y2 = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		if(a == 0 && b == 0)	{
			if(x1 == x2 && y1 == y2)	{
				System.out.println("YES");
				return;
			}
			if(x1 == y2 && y1 == -x2)	{
				System.out.println("YES");
				return;
			}
			if(x1 == -x2 && y1 == -y2)	{
				System.out.println("YES");
				return;
			}
			if(x1 == -y2 && y1 == x2)	{
				System.out.println("YES");
				return;
			}
			System.out.println("NO");
			return;
		}
		b = -b;
		int d = -b;
		int e = a;
		int c1 = x2-x1;
		int f1= y2-y1;
		if(pass(a,b,c1,d,e,f1))	{
			System.out.println("YES");
			return;
		}
		c1 = x2-y1;
		f1 = y2+x1;
		if(pass(a,b,c1,d,e,f1))	{
			System.out.println("YES");
			return;
		}
		c1 = x2+x1;
		f1 = y2+y1;
		if(pass(a,b,c1,d,e,f1))	{
			System.out.println("YES");
			return;
		}
		c1 = x2+y1;
		f1 = y2-x1;
		if(pass(a,b,c1,d,e,f1))	{
			System.out.println("YES");
			return;
		}
		System.out.println("NO");
	}
	public static boolean pass(long a, long b, long c, long d, long e, long f)	{
		long xNum = b*f-c*e;
		long yNum = a*f-c*d;
		long dem = a*e-b*d;
		return xNum%dem == 0 && yNum%dem == 0;
	}
	public static long sq(int x, int y)	{
		long xx = x;
		xx *= x;
		long yy = y;
		yy *= y;
		return xx+yy;
	}
	public static long[] extended(long p, long q) {
		if (q == 0)
			return new long[] { p, 1, 0 };
		long[] vals = extended(q, p % q);
		long d = vals[0];
		long a = vals[2];
		long b = vals[1] - (p / q) * vals[2];
		return new long[] { d, a, b };
	}
}
/*
46 -96 
28 42 
-36 -22
convert to
23 -48
14 21
-18 -11
*/