import java.io.*;
import java.math.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String[] list = new String[256];
		list['>'] = "1000";
		list['<'] = "1001";
		list['+'] = "1010";
		list['-'] = "1011";
		list['.'] = "1100";
		list[','] = "1101";
		list['['] = "1110";
		list[']'] = "1111";
		String s = br.readLine();
		StringBuilder sb = new StringBuilder();
		for(int i = 0; i < s.length(); i++)
			sb.append(list[s.charAt(i)]);
		System.out.println(new BigInteger(sb.toString(),2).mod(BigInteger.valueOf(1000003)));
	}
}