import java.io.*;
import java.util.*;
public class B94 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		boolean[][] match = new boolean[5][5];
		while(n-- > 0)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int a = Integer.parseInt(st.nextToken());
			int b = Integer.parseInt(st.nextToken());
			a--;
			b--;
			match[a][b] = match[b][a] = true;
		}
		for(int i = 0; i < 5; i++)
			for(int j = i+1; j < 5; j++)
				for(int k = j+1; k < 5; k++)
					if(match[i][j] && match[i][k] && match[j][k])		{
						System.out.println("WIN");
						return;
					}
					else if(!match[i][j] && !match[i][k] && !match[j][k])		{
						System.out.println("WIN");
						return;
					}
		System.out.println("FAIL");
	}
}