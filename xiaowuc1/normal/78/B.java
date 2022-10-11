import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	public static void main(String[] args) throws IOException {
		br = new StreamTokenizer(new BufferedReader(new InputStreamReader(System.in)));
		int n = readInt();
		StringBuilder sb = new StringBuilder("ROYGBIV");
		while(sb.length() < n)sb.append("GBIV");
		System.out.println(sb.substring(0,n));
	}
	public static int readInt() throws IOException	{
		br.nextToken();
		return (int)br.nval;
	}
}