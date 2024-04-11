//package round500; 
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

public class D {
	InputStream is;
	PrintWriter out;
//	String INPUT = "b ababa";
//	String INPUT = "ababa b";
//	String INPUT = "abab ab";
	String INPUT = "";
	
	// ab
	// ababa
	
	// ab
	// baba
	// 
	
	int[] merge(Deque<Integer> fs, Deque<Integer> ft, int odd)
	{
		int nfs = fs.size(), nft = ft.size();
		int min = 999999999;
		int arg = -1;
		for(int h = odd;h <= nft;h+=2){
			int v = Math.max(nfs + h - 1 - (nfs == 1 ? 0 : 1) , nft - h + 1 - (nft == h ? 0 : 1));
			if(v < min){
				min = v;
				arg = h;
			}
		}
		Deque<Integer> temp = new ArrayDeque<>();
		int sum = 0;
		for(int i = 0;i < arg;i++){
			int v = ft.pollLast();
			temp.add(v);
			sum += v;
		}
		int tar = fs.pollLast();
		
		int[] ret = new int[]{tar, sum};
		if(fs.isEmpty() || temp.isEmpty()){
		}else{
			fs.addLast(fs.pollLast() + temp.pollLast());
		}
		while(!temp.isEmpty()){
			fs.addLast(temp.pollLast());
		}
		if(ft.isEmpty()){
			ft.addLast(tar);
		}else{
			ft.addLast(ft.pollLast() + tar);
		}
		return ret;
	}
	
	int[] merge0(Deque<Integer> fs, Deque<Integer> ft, int odd)
	{
		int nfs = fs.size(), nft = ft.size();
		int min = 999999999;
		int arg = -1;
		for(int h = odd;h <= nft;h+=2){
			int v = Math.max(nfs + h - (nfs == 0 ? 0 : 1) , nft - h);
			if(v < min){
				min = v;
				arg = h;
			}
		}
		Deque<Integer> temp = new ArrayDeque<>();
		int sum = 0;
		for(int i = 0;i < arg;i++){
			int v = ft.pollLast();
			temp.add(v);
			sum += v;
		}
		
		int[] ret = new int[]{0, sum};
		if(fs.isEmpty() || temp.isEmpty()){
		}else{
			fs.addLast(fs.pollLast() + temp.pollLast());
		}
		while(!temp.isEmpty()){
			fs.addLast(temp.pollLast());
		}
		return ret;
	}
	
