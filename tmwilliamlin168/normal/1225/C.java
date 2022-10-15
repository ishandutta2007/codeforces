import java.io.*;
import java.util.*;
import java.math.*;
 
public class C {
 
	public void realMain() throws Exception {
 
		BufferedReader fin = new BufferedReader(new InputStreamReader(System.in), 1000000);
 
		String in = fin.readLine();
 
		String[] ar = in.split(" ");
 
		long n = Long.parseLong(ar[0]);
		long p = Long.parseLong(ar[1]);
 
		for(long i = 1; i < 1000; i++) {
			n -= p;
 
			if(n <= 0) {
				System.out.println("-1");
				return;
			}
			
			String s = Long.toString(n, 2);
 
			//System.out.println("Trying: " + i + " " + n + " " + s);
			
			int cnt = 0;
			int[] cnts = new int[s.length()];
			for(int j = 0; j < s.length(); j++) {
				if(s.charAt(j) == '1') {
					cnt++;
					cnts[j] = 1;
				}
			}
 
			if(cnt <= i && i <= n) {
				System.out.println(i);
				return;
			}
 
			/*if(cnt > i) {
				continue;
			}*/
 
			//if(i <= n) {
			//	System.out.println(i);
			//	return;
			//}
 
 
			/*for(int j = 0; j < s.length() - 1; j++) {
				while(cnts[j] > 0) {
					cnts[j+1]+=2;
					cnts[j]--;
					cnt++;
 
			*/
		}
		
 
		System.out.println("-1");
 
 
	}
 
 
	public static void main(String[] args) throws Exception {
		C c = new C();
		c.realMain();
	}
}