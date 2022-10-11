import java.io.*;
import java.util.*;
public class B43 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s1 = clean(br.readLine());
		String s2 = clean(br.readLine());
		int c = 0;
		for(int i = 0; i < s1.length() && c < s2.length(); i++)	{
			if(s1.charAt(i) == s2.charAt(c))
				c++;
		}
		System.out.println(c == s2.length() ? "YES" : "NO");
	}
	public static String clean(String s)	{
		char[] list = s.replaceAll(" ", "").toCharArray();
		Arrays.sort(list);
		return new String(list);
	}
}