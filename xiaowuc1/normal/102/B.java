import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int ret = 0;
		while(s.length() > 1)	{
			s = gen(s);
			ret++;
		}
		System.out.println(ret);
	}
	public static String gen(String s)	{
		int ret = 0;
		for(int i = 0; i < s.length(); i++)
			ret += s.charAt(i)-'0';
		return Integer.toString(ret);
	}
}