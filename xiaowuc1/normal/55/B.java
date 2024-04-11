import java.io.*;
import java.util.*;
public class B55 {
	static long ret;
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		ret = Long.MAX_VALUE;
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		boolean aa = true;
		boolean bb = true;
		boolean cc = true;
		st = new StringTokenizer(br.readLine());
		String s = st.nextToken();
		if(s.equals("*"))
			aa = false;
		s = st.nextToken();
		if(s.equals("*"))
			bb = false;
		s = st.nextToken();
		if(s.equals("*"))
			cc = false;
		go(a,b,c,d,aa,bb,cc);
		System.out.println(ret);
	}
	public static void go(long a, long b, long c, long d, boolean aa, boolean bb, boolean cc)		{
		if(b == -1)
			ret = Math.min(ret, a);
		else if(c == -1)		{
			if(cc)
				go(a+b,-1,-1,-1,aa,bb,cc);
			else
				go(a*b,-1,-1,-1,aa,bb,cc);
		}
		else if(d == -1)		{
			if(bb)		{
				go(a+b,c,-1,-1,aa,bb,cc);
				go(a+c,b,-1,-1,aa,bb,cc);
				go(b+c,a,-1,-1,aa,bb,cc);
			}
			else	{
				go(a*b,c,-1,-1,aa,bb,cc);
				go(a*c,b,-1,-1,aa,bb,cc);
				go(b*c,a,-1,-1,aa,bb,cc);
			}
		}
		else	{
			if(aa)		{
				go(a+b,c,d,-1,aa,bb,cc);
				go(a+c,b,d,-1,aa,bb,cc);
				go(a+d,b,c,-1,aa,bb,cc);
				go(b+c,a,d,-1,aa,bb,cc);
				go(b+d,a,c,-1,aa,bb,cc);
				go(c+d,a,b,-1,aa,bb,cc);
			}
			else {
				go(a*b,c,d,-1,aa,bb,cc);
				go(a*c,b,d,-1,aa,bb,cc);
				go(a*d,b,c,-1,aa,bb,cc);
				go(b*c,a,d,-1,aa,bb,cc);
				go(b*d,a,c,-1,aa,bb,cc);
				go(c*d,a,b,-1,aa,bb,cc);
			}
		}
	}
}