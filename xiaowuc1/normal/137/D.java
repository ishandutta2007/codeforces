import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;
public class D {
	static int[][] count;
	static String s;
	static int[][] ret;
	static ArrayList<String> go;
	public static void main(String[] args) throws IOException	{
		go = new ArrayList<String>();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		s = br.readLine();
		count = new int[s.length()][s.length()];
		for(int i = 0; i < s.length(); i++)	{
			for(int j = i+1; j < s.length(); j++)	{
				give(i,j);
			}
		}
		int num = Integer.parseInt(br.readLine());
		ret = new int[num+1][s.length()+1];
		for(int i = 0; i <= num; i++)	{
			Arrays.fill(ret[i], -1);
			ret[i][0] = 0;
		}
		System.out.println(solve(num, s.length()));
		gen(num, s.length());
		for(int i = 0; i < go.size()-1; i++)	{
			System.out.print(go.get(i) + "+");
		}
		System.out.println(go.get(go.size()-1));
	}
	public static String force(String s)	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < s.length(); i++)
			sb.append(s.charAt(Math.min(i, s.length()-1-i)));
		return sb.toString();
	}
	public static boolean gen(int numLeft, int lastChar)	{
		if(lastChar == 0)
			return true;
		for(int i = 0; i < lastChar; i++)	{
			if(ret[numLeft][lastChar] == count[i][lastChar-1] + solve(numLeft-1, i))	{
				go.add(0, force(s.substring(i, lastChar)));
				gen(numLeft-1, i);
				return true;
			}
		}
		return false;
	}
	public static int solve(int numLeft, int lastChar)	{
		if(ret[numLeft][lastChar] != -1)
			return ret[numLeft][lastChar];
		if(numLeft == 0)
			return 10000;
		int ans = 10000;
		for(int i = 0; i < lastChar; i++)	{
			ans = Math.min(ans, count[i][lastChar-1] + solve(numLeft-1, i));
		}
		ret[numLeft][lastChar] = ans;
		return ans;
	}
	public static void give(int min, int max)	{
		int ret = 0;
		for(int i = 0; min + i < max - i; i++)
			if(s.charAt(min+i) != s.charAt(max-i))
				ret++;
		count[min][max] = ret;
	}
}