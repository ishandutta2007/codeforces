import java.io.*;
import java.util.*;
public class A21 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int state = 0;
		for(int i = 0; i < s.length(); i++)		{
			if(state == 0)		{
				if(s.charAt(i) == '@')	{
					if(i != 0)
						state++;
					else	{
						System.out.println("NO");
						return;
					}
				}
				else if(!Character.isLetterOrDigit(s.charAt(i)) && s.charAt(i) != '_')			{
					System.out.println("NO");
					return;
				}
			}
			else if(state == 1)		{
				if(s.charAt(i) == '/')	{
					if(!Character.isLetterOrDigit(s.charAt(i-1)))	{
						System.out.println("NO");
						return;
					}
					state++;
				}
				else if(s.charAt(i-1) == '@' && !Character.isLetterOrDigit(s.charAt(i)))		{
					System.out.println("NO");
					return;
				}
				else if(i+1 < s.length() && s.charAt(i) == '.' && s.charAt(i+1) == '.')	{
					System.out.println("NO");
					return;
				}
				else if(!Character.isLetterOrDigit(s.charAt(i)) && s.charAt(i) != '.' && s.charAt(i) != '_')	{
					System.out.println("NO");
					return;
				}
			}
			else	{
				if(!Character.isLetterOrDigit(s.charAt(i)) && s.charAt(i) != '_')			{
					System.out.println("NO");
					return;
				}
			}
		}
		if(state >= 1 && s.charAt(s.length()-1) != '@' && s.charAt(s.length()-1) != '.' && s.charAt(s.length()-1) != '/')
			System.out.println("YES");
		else
			System.out.println("NO");
	}
}