import java.io.IOException;
import java.io.IOException;
import java.io.PrintStream;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Iterator;
import java.util.PriorityQueue;
import java.util.Scanner;
import static java.lang.Math.*;
import static java.lang.System.*;


public class T {
	
	
	static Scanner in;
	static PrintStream out;

    
    static class Pair implements Comparable {
    	public Integer c;
    	public Long d;
    	public Pair (Integer a, long b) {
    		c = a; d = b;
    	}
    	
		@Override
		public int compareTo(Object arg0) {
			Pair p = (Pair) arg0;
			if (this.d == p.d) return Integer.compare(this.c, p.c);
			return Long.compare(this.d, p.d);
			
		}
    }
	
	
	public static void main (String[] args) throws IOException {
		in = new Scanner(System.in);
		out = new PrintStream(System.out);
		
		PriorityQueue pq = new PriorityQueue<Pair>();
		
		int n = in.nextInt();
		int m = in.nextInt();
		
		long[] a = new long[n];
		long[] c = new long[n];
		
		for (int i = 0; i < n; i++) {
			a[i] = in.nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			c[i] = in.nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			pq.add(new Pair(i, c[i]));
		}
		
		

		
		long d;
		int t;
		for (int i = 0; i < m; i++) {
			long value = 0;
			t = in.nextInt() - 1;
			d = in.nextInt();		
         
			if (a[t] >= d) {
				a[t] = a[t] - d;
				value += c[t] * d;
				d = 0;
				//out.println(Arrays.toString(a));
				out.println(value);
				continue;
			} else {
			    value += a[t] * c[t];
			    d = d - a[t];
			    a[(int)t] = 0;
			    
			}
			
			while (d > 0 && !pq.isEmpty()) {
			    Pair p = (Pair) pq.peek();
			    if (a[p.c] == 0) {pq.remove(); continue;} 
			    
			    if (a[p.c] >= d) {
			    	value += d * c[p.c];
			    	a[p.c] -= d;
			    	d = 0;
			        
			    } else {
			    	value += a[p.c] * c[p.c];
			    	d -= a[p.c];
			    	a[p.c] = 0;
			    
			    }
			    if (a[p.c] == 0) pq.remove();
			   
			    
			}
			
			if (d > 0) value = 0;
			out.println(value);
		}
		
	}
}