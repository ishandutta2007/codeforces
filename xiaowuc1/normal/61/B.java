import java.io.*;
public class B61 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = clean(br.readLine());
		String b = clean(br.readLine());
		String c = clean(br.readLine());
		String s1 = a+b+c;
		String s2 = a+c+b;
		String s3 = b+a+c;
		String s4 = b+c+a;
		String s5 = c+b+a;
		String s6 = c+a+b;
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0)		{
			String s = clean(br.readLine());
			if(s.equals(s1) || s.equals(s2) || s.equals(s3) || s.equals(s4) || s.equals(s5) || s.equals(s6))
				System.out.println("ACC");
			else
				System.out.println("WA");
		}
	}
	public static String clean(String s)	{
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < s.length(); i++)
			if(Character.isLetter(s.charAt(i)))
			sb.append(s.charAt(i));
		return sb.toString().toLowerCase();
	}
}