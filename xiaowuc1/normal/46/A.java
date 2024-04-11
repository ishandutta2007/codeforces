import java.io.*;
public class A46 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringBuilder sb = new StringBuilder();
		int curr = 1;
		for(int i = 1; i < n; i++)	{
			curr += i;
			curr %= n;
			if(curr == 0)
				curr += n;
			sb.append(curr + " ");
		}
		System.out.println(sb.toString().trim());
	}
}