import java.io.*;
import java.util.*;
public class A70 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int n = Integer.parseInt(br.readLine());
		int mod = 1000003;
		int ret = 1;
		for(int i = 1; i < n; i++)	{
			ret *= 3;
			ret %= mod;
		}
		System.out.println(ret);
	}
}