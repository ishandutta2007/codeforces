import java.io.*;
import java.util.*;
public class AMain	{
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		System.out.println(s.contains("H") || s.contains("Q") || s.contains("9") ? "YES" : "NO");
	}
}