import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<Boolean> list = new ArrayList<Boolean>();
		String s = br.readLine();
		for(int i = 0; i < s.length(); i++)		{
			list.add(s.charAt(i) == '1');
		}
		int ret = 0;
		while(list.size() > 1)	{
			ret++;
			if(!list.get(list.size()-1))	{
				list.remove(list.size()-1);
			}
			else
				for(int index = list.size()-1; true; index--)	{
					if(index == -1)	{
						list.add(0, true);
						break;
					}
					if(!list.get(index))	{
						list.set(index, true);
						break;
					}
					list.set(index, false);
				}
		}
		System.out.println(ret);
	}
}