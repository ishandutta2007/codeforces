import java.io.*;
public class A53 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		String ret = null;
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0)	{
			String curr = br.readLine();
			if(curr.startsWith(s) && (ret == null || curr.compareTo(ret) < 0))
				ret = curr;
		}
		if(ret == null)
			ret = s;
		System.out.println(ret);
	}
}