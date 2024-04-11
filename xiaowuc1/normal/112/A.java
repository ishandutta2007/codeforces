import java.util.*;
import java.io.*;
public class A127 {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String a = br.readLine().toLowerCase();
		String b = br.readLine().toLowerCase();
		if(a.equals(b))
			System.out.println(0);
		else if(a.compareTo(b) < 0)
			System.out.println(-1);
		else
			System.out.println(1);
	}
}