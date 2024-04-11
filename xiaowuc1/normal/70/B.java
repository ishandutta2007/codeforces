import java.io.*;
import java.util.*;
public class AMain {
	static int max;
	static int ret;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		max = Integer.parseInt(br.readLine());
		if(process(br.readLine()))	{
			System.out.println(ret);
		}
		else	{
			System.out.println("Impossible");
		}
	}
	public static boolean process(String s)		{
		if(s.length() <= max){
			ret++;
			return true;
		}
		if(s.charAt(0) == ' ')
			return process(s.substring(1));
		for(int i = max-1; i >= 0; i--)	{
			if(s.charAt(i) == '?' || s.charAt(i) == '.' || s.charAt(i) == '!')	{
				ret++;
				return process(s.substring(i+1));
			}
		}
		return false;
	}
}