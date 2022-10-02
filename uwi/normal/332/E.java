//package round193;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E4 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] P = ns().toCharArray();
		char[] S = ns().toCharArray();
		int n = P.length, m = S.length;
		int K = ni();
		
		char[][] ps = new char[K][];
		for(int i = 0;i < K;i++){
			ps[i] = new char[(n+K-i-1)/K];
			for(int j = i, k = 0;j < n;j+=K, k++){
				ps[i][k] = P[j];
			}
		}
		
		String opt = "~";
		
		outer:
		for(int j = 1;j <= K;j++){
			char[][] qs = new char[j][];
			for(int o = 0;o < j;o++){
				int slen = (m-o+j-1)/j;
				qs[o] = new char[slen];
				for(int k = o, l = 0;k < m;k+=j, l++){
					qs[o][l] = S[k];
				}
			}
			char[] ret = new char[K];
			Arrays.fill(ret, '0');
			
			int y = j-1;
			for(int z = K-1;z >= 0 && y >= 0;z--){
				if(Arrays.equals(ps[z], qs[y])){
					ret[z] = '1';
					y--;
				}
			}
			if(y >= 0)continue outer;
			String T = new String(ret);
			if(T.compareTo(opt) < 0){
				opt = T;
			}
		}
		if(opt.equals("~")){
			out.println(0);
		}else{
			out.println(opt);
		}
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
	
	public static void main(String[] args) throws Exception { new E4().run(); }
	
	private byte[] inbuf = new byte[1024];
	private int lenbuf = 0, ptrbuf = 0;
	
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
	private int skip() { int b; while((b = readByte()) != -1 && isSpaceChar(b) && b != ' '); return b; }
	
	private String ns()
	{
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while(!(isSpaceChar(b) && b != ' ')){
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
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
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}