import java.io.*;
public class C9 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		for(int i = 1; true; i++)	{
			long now = Long.parseLong(Integer.toString(i,2));
			if(now > n)		{
				System.out.println(i-1);
				break;
			}
		}
	}
}