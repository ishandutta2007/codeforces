import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class A {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		if(n <= 10)	{
			System.out.println(0);
			return;
		}
		if(n <= 19)	{
			System.out.println(4);
			return;
		}
		if(n == 20){
			System.out.println(15);
			return;
		}
		if(n == 21)	{
			System.out.println(4);
			return;
		}
		System.out.println(0);
	}
}