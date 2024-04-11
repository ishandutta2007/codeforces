import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		StringBuilder sb = new StringBuilder();
		while(s.length() != 0)	{
			if(s.charAt(0) == '.'){
				sb.append(0);
				s = s.substring(1);
			}
			else	{
				if(s.charAt(1) == '.')	{
					sb.append(1);
				}
				else	{
					sb.append(2);
				}
				s = s.substring(2);
			}
		}
		System.out.println(sb);
	}
}