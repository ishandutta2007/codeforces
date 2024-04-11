//package round320;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[] s = ns().toCharArray();
		int n = s.length;
		int p = 0, q = 0;
		
		int[] mat = new int[n];
		Arrays.fill(mat, -1);
		while(true){
			while(p < n && s[p] != 'R')p++;
			while(q < n && (q <= p || s[q] != 'L'))q++;
			if(p == n || q == n)break;
			mat[p] = q;
			p++; q++;
		}
		p = 0; q = 0;
		while(true){
			while(p < n && s[p] != 'L')p++;
			while(q < n && (q <= p || s[q] != 'R'))q++;
			if(p == n || q == n)break;
			mat[p] = q;
			p++; q++;
		}
		int back = 0;
		for(int i = 0;i < n;i++){
			if(mat[i] == -1){
				back++;
			}
		}
		out.println(back-1);
		boolean[] ved = new boolean[n];
		int[] RL = new int[n];
		Arrays.fill(RL, -1);
		for(int i = 0;i < n;i++){
			if(!ved[i]){
				int last = -1;
				for(int j = i;j != -1;j = mat[j]){
					ved[j] = true;
					last = j;
				}
				RL[i] = 0;
				if(s[i] == 'R'){
					RL[i] |= 2;
				}
				if(s[last] == 'R'){
					RL[i] |= 1;
				}
			}
		}
		int[] nrl = new int[4];
		for(int v : RL){
			if(v >= 0)nrl[v]++;
		}
		assert Math.abs(nrl[0]-nrl[3]) <= 1;
		int nr = nrl[3] + nrl[1] + nrl[2], nl = nrl[0]+nrl[1]+nrl[2];
		ved = new boolean[n];
		if(nr > nl || nr == nl && nrl[2] > 0){
			// RL
			for(int i = 0;i < n;i++){
				if(RL[i] == 2){
					for(int j = i;j != -1;j = mat[j]){
						out.print(j+1 + " ");
					}
				}
			}
			int pr = 0, pl = 0;
			// R
			while(pr < n && RL[pr] != 3)pr++;
			if(pr < n){
				for(int j = pr;j != -1;j = mat[j]){
					out.print(j+1 + " ");
				}
				pr++;
				// LR
				for(int i = 0;i < n;i++){
					if(RL[i] == 1){
						for(int j = i;j != -1;j = mat[j]){
							out.print(j+1 + " ");
						}
					}
				}
				
				while(true){
					// L
					while(pl < n && RL[pl] != 0)pl++;
					if(pl == n)break;
					for(int j = pl;j != -1;j = mat[j]){
						out.print(j+1 + " ");
					}
					pl++;
					// R
					while(pr < n && RL[pr] != 3)pr++;
					if(pr == n)break;
					for(int j = pr;j != -1;j = mat[j]){
						out.print(j+1 + " ");
					}
					pr++;
				}
			}
		}else{
			// LR
			for(int i = 0;i < n;i++){
				if(RL[i] == 1){
					for(int j = i;j != -1;j = mat[j]){
						out.print(j+1 + " ");
					}
				}
			}
			int pr = 0, pl = 0;
			// L
			while(pl < n && RL[pl] != 0)pl++;
			if(pl < n){
				for(int j = pl;j != -1;j = mat[j]){
					out.print(j+1 + " ");
				}
				pl++;
				// RL
				for(int i = 0;i < n;i++){
					if(RL[i] == 2){
						for(int j = i;j != -1;j = mat[j]){
							out.print(j+1 + " ");
						}
					}
				}
				
				while(true){
					// R
					while(pr < n && RL[pr] != 3)pr++;
					if(pr == n)break;
					for(int j = pr;j != -1;j = mat[j]){
						out.print(j+1 + " ");
					}
					pr++;
					
					// L
					while(pl < n && RL[pl] != 0)pl++;
					if(pl == n)break;
					for(int j = pl;j != -1;j = mat[j]){
						out.print(j+1 + " ");
					}
					pl++;
				}
			}
		}
		out.println();
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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