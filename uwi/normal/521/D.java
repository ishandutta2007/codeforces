//package round295;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Comparator;
import java.util.InputMismatchException;

public class D {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int K = ni(), n = ni(), m = ni();
		int[] a = na(K);
		Query[] qs = new Query[n];
		for(int i = 0;i < n;i++){
			qs[i] = new Query(ni(), ni()-1, ni(), i);
		}
		
		Query[] muls = new Query[n];
		int mp = 0;
		for(int i = 0;i < n;i++){
			if(qs[i].type == 3)muls[mp++] = qs[i];
		}
		muls = Arrays.copyOf(muls, mp);
		Arrays.sort(muls, new Comparator<Query>() {
			public int compare(Query a, Query b) {
				return -(a.val - b.val);
			}
		});
		
		Query[] assigns = new Query[K];
		for(int i = 0;i < n;i++){
			if(qs[i].type == 1 && (assigns[qs[i].ind] == null || qs[i].val > assigns[qs[i].ind].val) && qs[i].val > a[qs[i].ind]){
				assigns[qs[i].ind] = qs[i];
			}
		}
		
		Query[][] adds = new Query[K][];
		int[] aps = new int[K];
		for(int i = 0;i < K;i++)if(assigns[i] != null)aps[i]++;
		for(int i = 0;i < n;i++){
			if(qs[i].type == 2){
				aps[qs[i].ind]++;
			}
		}
		for(int i = 0;i < K;i++)adds[i] = new Query[aps[i]];
		for(int i = 0;i < K;i++)if(assigns[i] != null){
			assigns[i].val -= a[i];
			adds[i][--aps[i]] = assigns[i];
		}
		for(int i = 0;i < n;i++){
			if(qs[i].type == 2){
				adds[qs[i].ind][--aps[qs[i].ind]] = qs[i];
			}
		}
		for(int i = 0;i < K;i++)assert aps[i] == 0;
		
		for(int i = 0;i < K;i++){
			if(adds[i].length == 0)continue;
			Arrays.sort(adds[i], new Comparator<Query>() {
				public int compare(Query a, Query b) {
					return -Long.compare(a.val, b.val);
				}
			});
			adds[i][0].cum = a[i];
			for(int j = 1;j < adds[i].length;j++){
				adds[i][j].cum = adds[i][j-1].cum + adds[i][j-1].val;
			}
//			tr("adds", i, adds[i]);
		}
		
		Query[] con = new Query[n];
		int cp = 0;
		for(int i = 0;i < K;i++){
			for(Query q : adds[i]){
				con[cp++] = q;
			}
		}
		Arrays.sort(con, 0, cp, new Comparator<Query>() {
			public int compare(Query a, Query b) {
				if(a.ind == b.ind){
					return -(a.val - b.val);
				}else{
					return Long.compare(a.cum*b.val, a.val*b.cum);
				}
			}
		});
//		tr("con", con);
		
		int bnadd = cp, bnmul = mp;
		if(bnadd + bnmul > m){
			bnadd = Math.min(m, cp); bnmul = m-bnadd;
//			tr(bnadd, bnmul);
			for(int nadd = Math.max(0, m-mp);nadd <= cp-1 && nadd < m;nadd++){ // #add
				int nmul = m-nadd;
				long orig = con[nadd].cum * muls[nmul-1].val;
				long next = con[nadd].cum + con[nadd].val;
//				tr(nadd, nmul, orig, next);
				if(orig > next){
					bnadd = nadd; bnmul = nmul;
					break;
				}
			}
		}
//		tr("bnadd", bnadd);
		Arrays.sort(con, 0, bnadd, new Comparator<Query>() {
			public int compare(Query a, Query b) {
				return a.type - b.type;
			}
		});
		
//		BigInteger[] b = new BigInteger[K];
//		for(int i = 0;i < K;i++)b[i] = BigInteger.valueOf(a[i]);
//		for(int i = 0;i < bnadd;i++){
//			if(con[i].type == 1){
//				b[con[i].ind] = b[con[i].ind].add(BigInteger.valueOf(con[i].val));
////				b[con[i].ind] = BigInteger.valueOf(con[i].val);
//			}else if(con[i].type == 2){
//				b[con[i].ind] = b[con[i].ind].add(BigInteger.valueOf(con[i].val));
//			}else{
//				b[con[i].ind] = b[con[i].ind].multiply(BigInteger.valueOf(con[i].val));
//			}
//		}
//		for(int i = 0;i < bnmul;i++){
//			if(muls[i].type == 1){
//				b[muls[i].ind] = BigInteger.valueOf(muls[i].val);
//			}else if(muls[i].type == 2){
//				b[muls[i].ind] = b[muls[i].ind].add(BigInteger.valueOf(muls[i].val));
//			}else{
//				b[muls[i].ind] = b[muls[i].ind].multiply(BigInteger.valueOf(muls[i].val));
//			}
//		}
//		BigInteger all = BigInteger.ONE;
//		for(int i = 0;i < K;i++)all = all.multiply(b[i]);
//		out.println(all);
		
		out.println(bnadd+bnmul);
		for(int i = 0;i < bnadd;i++){
			out.print(con[i].id+1 + " ");
		}
		for(int i = 0;i < bnmul;i++){
			out.print(muls[i].id+1 + " ");
		}
		out.println();
	}
	
	static class Query
	{
		public int type, ind, val, id;
		public long cum;
		private Query(int type, int ind, int val, int id) {
			this.type = type;
			this.ind = ind;
			this.val = val;
			this.id = id;
		}
		@Override
		public String toString() {
			return "Query [type=" + type + ", ind=" + ind + ", val=" + val
					+ ", id=" + id + ", cum=" + cum + "]";
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
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
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