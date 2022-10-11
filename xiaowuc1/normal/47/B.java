import java.io.*;
import java.util.*;
public class B47 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int[] list = new int[3];
		String s = br.readLine();
		if(s.charAt(1) == '>')
			list[s.charAt(0)-'A']++;
		else
			list[s.charAt(2)-'A']++;
		s = br.readLine();
		if(s.charAt(1) == '>')
			list[s.charAt(0)-'A']++;
		else
			list[s.charAt(2)-'A']++;
		s = br.readLine();
		if(s.charAt(1) == '>')
			list[s.charAt(0)-'A']++;
		else
			list[s.charAt(2)-'A']++;
		if(list[0] == 1 && list[1] == 1)
			System.out.println("Impossible");
		else if(list[0] == 2 && list[1] == 1)
			System.out.println("CBA");
		else if(list[0] == 2 && list[2] == 1)
			System.out.println("BCA");
		else if(list[1] == 2 && list[0] == 1)
			System.out.println("CAB");
		else if(list[1] == 2 && list[2] == 1)
			System.out.println("ACB");
		else if(list[2] == 2 && list[0] == 1)
			System.out.println("BAC");
		else if(list[2] == 2 && list[1] == 1)
			System.out.println("ABC");
	}
}