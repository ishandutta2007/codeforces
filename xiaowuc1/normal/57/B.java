import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	final static int MOD = 100000000;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int v = readInt();
		int m = readInt();
		int k = readInt();
		int[] begin = new int[m];
		int[] end = new int[m];
		int[] init = new int[m];
		for(int i = 0; i < m; i++)	{
			begin[i] = readInt();
			end[i] = readInt();
			init[i] = readInt();
		}
		long ret = 0;
		while(k-- > 0)	{
			int desire = readInt();
			for(int i = 0; i < m; i++)	{
				if(desire >= begin[i] && desire <= end[i])	{
					ret += init[i] + (desire-begin[i]);
				}
			}
		}
		System.out.println(ret);
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}