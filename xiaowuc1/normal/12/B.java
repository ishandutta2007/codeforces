import java.io.*;
import java.util.*;
public class B12 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		String t = br.readLine();
		int[] count = new int[10];
		for(int i = 0; i < s.length(); i++)
			count[s.charAt(i)-'0']++;
		String now = "";
		for(int i = 1; i < 10; i++)		{
			if(count[i] > 0)		{
				count[i]--;
				now += i;
				break;
			}
		}
		for(int i = 0; i < 10; i++)		{
			while(count[i] > 0)			{
				count[i]--;
				now += i;
			}
		}
		System.out.println(t.equals(now) ? "OK" : "WRONG_ANSWER");
	}
}