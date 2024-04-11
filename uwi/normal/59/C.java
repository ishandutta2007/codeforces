//package round55;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int k = ni();
		char[] str = in.next().toCharArray();
		int n = str.length;
		BitSet dq = new BitSet();
		int used = 0;
		for(int i = 0;i <= (n-1)/2;i++){
			if(str[i] != '?' && str[n-1-i] != '?'){
				if(str[i] != str[n-1-i]){
					out.println("IMPOSSIBLE");
					return;
				}
				used |= 1<<(str[i]-'a');
			}else if(str[i] == '?' && str[n-1-i] == '?'){
				dq.set(i);
			}else{
				if(str[i] == '?'){
					str[i] = str[n-1-i];
				}else{
					str[n-1-i] = str[i];
				}
				used |= 1<<(str[i]-'a');
			}
		}
		if(used >= (1<<k)){
			out.println("IMPOSSIBLE");
			return;
		}
		int f = Integer.bitCount(used) + dq.cardinality() - k;
		if(f < 0){
			out.println("IMPOSSIBLE");
			return;
		}
		int q = k-1;
		for(int i = (n-1) / 2;i >= 0;i--){
			if(dq.get(i)){
				while(q >= 0 && (used&(1<<q))!=0)q--;
				if(q < 0)break;
				str[i] = (char)('a'+q);
				str[n-1-i] = (char)('a'+q);
				used |= 1<<q;
			}
		}
		for(int i = 0;i < n;i++){
			if(str[i] == '?'){
				str[i] = 'a';
			}
		}
		out.println(new String(str));
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