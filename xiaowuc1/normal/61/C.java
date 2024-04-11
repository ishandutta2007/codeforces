import java.io.*;
import java.util.*;
public class C61 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		String b = st.nextToken();
		String num = br.readLine();
		long val = Long.parseLong(num, a);
		if(b.equals("R"))
			roman(val);
		else
			System.out.println(Long.toString(val, Integer.parseInt(b)).toUpperCase());
	}
	public static void roman(long num)		{
		while(num > 0)	{
			if(num >= 1000)	{
				num -= 1000;
				System.out.print("M");
			}
			else if(num >= 900)	{
				num -= 900;
				System.out.print("CM");
			}
			else if(num >= 500)	{
				num -= 500;
				System.out.print("D");
			}
			else if(num >= 400)	{
				num -= 400;
				System.out.print("CD");
			}
			else if(num >= 100)	{
				num -= 100;
				System.out.print("C");
			}
			else if(num >= 90)	{
				num -= 90;
				System.out.print("XC");
			}
			else if(num >= 50)	{
				num -= 50;
				System.out.print("L");
			}
			else if(num >= 40)	{
				num -= 40;
				System.out.print("XL");
			}
			else if(num >= 10)	{
				num -= 10;
				System.out.print("X");
			}
			else if(num >= 9)	{
				num -= 9;
				System.out.print("IX");
			}
			else if(num >= 5)	{
				num -= 5;
				System.out.print("V");
			}
			else if(num >= 4)	{
				num -= 4;
				System.out.print("IV");
			}
			else if(num >= 1)	{
				num--;
				System.out.print("I");
			}
		}
	}
}