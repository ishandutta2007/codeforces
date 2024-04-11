//package round378;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.InputMismatchException;
import java.util.List;

public class C {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int K = ni();
		int[] b = na(K);
		int p = 0;
		if(Arrays.stream(a).sum() != Arrays.stream(b).asLongStream().sum()){
			out.println("NO");
			return;
		}
		int[] bd = new int[K+1];
		for(int i = 0;i < K;i++){
			int rem = b[i];
			while(p < n && rem > 0){
				rem -= a[p++];
			}
			if(rem != 0){
				out.println("NO");
				return;
			}
			bd[i+1] = p;
		}
		int[] args = new int[K];
		boolean[] lower = new boolean[K];
		for(int i = 0;i < K;i++){
			boolean same = true;
			int max = -1;
			for(int j = bd[i];j < bd[i+1];j++){
				if(a[j] != a[bd[i]])same = false;
				if(a[j] >= max){
					max = a[j];
				}
			}
			if(same && bd[i+1] - bd[i] > 1){
				out.println("NO");
				return;
			}
			int arg = bd[i];
			for(int j = bd[i];j < bd[i+1];j++){
				if(a[j] == max){
					if(j+1 < bd[i+1] && a[j+1] < a[j]){
						arg = j;
						lower[i] = false;
						break;
					}
					if(j-1 >= bd[i] && a[j-1] < a[j]){
						arg = j;
						lower[i] = true;
						break;
					}
				}
			}
			args[i] = arg;
		}
		
//		List<int[]> opes = new ArrayList<>();
		out.println("YES");
		for(int i = K-1;i >= 0;i--){
			if(lower[i]){
				for(int j = args[i]-1;j >= bd[i];j--){
//					opes.add(new int[]{j+1, -1});
					out.println((j+2) + " " + "L");
				}
				for(int j = args[i]+1;j < bd[i+1];j++){
//					opes.add(new int[]{bd[i], 1});
					out.println((bd[i]+1) + " " + "R");
				}
			}else{
				for(int j = args[i]+1;j < bd[i+1];j++){
//					opes.add(new int[]{args[i], 1});
					out.println((args[i]+1) + " " + "R");
				}
				for(int j = args[i]-1;j >= bd[i];j--){
//					opes.add(new int[]{j+1, -1});
					out.println((j+2) + " " + "L");
				}
			}
		}
//		check(opes, a, b);
	}
	
	void check(List<int[]> ope, int[] a, int[] last){
		assert ope.size() == a.length -  last.length;
		int n = a.length;
		List<Integer> list = new ArrayList<>();
		for(int v : a)list.add(v);
		for(int[] o : ope){
			int my = list.get(o[0]);
			int ne = list.get(o[0]+o[1]);
			assert my > ne;
			if(o[1] == 1){
				list.remove(o[0]);
				list.remove(o[0]);
				list.add(o[0], my + ne);
			}else{
				list.remove(o[0]);
				list.remove(o[0]-1);
				list.add(o[0]-1, my + ne);
			}
		}
		for(int i = 0;i < last.length;i++){
			assert list.get(i).intValue() == last[i];
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
	
	public static void main(String[] args) throws Exception { new C().run(); }
	
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