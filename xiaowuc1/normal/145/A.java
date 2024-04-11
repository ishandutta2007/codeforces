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
		String t = br.readLine();
		int four = 0;
		int seven = 0;
		for(int i = 0; i < s.length(); i++)	{
			if(s.charAt(i) != t.charAt(i))	{
				if(s.charAt(i) == '4')
					four++;
				else
					seven++;
			}
		}
		System.out.println(Math.max(four, seven));
	}
}