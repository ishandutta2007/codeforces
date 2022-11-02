import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static long ch(char c){
		return c - '0';
	}
	public static void main(String args[]) throws IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(System.out);
		String s = in.readLine();
		long n = ch(s.charAt(0)) * 100000 + ch(s.charAt(2)) * 10000 + ch(s.charAt(4)) * 1000 + ch(s.charAt(3)) * 100 + ch(s.charAt(1)) * 10;
		n /= 10;
		long m = n;
		for(int i = 2; i <= 5; i++){
			m = m * n;
			m %= 100000L;
		}
		String str = String.valueOf(m);
		while(str.length() < 5)
			str = "0" + str;
		out.println(str);
		out.flush();
	}
}