//package school2;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;

public class I {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	int n;
	
	void solve()
	{
		n = ni();
		List<Integer> logg = new ArrayList<Integer>();
		for(int i = 1;i < n;i++){
			int[] state = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
			List<Integer> nlogg = new ArrayList<Integer>();
			nlogg.add(i);
			nlogg.add(1);
			
			int cur = 1;
			for(int j = 0;j < logg.size();j+=2){
				if(cur > 0){
					if(logg.get(j+1) == cur){
						// +
						nlogg.add(-i);
						nlogg.add(cur + 1);
						cur++;
					}else{
						// -
						int ct = 0;
						for(int k = 0;k < i;k++){
							if(state[Math.abs(logg.get(j))] == state[k]){
								ct++;
							}
						}
						if(ct == 1 && state[Math.abs(logg.get(j))] == cur - 1){
							nlogg.add(-i);
							nlogg.add(cur - 1);
							cur--;
						}
					}
				}
				nlogg.add(logg.get(j));
				nlogg.add(logg.get(j+1));
				state[Math.abs(logg.get(j))] = logg.get(j+1);
				if(logg.get(j) < 0){
					continue;
				}
				
				if(cur == 0){
					int sup = ssup(state, i-1);
					for(int k = 1;k <= sup + 1;k++){
						nlogg.add(i);
						nlogg.add(k);
					}
					cur = sup + 1;
				}else{
					for(int k = cur - 1;k >= 0;k--){
						nlogg.add(i);
						nlogg.add(k);
					}
					cur = 0;
				}
			}
			logg = nlogg;
		}
		int ct = 1;
		for(int i = 0;i < logg.size();i+=2){
			if(logg.get(i) >= 0)ct++;
		}
		out.println(ct);
		
		int[] state = new int[]{0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
		print(state, n);
		for(int i = 0;i < logg.size();i+=2){
			state[Math.abs(logg.get(i))] = logg.get(i+1);
			if(logg.get(i) >= 0){
				print(state, n);
			}
		}
	}
	
	int ssup(int[] state, int n)
	{
		int ret = 0;
		for(int v : state){
			ret = Math.max(ret, v);
		}
		return ret;
	}
	
	void print(int[] state, int n)
	{
		StringBuilder sb = new StringBuilder();
		int max = 0;
		for(int i = 0;i < n;i++){
			max = Math.max(max, state[i]);
		}
		
		for(int i = 0;i <= max;i++){
			sb.append("{");
			for(int j = 0;j < n;j++){
				if(state[j] == i){
					sb.append(j+1);
					sb.append(',');
				}
			}
			sb.deleteCharAt(sb.length() - 1);
			sb.append("},");
		}
		sb.deleteCharAt(sb.length() - 1);
		out.println(sb);
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
		new I().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}