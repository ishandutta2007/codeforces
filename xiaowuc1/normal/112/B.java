import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		int i = Integer.parseInt(st.nextToken());
		int j = Integer.parseInt(st.nextToken());
		if((n/2 == i || n/2 == i-1) && (n/2 == j || n/2 == j-1))	{
			System.out.println("NO");
		}
		else	{
			System.out.println("YES");
		}
	}
}