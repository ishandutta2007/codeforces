import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	static long even(long l, long r){
	    if(r - l <= 20){
	        long ans = 0L;
	        for(long i = l; i <= r; i++){if(i % 2 == 0){ans++;}}
	        return ans;
	    }
	    long l1 = (l % 2 == 0) ? l : (l + 1);
	    long r1 = (r % 2 == 1) ? r : (r - 1);
	    long ans = (r1 - l1 + 1) / 2;
	    if(r % 2 == 0)
	        ans++;
	    return ans;
	}
	static long odd(long l, long r){
		return (r - l + 1) - even(l, r);
	}
	public static void main(String args[]) throws IOException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		long x1, y1, x2, y2;
		x1 = in.nextLong(); y1 = in.nextLong(); x2 = in.nextLong(); y2 = in.nextLong();
		out.println(((y2 - y1)/2 + 1) * (x2 - x1 + 1) - (x2 - x1)/2);
		out.flush();
	}
}