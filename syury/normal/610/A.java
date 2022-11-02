import java.util.*;
import java.math.*;
import java.io.*;

public class Main{
	public static void main(String args[]) throws IOException {
		//BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(System.out);
		int n = in.nextInt();
		if(n % 2 == 1){
			out.println(0);
		}
		else{
			int x = n/2;
			x /= 2;
			if((n / 2)%2 == 0){x--;}
			out.println(x);
		}
		out.flush();
	}
}