//package round151;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Map;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		Map<String, Integer> map = new HashMap<String, Integer>();
		int[] ids = new int[n+1];
		ids[n] = n;
		int u = 0;
		int[] par = new int[n+1];
		for(int i = 0;i < n;i++){
			String name = ns();
			if(!map.containsKey(name))map.put(name, u++);
			ids[i] = map.get(name);
			par[i] = ni()-1;
			if(par[i] == -1)par[i] = n;
		}
		par[n] = -1;
		int[][] ch = parentToChildren(par);
		
		int[] ord = new int[n+1];
		int[] dep = new int[n+1];
		Queue<Integer> qq = new ArrayDeque<Integer>();
		qq.add(n);
		int p = 0;
		while(!qq.isEmpty()){
			int cur = qq.poll();
			ord[p++] = cur;
			for(int e : ch[cur]){
				dep[e] = dep[cur] + 1;
				qq.add(e);
			}
		}
//		tr("ids", ids);
//		tr(ord);
//		tr(dep);
		
		int[] iord = new int[n+1];
		for(int i = 0;i < n+1;i++)iord[ord[i]] = i;
		
//		tr(iord);
		int[][] lp = logstepParents(par);
		int m = ni();
		int[][] q = new int[m][];
		for(int z = 0;z < m;z++){
			int v = ni()-1;
			int k = ni();
			int d = dep[v] + k;
			int sup, inf;
			{
				int low = -1, high = n+1;
				while(high - low > 1){
					int x = (high+low)/2;
					int y = ord[x];
//					tr(x, y, ancestor(y, k, lp));
					if(dep[y] > d || (dep[y] == d && iord[ancestor(y, k, lp)] > iord[v])){
						high = x;
					}else{
						low = x;
					}
				}
				sup = low;
			}
			{
				int low = -1, high = n+1;
				while(high - low > 1){
					int x = (high+low)/2;
					int y = ord[x];
					if(dep[y] > d || (dep[y] == d && iord[ancestor(y, k, lp)] >= iord[v])){
						high = x;
					}else{
						low = x;
					}
				}
				inf = high;
			}
//			tr(inf, sup);
			q[z] = new int[]{inf, sup, z};
		}
		
		final int S = (int)Math.sqrt(n);
		Arrays.sort(q, new Comparator<int[]>() {
			public int compare(int[] a, int[] b) {
				if(a[0]/S == b[0]/S){
					return a[1] - b[1];
				}else{
					return a[0] - b[0];
				}
			}
		});
		
		int s = 0, t = -1;
		int[] ct = new int[n+1];
		int[] ret = new int[m];
		int dis = 0;
		for(int i = 0;i < m;i++){
			int[] c = q[i];
			while(t < c[1]){
				t++;
				ct[ids[ord[t]]]++;
				if(ct[ids[ord[t]]] == 1)dis++;
			}
			while(s > c[0]){
				s--;
				ct[ids[ord[s]]]++;
				if(ct[ids[ord[s]]] == 1)dis++;
			}
			while(t > c[1]){
				ct[ids[ord[t]]]--;
				if(ct[ids[ord[t]]] == 0)dis--;
				t--;
			}
			while(s < c[0]){
				ct[ids[ord[s]]]--;
				if(ct[ids[ord[s]]] == 0)dis--;
				s++;
			}
			ret[c[2]] = dis;
//			tr(i, c, dis, ct);
		}
		
		for(int i = 0;i < m;i++){
			out.println(ret[i]);
		}
	}
	
	protected static int ancestor(int a, int m, int[][] spar)
	{
		for(int i = 0;m > 0 && a != -1;m>>>=1,i++){
			if((m&1)==1)a = spar[i][a];
		}
		return a;
	}
	
	/**
	 * 2^k
	 * @param par
	 * @return
	 */
	public static int[][] logstepParents(int[] par)
	{
		int n = par.length;
		int m = Integer.numberOfTrailingZeros(Integer.highestOneBit(n-1))+1;
		int[][] pars = new int[m][n];
		pars[0] = par;
		for(int j = 1;j < m;j++){
			for(int i = 0;i < n;i++){
				pars[j][i] = pars[j-1][i] == -1 ? -1 : pars[j-1][pars[j-1][i]];
			}
		}
		return pars;
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
	
	
	void run() throws Exception
	{
//		int n = 100000, m = 99999;
//		Random gen = new Random();
//		StringBuilder sb = new StringBuilder();
//		sb.append(n + " ");
//		for(int i = 0;i < n;i++){
//			sb.append(gen.nextInt(10) + " " + gen.nextInt(i+1) + " ");
//		}
//		sb.append(m + " ");
//		for(int i = 0;i < m;i++){
//			sb.append((gen.nextInt(n)+1) + " " + (gen.nextInt(3)+1) + " ");
//		}
//		INPUT = sb.toString();
		
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