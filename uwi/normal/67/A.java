//package manthan;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[] com = in.next().toCharArray();
		{
			int i;
			for(i = 0;i < n-1;i++){
				if(com[i] != '=')break;
			}
			if(i == n - 1){
				for(int j = 0;j < n;j++){
					out.print("1 ");
				}
				out.println();
				return;
			}
		}
		
		BitSet lowr = new BitSet();
		{
			int prev = 0;
			for(int i = 0;i < n-1;i++){
				if(com[i] == 'R'){
					lowr.set(prev, i+1);
					prev = i+1;
				}else if(com[i] == '='){
				}else{
					prev = i+1;
				}
			}
		}
		BitSet lowl = new BitSet();
		{
			int prev = n-1;
			for(int i = n-2;i >= 0;i--){
				if(com[i] == 'L'){
					lowl.set(i+1, prev+2);
					prev = i-1;
				}else if(com[i] == '='){
				}else{
					prev = i-1;
				}
			}
		}
		if(lowr.get(0))lowl.set(0);
		if(lowl.get(n-1))lowr.set(n-1);
		lowl.and(lowr);
//		tr(lowl, lowr);
		int[] ret = new int[n];
		for(int i = lowl.nextSetBit(0);i != -1;i = lowl.nextSetBit(i + 1)){
			ret[i] = 1;
			for(int j = i+1;j < n;j++){
				if(com[j-1] == 'R'){
					ret[j] = Math.max(ret[j], ret[j-1]+1);
				}else if(com[j-1] == '='){
					ret[j] = Math.max(ret[j], ret[j-1]);
				}else{
					break;
				}
			}
			for(int j = i-1;j >= 0;j--){
				if(com[j] == 'L'){
					ret[j] = Math.max(ret[j], ret[j+1]+1);
				}else if(com[j] == '='){
					ret[j] = Math.max(ret[j], ret[j+1]);
				}else{
					break;
				}
			}
		}
		for(int i = 0;i < n;i++){
			out.print(ret[i] + " ");
		}
		out.println();
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}