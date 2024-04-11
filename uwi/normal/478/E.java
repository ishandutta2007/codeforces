//package round273;
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
	
	int[] all = new int[1000000];
	int ap = 0;
	
	void dfs(int n, int d, int dir)
	{
		if(n >= 10000000)return;
		all[ap++] = n<<2|dir+1;
		if(dir == 0 || dir == 1){
			for(int i = 0;i <= d-1;i++)dfs(n*10+i, i, -1);
		}
		if(dir == 0 || dir == -1){
			for(int i = d+1;i <= 9;i++)dfs(n*10+i, i, 1);
		}
	}
	
	void solve()
	{
		for(int i = 1;i <= 9;i++){
			dfs(i, i, 0);
		}
		all = Arrays.copyOf(all, ap);
		Arrays.sort(all);
		long nn = nl();
		long K = nl();
		if((double)nn*K > 2E14){
			out.println(-1);
			return;
		}
		if(nn > 2000000){
			for(long i = nn;i <= 100000000000000L;i+=nn){
				if(zigzag(i)){
					K--;
					if(K == 0){
						out.println(i);
						return;
					}
				}
			}
			out.println(-1);
			return;
		}else{
			int n = (int)nn;
			for(int ii : all){
				int i = ii>>>2;
				if(i % n == 0){
					K--;
					if(K == 0){
						out.println(i);
						return;
					}
				}
			}
			
			int[][] asccount = new int[n][10];
			int[][] desccount = new int[n][10];
			for(int ii : all){
				int i = ii>>>2;
				int z = zigzag2(i);
				if(z == 1){
					asccount[i%n][i/1000000]++;
				}else if(z == -1){
					desccount[i%n][i/1000000]++;
				}
			}
			
			for(int i = 0;i < n;i++){
				for(int j = 1;j <= 9;j++){
					desccount[i][j] += desccount[i][j-1];
				}
				for(int j = 8;j >= 0;j--){
					asccount[i][j] += asccount[i][j+1];
				}
			}
			
			int B = 10000000;
//			int bn = B % n;
			for(int ii : all){
				int i = ii>>>2;
				int need = (int)(-(long)B*i%n);
				if(need < 0)need += n;
				int z = ii&3;
				int minus = 0;
				if(z == 2){
					minus = i%10 == 0 ? 0 : desccount[need][i%10-1];
				}else if(z == 0){
					minus = i%10 == 9 ? 0 : asccount[need][i%10+1];
				}else if(z == 1){
					minus = i%10 == 0 ? 0 : desccount[need][i%10-1];
					minus += i%10 == 9 ? 0 : asccount[need][i%10+1];
				}
				if(K - minus <= 0){
					for(int jj : all){
						int j = jj>>>2;
						long num = i*(long)B+j;
						if(num % n == 0 && zigzag(num)){
							K--;
							if(K == 0){
								out.println(i*(long)B+j);
								return;
							}
						}
					}
					throw new RuntimeException();
				}
				K -= minus;
			}
			out.println(-1);
		}
	}
	
	int zigzag1(long n)
	{
		long dig = n%10;
		n /= 10;
		int dir = 0;
		int first = 0;
		while(n > 0){
			long d = n%10;
			if(dir == 0){
				if(d > dig){
					dir = 1;
					first = -1;
				}else if(d < dig){
					dir = -1;
					first = 1;
				}else{
					return 999;
				}
			}else if(dir == 1){
				if(d < dig){
					dir = -1;
				}else{
					return 999;
				}
			}else{
				if(d > dig){
					dir = 1;
				}else{
					return 999;
				}
			}
			dig = d;
			n /= 10;
		}
		return first;
	}
	
	int zigzag2(long n)
	{
		long dig = n%10;
		n /= 10;
		int dir = 0;
		for(int i = 0;i < 6;i++){
			long d = n%10;
			if(dir == 0){
				if(d > dig){
					dir = 1;
				}else if(d < dig){
					dir = -1;
				}else{
					return 999;
				}
			}else if(dir == 1){
				if(d < dig){
					dir = -1;
				}else{
					return 999;
				}
			}else{
				if(d > dig){
					dir = 1;
				}else{
					return 999;
				}
			}
			dig = d;
			n /= 10;
		}
		return dir;
	}
	
	boolean zigzag(long n)
	{
		long dig = n%10;
		n /= 10;
		int dir = 0;
		while(n > 0){
			long d = n%10;
			if(dir == 0){
				if(d > dig){
					dir = 1;
				}else if(d < dig){
					dir = -1;
				}else{
					return false;
				}
			}else if(dir == 1){
				if(d < dig){
					dir = -1;
				}else{
					return false;
				}
			}else{
				if(d > dig){
					dir = 1;
				}else{
					return false;
				}
			}
			dig = d;
			n /= 10;
		}
		return true;
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