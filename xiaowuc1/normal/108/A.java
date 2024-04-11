import java.util.*;
import java.io.*;
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine(), ":");
		int h = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int now = 60*h+m;
		while(!bad(++now%1440));
		System.out.printf("%02d:%02d", now%1440/60, now%60);
	}
	public static boolean bad(int curr)	{
		String a = Integer.toString(curr/60);
		String b = Integer.toString(curr%60);
		if(a.length() < 2)
			a = '0'+a;
		if(b.length() < 2)
			b = '0'+b;
		return a.charAt(0) == b.charAt(1) && a.charAt(1) == b.charAt(0);
	}
}