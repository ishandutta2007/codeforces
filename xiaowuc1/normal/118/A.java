import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		String s = scan.nextLine();
		s = s.toLowerCase();
		for(int i = 0; i < s.length(); i++)	{
			if(s.charAt(i) != 'a' && s.charAt(i) != 'e' && s.charAt(i) != 'i' && s.charAt(i) != 'o' && s.charAt(i) != 'u' && s.charAt(i) != 'y')
				System.out.print("." + s.charAt(i));
		}
	}
}