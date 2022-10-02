//package round60;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class D2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	long enc(int[] ct)
	{
		long ret = 0;
		for(int i = 0;i < 4;i++){
			ret = ret * 10001 + ct[i];
		}
		return ret;
	}
	
	int[] dec(long code)
	{
		int[] ret = new int[4];
		for(int i = 3;i >= 0;i--){
			ret[i] = (int)(code % 10001);
			code /= 10001;
		}
		return ret;
	}
	
	void solve()
	{
		int n = ni();
		char[] str = in.next().toCharArray();
		int[] map = new int[128];
		map['G'] = 0;
		map['H'] = 1;
		map['R'] = 2;
		map['S'] = 3;
		
		int[] ct = {0,0,0,0};
		
		Set<Long> q = new HashSet<Long>();
		q.add(enc(ct));
		for(int i = 0;i < n;i++){
			Set<Long> nq = new HashSet<Long>();
			if(str[i] == '?'){
				for(long c : q){
					int[] r = dec(c);
					int min = 999999;
					for(int j = 0;j < 4;j++){
						min = Math.min(min, r[j]);
					}
					for(int j = 0;j < 4;j++){
						if(r[j] == min){
							nq.add(c + X[j]);
						}
					}
				}
			}else{
				for(long c : q){
					nq.add(c + X[map[str[i]]]);
				}
			}
			q = nq;
		}
		
		int valid = 0;
		for(long c : q){
			int[] r = dec(c);
			int min = 999999;
			for(int j = 0;j < 4;j++){
				min = Math.min(min, r[j]);
			}
			for(int j = 0;j < 4;j++){
				if(r[j] == min){
					valid |= 1<<j;
				}
			}
		}
		for(int i = 0;i < 4;i++){
			if((valid&1<<i)!=0){
				out.println(houses[i]);
			}
		}
	}
	long[] X = {10001L*10001*10001, 10001L*10001, 10001, 1};
	
	String[] houses = {"Gryffindor", "Hufflepuff", "Ravenclaw", "Slytherin"};
	
	void run() throws Exception
	{
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
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}