import java.io.*;
import java.util.*;
public class C7 {
	public static void main(String[] args) throws IOException	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		long a = Long.parseLong(st.nextToken());
		long b = Long.parseLong(st.nextToken());
		long c = Long.parseLong(st.nextToken());
		long[] ext = extended(Math.abs(a),Math.abs(b));
		if(a<0)
			ext[1] = -ext[1];
		if(b<0)
			ext[2] = -ext[2];
		if(c % ext[0] != 0)	{
			System.out.println(-1);
			return;
		}
		System.out.println(ext[1] * (-c/ext[0]) + " " + ext[2] * (-c/ext[0]));
	}
	public static long[] extended(long p, long q) {
		if (q == 0)
			return new long[] { p, 1, 0 };
		long[] vals = extended(q, p % q);
		long d = vals[0];
		long a = vals[2];
		long b = vals[1] - (p / q) * vals[2];
		return new long[] { d, a, b };
	}
}