//package round57;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int a = ni();
		String b = in.next();
		String s = in.next();
		int n = s.length();
		long num = 0;
		for(int i = 0;i < n;i++){
			char c = s.charAt(i);
			int d = 0;
			if(c >= '0' && c <= '9'){
				d = c - '0';
			}else{
				d = c - 'A' + 10;
			}
			num = num * a + d;
		}
		if(b.equals("R")){
			StringBuilder sb = new StringBuilder();
			long q = num;
			for(int i = 0;i < q%5;i++)sb.append("I");
			q /= 5;
			for(int i = 0;i < q%2;i++)sb.append("V");
			q /= 2;
			for(int i = 0;i < q%5;i++)sb.append("X");
			q /= 5;
			for(int i = 0;i < q%2;i++)sb.append("L");
			q /= 2;
			for(int i = 0;i < q%5;i++)sb.append("C");
			q /= 5;
			for(int i = 0;i < q%2;i++)sb.append("D");
			q /= 2;
			for(int i = 0;i < q;i++)sb.append("M");
			String ret = sb.reverse().toString();
			ret = ret.replace("DCCCC", "CM");
			ret = ret.replace("CCCC", "CD");
			ret = ret.replace("LXXXX", "XC");
			ret = ret.replace("XXXX", "XL");
			ret = ret.replace("VIIII", "IX");
			ret = ret.replace("IIII", "IV");
			out.println(ret);
		}else{
			int bb = Integer.parseInt(b);
			if(num == 0){
				out.println(0); // ><
			}else{
				StringBuilder sb = new StringBuilder();
				while(num > 0){
					int d = (int)(num % bb);
					char c = 0;
					if(d >= 10){
						c = (char)('A' + (d - 10));
					}else{
						c = (char)('0' + d);
					}
					sb.append(c);
					num /= bb;
				}
				out.println(sb.reverse().toString());
			}
		}
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}