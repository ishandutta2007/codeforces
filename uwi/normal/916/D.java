//package round457;
import java.io.BufferedReader;
import java.io.ByteArrayInputStream;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

public class D {
	BufferedReader br;
	PrintWriter out;
	String INPUT = "";
	
	void solve() throws Exception
	{
		int Q = Integer.parseInt(br.readLine());
		PersistentArray pa = new PersistentArray(-1, Q+1, Q);
		PersistentDynamicSegmentTreeRSQSimple pdst = new PersistentDynamicSegmentTreeRSQSimple(2*Q, 31);
		Map<String, Integer> map = new HashMap<>(); // for id
		int[] eidspa = new int[Q+1];
		int[] eidspdst = new int[Q+1];
		Arrays.fill(eidspa, -1);
		Arrays.fill(eidspdst, -1);
		eidspa[0] = pa.eidgen-1;
		eidspdst[0] = pdst.egen-1;
		int idgen = 0;
		for(int z = 0;z < Q;z++){
			String[] sp = br.readLine().split(" ");
			if(sp[0].equals("set")){
				String key = sp[1];
				int val = Integer.parseInt(sp[2]);
				if(!map.containsKey(key)){
					map.put(key, idgen++);
				}
				int id = map.get(key);
				
				int prev = pa.get(eidspa[z], id);
				if(prev != -1){
					pdst.add(eidspdst[z], prev, -1);
					pdst.add(val, 1);
				}else{
					pdst.add(eidspdst[z], val, 1);
				}
				
				pa.set(eidspa[z], id, val);
				
				eidspa[z+1] = pa.eidgen-1;
				eidspdst[z+1] = pdst.egen-1;
			}else if(sp[0].equals("remove")){
				String key = sp[1];
				if(!map.containsKey(key)){
					map.put(key, idgen++);
				}
				int id = map.get(key);
				
				int prev = pa.get(eidspa[z], id);
				if(prev != -1){
					pdst.add(eidspdst[z], prev, -1);
					eidspdst[z+1] = pdst.egen-1;
				}else{
					eidspdst[z+1] = eidspdst[z];
				}
				
				pa.set(eidspa[z], id, -1);
				eidspa[z+1] = pa.eidgen-1;
			}else if(sp[0].equals("query")){
				String key = sp[1];
				if(!map.containsKey(key)){
					map.put(key, idgen++);
				}
				int id = map.get(key);
				int val = pa.get(eidspa[z], id);
				if(val == -1){
					out.println(-1);
					out.flush();
				}else{
					out.println(pdst.sum(eidspdst[z], 0L, val));
					out.flush();
				}
				eidspa[z+1] = eidspa[z];
				eidspdst[z+1] = eidspdst[z];
			}else if(sp[0].equals("undo")){
				int to = z - Integer.parseInt(sp[1]);
				eidspa[z+1] = eidspa[to];
				eidspdst[z+1] = eidspdst[to];
			}else{
				throw new RuntimeException();
			}
		}
	}
	
	public static class PersistentDynamicSegmentTreeRSQSimple {
		public int[] vals;
		public int[] ls;
		public int[] rs;
		public int[] entries;
		public int gen;
		public int height;
		public int egen;
		
		public PersistentDynamicSegmentTreeRSQSimple(int q, int height)
		{
			int bufsize = q * (height+1) + 1;
			this.vals = new int[bufsize];
			this.ls = new int[bufsize];
			this.rs = new int[bufsize];
			this.entries = new int[q+1];
			Arrays.fill(this.ls, -1);
			Arrays.fill(this.rs, -1);
			this.height = height;
			gen = 0;
			egen = 0;
			vals[gen++] = 0;
			entries[egen++] = 0;
		}
		
		public void add(long x, int v)
		{
			entries[egen] = addDfs(entries[egen-1], x, v, height-1);
			egen++;
		}
		
		public void add(int eid, long x, int v)
		{
			entries[egen] = addDfs(entries[eid], x, v, height-1);
			egen++;
		}
		
		private int clone(int id)
		{
			vals[gen] = vals[id];
			ls[gen] = ls[id];
			rs[gen] = rs[id];
			return gen++;
		}
		
		private int addDfs(int id, long x, int v, int d)
		{
			id = id == -1 ? gen++ : clone(id);
			if(d == -1){
				vals[id] += v;
			}else{
				if(x<<~d<0){
					rs[id] = addDfs(rs[id], x, v, d-1);
				}else{
					ls[id] = addDfs(ls[id], x, v, d-1);
				}
				propagate(id);
			}
			return id;
		}
		
		private int val(int id){ return id == -1 ? 0 : vals[id]; }
		private int L(int id){ return id == -1 ? -1 : ls[id]; }
		private int R(int id){ return id == -1 ? -1 : rs[id]; }
		
		private void propagate(int id)
		{
			if(id == -1)return;
			vals[id] = val(ls[id]) + val(rs[id]);
		}
		
