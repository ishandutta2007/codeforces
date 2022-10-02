//package yandex2011.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class C3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "2 1 A"; 
//	String INPUT = "6 2 CAT TACT"; 
//	String INPUT = "8 2 AGCT AGC"; // 3
//	String INPUT = "5 6\r\n" + // 7
//			"\r\n" + 
//			"CGTTGAA\r\n" + 
//			"\r\n" + 
//			"ATTATGAACC\r\n" + 
//			"\r\n" + 
//			"TTA\r\n" + 
//			"\r\n" + 
//			"TCAG\r\n" + 
//			"\r\n" + 
//			"CCGAGG\r\n" + 
//			"\r\n" + 
//			"T";
	int mod = 1000000009;
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] words = new char[m][];
		for(int i = 0;i < m;i++) {
			words[i] = ns().toCharArray();
		}
		int[][] trie = buildDNATrie(words);
		int[] fail = buildFailure(trie);
		
		int z = trie.length;
		int[][][] dp = new int[n+1][z][11];
		dp[0][0][0] = 1;
//		for(int[] row : trie){tr(row);}
//		tr(fail);
//		tr(enumSuffixes(trie));
//		tr(dp[0]);
		for(int i = 0;i < n;i++) {
			for(int j = 0;j < z;j++) {
				for(int h = 0;h <= 10;h++) {
					for(int k = 0;k < 4;k++) {
						int cur = j;
						while(cur != 0 && trie[cur][k] == -1)cur = fail[cur];
						int nex = trie[cur][k];
						if(nex == -1)nex = 0;
						
						if(nex > 0) {
							int nh = h+1;
							for(int x = 0;x < m;x++) {
								if(trie[nex][4]<<31-x<0) {
									if(words[x].length >= nh) {
										nh = 0;
									}
								}
							}
							if(nh <= 10) {
								dp[i+1][nex][nh] = (dp[i+1][nex][nh] + dp[i][j][h]) % mod;
							}
						}
					}
				}
			}
//			tr(dp[i+1]);
		}
		
		int tot = 0;
		for(int j = 0;j < z;j++) {
			tot = (tot + dp[n][j][0]) % mod;
		}
		out.println(tot);
	}
	
	public static String[] enumSuffixes(int[][] trie)
	{
		String[] ret = new String[trie.length];
		Queue<Integer> q = new ArrayDeque<Integer>();
		ret[0] = "";
		q.add(0);
		char[] ATCG = "ATCG".toCharArray();
		while(!q.isEmpty()) {
			int cur = q.poll();
			for(int k = 0;k < 4;k++) {
				if(trie[cur][k] != -1 && ret[trie[cur][k]] == null) {
					ret[trie[cur][k]] = ret[cur] + ATCG[k];
					q.add(trie[cur][k]);
				}
			}
		}
		return ret;
	}
	
	public static int[] buildFailure(int[][] trie)
	{
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(0);
		int[] failure = new int[trie.length];
		int sz = trie[0].length-1;
		Arrays.fill(failure, -1);
		failure[0] = 0;
		while(q.size() > 0) {
			int cur = q.poll();
			for(int i = 0;i < sz;i++) {
				int nex = trie[cur][i];
				if(nex != -1){
					q.add(nex);
					if(cur == 0){
						failure[nex] = 0;
					}else{
						int fc = failure[cur];
						for(;fc != 0 && trie[fc][i] == -1;fc = failure[fc]);
						failure[nex] = trie[fc][i] == -1 ? 0 : trie[fc][i];
						
						trie[nex][sz] |= trie[failure[nex]][sz];
					}
				}
			}
		}
		return failure;
	}
	
	public static int[][] buildDNATrie(char[][] q)
	{
		int[] T = new int[128];
		T['A'] = 0;
		T['T'] = 1;
		T['C'] = 2;
		T['G'] = 3;
		
		int m = 1;
		for(int i = 0;i < q.length;i++)m += q[i].length;
		int[][] trie = new int[m][5];
		for(int i = 0;i < m;i++){
			Arrays.fill(trie[i], -1);
			trie[i][4] = 0;
		}
		
		int tp = 1;
		for(int j = 0;j < q.length;j++){
			int cur = 0;
			for(int i = 0;i < q[j].length;i++){
				int ind = T[q[j][i]];
				if(trie[cur][ind] == -1)trie[cur][ind] = tp++;
				cur = trie[cur][ind];
			}
			trie[cur][4] |= 1<<j;
		}
		return Arrays.copyOf(trie, tp);
	}
	
	void run() throws Exception
	{
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new C3().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}