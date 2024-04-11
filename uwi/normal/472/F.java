//package round270;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class F2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int[] b = na(n);
		List<int[]> ba = basis(a);
		List<int[]> bb = basis(b);
		int rank = 0;
		for(int v : a){
			if(v != 0)rank++;
		}
		
		for(int v : b){
			if(v == 0)continue;
			for(int i = 0;i < rank;i++){
				if(Integer.highestOneBit(v) == Integer.highestOneBit(a[i])){
					v ^= a[i];
				}
			}
			if(v != 0){
				out.println(-1);
				return;
			}
		}
		
		List<int[]> inter = new ArrayList<int[]>();
		for(int j = 0;j < 32 && j < n;j++){
			int v = b[j];
			if(v == 0){
				inter.add(new int[]{j, j});
				a[j] = 0;
				continue;
			}
			int first = -1;
			for(int i = 0;i < rank;i++){
				if(Integer.highestOneBit(v) == Integer.highestOneBit(a[i])){
					v ^= a[i];
					if(first == -1){
						first = i;
					}else{
						inter.add(new int[]{i, first});
					}
				}
			}
			a[first] = b[j];
			if(first != j){
				inter.add(new int[]{first, j});
				inter.add(new int[]{j, first});
				inter.add(new int[]{first, j});
				int du = a[first]; a[first] = a[j]; a[j] = du;
			}
		}
		out.println(ba.size() + bb.size() + inter.size());
		for(int[] r : ba)out.println((r[1]+1) + " " + (r[0] + 1));
		for(int[] r : inter)out.println((r[1]+1) + " " + (r[0] + 1));
		for(int i = bb.size()-1;i >= 0;i--){
			out.println((bb.get(i)[1]+1) + " " + (bb.get(i)[0]+1));
		}
	}
	
	
	
	public static List<int[]> basis(int[] a)
	{
		List<int[]> route = new ArrayList<int[]>();
		int n = a.length;
		int h = 0;
		for(int d = 30;d >= 0;d--){
			int p = h;
			for(;p < n;p++){
				if(a[p]<<~d<0){
					if(p != h){
						// swap
						route.add(new int[]{p, h});
						route.add(new int[]{h, p});
						route.add(new int[]{p, h});
						int x = a[p]; a[p] = a[h]; a[h] = x;
					}
					
					for(int i = h+1;i < n;i++){
						if(a[i]<<~d<0){
							route.add(new int[]{h, i});
							a[i] ^= a[h];
						}
					}
					h++;
					
					break;
				}
			}
		}
		return route;
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
	
	public static void main(String[] args) throws Exception { new F2().run(); }
	
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