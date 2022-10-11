import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		int n = scan.nextInt();
		for(int i = 0; i <= 2*n; i++)	{
			StringBuilder sb = new StringBuilder();
			for(int j = 0; j <= 2*n; j++)	{
				int now = n-Math.abs(n-i)-Math.abs(n-j);
				if(now >= 0)
					sb.append(now);
				else
					sb.append(" ");
				if(j != 2*n)
					sb.append(" ");
			}
			while(sb.charAt(sb.length()-1) == ' ')
				sb.deleteCharAt(sb.length()-1);
			System.out.println(sb);
		}
	}
}