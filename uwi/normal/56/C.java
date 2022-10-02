//package round52;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	int pos = 0;
	char[] str;
	
	int num = 0;
	String[] dic = new String[1000];
	BitSet hist = new BitSet();
	
	void solve()
	{
		str = in.next().toCharArray();
		employee();
		out.println(ct);
	}
	
	int ct = 0;
	
	int employee()
	{
		name();
		int cur = num - 1;
		for(int i = hist.nextSetBit(0);i != -1;i = hist.nextSetBit(i + 1)){
			if(dic[cur].equals(dic[i])){
				ct++;
			}
		}
		if(str[pos++] == ':'){
			hist.set(cur);
			do{
				int e = employee();
			}while(str[pos++] == ',');
			hist.clear(cur);
		}
		return cur;
	}
	
	void name()
	{
		int i;
		for(i = pos;str[i] != '.' && str[i] != ':';i++);
		String ret = new String(Arrays.copyOfRange(str, pos, i));
		dic[num++] = ret;
		pos = i;
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