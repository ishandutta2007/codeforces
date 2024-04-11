import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
public class B {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		ArrayList<String> list = new ArrayList<String>();
		while(br.ready())	{
			String s = br.readLine();
			list.add(s);
		}
		boolean leftM = false;
		int maxLength = 0;
		for(String s: list)
			maxLength = Math.max(maxLength, s.length());
		String[] ret = new String[list.size() + 2];
		StringBuilder frame = new StringBuilder();
		for(int i = 1; i <= maxLength; i++)
			frame.append("*");
		frame.append("**");
		ret[0] = ret[ret.length-1] = frame.toString();
		for(int i = 0; i < list.size(); i++)	{
			String other = list.get(i);
			int length = other.length();
			int left = ((maxLength-length)>>1);
			int right = left;
			if(left+right != maxLength-length)	{
				if(leftM)
					left++;
				else
					right++;
				leftM = !leftM;
			}
			StringBuilder sb = new StringBuilder();
			sb.append('*');
			for(int z = 1; z <= left; z++)
				sb.append(' ');
			sb.append(other);
			for(int z = 1; z <= right; z++)
				sb.append(' ');
			sb.append('*');
			ret[i+1] = sb.toString();
		}
		for(String ss: ret)
			System.out.println(ss);
	}
}