import java.io.*;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		for(int i = 1; i + 1 < s.length(); i++)	{
			if(s.substring(i, i+2).equals("at"))	{
				s = s.substring(0,i) + "@" + s.substring(i+2);
				break;
			}
		}
		for(int i = 1; i + 3 < s.length(); i++)	{
			if(s.substring(i,i+3).equals("dot"))	{
				s = s.substring(0,i) + "." + s.substring(i+3);
				i=0;
			}
		}
		System.out.println(s);
	}
}