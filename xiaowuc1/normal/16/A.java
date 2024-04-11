import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int r = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		String[] s = new String[r];
		for(int i = 0; i < r; i++)
			s[i] = br.readLine();
		for(int i = 0; i < r; i++)	{
			Set<Character> set = new HashSet<Character>();
			for(int j = 0; j < s[i].length(); j++)
				set.add(s[i].charAt(j));
			if(set.size() > 1)	{
				System.out.println("NO");
				return;
			}
		}
		for(int i = 0; i < r-1; i++)	{
			if(s[i].charAt(0) == s[i+1].charAt(0))	{
				System.out.println("NO");
				return;
			}
		}
		System.out.println("YES");
	}

}