import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		long n = Long.parseLong(in.readLine());
		long m = n % 2;
		if(m == 0L)
			m = 2;
		out.println(m);
		out.flush();
	}
}