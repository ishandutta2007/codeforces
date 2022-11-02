import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		long n = Long.parseLong(in.readLine());
		long m = n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
		m /= (long)120;
		m *= n * (n - 1) * (n - 2) * (n - 3) * (n - 4);
		out.println(m);
		out.flush();
	}
}