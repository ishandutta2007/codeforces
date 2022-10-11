import java.io.*;
import java.util.*;
public class A78 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		System.out.println(solve(br.readLine()) == 5 && solve(br.readLine()) == 7 && solve(br.readLine()) == 5 ? "YES" : "NO");
	}
	public static int solve(String s)		{
		int ret = 0;
		for(int i = 0; i < s.length(); i++)
			if(s.charAt(i) == 'a')
				ret++;
			else if(s.charAt(i) == 'e')
				ret++;
			else if(s.charAt(i) == 'i')
				ret++;
			else if(s.charAt(i) == 'o')
				ret++;
			else if(s.charAt(i) == 'u')
				ret++;
		return ret;
	}
}