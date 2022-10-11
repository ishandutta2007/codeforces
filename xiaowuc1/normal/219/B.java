import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer st = new StringTokenizer(br.readLine());
	long n = Long.parseLong(st.nextToken());
	long d = Long.parseLong(st.nextToken());
	long curr = 1;
	LinkedList<Integer> q = new LinkedList<Integer>();
	while(true) {
	    int div = (int)((n+1)%10);
	    if(curr * div <= d) {
		d -= curr * div;
		n -= div;
		n /= 10;
		q.add(9);
		curr *= 10;
	    }
	    else {
		break;
	    }
	}
	if(n!=0) {
	    System.out.print(n);
	}
	for(int out: q) {
	    System.out.print(out);
	}
	System.out.println();
    }
}