//package round197;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.InputMismatchException;

public class E3 {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int[] a = na(n);
		int del = 1;
		int[] cuts = new int[7*3];
		int cp = 0;
		int cur = 0;
		for(int i = 0;i < n;i++){
			if(del != 0 && cur+del != a[i]){
				cuts[cp++] = i;
				del = 0;
			}else if(del == 0 && Math.abs(a[i]-a[i-1]) != 1){
				cuts[cp++] = i;
				del = 0;
			}else{
				if(i > 0)del = a[i] - a[i-1];
			}
			cur = a[i];
		}
		if(cur != n){
			cuts[cp++] = n;
		}
		if(cp == 0){
			out.println(0);
			return;
		}
		
		for(int i = cp-1;i >= 0;i--){
			if(cuts[i]+1 <= n)cuts[cp++] = cuts[i]+1;
			if(cuts[i]-1 >= 0)cuts[cp++] = cuts[i]-1;
		}
		Arrays.sort(cuts, 0, cp);
		int up = 0;
		for(int i = 0;i < cp;i++){
			if(i == 0 || cuts[i] != cuts[i-1]){
				cuts[up++] = cuts[i];
			}
		}
		cp = up;
		cuts = Arrays.copyOf(cuts, cp);
		
		int[] islope = new int[cp-1];
		int[] inum = new int[cp-1];
		for(int i = 0;i < cp-1;i++){
			if(cuts[i+1]-cuts[i] <= 1){
				islope[i] = 0;
			}else{
				islope[i] = a[cuts[i]+1]-a[cuts[i]];
			}
			inum[i] = a[cuts[i]];
		}
		
		int[] slope = new int[cp-1];
		Arrays.fill(slope, 1);
		int[] num = Arrays.copyOf(inum, cp-1);
		Arrays.sort(num);
		
		hist = new int[6];
		opthist = null;
		if(!dfs(slope, num, islope, inum, 0))throw new RuntimeException();
		
		int[][] ret = new int[opthist.length/2][];
		int op = 0;
		for(int i = opthist.length-2;i >= 0;i-=2){
			ret[op] = new int[]{cuts[opthist[i]]+1, cuts[opthist[i+1]+1]};
			if(ret[op][0] == ret[op][1])continue;
			op++;
			int sum = cuts[opthist[i]]+cuts[opthist[i+1]+1];
			for(int j = opthist[i];j <= opthist[i+1]+1;j++){
				cuts[j] = sum - cuts[j];
			}
			Arrays.sort(cuts, 0, cp);
		}
		
		ret = Arrays.copyOf(ret, op);
		out.println(op);
		for(int w = 0, y = op-1;w < y;w++,y--){
			int[] x = ret[w]; ret[w] = ret[y]; ret[y] = x;
		}
		
		for(int i = 0;i < ret.length;i++){
			out.println(ret[i][0] + " " + ret[i][1]);
		}
		
		int[] check = new int[n];
		for(int i = 0;i < n;i++)check[i] = i+1;
		for(int i = 0;i < ret.length;i++){
			int l = ret[i][0]-1;
			int r = ret[i][1]-1;
			for(;l < r;l++,r--){
				int d = check[l]; check[l] = check[r]; check[r] = d;
			}
		}
		if(!Arrays.equals(a, check)){
			throw new RuntimeException();
		}
	}
	
	int[] opthist = null;
	int[] hist;
	
	boolean dfs(int[] slope, int[] num, final int[] islope, final int[] inum, int dep)
	{
		boolean ok = Arrays.equals(num, inum);
//		tr(slope, islope, dep);
		for(int i = 0;i < slope.length;i++){
			if(islope[i] == 0 || slope[i] == islope[i]){
			}else{
				ok = false;
				break;
			}
		}
		if(ok){
			opthist = Arrays.copyOf(hist, 2*dep);
			return true;
		}
		if(dep == 3)return false;
		
		for(int l = 0;l < slope.length;l++){
			for(int r = l;r < slope.length;r++){
				hist[2*dep] = l; hist[2*dep+1] = r;
				for(int p = l, q = r;p < q;p++,q--){
					int d = slope[p]; slope[p] = slope[q]; slope[q] = d;
					d = num[p]; num[p] = num[q]; num[q] = d;
				}
				for(int p = l;p <= r;p++)slope[p] = -slope[p];
				if(dfs(slope, num, islope, inum, dep+1))return true;
				for(int p = l, q = r;p < q;p++,q--){
					int d = slope[p]; slope[p] = slope[q]; slope[q] = d;
					d = num[p]; num[p] = num[q]; num[q] = d;
				}
				for(int p = l;p <= r;p++)slope[p] = -slope[p];
			}
		}
		return false;
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
	
	public static void main(String[] args) throws Exception { new E3().run(); }
	
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