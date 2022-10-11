import java.io.*;
public class A20 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		for(int i = 0; i < s.length()-1; i++)	{
			if(s.charAt(i) == '/' && s.charAt(i+1) == '/')		{
				s = s.substring(0,i) + s.substring(i+1);
				i--;
			}
		}
		if(s.length() > 1 && s.charAt(s.length()-1) == '/')
			s=s.substring(0,s.length()-1);
		System.out.println(s);
	}
}