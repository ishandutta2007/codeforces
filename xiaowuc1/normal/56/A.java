import java.io.*;
import java.util.*;
public class A56 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("ABSINTH,BEER,BRANDY,CHAMPAGNE,GIN,RUM,SAKE,TEQUILA,VODKA,WHISKEY,WINE", ",");
		Set<String> set = new HashSet<String>();
		while(st.hasMoreTokens())
			set.add(st.nextToken());
		int ret = 0;
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0)		{
			String s = br.readLine();
			try	{
				if(set.contains(s) || Integer.parseInt(s) < 18)
					ret++;
			}
			catch(Exception e){}
		}
		System.out.println(ret);
	}
}