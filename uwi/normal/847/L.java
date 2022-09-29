//package neerc2017;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Queue;

public class L {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		List<List<BitSet>> sets = new ArrayList<>();
		for(int i = 0;i < n;i++){
			String line = ns();
			String[] sp = line.split("-");
			List<BitSet> row = new ArrayList<>();
			for(String s : sp){
				int colon = s.indexOf(':');
				String[] to = s.substring(colon+1).split(",");
				BitSet tos = new BitSet();
				for(int j = 0;j < to.length;j++){
					tos.set(Integer.valueOf(to[j])-1);
				}
				row.add(tos);
			}
			sets.add(row);
		}
		
		int root = -1;
		for(int i = 0;i < n;i++){
			if(sets.get(i).size() == 1){
				root = i;
				break;
			}
		}
		if(root == -1){
			out.println(-1);
			return;
		}
		
		Queue<Integer> q = new ArrayDeque<>();
		q.add(root);
		
		int[][] es = new int[n-1][];
		int p = 0;
		boolean[] ved = new boolean[n];
		ved[root] = true;
		while(!q.isEmpty()){
			int cur = q.poll();
			outer:
			for(BitSet curb : sets.get(cur)){
//				tr(cur, curb);
				int hit = 0;
				for(int i = curb.nextSetBit(0);i < n && i != -1;i = curb.nextSetBit(i+1)){
					if(ved[i])continue outer;
					for(int j = 0;j < sets.get(i).size();j++){
						BitSet bs = sets.get(i).get(j);
						if(bs.cardinality() + curb.cardinality() == n && !bs.intersects(curb)){
//							tr(cur, i);
							hit++;
							if(ved[i]){
								out.println(-1);
								return;
							}
							if(p == n-1){
								out.println(-1);
								return;
							}
							es[p++] = new int[]{cur, i};
							q.add(i);
							ved[i] = true;
						}
					}
				}
				if(hit != 1){
					out.println(-1);
					return;
				}
			}
		}
		if(p < n-1){
			out.println(-1);
			return;
		}
		out.println(n-1);
		for(int[] e : es){
			out.println((e[0]+1) + " " + (e[1]+1));
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
	
	public static void main(String[] args) throws Exception { new L().run(); }
	
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