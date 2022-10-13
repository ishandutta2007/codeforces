import java.io.*;
public class B23 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		while(n-- > 0)	{
			System.out.println(Math.max(0,Integer.parseInt(br.readLine())-2));
		}
	}
}