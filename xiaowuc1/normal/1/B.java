import java.io.*;
import java.util.*;
public class B1 {
	static String alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static String loc = " ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int qq = Integer.parseInt(br.readLine());
		while(qq-- > 0)		{
			String s = br.readLine();
			if(rc(s))		{
				System.out.println(rcconvert(s));
			}
			else	{
				System.out.println(reverse(s));
			}
		}
	}
	public static String reverse(String s)		{
		int change = 0;
		for(; change < s.length(); change++)
			if(Character.isDigit(s.charAt(change)))
				break;
		String first = s.substring(0,change);
		int next = Integer.parseInt(s.substring(change));
		return "R" + next + "C" + convert(first);
	}
	public static String rcconvert(String s)	{
		int a = s.indexOf("R");
		int b = s.indexOf("C");
		int r = Integer.parseInt(s.substring(a+1,b));
		int c = Integer.parseInt(s.substring(b+1));
		return convert(c) + r;
	}
	public static int convert(String s)		{
		int ret = 0;
		for(int i = 0; i < s.length(); i++)	{
			ret *= 26;
			ret += loc.indexOf(Character.toString(s.charAt(i)));
		}
		return ret;
	}
	public static String convert(int num)		{
		int prod = 26;
		int len = 1;
		while(prod < num)		{
			num -= prod;
			prod *= 26;
			len++;
		}
		String ret = gen(num);
		while(ret.length() < len)
			ret = "A" + ret;
		return ret;
	}
	public static String gen(int num)		{
		if(num == 1)
			return "A";
		num--;
		String ret = "";
		ArrayList<Integer> list = new ArrayList<Integer>();
		while(num > 0)		{
			list.add(num%26);
			num /= 26;
		}
		for(int i = list.size()-1; i >= 0; i--)
			ret += alpha.charAt(list.get(i));
		return ret;
	}
	public static boolean rc(String s)		{
		int r = s.indexOf("R");
		int c = s.indexOf("C");
		if(r > c || r == -1 || c == -1 || r+1 == c)
			return false;
		for(int i = r+1; i < c; i++)
			if(!Character.isDigit(s.charAt(i)))
				return false;
		return true;
	}
}