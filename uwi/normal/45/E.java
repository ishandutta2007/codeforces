//package school3;

import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "3 Ea Eb Ec Eb Ae Fc";
//	String INPUT = "4 Bb B Bc Bd Aa Ab Ac Bb";
//	String INPUT = "2 Sz Zy Zy Zz";
//	String INPUT = "1 Qq Qq";
//	String INPUT = "4 Aa Ab Ac Ba Ad Ae Bb Bc";
//	String INPUT = "4 Ann Anna Sabrina John Petrov Ivanova Stoltz Abacaba";
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		final String[] name = new String[n];
		final String[] surname = new String[n];
		for(int i = 0;i < n;i++)name[i] = in.next();
		for(int i = 0;i < n;i++)surname[i] = in.next();
		
		Arrays.sort(name);
		Arrays.sort(surname);
		
		int[] ctn = new int[26];
		int[] cts = new int[26];
		for(int i = 0;i < n;i++){
			ctn[name[i].charAt(0) - 'A']++;
			cts[surname[i].charAt(0) - 'A']++;
		}
		int[] match = new int[26];
		for(int i = 0;i < 26;i++){
			match[i] = Math.min(ctn[i], cts[i]);
		}
		BitSet left = new BitSet();
		StringBuilder sb = new StringBuilder();
		for(int i = 0;i < n;i++){
			sb.append(name[i] + " ");
			int cn = name[i].charAt(0) - 'A';
			int candi = 99999;
			if(match[cn] > 0){
				for(int j = left.nextClearBit(0);j < n;j = left.nextClearBit(j+1)){
					if(cn == surname[j].charAt(0) - 'A'){
						candi = j;
						break;
					}
				}
			}
			if(ctn[cn] > match[cn]){
				int j = -1;
				while(true){
					j = left.nextClearBit(j + 1);
					int c = surname[j].charAt(0) - 'A';
					if(cts[c] > match[c]){
						candi = Math.min(candi, j);
						break;
					}
				}
			}
			
			if(candi == 99999)throw new Error();
			cts[surname[candi].charAt(0) - 'A']--;
			ctn[cn]--;
			if(cn == surname[candi].charAt(0) - 'A'){
				match[cn]--;
			}
			left.set(candi);
			
			sb.append(surname[candi]);
			if(i < n - 1)sb.append(", ");
		}
		
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length > 1 || o[0].getClass().isArray() ? Arrays.deepToString(o) : o[0]); }
}