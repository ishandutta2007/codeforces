import java.io.*;
import java.math.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		String x = Integer.toString(a, 3);
		String y = Integer.toString(b, 3);
		while(x.length() < y.length())
			x = '0' + x;
		while(y.length() < x.length())
			y = '0' + y;
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < x.length(); i++)	{
			int aCurr = x.charAt(i) - '0';
			int bCurr = y.charAt(i) - '0';
			for(int k = 0; k < 3; k++)	{
				if((aCurr + k)%3 == bCurr)	{
					sb.append((char)('0' + k));
				}
			}
		}
		System.out.println(Integer.parseInt(sb.toString(), 3));
	}
}