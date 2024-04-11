import java.io.*;
import java.util.*;
public class C43 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int[] list = new int[3];
		StringTokenizer st = new StringTokenizer(br.readLine());
		while(n-- > 0)
			list[Integer.parseInt(st.nextToken())%3]++;
		System.out.println(list[0]/2 + Math.min(list[1], list[2]));
	}
}