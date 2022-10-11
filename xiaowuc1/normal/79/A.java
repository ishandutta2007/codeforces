import java.io.*;
import java.util.*;
public class A79 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		while(true)	{
			if(a >= 2 && b >= 2)	{
				a -= 2;
				b -= 2;
			}
			else if(a >= 1 && b >= 12)	{
				a--;
				b -= 12;
			}
			else if(b >= 22)	{
				b -= 22;
			}
			else	{
				System.out.println("Hanako");
				break;
			}
			if(b >= 22)	{
				b -= 22;
			}
			else if(a >= 1 && b >= 12)	{
				a--;
				b -= 12;
			}
			else if(a >= 2 && b >= 2)	{
				a -= 2;
				b -= 2;
			}
			else	{
				System.out.println("Ciel");
				break;
			}
		}
	}
}