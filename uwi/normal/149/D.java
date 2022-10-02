//package round106;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	int mod = 1000000007;
	char[] str;
	int pos = 0;
	int[][] g = new int[9][81];
	int[] ng = new int[9];
	
	void solve()
	{
		Map<String, Integer> map = new HashMap<String, Integer>();
		for(int i = 0;i < 9;i++){
			map.put(Q[i], i);
		}
		for(int i = 0;i < 9;i++){
			for(int j = 0;j < 9;j++){
				if(Q[i].charAt(1) == Q[j].charAt(0) && Q[i].charAt(1) != 'N')continue;
				String nex = new String(new char[]{Q[i].charAt(0), Q[j].charAt(1)});
				int ind = map.get(nex);
				g[ind][ng[ind]++] = i*9+j;
			}
		}
		
		str = ns(700);
		long[] ret = parse();
		long ss = 0;
		for(long r : ret){
			ss += r;
		}
		out.println(ss % mod);
	}
	
	String[] Q = {"NN", "NB", "NR", "BN", "BB", "BR", "RN", "RB", "RR"};
	long[] parse()
	{
		long[] cur = null;
		while(pos < str.length && str[pos] == '('){
			pos++;
			long[] res = new long[]{0, 1, 1, 1, 0, 0, 1, 0, 0};
			if(str[pos] == ')'){
			}else{
				long[] inner = parse();
				res[1] = (inner[0]+inner[2]+inner[3]+inner[5]+inner[6]+inner[8])%mod;
				res[2] = (inner[0]+inner[1]+inner[3]+inner[4]+inner[6]+inner[7])%mod;
				res[3] = (inner[0]+inner[1]+inner[2]+inner[6]+inner[7]+inner[8])%mod;
				res[6] = (inner[0]+inner[1]+inner[2]+inner[3]+inner[4]+inner[5])%mod;
			}
			if(cur == null){
				cur = res;
			}else{
				long[] nex = new long[9];
				for(int i = 0;i < 9;i++){
					for(int j = 0;j < ng[i];j++){
						nex[i] += cur[g[i][j]/9]*res[g[i][j]%9]%mod;
					}
					nex[i] %= mod;
				}
				cur = nex;
			}
			pos++;
		}
		if(cur == null)return new long[9];
		return cur;
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
		new D().run();
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