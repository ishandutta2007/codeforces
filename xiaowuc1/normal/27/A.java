import java.io.*;
import java.util.*;
public class A27 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		boolean[] can = new boolean[3005];
		StringTokenizer st = new StringTokenizer(br.readLine());
		for(int i = 0; i < n; i++)
			can[Integer.parseInt(st.nextToken())] = true;
		for(int i = 1; i < can.length; i++)		{
			if(!can[i])		{
				System.out.println(i);
				return;
			}
		}
	}
}