	void solve()
	{
		char[] s = ns().toCharArray();
		char[] t = ns().toCharArray();
		
		if(s[0] != t[0]){
			Deque<Integer> fs = make(s);
			Deque<Integer> ft = make(t);
			
			String o = null;
			int nfs = fs.size(), nft = ft.size();
			if(!(nfs == 1 && nft == 1)){
				if(nfs < nft){
					int[] res = merge(fs, ft, 1);
					o = res[0] + " " + res[1];
				}else if(nfs > nft){
					int[] res = merge(ft, fs, 1);
					o = res[1] + " " + res[0];
				}
			}
			// a, b
			// a+h-1-1, b-h+1-1
			// a+h-2=b-h
			// h = (b-a+2)/2
			List<String> opes = go(fs, ft);
			if(o != null){
				opes.add(0, o);
			}
			
			out.println(opes.size());
			for(String ope : opes){
				out.println(ope);
			}
//			check(opes, s, t);
		}else{
			List<String> opes;
			{
				Deque<Integer> fs = make(s);
				Deque<Integer> ft = make(t);
				
				int x = fs.pollLast();
				String p = x + " " + 0;
				ft.addLast(ft.pollLast() + x);
				
				String o = null;
				int nfs = fs.size(), nft = ft.size();
				if(nfs != 0 && nft != 0){
					if(nfs < nft){
						int[] res = merge(fs, ft, 1);
						o = res[0] + " " + res[1];
					}else if(nfs > nft){
						int[] res = merge(ft, fs, 1);
						o = res[1] + " " + res[0];
					}
				}
					
				opes = go(fs, ft);
				if(o != null){
					opes.add(0, o);
				}
				opes.add(0, p);
			}
			{
				Deque<Integer> fs = make(s);
				Deque<Integer> ft = make(t);
				
				int x = ft.pollLast();
				String p = 0 + " " + x;
				fs.addLast(fs.pollLast() + x);
				
				String o = null;
				int nfs = fs.size(), nft = ft.size();
				if(nfs != 0 && nft != 0){
					if(nfs < nft){
						int[] res = merge(fs, ft, 1);
						o = res[0] + " " + res[1];
					}else if(nfs > nft){
						int[] res = merge(ft, fs, 1);
						o = res[1] + " " + res[0];
					}
				}
					
				List<String> lopes = go(fs, ft);
				if(o != null){
					lopes.add(0, o);
				}
				lopes.add(0, p);
				if(lopes.size() < opes.size()){
					opes = lopes;
				}
			}
			
			{
				Deque<Integer> fs = make(s);
				Deque<Integer> ft = make(t);
				
				String o = null;
				int nfs = fs.size(), nft = ft.size();
				if(nfs != 0 && nft != 0){
					if(nfs < nft){
						int[] res = merge0(fs, ft, 1);
						o = res[0] + " " + res[1];
					}else{
						int[] res = merge0(ft, fs, 1);
						o = res[1] + " " + res[0];
					}
				}
					
				List<String> lopes = go(fs, ft);
				if(o != null){
					lopes.add(0, o);
				}
				if(lopes.size() < opes.size()){
					opes = lopes;
				}
			}
			
			{
				Deque<Integer> fs = make(s);
				Deque<Integer> ft = make(t);
				
				String o = null;
				int nfs = fs.size(), nft = ft.size();
				if(nfs != 0 && nft != 0){
					if(nfs < nft){
						int[] res = merge(fs, ft, 0);
						o = res[0] + " " + res[1];
					}else if(nfs > nft){
						int[] res = merge(ft, fs, 0);
						o = res[1] + " " + res[0];
					}
				}
				
				if(fs.size() > 0 && ft.size() > 0){
					int x = ft.pollLast();
					String p = 0 + " " + x;
					fs.addLast(fs.pollLast() + x);
					
					
					List<String> lopes = go(fs, ft);
					lopes.add(0, p);
					if(o != null){
						lopes.add(0, o);
					}
					if(lopes.size() < opes.size()){
						opes = lopes;
					}
				}
			}
			
			{
				Deque<Integer> fs = make(s);
				Deque<Integer> ft = make(t);
				
				String o = null;
				int nfs = fs.size(), nft = ft.size();
				if(nfs != 0 && nft != 0){
					if(nfs < nft){
						int[] res = merge(fs, ft, 0);
						o = res[0] + " " + res[1];
					}else if(nfs > nft){
						int[] res = merge(ft, fs, 0);
						o = res[1] + " " + res[0];
					}
				}
				
				if(fs.size() > 0 && ft.size() > 0){
					int x = fs.pollLast();
					String p = x + " " + 0;
					ft.addLast(ft.pollLast() + x);
					
					
					List<String> lopes = go(fs, ft);
					lopes.add(0, p);
					if(o != null){
						lopes.add(0, o);
					}
					if(lopes.size() < opes.size()){
						opes = lopes;
					}
				}
			}
			
			out.println(opes.size());
			for(String ope : opes){
				out.println(ope);
			}
//			check(opes, s, t);
		}
	}
	
	void check(List<String> opes, char[] s, char[] t)
	{
		tr(opes);
		tr(new String(s));
		tr(new String(t));
		StringBuilder sbs = new StringBuilder(new String(s));
		StringBuilder sbt = new StringBuilder(new String(t));
		for(String o : opes){
			String[] sp = o.split(" ");
			int a = Integer.parseInt(sp[0]);
			int b = Integer.parseInt(sp[1]);
			StringBuilder ts = new StringBuilder(); 
			StringBuilder tt = new StringBuilder(); 
			for(int i = 0;i < a;i++){
				ts.append(sbs.charAt(0));
				sbs.deleteCharAt(0);
			}
			for(int i = 0;i < b;i++){
				tt.append(sbt.charAt(0));
				sbt.deleteCharAt(0);
			}
			sbs.insert(0, tt);
			sbt.insert(0, ts);
		}
		for(int i = 1;i < sbs.length();i++){
			assert sbs.charAt(i) == sbs.charAt(i-1);
		}
		for(int i = 1;i < sbt.length();i++){
			assert sbt.charAt(i) == sbt.charAt(i-1);
		}
	}
	
	List<String> go(Deque<Integer> fs, Deque<Integer> ft)
	{
		List<String> opes = new ArrayList<>();
		while(!(fs.size() <= 1 && ft.size() <= 1)){
			Integer x = fs.pollLast();
			int es = x == null ? 0 : x;
			x = ft.pollLast();
			int et = x == null ? 0 : x;
			opes.add(es + " " + et);
			if(es > 0){
				if(!ft.isEmpty()){
					ft.addLast(ft.pollLast() + es);
				}else{
					ft.add(es);
				}
			}
			if(et > 0){
				if(!fs.isEmpty()){
					fs.addLast(fs.pollLast() + et);
				}else{
					fs.add(et);
				}
			}
		}
		return opes;
	}
	
	Deque<Integer> make(char[] s)
	{
		char pre = 0;
		int ct = 0;
		Deque<Integer> ret = new ArrayDeque<>();
		for(int i = 0;i < s.length;i++){
			if(s[s.length-1-i] != pre){
				if(ct > 0){
					ret.add(ct);
				}
				ct = 0;
				pre = s[s.length-1-i];
			}
			ct++;
		}
		if(ct > 0){
			ret.add(ct);
		}
		return ret;
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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