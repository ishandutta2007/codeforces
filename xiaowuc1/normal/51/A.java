import java.io.*;
import java.util.*;
public class A51 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		Set<State> set = new HashSet<State>();
		for(int i = 0; i < n; i++)	{
			String s = br.readLine();
			String t = br.readLine();
			if(br.ready())
				br.readLine();
			int a = s.charAt(0) - '0';
			int b = s.charAt(1) - '0';
			int c = t.charAt(1) - '0';
			int d = t.charAt(0) - '0';
			set.add(new State(a,b,c,d));
		}
		System.out.println(set.size());
	}
	static class State	{
		public int a,b,c,d;
		public State(int w, int x, int y, int z)		{
			a=w;
			b=x;
			c=y;
			d=z;
		}
		public int hashCode()		{
			return a+b+c+d;
		}
		public boolean equals(Object o)		{
			State s = (State)o;
			if(a==s.a && b==s.b && c==s.c && d==s.d)
				return true;
			if(a==s.b && b==s.c && c==s.d && d==s.a)
				return true;
			if(a==s.c && b==s.d && c==s.a && d==s.b)
				return true;
			if(a==s.d && b==s.a && c==s.b && d==s.c)
				return true;
			return false;
		}
	}
}