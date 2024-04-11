import java.io.*;
import java.util.*;

public class Main {

    static BufferedReader br;
    static StringTokenizer st;

    public static void main(String[] args) throws IOException {
	br = new BufferedReader(new InputStreamReader(System.in));
	String str = br.readLine();
	int num = 0;
	for(int i = 0; i < str.length(); i++) {
	    if(str.charAt(i) == 'x')
		num++;
	    else
		num--;
	}
	char print = num > 0 ? 'x' : 'y';
	num = Math.abs(num);
	while(num-- > 0)
	    System.out.print(print);
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

}