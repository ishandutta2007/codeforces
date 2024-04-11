import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		br.readLine();
		String s = br.readLine();
		if(s.length() % 2 == 0)	{
			for(int i = 0; i < s.length(); i += 2)	{
				System.out.print(s.substring(i, i+2));
				if(i+2 == s.length())
					System.out.println();
				else
					System.out.print('-');
			}
		}
		else	{
			System.out.print(s.substring(0, 3));
			if(s.length() > 3)	{
				System.out.print('-');
				for(int i = 3; i < s.length(); i += 2)	{
					System.out.print(s.substring(i, i+2));
					if(i+2 == s.length())
						System.out.println();
					else
						System.out.print('-');
				}
			}
			else
				System.out.println();
		}
	}
}