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
		for(int i = 0; i < s.length(); i++)
			if(s.charAt(i) == '4' || s.charAt(i) == '7')
				ret++;
		System.out.println(ret == 4 || ret == 7 ? "YES" : "NO");
	}
}