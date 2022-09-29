//package mailru2018;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Deque;
import java.util.InputMismatchException;
import java.util.List;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		Deque[][] src = new Deque[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				char[] s = ns().toCharArray();
				src[i][j] = new ArrayDeque<Character>();
				for(char c : s){
					src[i][j].addLast(c);
				}
			}
		}
		Deque[][] dst = new Deque[n][m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				char[] s = ns().toCharArray();
				dst[i][j] = new ArrayDeque<Character>();
				for(char c : s){
					dst[i][j].addLast(c);
				}
			}
		}
		
		int[] tar0 = new int[n];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(char c : (Deque<Character>)src[i][j]){
					if(c == '0')tar0[i]++;
				}
			}
		}
		tar0[1] += tar0[0];
		tar0[0] = 0;
		
		int[] tar1 = new int[m];
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				for(char c : (Deque<Character>)src[i][j]){
					if(c == '1')tar1[j]++;
				}
			}
		}
		tar1[1] += tar1[0];
		tar1[0] = 0;
		
		// tail to head
		List<int[]> rf = toh(src, tar0, tar1);
		List<int[]> rr = hot(dst);
		
		for(int i = 1, j = 1;i < n;i++){
			if(src[i][0].size() <= dst[i][0].size())continue;
			while(src[i][0].size() > dst[i][0].size()){
				while(j < n && src[j][0].size() >= dst[j][0].size())j++;
				assert j < n;
				while(src[i][0].size() > dst[i][0].size() && 
						src[j][0].size() < dst[j][0].size()){
					src[j][0].addFirst(src[i][0].pollLast());
					rf.add(new int[]{i, 0, j, 0});
				}
			}
		}
		
//		print(src);
//		print(dst);
		
		for(int i = 1, j = 1;i < m;i++){
			if(src[0][i].size() <= dst[0][i].size())continue;
			while(src[0][i].size() > dst[0][i].size()){
				while(j < m && src[0][j].size() >= dst[0][j].size())j++;
				assert j < m;
				while(src[0][i].size() > dst[0][i].size() && 
						src[0][j].size() < dst[0][j].size()){
					src[0][j].addFirst(src[0][i].pollLast());
					rf.add(new int[]{0, i, 0, j});
				}
			}
		}
		
		out.println(rf.size() + rr.size());
		for(int[] x : rf){
			out.println((x[0]+1) + " " + (x[1]+1) + " " + (x[2]+1) + " " + (x[3]+1));
		}
		for(int i = rr.size()-1;i >= 0;i--){
			int[] x = rr.get(i);
			out.println((x[2]+1) + " " + (x[3]+1) + " " + (x[0]+1) + " " + (x[1]+1));
		}
	}
	
	void print(Deque[][] src)
	{
		int n = src.length, m = src[0].length;
		for(int i = 0;i < n;i++){
			for(int j = 0;j < m;j++){
				tr(i, j, src[i][j]);
			}
		}
	}
	
	List<int[]> toh(Deque[][] src, int[] tar0, int[] tar1)
	{
		int n = src.length, m = src[0].length;
		List<int[]> route = new ArrayList<>();
		for(int i = 1;i < n;i++){
			while(!src[i][0].isEmpty()){
				src[0][0].addFirst(src[i][0].pollLast());
				route.add(new int[]{i, 0, 0, 0});
			}
		}
		for(int i = 1;i < m;i++){
			while(!src[0][i].isEmpty()){
				src[0][0].addFirst(((Deque<Character>)src[0][i]).pollLast());
				route.add(new int[]{0, i, 0, 0});
			}
		}
		for(int i = 1;i < n;i++){
			for(int j = 1;j < m;j++){
				while(!src[i][j].isEmpty()){
					char x = ((Deque<Character>)src[i][j]).pollLast();
					if(x == '0'){
						route.add(new int[]{i, j, i, 0});
						src[i][0].addFirst('0');
					}else{
						route.add(new int[]{i, j, 0, j});
						src[0][j].addFirst('1');
					}
				}
			}
		}
		int p = 1, q = 1;
		while(!src[0][0].isEmpty()){
			char x = ((Deque<Character>)src[0][0]).pollLast();
			if(x == '0'){
				while(p < n && src[p][0].size() >= tar0[p])p++;
				int pp = p < n ? p : 1;
				route.add(new int[]{0, 0, pp, 0});
				src[pp][0].addFirst('0');
			}else{
				while(q < m && src[0][q].size() >= tar1[q])q++;
				int qq = q < m ? q : 1;
				route.add(new int[]{0, 0, 0, qq});
				src[0][qq].addFirst('1');
			}
		}
		return route;
	}
	
	
	List<int[]> hot(Deque[][] src)
	{
		int n = src.length, m = src[0].length;
		List<int[]> route = new ArrayList<>();
		for(int i = 1;i < n;i++){
			while(!src[i][0].isEmpty()){
				src[0][0].addLast(src[i][0].pollFirst());
				route.add(new int[]{i, 0, 0, 0});
			}
		}
		for(int i = 1;i < m;i++){
			while(!src[0][i].isEmpty()){
				src[0][0].addLast(((Deque<Character>)src[0][i]).pollFirst());
				route.add(new int[]{0, i, 0, 0});
			}
		}
		for(int i = 1;i < n;i++){
			for(int j = 1;j < m;j++){
				while(!src[i][j].isEmpty()){
					char x = ((Deque<Character>)src[i][j]).pollFirst();
					if(x == '0'){
						route.add(new int[]{i, j, i, 0});
						src[i][0].addLast('0');
					}else{
						route.add(new int[]{i, j, 0, j});
						src[0][j].addLast('1');
					}
				}
			}
		}
		while(!src[0][0].isEmpty()){
			char x = ((Deque<Character>)src[0][0]).pollFirst();
			if(x == '0'){
				int pp = 1;
				route.add(new int[]{0, 0, pp, 0});
				src[pp][0].addLast('0');
			}else{
				int qq = 1;
				route.add(new int[]{0, 0, 0, qq});
				src[0][qq].addLast('1');
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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