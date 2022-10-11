import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
	br = new BufferedReader(new InputStreamReader(System.in));
	long n = readLong();
	long min = 1 + (long)Math.sqrt(n);
	for(long i = Math.max(1, min-10000); i <= min; i++) {
	    if(i*i+s(i)*i-n == 0) {
		System.out.println(i);
		return;
	    }
	}
	System.out.println(-1);
    }

    public static int s(long n) {
	int ret = 0;
	while(n > 0) {
	    ret += n % 10;
	    n /= 10;
	}
	return ret;
    }

    public static String nextToken() throws IOException {
	while(st == null || !st.hasMoreTokens()) {
	    if(!br.ready()) {
		System.exit(0);
	    }
	    st = new StringTokenizer(br.readLine());
	}
	return st.nextToken();
    }

    public static int readInt() throws IOException {
	return Integer.parseInt(nextToken());
    }

    public static long readLong() throws IOException {
	return Long.parseLong(nextToken());
    }

}