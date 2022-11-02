import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		long n = Long.parseLong(in.readLine());
		long m = (long)2520;
		out.println(n/m);
		out.flush();
	}
}