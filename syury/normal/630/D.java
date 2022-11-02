import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		long n = Long.parseLong(in.readLine());
		long m = (long)6;
		m = (m + m * n) * n / 2L;
		m++;
		out.println(m);
		out.flush();
	}
}