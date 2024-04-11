//package round653;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.InputMismatchException;
import java.util.List;
import java.util.PriorityQueue;

public class E2 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		List<Long> as = new ArrayList<>();
		List<Long> bs = new ArrayList<>();
		List<Long> both = new ArrayList<>();
		PriorityQueue<Long> trash = new PriorityQueue<>();
		PriorityQueue<Long> rtrash = new PriorityQueue<>();
		PriorityQueue<Long> trash2 = new PriorityQueue<>();
		long intrash = 0;
		long intrash2 = 0;
		int n = ni(), m = ni(), K = ni();
		for(int i = 0;i < n;i++){
			int t = ni(), a = ni(), b = ni();
			if(a == 1 && b == 1){
				both.add((long)t<<32|i);
			}else if(a == 1){
				as.add((long)t<<32|i);
			}else if(b == 1){
				bs.add((long)t<<32|i);
			}else{
				trash.add(-((long)t<<32|i));
				trash2.add(-((long)t<<32|i));
				intrash += t;
				intrash2 += t;
			}
		}
		Collections.sort(both);
		Collections.sort(as);
		Collections.sort(bs);
		
		long[] cboth = new long[both.size()+1];
		for(int i = 0;i < both.size();i++){
			cboth[i+1] = cboth[i] + (both.get(i)>>>32);
		}
		long[] cas = new long[as.size()+1];
		for(int i = 0;i < as.size();i++){
			cas[i+1] = cas[i] + (as.get(i)>>>32);
		}
		long[] cbs = new long[bs.size()+1];
		for(int i = 0;i < bs.size();i++){
			cbs[i+1] = cbs[i] + (bs.get(i)>>>32);
		}
		long ans = Long.MAX_VALUE;
		int ap = as.size(), bp = bs.size();
		int arg = -1;
		for(int i = 0;i <= both.size();i++){
			int rem = Math.max(0, K-i);
			if(rem <= as.size() && rem <= bs.size() && i+2*rem <= m){
				while(ap > rem){
					trash.add(-as.get(ap-1));
					intrash += (as.get(ap-1)>>>32);
					ap--;
				}
				while(bp > rem){
					trash.add(-bs.get(bp-1));
					intrash += (bs.get(bp-1)>>>32);
					bp--;
				}
				for(int z = 0;z < 2;z++){
					if(rtrash.size() > 0){
						long x = rtrash.poll();
						trash.add(-x);
						intrash += x>>>32;
					}
				}
				while(trash.size() > m-(i+2*rem)){
					long x = trash.poll();
					intrash -= (-x)>>>32;
					rtrash.add(-x);
				}
				if(trash.size() != m-(i+2*rem))continue;
//				tr(cboth[i], cas[rem], cbs[rem], intrash);
				long score = cboth[i] + cas[rem] + cbs[rem] + intrash;
				if(score < ans){
					ans = score;
					arg = i;
				}
			}
		}
		if(ans == Long.MAX_VALUE){
			out.println(-1);
		}else{
			out.println(ans);
			ap = as.size(); bp = bs.size();
			{
				int i = arg;
				int rem = Math.max(0, K-i);
				while(ap > rem){
					trash2.add(-as.get(ap-1));
//					intrash2 += (as.get(ap-1)>>>32);
					ap--;
				}
				while(bp > rem){
					trash2.add(-bs.get(bp-1));
//					intrash2 += (bs.get(bp-1)>>>32);
					bp--;
				}
				while(trash2.size() > m-(i+2*rem)){
					intrash2 -= (-trash2.poll())>>>32;
				}
				for(int j = 0;j < i;j++){
					out.print(both.get(j).intValue()+1 + " ");
				}
				for(int j = 0;j < rem;j++){
					out.print(as.get(j).intValue()+1 + " ");
				}
				for(int j = 0;j < rem;j++){
					out.print(bs.get(j).intValue()+1 + " ");
				}
				for(long t : trash2){
					out.print(((int)(-t))+1 + " ");
				}
				out.println();
			}
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
	
	public static void main(String[] args) throws Exception { new E2().run(); }
	
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