//package round528;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	int[] s, a, b;
	
	int[] toi(char[] a)
	{
		int[] ret = new int[a.length];
		for(int i = 0;i < a.length;i++){
			ret[i] = a[i] - 'a';
		}
		return ret;
	}
	
	void solve()
	{
		outer:
		for(int T = ni();T > 0;T--){
			int K = ni();
			s = toi(ns().toCharArray());
			a = toi(ns().toCharArray());
			b = toi(ns().toCharArray());
			int n = s.length;
			int com = n;
			for(int i = 0;i < n;i++){
				if(a[i] != b[i]){
					com = i;
					break;
				}
			}
			
			int[] f = new int[K];
			Arrays.fill(f, -1);
			int used = 0;
			for(int i = 0;i < com;i++){
				if(f[s[i]] != -1){
					if(f[s[i]] != b[i]){
						out.println("NO");
						continue outer;
					}
				}else{
					if(used<<~b[i]<0){
						out.println("NO");
						continue outer;
					}
					f[s[i]] = b[i];
					used |= 1<<b[i];
				}
			}
			
			if(com < n){
				if(a[com]+1 < b[com]){
					if(f[s[com]] == -1){
						for(int i = a[com]+1;i < b[com];i++){
							if(used<<~i>=0){
								f[s[com]] = i;
								used |= 1<<i;
								break;
							}
						}
					}
					if(f[s[com]] != -1 && a[com] < f[s[com]] && f[s[com]] < b[com]){
						ok(f, used);
						continue outer;
					}
				}
			}
			
			int res = sup(com, Arrays.copyOf(f, K), s, b, used);
			if(res != 0)continue;
			
			res = inf(com, Arrays.copyOf(f, K), s, a, used);
			if(res != 0)continue;
			
			out.println("NO");
		}
	}
	
	int sup(int com, int[] f, int[] s, int[] b, int used)
	{
		int n = s.length;
		for(int i = com;i < n;i++){
//			tr(i, f, used, s, a, b);
			if(f[s[i]] != -1){
				if(f[s[i]] > b[i]){
					return 0;
				}
				if(f[s[i]] < b[i])return 0;
			}else{
				if(used<<~b[i]<0){
					return 0;
				}
				f[s[i]] = b[i];
				used |= 1<<b[i];
			}
			
			if(i+1 < n){
				if(f[s[i+1]] == -1){
					for(int j = 0;j < b[i+1];j++){
						if(used<<~j>=0){
							f[s[i+1]] = j;
							used |= 1<<j;
							break;
						}
					}
				}
				if(f[s[i+1]] != -1 && f[s[i+1]] < b[i+1]){
					ok(f, used);
					return 1;
				}
			}
		}
		ok(f, used);
		return 1;
	}
	
	int inf(int com, int[] f, int[] s, int[] a, int used)
	{
		int n = s.length;
//		tr(f, used);
		for(int i = com;i < n;i++){
			if(f[s[i]] != -1){
				if(f[s[i]] < a[i]){
					return 0;
				}
				if(f[s[i]] > a[i])return 0;
			}else{
				if(used<<~a[i]<0){
					return 0;
				}
				f[s[i]] = a[i];
				used |= 1<<a[i];
			}
			
			if(i+1 < n){
				if(f[s[i+1]] == -1){
					for(int j = a[i+1] + 1;j < f.length;j++){
						if(used<<~j>=0){
							f[s[i+1]] = j;
							used |= 1<<j;
							break;
						}
					}
				}
				if(f[s[i+1]] != -1 && f[s[i+1]] > a[i+1]){
					ok(f, used);
					return 1;
				}
			}
		}
		ok(f, used);
		return 1;
	}
	
	void ok(int[] f, int used)
	{
		for(int i = 0;i < f.length;i++){
			if(f[i] == -1){
				int v = Integer.numberOfTrailingZeros(~used);
				f[i] = v;
				used |= 1<<v;
			}
		}
		out.println("YES");
		for(int i = 0;i < f.length;i++){
			out.print((char)('a'+f[i]));
		}
		out.println();
		
//		// check
//		int[] u = new int[s.length];
//		for(int i = 0;i < s.length;i++){
//			u[i] = f[s[i]];
//		}
//		tr("f", f, used);
//		for(int i = 0;i < s.length;i++){
//			if(a[i] != u[i]){
//				assert a[i] < u[i];
//				break;
//			}
//		}
//		for(int i = 0;i < s.length;i++){
//			if(b[i] != u[i]){
//				assert b[i] > u[i];
//				break;
//			}
//		}
		
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
	private byte[] inbuf = new byte[1024];
	public int lenbuf = 0, ptrbuf = 0;
	
	private int readByte()
	{
		if(lenbuf == -1)throw new InputMismatchException();
		if(ptrbuf >= lenbuf){
			ptrbuf = 0;
			try { lenbuf = is.read(inbuf); } catch (IOException e) { throw new InputMismatchException(); }
			if(lenbuf <= 0)return -1;
		}
		return inbuf[ptrbuf++];
	}
	
	private boolean isSpaceChar(int c) { return !(c >= 33 && c <= 126); }
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b)); return b; }
	
	private double nd() { return Double.parseDouble(ns()); }
	private char nc() { return (char)skip(); }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b))){ // when nextLine, (isSpaceChar(b) && b != ' ')
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}
	
	private char[] ns(int n)
	{
		char[] buf = new char[n];
		int b = skip(), p = 0;
		while(p < n && !(isSpaceChar(b))){
			buf[p++] = (char)b;
			b = readByte();
		}
		return n == p ? buf : Arrays.copyOf(buf, p);
	}
	
	private char[][] nm(int n, int m)
	{
		char[][] map = new char[n][];
		for(int i = 0;i < n;i++)map[i] = ns(m);
		return map;
	}
	
	private int[] na(int n)
	{
		int[] a = new int[n];
		for(int i = 0;i < n;i++)a[i] = ni();
		return a;
	}
	
	private int ni()
	{
		int num = 0, b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private long nl()
	{
		long num = 0;
		int b;
		boolean minus = false;
		while((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'));
		if(b == '-'){
			minus = true;
			b = readByte();
		}
		
		while(true){
			if(b >= '0' && b <= '9'){
				num = num * 10 + (b - '0');
			}else{
				return minus ? -num : num;
			}
			b = readByte();
		}
	}
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}