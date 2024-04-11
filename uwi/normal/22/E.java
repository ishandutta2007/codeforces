//package round22;


import java.io.PrintWriter;
import java.io.StringReader;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.List;
import java.util.Scanner;

public class E {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "7 2 3 1 3 4 4 1";
//	private String INPUT = "3 3 3 2";
//	private String INPUT = "3 2 3 1";
//	private String INPUT = "6 2 1 1 2 6 5";
//	private String INPUT = "100000 2 " + add("1 ", 99999);
	private String INPUT = "";
	
	int n;
	
	public void solve()
	{
		n = ni();
		int[] f = new int[n];
		for(int i = 0;i < n;i++){
			f[i] = ni() - 1;
		}
		
		int[] cs = new int[n];
		BitSet srcs = new BitSet(n);
		for(int i = 0;i < n;i++){
			srcs.set(f[i]);
		}
		
		Arrays.fill(cs, -1);
		List<List<Integer>> srclist = new ArrayList<List<Integer>>();
		int[] sinks = new int[n];
		int p = 0;
		for(int i = 0;i < n;i++){
//		for(int i = srcs.nextClearBit(0);i < n;i = srcs.nextClearBit(i + 1)){
			if(cs[i] == -1){
				int j;
				for(j = i;cs[j] == -1;j = f[j])cs[j] = p;
				if(cs[j] < p){
					for(int k = i;cs[k] == p;k = f[k])cs[k] = cs[j];
					if(!srcs.get(i)){
						srclist.get(cs[j]).add(i);
					}
				}else{
					List<Integer> added = new ArrayList<Integer>();
					if(!srcs.get(i))added.add(i);
					srclist.add(added);
					sinks[p] = j;
					p++;
				}
			}
		}
		
//		tr(p);
//		tr(srcs);
//		tr(srclist);
//		tr(Arrays.toString(sinks));
		
		int num = 0;
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < p;i++){
			int t = (i + 1) % p;
			if(srclist.get(t).size() == 0){
				if(i != t){
					sb.append(sinks[i] + 1);
					sb.append(' ');
					sb.append(sinks[t] + 1);
					sb.append('\n');
					num++;
				}
			}else{
				for(int j = 0;j < srclist.get(t).size();j++){
					sb.append(sinks[i] + 1);
					sb.append(' ');
					sb.append(srclist.get(t).get(j) + 1);
					sb.append('\n');
					num++;
				}
			}
		}
		
		out.println(num);
		if(num != 0)out.print(sb.toString());
	}
	
	public void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 1;i <= n;i+=2){
//			sb.append((i+1) + " " + i + " ");
//		}
//		INPUT = sb.toString();
		
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(new StringReader(INPUT));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public static String add(String str, int k)
	{
		StringBuilder mul = new StringBuilder(str);
		StringBuilder ret = new StringBuilder();
		for(int i = k;i > 0;i >>= 1){
			if((i & 1) == 1)ret.append(mul);
			mul.append(mul);
		}
		return ret.toString();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private static void tr(Object... o) { System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}