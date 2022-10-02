//package vkcup2012.r2;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.BitSet;
import java.util.Comparator;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
//	String INPUT = "26 3\r\n" + 
//			"bbaaa\r\n" + 
//			"abaaab\r\n" + 
//			"aa\r\n" + 
//			"-3\r\n" + 
//			"?aabaabaaab\r\n";
//	String INPUT = "7 3\r\n" + 
//			"a\r\n" + 
//			"aa\r\n" + 
//			"ab\r\n" + 
//			"?aaab\r\n" + 
//			"-2\r\n" + 
//			"?aaab\r\n" + 
//			"-3\r\n" + 
//			"?aaab\r\n" + 
//			"+2\r\n" + 
//			"?aabbaa";
	
	void solve()
	{
		int n = ni(), m = ni();
		char[][] s = new char[m][];
		for(int i = 0;i < m;i++){
			s[i] = ns().toCharArray();
		}
		
		int[][][] trie = buildAlphabetTrie(s);
		int t = trie.length;
		int[] fail = buildFailure(trie);
		fail[0] = -1;
		int[][] fch = parentToChildren(fail);
		
//		tr(fail);
//		tr(t);
//		int[] ord = new int[t];
//		sortByPreorder(fch, 0, ord, 0, -1);;
		int[] ord = sortByPreorder(fch, 0);
		int[] right = new int[t];
		for(int i = t-1;i >= 0;i--){
			right[ord[i]] = i;
			for(int e : fch[ord[i]]){
				right[ord[i]] = Math.max(right[ord[i]], right[e]);
			}
		}
		// right :  -> ftpos
		// ord : ftpos -> 
		
		int[] iord = new int[t];
		for(int i = 0;i < t;i++)iord[ord[i]] = i;
		
		int[] ft0 = new int[t+1];
		int[] ft1 = new int[t+1];
		
		int[] key = new int[m];
		for(int i = 0;i < m;i++){
			int cur = 0;
			for(int j = 0;j < s[i].length;j++){
				cur = next(trie, cur, s[i][j]-'a');
			}
			key[i] = cur;
			addRangeFenwick(ft0, ft1, iord[cur], right[cur], 1);
		}
		boolean[] used = new boolean[m];
		Arrays.fill(used, true);
//		tr(restoreFenwick(ft0, ft1));
		
		for(int i = 0;i < n;i++){
			char o = nc();
			if(o == '?'){
				char[] q = ns().toCharArray();
				long hit = 0;
				int cur = 0;
				for(char c : q){
					while(cur > 0 && next(trie, cur, c-'a') == -1)cur = fail[cur];
					int nex = next(trie, cur, c-'a');
					if(nex == -1)nex = 0;
					cur = nex;
					hit += sumRangeFenwick(ft0, ft1, iord[cur]) - sumRangeFenwick(ft0, ft1, iord[cur]-1);
				}
				out.println(hit);
			}else if(o == '+'){
				int ind = ni()-1;
				if(!used[ind]){
					addRangeFenwick(ft0, ft1, iord[key[ind]], right[key[ind]], 1);
					used[ind] = true;
				}
			}else if(o == '-'){
				int ind = ni()-1;
				if(used[ind]){
					addRangeFenwick(ft0, ft1, iord[key[ind]], right[key[ind]], -1);
					used[ind] = false;
				}
			}
		}
	}
	
	public static int[] sortByPreorder(int[][] g, int root){
		int n = g.length;
		int[] stack = new int[n];
		int[] ord = new int[n];
		BitSet ved = new BitSet();
		stack[0] = root;
		int p = 1;
		int r = 0;
		ved.set(root);
		while(p > 0){
			int cur = stack[p-1];
			ord[r++] = cur;
			p--;
			for(int e : g[cur]){
				if(!ved.get(e)){
					stack[p++] = e;
					ved.set(e);
				}
			}
		}
		return ord;
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(i++;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		if(v == 0)return;
		int n = ft.length;
		for(i++;i < n;i += i&-i)ft[i] += v;
	}
	
	public static int valFenwick(int[] ft, int i)
	{
		return sumFenwick(ft, i) - sumFenwick(ft, i-1);
	}
	
	public static int[] restoreFenwick(int[] ft)
	{
		int n = ft.length-1;
		int[] ret = new int[n];
		for(int i = 0;i < n;i++)ret[i] = sumFenwick(ft, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static long[] restoreFenwick(int[] ft0, int[] ft1)
	{
		int n = ft0.length-1;
		long[] ret = new long[n];
		for(int i = 0;i < n;i++)ret[i] = sumRangeFenwick(ft0, ft1, i);
		for(int i = n-1;i >= 1;i--)ret[i] -= ret[i-1];
		return ret;
	}
	
	public static void addRangeFenwick(int[] ft0, int[] ft1, int i, int v)
	{
		addFenwick(ft1, i+1, -v);
		addFenwick(ft1, 0, v);
		addFenwick(ft0, i+1, v*(i+1));
	}
	
	public static void addRangeFenwick(int[] ft0, int[] ft1, int a, int b, int v)
	{
		if(a <= b){
			addFenwick(ft1, b+1, -v);
			addFenwick(ft0, b+1, v*(b+1));
			addFenwick(ft1, a, v);
			addFenwick(ft0, a, -v*a);
		}
	}
	
	public static long sumRangeFenwick(int[] ft0, int[] ft1, int i)
	{
		return (long)sumFenwick(ft1, i) * (i+1) + sumFenwick(ft0, i);
	}
	
	public static int sortByPreorder(int[][] g, int cur, int[] ord, int pos, int prev)
	{
		ord[pos++] = cur;
		for(int e : g[cur])if(prev != e)pos = sortByPreorder(g, e, ord, pos, cur);
		return pos;
	}
	
	public static int[][] parentToChildren(int[] parent)
	{
		int n = parent.length;
		int[] ct = new int[n];
		for(int i = 0;i < n;i++){
			if(parent[i] >= 0){
				ct[parent[i]]++;
			}
		}
		int[][] ret = new int[n][];
		for(int i = 0;i < n;i++){
			ret[i] = new int[ct[i]];
		}
		for(int i = 0;i < n;i++){
			if(parent[i] >= 0){
				ret[parent[i]][--ct[parent[i]]] = i;
			}
		}
		
		return ret;
	}
	
	
	char nc() {
		try{
			int b;
			while ((b = is.read()) != -1
					&& (b == ' ' || b == '\r' || b == '\n'))
				;
			if(b == -1)
				return 0;
			return (char) b;
		}catch (IOException e){
		}
		return 0;
	}

	public static int[][][] buildAlphabetTrie(char[][] oss)
	{
		char[][] ss = Arrays.copyOf(oss, oss.length);
		
		int m = 1;
		for(int i = 0;i < ss.length;i++)m += ss[i].length;
		Arrays.sort(ss, new Comparator<char[]>(){
			public int compare(char[] a, char[] b){
				for(int i = 0;i < a.length && i < b.length;i++){
					if(a[i] != b[i])return a[i] - b[i];
				}
				return a.length - b.length;
			}
		});
		
		int[][][] trie = new int[m][][];
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{0, ss.length-1, 0, -1}); // [start, end, len, parent]
		int[] lq = new int[ss.length];
		int p = 0;
		int r = 1;
		while(!q.isEmpty()){
			int[] cur = q.poll();
			int from = cur[0];
			int lp = 0;
			for(int i = cur[0];i <= cur[1];i++){
				if(i == cur[1] || !(
						(ss[i].length == cur[2] && ss[i+1].length == cur[2]) || 
						(ss[i].length > cur[2] && ss[i+1].length > cur[2] && ss[i][cur[2]] == ss[i+1][cur[2]])
						)){
					if(ss[i].length > cur[2]){
						lq[lp++] = i;
						q.add(new int[]{from, i, cur[2]+1, p});
					}
					from = i+1;
				}
				
			}
			
			trie[p] = new int[2][lp];
			for(int i = 0;i < lp;i++){
				trie[p][0][i] = ss[lq[i]][cur[2]]-'a';
				trie[p][1][i] = r++;
			}
			p++;
		}
		
		return Arrays.copyOf(trie, p);
	}
	
	public static int[] buildFailure(int[][][] trie)
	{
		Queue<Integer> q = new ArrayDeque<Integer>();
		q.add(0);
		int[] failure = new int[trie.length];
		Arrays.fill(failure, -1);
		failure[0] = 0;
		while(q.size() > 0) {
			int cur = q.poll();
			for(int j = 0;j < trie[cur][0].length;j++){
				int nex = trie[cur][1][j];
				int c = trie[cur][0][j];
				
				q.add(nex);
				if(cur == 0){
					failure[nex] = 0;
				}else{
					int fc = failure[cur];
					for(;fc != 0 && next(trie, fc, c) == -1;fc = failure[fc]);
					int nn = next(trie, fc, c);
					failure[nex] = nn == -1 ? 0 : nn;
				}
			}
		}
		return failure;
	}
	
	public static int next(int[][][] trie, int cur, int q)
	{
		int ind = Arrays.binarySearch(trie[cur][0], q);
		return ind >= 0 ? trie[cur][1][ind] : -1;
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
	
	public static void main(String[] args) throws Exception
	{
		new E().run();
	}
	
	public int ni()
	{
		try {
			int num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public long nl()
	{
		try {
			long num = 0;
			boolean minus = false;
			while((num = is.read()) != -1 && !((num >= '0' && num <= '9') || num == '-'));
			if(num == '-'){
				num = 0;
				minus = true;
			}else{
				num -= '0';
			}
			
			while(true){
				int b = is.read();
				if(b >= '0' && b <= '9'){
					num = num * 10 + (b - '0');
				}else{
					return minus ? -num : num;
				}
			}
		} catch (IOException e) {
		}
		return -1;
	}
	
	public String ns()
	{
		try{
			int b = 0;
			StringBuilder sb = new StringBuilder();
			while((b = is.read()) != -1 && (b == '\r' || b == '\n' || b == ' '));
			if(b == -1)return "";
			sb.append((char)b);
			while(true){
				b = is.read();
				if(b == -1)return sb.toString();
				if(b == '\r' || b == '\n' || b == ' ')return sb.toString();
				sb.append((char)b);
			}
		} catch (IOException e) {
		}
		return "";
	}
	
	public char[] ns(int n)
	{
		char[] buf = new char[n];
		try{
			int b = 0, p = 0;
			while((b = is.read()) != -1 && (b == ' ' || b == '\r' || b == '\n'));
			if(b == -1)return null;
			buf[p++] = (char)b;
			while(p < n){
				b = is.read();
				if(b == -1 || b == ' ' || b == '\r' || b == '\n')break;
				buf[p++] = (char)b;
			}
			return Arrays.copyOf(buf, p);
		} catch (IOException e) {
		}
		return null;
	}
	
	
	double nd() { return Double.parseDouble(ns()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}