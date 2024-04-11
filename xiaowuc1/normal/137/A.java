import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int ret = 0;
		outer: while(s.length() != 0)	{
			ret++;
			for(int i = 1; i < Math.min(s.length(), 5); i++)	{
				if(s.charAt(i) != s.charAt(0))	{
					s = s.substring(i);
					continue outer;
				}
			}
			s = s.substring(Math.min(s.length(), 5));
		}
		System.out.println(ret);
	}
}