//package round131;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;

public class A {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
//	String INPUT = "1 1 0";
//	String INPUT = "5\r\n" + 
//			"2 2 1 1 3\r\n" + 
//			"1 5\r\n" + 
//			"2 5 1\r\n" + 
//			"2 5 4\r\n" + 
//			"1 5\r\n" + 
//			"0";
	int min = 398;
	
	void solve()
	{
		int n = ni();
		int[] c = new int[n];
		for(int i = 0;i < n;i++)c[i] = ni()-1;
		
		boolean[][] g = new boolean[n][n];
		int[] need = new int[n];
		for(int i = 0;i < n;i++){
			int K = ni();
			for(int j = 0;j < K;j++){
				int f = ni()-1;
				g[f][i] = true;
			}
			need[i] = K;
		}
		int[] ord = sortTopologically(g);
		
		BitSet ced = new BitSet();
		dfs(0, ced, need, ord, g, c, 0);
		dfs(1, ced, need, ord, g, c, 0);
		dfs(2, ced, need, ord, g, c, 0);
		out.println(min + n);
	}
	
	void dfs(int cur, BitSet ced, int[] need, int[] ord, boolean[][] g, int[] c, int cum)
	{
		if(cum >= min)return;
		
		int n = g.length;
		int[] nneed = Arrays.copyOf(need, n);
		BitSet ned = (BitSet)ced.clone();
		for(int i = 0;i < n;i++){
			int u = ord[i];
			if(nneed[u] == 0 && !ced.get(u) && c[u] == cur){
				for(int j = i+1;j < n;j++){
					if(g[u][ord[j]])nneed[ord[j]]--;
				}
				ned.set(u);
			}
		}
		if(ned.cardinality() == n){
			min = Math.min(min, cum);
		}else{
//			if(ced.cardinality() < ned.cardinality()){
				dfs((cur+1)%3, ned, nneed, ord, g, c, cum+1);
//				dfs((cur+2)%3, ned, nneed, ord, g, c, cum+2);
//			}
		}
	}
	
	public static int[] sortTopologically(boolean[][] g)
	{
		int n = g.length;
		int[] ec = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(g[i][j])ec[j]++;
			}
		}
		int[] ret = new int[n];
		int p = 0;
		int q = 0;
		
		ost:
		for(int i = 0;i < n;i++){
			for(int j = 0;j < n;j++){
				if(g[j][i])continue ost;
			}
			ret[q++] = i;
		}
		
		for(;p < q;p++){
			int cur = ret[p];
			for(int i = 0;i < n;i++){
				if(g[cur][i]){
					ec[i]--;
					if(ec[i] == 0)ret[q++] = i;
				}
			}
		}
		for(int i = 0;i < n;i++){
			if(ec[i] > 0){
				return null;
			}
		}
		return ret;
	}
	
	void run() throws Exception
	{
//		int n = 200;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(3)+1 + " ");
//		}
//		for(int i = 0;i < n;i++){
//			if(i < n-1){
//				int m = 1;
//				sb.append(m + " ");
//				for(int j = 0;j < m;j++){
//					sb.append((i+2) + " ");
//				}
//			}else{
//				sb.append(0 + " ");
//			}
//		}
//		INPUT = sb.toString();
		
		is = oj ? System.in : new ByteArrayInputStream(INPUT.getBytes());
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
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
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}