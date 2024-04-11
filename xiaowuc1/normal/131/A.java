import java.io.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		System.out.println(caps(s) ? swap(s) : s);
	}
	public static String swap(String s)	{
		String ret = "";
		for(int i = 0; i < s.length(); i++)	{
			if(Character.isUpperCase(s.charAt(i)))
				ret += Character.toLowerCase(s.charAt(i));
			else
				ret += Character.toUpperCase(s.charAt(i));
		}
		return ret;
	}
	public static boolean caps(String s)	{
		for(int i = 1; i < s.length(); i++)	{
			if(Character.isLowerCase(s.charAt(i)))
				return false;
		}
		return true;
	}
}