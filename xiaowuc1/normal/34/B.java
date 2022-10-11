import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		int max = readInt();
		int ret = 0;
		int[] list = new int[n];
		for(int i = 0; i < n; i++)
			list[i] = readInt();
		Arrays.sort(list);
		for(int i = 0; i < max; i++)
			if(list[i] > 0)
				break;
			else
				ret -= list[i];
		System.out.println(ret);
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}