import java.io.ByteArrayInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.BitSet;
import java.util.HashMap;
import java.util.Map;

public class H {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] s = new char[n][];
		int[][] g = new int[n][];
		
		Map<Integer, Integer> map = new HashMap<Integer, Integer>();
		
		int p = 0;
		for(int i = 0;i < n;i++) {
			s[i] = ns(10);
			if(s[i].length <= 4) {
				int code = enc(s[i]);
				if(!map.containsKey(code))map.put(code, p++);
				g[i] = new int[] {map.get(code)};
			}else {
				int f = s[i].length;
				BitSet bs = new BitSet();
				for(int j = 0;j < f;j++) {
					for(int k = j+1;k < f;k++) {
						for(int l = k+1;l < f;l++) {
							for(int m = l+1;m < f;m++) {
								int code = (((s[i][j]-'`')*27+(s[i][k]-'`'))*27+(s[i][l]-'`'))*27+(s[i][m]-'`');
								if(!map.containsKey(code))map.put(code, p++);
								bs.set(map.get(code));
							}
						}
					}
				}
				for(int j = 0;j < f;j++) {
					for(int k = j+1;k < f;k++) {
						for(int l = k+1;l < f;l++) {
							int code = ((s[i][j]-'`')*27+(s[i][k]-'`'))*27+(s[i][l]-'`');
							if(!map.containsKey(code))map.put(code, p++);
							bs.set(map.get(code));
						}
					}
				}
				for(int j = 0;j < f;j++) {
					for(int k = j+1;k < f;k++) {
						int code = (s[i][j]-'`')*27+(s[i][k]-'`');
						if(!map.containsKey(code))map.put(code, p++);
						bs.set(map.get(code));
					}
				}
				for(int j = 0;j < f;j++) {
					int code = s[i][j]-'`';
					if(!map.containsKey(code))map.put(code, p++);
					bs.set(map.get(code));
				}
				
				int[] row = new int[bs.cardinality()];
				int q = 0;
				for(int j = bs.nextSetBit(0);j != -1;j = bs.nextSetBit(j+1)) {
					row[q++] = j;
				}
				
				g[i] = row;
			}
		}
		
		int[] imap = new int[50000];
		for(Map.Entry<Integer, Integer> e : map.entrySet()) {
			imap[e.getValue()] = e.getKey();
		}
		
		int[] ret = doBipartiteMatching(g, p);
		if(ret == null) {
			out.println(-1);
		}else {
			for(int i = 0;i < n;i++) {
				out.println(dec(imap[ret[i]]));
			}
		}
	}
	
	public static int[] doBipartiteMatching(int[][] g, int m)
	{
		if(g.length == 0)return null;
		int n = g.length;
		int[] im = new int[m];
		Arrays.fill(im, -1);
		BitSet visited = new BitSet();
		int matched = 0;
		for(int i = 0;i < n;i++){
			if(visit(g, i, visited, im)) {
				visited.clear();
				matched++;
			}
		}
		if(matched < n)return null;

		int[] ret = new int[n];
		Arrays.fill(ret, -1);
		for(int i = 0;i < m;i++){
			if(im[i] != -1)ret[im[i]] = i;
		}
		return ret;
	}
	
	public static boolean visit(int[][] g, int cur, BitSet visited, int[] im)
	{
		if(cur == -1)return true;

		for(int i : g[cur]){
			if(!visited.get(i)){
				visited.set(i);
				if(visit(g, im[i], visited, im)){
					im[i] = cur;
					return true;
				}
			}
		}
		return false;
	}
	
	int enc(char[] s)
	{
		int code = 0;
		for(char c : s) {
			code = code * 27 + (c-'`');
		}
		return code;
	}
	
	String dec(int x)
	{
		char[] q = new char[4];
		for(int i = 3;i >= 0;i--, x/=27) {
			if(x % 27 == 0) {
				q[i] = ' ';
			}else {
				q[i] = (char)('`' + x % 27);
			}
		}
		return new String(q).trim();
	}
	
	void run() throws Exception
	{
		is = oj ? new FileInputStream(new File("input.txt")) : new ByteArrayInputStream(INPUT.getBytes());
		out = oj ? new PrintWriter(new File("output.txt")) : new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new H().run();
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
	
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}