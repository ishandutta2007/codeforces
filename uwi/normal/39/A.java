//package school1;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
//	String INPUT = "1 5*a++-3*++a+a++";
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		char[] com = in.next().toCharArray();
		out.println(expression(com, 0, a));
	}
	
	// summand[+-]summand...
	int expression(char[] com, int pos, int a)
	{
		int[] coas = new int[1001];
		int p = 0;
		int consum = 0;
		
		char op = '+';
		while(true){
			int[] sum = summand(com, pos);
			if(sum[0] == -1)break;
			coas[p++] = op == '+' ? sum[1] : -sum[1];
			consum += op == '+' ? sum[2] : -sum[2];
			pos = sum[0];
			if(pos >= com.length)break;
			op = com[pos++];
			if(op != '+' && op != '-')throw new AssertionError();
		}
		
		Arrays.sort(coas, 0, p);
		for(int i = 0;i < p;i++){
			consum += coas[i] * (a++);
		}
		return consum;
	}
	
	// [newpos, co_a, const]
	int[] summand(char[] com, int pos)
	{
		int[] co = coefficient(com, pos);
		if(co[0] != -1 && com[co[0]] != '*')return new int[]{-1};
		int[] inc = increment(com, co[0] == -1 ? pos : co[0] + 1);
		return new int[]{inc[0], co[1] * inc[1], co[1] * inc[2]};
	}
	
	int[] coefficient(char[] com, int pos)
	{
		int val = 0;
		int i;
		for(i = pos;i < com.length;i++){
			if(i >= pos + 5)throw new AssertionError();
			if(com[i] >= '0' && com[i] <= '9'){
				val = val * 10 + (com[i] - '0');
			}else{
				break;
			}
		}
		if(i == pos)return new int[]{-1, 1};
		return new int[]{i, val};
	}
	
	int[] increment(char[] com, int pos)
	{
//		if(pos + 3 >= com.length)throw new AssertionError();
		if(com[pos] == '+' && com[pos+1] == '+' && com[pos+2] == 'a'){
			// ++a
			return new int[]{pos + 3, 1, 1};
		}else if(com[pos] == 'a' && com[pos+1] == '+' && com[pos+2] == '+'){
			return new int[]{pos + 3, 1, 0};
		}
		throw new AssertionError();
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}