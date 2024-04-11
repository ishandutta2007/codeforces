import java.io.*;
import java.util.*;
public class B80 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int h = Integer.parseInt(s.substring(0,2));
		h %= 12;
		int m = Integer.parseInt(s.substring(3));
		System.out.println((h * 30. + m / 2.) + " " + m*6.);
	}
}