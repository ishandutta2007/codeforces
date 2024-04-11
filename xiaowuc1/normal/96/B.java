import java.io.*;
import java.util.*;
public class B96 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long max = Long.MAX_VALUE;
		int n = Integer.parseInt(br.readLine());
		for(int length = 1; length <= 10; length++)	{
			for(int i = 0; i < (1<<length); i++)	{
				if(Integer.bitCount(i) * 2 != length)
					continue;
				String s = "";
				for(int j = 0; j < length; j++)	{
					if((i&(1<<j)) == 0)
						s += '4';
					else
						s += '7';
				}
				long test = Long.parseLong(s);
				if(test < max && test >= n)
					max = test;
			}
		}
		System.out.println(max);
	}
}