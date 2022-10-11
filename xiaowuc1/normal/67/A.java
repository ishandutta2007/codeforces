import java.io.*;
import java.util.*;
public class A67 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] list = new int[Integer.parseInt(br.readLine())];
		String s = br.readLine();
		Arrays.fill(list, 1);
		while(true)	{
			boolean change = false;
			for(int i = 0; i < s.length(); i++)	{
				if(s.charAt(i) == 'L' && list[i] <= list[i+1])	{
					change = true;
					list[i] = list[i+1] + 1;
				}
				else if(s.charAt(i) == 'R' && list[i] >= list[i+1])	{
					change = true;
					list[i+1] = list[i] + 1;
				}
				else if(s.charAt(i) == '=' && list[i] != list[i+1])	{
					change = true;
					list[i] = Math.max(list[i], list[i+1]);
					list[i+1] = Math.max(list[i], list[i+1]);
				}
			}
			if(!change)
				break;
		}
		for(int x: list)
			System.out.print(x + " ");
	}
}