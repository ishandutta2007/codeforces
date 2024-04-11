import java.io.*;
import java.util.*;
public class A75 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine();
		String b = br.readLine();
		int expect = Integer.parseInt(Integer.toString(Integer.parseInt(a)+Integer.parseInt(b)).replaceAll("0", ""));
		a = a.replaceAll("0", "");
		b = b.replaceAll("0", "");
		int other = Integer.parseInt(a)+Integer.parseInt(b);
		System.out.println(expect == other ? "YES" : "NO");
	}
}