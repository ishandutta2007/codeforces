//package yandex2011.r1;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class D2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
//		long ss = System.currentTimeMillis();
		int n = ni();
		int[] ope = new int[n];
		int[] num = new int[n];
		Map<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for(int i = 0;i < n;i++){
			String o = in.next();
			if(o.equals("add")){
				ope[i] = 0;
				num[i] = ni();
				hm.put(num[i], 0);
			}else if(o.equals("del")){
				ope[i] = 1;
				num[i] = ni();
				hm.put(num[i], 0);
			}else{
				ope[i] = 2;
			}
		}
		int p = 0;
		int[] imap = new int[hm.size()];
		for(int v : hm.keySet())imap[p++] = v;
		Arrays.sort(imap);
		for(int i = 0;i < imap.length;i++)hm.put(imap[i], i);
		
		SegmentTreeRSQ st = new SegmentTreeRSQ(hm.size(), imap);
		for(int i = 0;i < n;i++){
			if(ope[i] == 0){
				st.add(hm.get(num[i]), 1);
			}else if(ope[i] == 1){
				st.add(hm.get(num[i]), -1);
			}else{
				out.println(st.smod[1][2]);
			}
		}
	}
	
	public class SegmentTreeRSQ {
		public int M, H, N;
		public int[] st;
		public long[][] smod;
		
		public SegmentTreeRSQ(int n, int[] imap)
		{
			N = n;
			M = Integer.highestOneBit(Math.max(n, 1))<<2;
			H = M>>>1;
			st = new int[M];
			smod = new long[M][5];
			for(int i = 0;i < n;i++){
				smod[H+i][0] = imap[i];
			}
		}
		
		public void add(int pos, int v)
		{
			for(int i = H+pos;i >= 1;i >>>= 1){
				st[i] += v;
				if(i < H){
					Arrays.fill(smod[i], 0);
					if(st[2*i] > 0){
						for(int j = 0;j < 5;j++){
							smod[i][j] = smod[2*i][j];
						}
					}
					if(st[2*i+1] > 0){
						for(int j = 0;j < 5;j++){
							smod[i][(j+st[2*i])%5] += smod[2*i+1][j];
						}
					}
				}
			}
		}
	}
	
	void run() throws Exception
	{
//		int n = 100000;
//		StringBuilder sb = new StringBuilder(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append("add " + (101012000 - i) + " ");
//		}
//		INPUT = sb.toString();

		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}