import java.io.*;
public class B50 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s = br.readLine();
		int[] list = new int[256];
		for(int i = 0; i < s.length(); i++)
			list[s.charAt(i)]++;
		long ret = 0;
		for(long x: list)
			ret += x*x;
				System.out.println(ret);
	}
}