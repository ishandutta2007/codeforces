import java.io.*;
import java.util.*;
public class A40 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		StringTokenizer st = new StringTokenizer(br.readLine());
		int curr = 1;
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int year = 2001; year <= 2000 + n; year++)		{
			if(Integer.parseInt(st.nextToken()) == curr)		{
				list.add(year);
				curr++;
			}
		}
		System.out.println(list.size());
		if(list.size() == 0)		{
			return;
		}
		for(int i = 0; i < list.size()-1; i++)
			System.out.print(list.get(i) + " ");
		System.out.println(list.get(list.size()-1));
	}
}