//package round213;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;
import java.util.TreeSet;

public class CEx2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int K = ni();
		if(K >= 25){
			int n = 2*K*K;
			
			int[][] ved = new int[1<<5][1000];
			int[] p = new int[1<<5];
			
			TreeSet<Integer> q = new TreeSet<Integer>();
			q.add(1);
			int[] P = {2, 3, 5, 7, 11};
			while(!q.isEmpty()){
				int cur = q.pollFirst();
				int bit = 0;
				for(int i = 0;i < 5;i++){
					if(cur % P[i] == 0){
						bit |= 1<<i;
					}
				}
				ved[bit][p[bit]++] = cur;
				for(int u : P){
					if((long)cur*u <= n){
						q.add(cur*u);
					}
				}
			}
			
			int[] rem = new int[5];
			Arrays.fill(rem, (K+1)/2);
			
			Integer[] v = new Integer[32];
			for(int i = 0;i < 32;i++)v[i] = i;
			Arrays.sort(v, new Comparator<Integer>() {
				public int compare(Integer a, Integer b) {
					return -(Integer.bitCount(a) - Integer.bitCount(b));
				}
			});
			
			inner:
			for(int i = 0;i < K;i++){
				int max = -99999, maxj = -1;
				for(int j = 0;j < 5;j++){
					if(rem[j] > max){
						max = rem[j];
						maxj = j;
					}
				}
				for(int j = 0;j < 32;j++){
					if(p[v[j]] > 0 && v[j]<<31-maxj<0){
						for(int l = 0;l < 5;l++){
							if(v[j]<<31-l<0)rem[l]--;
						}
						if(i > 0)out.print(" ");
						out.print(ved[v[j]][--p[v[j]]]);
						continue inner;
					}
				}
				throw new RuntimeException();
			}
			out.println();
//			int max = -99999, maxj = -1;
//			for(int j = 0;j < 5;j++){
//				if(rem[j] > max){
//					max = rem[j];
//				}
//			}
//			tr(K);
//			tr(rem);
//			if(max > 0)throw new RuntimeException();
		}else{
			int n = 2*K*K;
			
			int[][] ved = new int[1<<2][1000];
			int[] p = new int[1<<2];
			
			TreeSet<Integer> q = new TreeSet<Integer>();
			q.add(1);
			int[] P = {2, 3};
			while(!q.isEmpty()){
				int cur = q.pollFirst();
				int bit = 0;
				for(int i = 0;i < 2;i++){
					if(cur % P[i] == 0){
						bit |= 1<<i;
					}
				}
				ved[bit][p[bit]++] = cur;
				for(int u : P){
					if((long)cur*u <= n){
						q.add(cur*u);
					}
				}
			}
			
			int[] rem = new int[2];
			Arrays.fill(rem, (K+1)/2);
			
			Integer[] v = new Integer[4];
			for(int i = 0;i < 4;i++)v[i] = i;
			Arrays.sort(v, new Comparator<Integer>() {
				public int compare(Integer a, Integer b) {
					return -(Integer.bitCount(a) - Integer.bitCount(b));
				}
			});
			
			inner:
			for(int i = 0;i < K;i++){
				int max = -99999, maxj = -1;
				for(int j = 0;j < 2;j++){
					if(rem[j] > max){
						max = rem[j];
						maxj = j;
					}
				}
				for(int j = 0;j < 4;j++){
					if(p[v[j]] > 0 && v[j]<<31-maxj<0){
						for(int l = 0;l < 2;l++){
							if(v[j]<<31-l<0)rem[l]--;
						}
//						--p[v[j]];
						if(i > 0)out.print(" ");
						out.print(ved[v[j]][--p[v[j]]]);
						continue inner;
					}
				}
				throw new RuntimeException();
			}
			out.println();
//			int max = -99999, maxj = -1;
//			for(int j = 0;j < 2;j++){
//				if(rem[j] > max){
//					max = rem[j];
//				}
//			}
//			tr(K);
//			tr(rem);
//			if(max > 0)throw new RuntimeException();
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
	
	public static void main(String[] args) throws Exception { new CEx2().run(); }
	
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