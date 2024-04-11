import java.io.*;
import java.math.BigInteger;
import java.util.*;
public class AMain {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String text = br.readLine();
		if(text.charAt(0) == '@' || text.charAt(text.length()-1) == '@')	{
			System.out.println("No solution");
			return;
		}
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 0; i < text.length(); i++)	{
			if(text.charAt(i) == '@')	{
				list.add(i);
			}
		}
		if(list.size() == 0)	{
			System.out.println("No solution");
			return;
		}
		if(list.size() == 1)	{
			System.out.println(text);
			return;
		}
		for(int i = 1; i < list.size(); i++)	{
			if(list.get(i) - list.get(i-1) <= 2)	{
				System.out.println("No solution");
				return;
			}
		}
		for(int i = 0; i < list.size() - 1; i++)	{
			int start = i == 0 ? 0 : list.get(i-1) + 2;
			int end = list.get(i) + 2;
			System.out.print(text.substring(start,end) + ",");
		}
		System.out.println(text.substring(list.get(list.size()-2)+2));
	}
}