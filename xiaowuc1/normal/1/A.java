import java.io.*;
import java.util.*;
public class A1 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = a/c;
		if(a%c!=0)
			d++;
		int e = b/c;
		if(b%c!=0)
			e++;
		long p = d;
		p *= e;
		System.out.println(p);
	}
}