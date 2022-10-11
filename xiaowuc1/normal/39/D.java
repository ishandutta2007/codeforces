import java.io.*;
import java.util.*;
public class AMain	{
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException	{
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int a = readInt();
		int b = readInt();
		int c = readInt();
		int d = readInt();
		int e = readInt();
		int f = readInt();
		if(a == d || b == e || c == f)	{
			System.out.println("YES");
		}
		else	{
			System.out.println("NO");
		}
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}