import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		int[] list = new int[n];
		for(int i = 0; i < n; i++)	{
			list[i] = readInt();
		}
		Arrays.sort(list);
		for(int i = 0; i < n-1; i++)	{
			if(2*list[i] > list[i+1] && list[i] != list[i+1])	{
				System.out.println("YES");
				return;
			}
		}
		System.out.println("NO");
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}