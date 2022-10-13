import java.io.*;
import java.util.*;
public class AMain {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int a = readInt();
		int b = readInt();
		int ret = 0;
		for(int i = 2; i <= 100; i++)	{
			try	{
				ret = Math.max(ret, Integer.toString(Integer.parseInt(Integer.toString(a), i) + Integer.parseInt(Integer.toString(b),i), i).length());
			}
			catch(Exception e){}
		}
		System.out.println(ret);
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}