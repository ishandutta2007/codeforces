import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int ret = 0;
		int curr = 0;
		for(int i = 0; i < s.length(); i++)	{
			if(s.charAt(i) == '(')
				curr++;
			else	{
				if(curr > 0)	{
					ret += 2;
					curr--;
				}
			}
		}
		System.out.println(ret);
	}
}