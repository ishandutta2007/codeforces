import java.io.*;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(br.readLine());
		// y = x/4
		while(t-- > 0)	{
			StringTokenizer st = new StringTokenizer(br.readLine());
			int x = Integer.parseInt(st.nextToken());
			int y = Integer.parseInt(st.nextToken());
			if(x == 0)	{
				if(y != 0)	{
					System.out.println(.5);
				}
				else	{
					System.out.println(1);
				}
			}
			else if(x <= 4*y)	{
				System.out.println(.5 + x/16./y);
			}
			else	{
				System.out.println(1 - y/1./x);
			}
		}
	}
}