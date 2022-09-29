import java.io.*;
import java.util.*;

public class YanAlgo2011R2QDPowerfulArray {

	static int n,t;
	static int a[],count[];
	static Query q[];
	static long ans;
	static long qans[];
	
	public static void main(String args[] ) throws Exception {
		
		InputReader2 in = new InputReader2(System.in);
	    PrintWriter w = new PrintWriter(System.out);
	        
	    n = in.nextInt();
	    t = in.nextInt();
	          
	    a = new int[n];
	    for(int i=0;i<n;i++)
	    	a[i] = in.nextInt();
	        
	    count = new int[1000001];
	    ans = 0;
	    q = new Query[t];
	    Query.nsqrt = (int)(Math.sqrt(n));
	    qans = new long[t];
	    
	    for(int i=0;i<t;i++){
	    	int l = in.nextInt() - 1;
	    	int r = in.nextInt() - 1;
	    	q[i] = new Query(l,r,i);
	    }
	    
	    Arrays.sort(q);
	    int left = 0,right = -1;
	    
		for (int i = 0; i < t; i++) {
			while (left < q[i].l)  remove(a[left++]);
			while (left > q[i].l)  add(a[--left]);
			while (right < q[i].r) add(a[++right]);
			while (right > q[i].r) remove(a[right--]);
			qans[q[i].id] = ans;
		}
	   
	    for(long i : qans)
	    	w.println(i);
	    w.close(); 
	}
	
	public static void add(int val){
		ans += val * (count[val] + count[val] + 1);
		count[val]++;
	}
	
	public static void remove(int val){
		ans -= val * (count[val] + count[val] - 1);
		count[val]--;
	}
	
	public static int ip(String s){
		return Integer.parseInt(s);
	}


static class Query implements Comparable<Query>{
	int l,r,block,id;
	static int nsqrt;
	
	public Query(int l,int r,int id){
		this.l = l;
		this.r = r;
		block = l / nsqrt ;
		this.id = id;
	}
	
	public int compareTo(Query b){
		if(block != b.block)
			return block - b.block;
		return r - b.r;
	}
	
	public String toString(){
		return id + " " + l + " " + r + " " + block;
	}
}
}

class InputReader2 {

	private InputStream stream;
	private byte[] buf = new byte[1024];
	private int curChar;
	private int numChars;
	private SpaceCharFilter filter;
	public InputReader2(InputStream stream) {
		this.stream = stream;
	}
	
	public int snext() {
		if (numChars == -1)
			throw new InputMismatchException();
		if (curChar >= numChars) {
			curChar = 0;
			try {
				numChars = stream.read(buf);
			} catch (IOException e) {
				throw new InputMismatchException();
			}
			if (numChars <= 0)
				return -1;
		}
		return buf[curChar++];
	}

	public int nextInt() {
		int c = snext();
		while (isSpaceChar(c))
			c = snext();
		int sgn = 1;
		if (c == '-') {
			sgn = -1;
			c = snext();
		}

		int res = 0;

		do {
			if (c < '0' || c > '9')
				throw new InputMismatchException();
			res *= 10;
			res += c - '0';
			c = snext();
		} while (!isSpaceChar(c));

		return res * sgn;
	}

	public boolean isSpaceChar(int c) {
		if (filter != null)
			return filter.isSpaceChar(c);
		return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
	}

	public interface SpaceCharFilter {
		public boolean isSpaceChar(int ch);
	}
}