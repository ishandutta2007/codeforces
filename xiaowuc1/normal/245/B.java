import java.awt.*;
import java.awt.geom.*;
import java.io.*;
import java.math.*;
import java.text.*;
import java.util.*;

public class Main {
	private static BufferedReader br;
	private static StringTokenizer st;
	private static PrintWriter pw;

	public static void main(String[] args) throws IOException	{
		br = new BufferedReader(new InputStreamReader(System.in));
		pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		String name = nextToken();
		String ret = "";
		if(name.startsWith("ftp"))	{
			ret = "ftp";
			name = name.substring(3);
		}
		else if(name.startsWith("http"))	{
			ret = "http";
			name = name.substring(4);
		}
		int index = 1 + name.substring(1).indexOf("ru");
		ret += "://" + name.substring(0, index) + ".ru";
		name = name.substring(index+2);
		if(name.length() != 0)
			ret += "/" + name;
		pw.println(ret);
		pw.close();
	}

	public static void loadArray(int[] in) throws IOException {
		for(int i = 0; i < in.length; i++)
			in[i] = readInt();
	}
	
	private static long readLong() throws IOException	{
		return Long.parseLong(nextToken());
	}

	private static double readDouble() throws IOException	{
		return Double.parseDouble(nextToken());
	}

	private static int readInt() throws IOException	{
		return Integer.parseInt(nextToken());
	}

	private static String nextToken() throws IOException	{
		while(st == null || !st.hasMoreTokens())	{
			st = new StringTokenizer(br.readLine().trim());
		}
		return st.nextToken();
	}
}