import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class C {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Set<String> in = new HashSet<String>();
		int k = 0;
		while(br.ready())	{
			String s = br.readLine();
			if(s.charAt(0) == '+')
				in.add(s.substring(1));
			else if(s.charAt(0) == '-')
				in.remove(s.substring(1));
			else	{
				String l = s.substring(s.indexOf(":") + 1);
				k += l.length()*(in.size());
			}
		}
		System.out.println(k);
	}
}