import java.io.*;
import java.util.*;
public class A71 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0)	{
			String s = br.readLine();
			System.out.println(s.length() > 10 ? (s.charAt(0) + "" + (s.length()-2) + "" + s.charAt(s.length()-1)) : (s));
		}
	}
}