		// K:0-indexed
		public long parallelKth(int e1, int e2, int K)
		{
			int eid1 = entries[e1], eid2 = entries[e2];
			if(K >= val(eid2)-val(eid1))return -1;
			long val = 0;
			for(int d = height-1;d >= 0;d--){
				val = val<<1;
				if(K >= val(L(eid2)) - val(L(eid1))){
					K -= val(L(eid2)) - val(L(eid1));
					eid1 = R(eid1); eid2 = R(eid2);
					val |= 1L;
				}else{
					eid1 = L(eid1); eid2 = L(eid2);
				}
			}
			// leaf value = val
			// leaf freq = val(eid2)-val(eid1)
			// k in leaf = K(0-indexed) 
			return val;
		}
//		
//		public long sum(int l, int r)
//		{
//			return sum(l, r, height-1, 0);
//		}
//		
//		private long sum(int l, int r, int d, int id)
//		{
//			if(l <= 0 && r >= 1<<d+1){
//				return vals[id];
//			}else{
//				// [l,r), [0,1<<d-1)
//				long ret = 0;
//				if(l < 1<<d && 0 < r && L(id) != -1){
//					ret += sum(l, r, d-1, L(id));
//				}
//				if(l < 1<<d+1 && 1<<d < r && R(id) != -1){
//					ret += sum(l-(1<<d), r-(1<<d), d-1, R(id));
//				}
//				return ret;
//			}
//		}
		
		public long sum(int eid, long l, long r)
		{
			return sumDfs(entries[eid], l, r, 0L, 1L<<height);
		}
		
		private long sumDfs(int id, long l, long r, long cl, long cr)
		{
			if(id == -1)return 0;
			if(l <= cl && cr <= r){
				return vals[id];
			}else{
				long ret = 0;
				long mid = cl+cr>>>1;
				if(cl < r && l < mid){
					ret += sumDfs(ls[id], l, r, cl, mid);
				}
				if(mid < r && l < cr){
					ret += sumDfs(rs[id], l, r, mid, cr);
				}
				return ret;
			}
		}
	}
	
	public static class PersistentArray {
		public int K = 2; // 2^K-partitioned tree
		public int[] shifts; // height*K
		public int[] vals;
		public int[][] child; // [child-number][parent]
		public int idgen;
		public int[] entries;
		public int eidgen;
		public static int I = Integer.MAX_VALUE;
		public int n;
		
		public PersistentArray(int[] a, int Q) {
			n = a.length;
			int m = 0;
			int dep = 0;
			for(int u = n;u > 0;u>>>=K){
				m += u+1;
				dep++;
			}
			m += Q*(dep+1);
			vals = new int[m];
			child = new int[1<<K][m];
			entries = new int[Q+1];
			shifts = new int[m];
			eidgen = 0;
			idgen = 0;
			for(int i = 0;i < 1<<K;i++)Arrays.fill(child[i], -1);
			Arrays.fill(entries, -1);
			
			for(int i = 0;i < a.length;i++){
				vals[idgen] = a[i];
				shifts[idgen] = 0;
				idgen++;
			}
			int tail = 0;
			while(true){
				int head = idgen;
				if(head-tail <= 1)break;
				int nshift = shifts[tail] + K;
				while(tail < head){
					vals[idgen] = I;
					shifts[idgen] = nshift;
					for(int i = 0;i < 1<<K && tail < head;i++, tail++){
						child[i][idgen] = tail;
					}
					idgen++;
				}
				tail = head;
			}
			entries[eidgen++] = idgen-1;
		}
		
		public PersistentArray(int val, int n, int Q) {
			this.n = n;
			int m = 0;
			int dep = 0;
			for(int u = n;u > 0;u>>>=K){
				m += u+1;
				dep++;
			}
			m += Q*(dep+1);
			m -= n-1;
			vals = new int[m];
			child = new int[1<<K][m];
			entries = new int[Q+1];
			shifts = new int[m];
			eidgen = 0;
			idgen = 0;
			for(int i = 0;i < 1<<K;i++)Arrays.fill(child[i], -1);
			Arrays.fill(entries, -1);
			
			vals[idgen] = val;
			shifts[idgen] = 0;
			idgen++;
			
			int tail = -n+1;
			while(true){
				int head = idgen;
				if(head-tail <= 1)break;
				int nshift = shifts[Math.max(0, tail)] + K;
				while(tail < head){
					vals[idgen] = I;
					shifts[idgen] = nshift;
					for(int i = 0;i < 1<<K && tail < head;i++, tail++){
						child[i][idgen] = Math.max(0, tail);
					}
					idgen++;
				}
				tail = head;
			}
			entries[eidgen++] = idgen-1;
		}
		
		public int get(int eid, int pos)
		{
			int cur = entries[eid];
			while(shifts[cur] > 0){
				cur = child[pos>>>shifts[cur]-K&(1<<K)-1][cur];
			}
			return vals[cur];
		}
		
		public int set(int eid, int pos, int value)
		{
			entries[eidgen] = setdfs(entries[eid], pos, value);
			return eidgen++;
		}
		
		private int clone(int cur)
		{
			vals[idgen] = vals[cur];
			shifts[idgen] = shifts[cur];
			for(int i = 0;i < 1<<K;i++){
				child[i][idgen] = child[i][cur];
			}
			return idgen++;
		}
		
		private int setdfs(int cur, int pos, int value)
		{
			int cloned = clone(cur);
			if(shifts[cloned] > 0){
				int chind = pos>>>shifts[cloned]-K&(1<<K)-1;
				child[chind][cloned] = setdfs(child[chind][cloned], pos, value);
			}else{
				vals[cloned] = value;
			}
			return cloned;
		}
		
		public String toString(int eid) {
			int[] vals = new int[n];
			for(int i = 0;i < n;i++){
				vals[i] = get(eid, i);
			}
			return Arrays.toString(vals);
		}
	}
	
	void run() throws Exception
	{
		br = oj ? new BufferedReader(new InputStreamReader(System.in)) : 
			new BufferedReader(new InputStreamReader(new ByteArrayInputStream(INPUT.getBytes())));
		out = new PrintWriter(System.out);
		
		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception { new D().run(); }
	
	private boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	private void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}