//package educational.round72;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.Random;
import java.util.Set;

public class F {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni(), m = ni();
		DynamicConnectivity10ForCheck dc = new DynamicConnectivity10ForCheck(n);
		int last = 0;
		Set<Long> es = new HashSet<>();
		for(int i = 0;i < m;i++) {
			int t = ni();
			if(t == 1) {
				int x = (ni()+last)%n, y = (ni()+last)%n;
				if(x > y) {
					int d = x; x = y; y = d;
				}
				long code = (long)x<<32|y;
				if(es.contains(code)) {
					es.remove(code);
					dc.delete(x, y);
				}else {
					dc.union(x, y);
					es.add(code);
				}
			}else {
				int x = (ni()+last)%n, y = (ni()+last)%n;
				last = dc.areConnected(x, y) ? 1 : 0;
				out.print(last);
			}
		}
	}
	
	public static class DynamicConnectivity10ForCheck {
		public static Random gen = new Random();
		public int gctReroot = 0;
		public int gctCon = 0;
		public int gctUTEL = 0;
		public int gctLink = 0;
		public int gctCollect = 0;
		public static int gctMerge = 0;
		public static int gctSplit = 0;
		int[] collected;
		
		public DynamicConnectivity10ForCheck(int n) {
			lvs = new Level[20];
			lvs[0] = new Level(n);
			
			bank = new IntHashMap[n];
			for(int i = 0;i < n;i++){
				bank[i] = new IntHashMap();
			}
			collected = new int[n];
		}
		
		public static class Level
		{
			public Node[] forest;
			public AuxiliaryEdge[] auxis;
			public int[] nauxis;

			public Level(int n)
			{
				this.forest = new Node[n];
				this.auxis = new AuxiliaryEdge[n];
				this.nauxis = new int[n];
			}
		}
		public Level[] lvs;
		public IntHashMap[] bank;
		
		public boolean union(int x, int y)
		{
			if(x == y)return false;
			if(x > y){
				int d = x; x = y; y = d;
			}
			NodeInfo info = (NodeInfo)bank[x].get(y);
			if(info != null){
				info.dup++;
				return false;
			}else if(areConnected(x, y)){ // new auxiliary edge
				info = new NodeInfo(x, y, 1, 0, false);
				info.ft = new AuxiliaryEdge(y);
				info.tf = new AuxiliaryEdge(x);
				bank[x].put(y, info);
				insertToAuxis(info);
				return false;
			}else{ // new tree edge
				info = new NodeInfo(x, y, 1, 0, true);
				bank[x].put(y, info);
				info.zero = link(x, y, 0, info);
				return true;
			}
		}
		
		static public class AuxiliaryEdge
		{
			public int to;
			public AuxiliaryEdge prev, next;
			
			public AuxiliaryEdge(int to) {
				this.to = to;
			}
		}

		static public class NodeInfo
		{
			public int from, to;
			public int dup;
			public int level;
			public boolean isTreeNode;
			public Node zero;
			public AuxiliaryEdge ft, tf;
			
			public NodeInfo(int from, int to, int dup, int level, boolean isTreeNode) {
				this.from = from;
				this.to = to;
				this.dup = dup;
				this.level = level;
				this.isTreeNode = isTreeNode;
			}
		}
		
		static public class Node
		{
			public int from, to;
			public int priority;
			public Node left, right, parent; // info of Treap
			public Node reverse, prev, next, up; // reverse edge, prev node in forest(has same 'from'), next node in forest, uplevel node
			
			public NodeInfo info;
			public Level level;
			public int desptn;
			public int desaux;
			
			public int count;
			
			private Node(int from, int to, NodeInfo info, Level level)
			{
				this.from = from; this.to = to;
				this.info = info;
				priority = gen.nextInt();
				this.level = level;
				update(this);
			}
			
			@Override
			public String toString() {
				return "Node [from=" + from + ", to=" + to + ", desptn=" + desptn
						+ ", desaux=" + desaux + ", count=" + count + "]";
			}
		}
		
		private void insertToAuxis(NodeInfo info)
		{
			{
				AuxiliaryEdge next = lvs[info.level].auxis[info.from];
				lvs[info.level].auxis[info.from] = info.ft;
				lvs[info.level].nauxis[info.from]++;
				info.ft.next = next;
				if(next != null)next.prev = info.ft;
				info.ft.prev = null;
				updateForestIns(info.level, info.from);
			}
			{
				AuxiliaryEdge next = lvs[info.level].auxis[info.to];
				lvs[info.level].auxis[info.to] = info.tf;
				lvs[info.level].nauxis[info.to]++;
				info.tf.next = next;
				if(next != null)next.prev = info.tf;
				info.tf.prev = null;
				updateForestIns(info.level, info.to);
			}
		}
		
		private void removeFromAuxis(NodeInfo info)
		{
			{
				if(lvs[info.level].auxis[info.from] == info.ft){
					lvs[info.level].auxis[info.from] = info.ft.next;
				}
				lvs[info.level].nauxis[info.from]--;
				AuxiliaryEdge next = info.ft.next;
				AuxiliaryEdge prev = info.ft.prev;
				if(next != null)next.prev = prev;
				if(prev != null)prev.next = next;
				updateForestRem(info.level, info.from);
			}
			{
				if(lvs[info.level].auxis[info.to] == info.tf){
					lvs[info.level].auxis[info.to] = info.tf.next;
				}
				lvs[info.level].nauxis[info.to]--;
				AuxiliaryEdge next = info.tf.next;
				AuxiliaryEdge prev = info.tf.prev;
				if(next != null)next.prev = prev;
				if(prev != null)prev.next = next;
				updateForestRem(info.level, info.to);
			}
		}
		
		public static long timeval = 0;
		
		private Node link(int x, int y, int level, NodeInfo info)
		{
			gctLink++;
			Node tsx = reroot(x, level);
			Node tsy = reroot(y, level);
			Node xy = new Node(x, y, info, lvs[level]);
			Node yx = new Node(y, x, info, lvs[level]);
			xy.reverse = yx;
			yx.reverse = xy;
			insertToForest(xy, level);
			insertToForest(yx, level);
			tsx = insert(tsx, count(tsx), xy);
			tsy = insert(tsy, count(tsy), yx);
			merge(tsx, tsy);
//			merge(tsx, xy, tsy, yx);
			return xy;
		}
		
		private void insertToForest(Node xy, int k)
		{
			Node[] forest = lvs[k].forest;
			if(forest[xy.from] == null){
				forest[xy.from] = xy;
				xy.prev = xy.next = null;
				update(xy); // 
			}else{
				Node z = forest[xy.from];
				Node zn = z.next;
				if(zn != null)zn.prev = xy;
				z.next = xy;
				xy.prev = z;
				xy.next = zn;
			}
		}
		
		private void removeFromForest(Node xy, int k)
		{
			Node[] forest = lvs[k].forest;
			if(forest[xy.from] == xy){
				forest[xy.from] = xy.next;
				gctSplit++;
				updateForest(k, xy.from);
			}
			Node next = xy.next;
			Node prev = xy.prev;
			if(prev != null)prev.next = next;
			if(next != null)next.prev = prev;
			xy.prev = xy.next = null;
		}
		
		private void updateForest(int k, int x)
		{
			for(Node q = lvs[k].forest[x];q != null;q = q.parent)update(q);
		}
		
		private void updateForestRem(int k, int x)
		{
			for(Node q = lvs[k].forest[x];q != null;q = q.parent)q.desaux--;
		}
		
		private void updateForestIns(int k, int x)
		{
			for(Node q = lvs[k].forest[x];q != null;q = q.parent)q.desaux++;
		}
		
		private int collect(Node cur, int p)
		{
			gctCollect++;
			if(cur == null || cur.desaux == 0)return p;
			if(cur.desaux - (cur.left != null ? cur.left.desaux : 0) - (cur.right != null ? cur.right.desaux : 0) > 0){
				collected[p++] = cur.from;
			}
			p = collect(cur.left, p);
			p = collect(cur.right, p);
			return p;
		}
		
		private boolean sample(Node cur, int k)
		{
			if(cur == null || cur.desaux == 0)return false;
			int val = gen.nextInt(cur.desaux);
			int ld = cur.left != null ? cur.left.desaux : 0;
			if(val < ld){
				boolean ret = sample(cur.left, k);
				update(cur);
				return ret;
			}
			val -= ld;
			
			int rd = cur.right != null ? cur.right.desaux : 0;
			if(val < rd){
				boolean ret = sample(cur.right, k);
				update(cur);
				return ret;
			}
			val -= rd;
			
			// edge sample
			int from = cur.from;
			for(AuxiliaryEdge aux = lvs[k].auxis[from];aux != null;){
				int to = aux.to;
				AuxiliaryEdge next = aux.next;
				if(areConnected(from, to)){
					// level up
					NodeInfo linfo = (NodeInfo)bank[Math.min(from, to)].get(Math.max(from, to));
					removeFromAuxis(linfo);
					linfo.level++;
					insertToAuxis(linfo);
				}else{
					// promote
					int f = Math.min(from, to), t = Math.max(from, to);
					NodeInfo linfo = (NodeInfo)bank[f].get(t);
					linfo.isTreeNode = true;
					removeFromAuxis(linfo);
					
					Node prev = null;
					for(int l = 0;l <= k;l++){
						Node z = link(f, t, l, linfo);
						if(l == 0){
							linfo.zero = z;
						}else{
							prev.up = z;
							prev.reverse.up = prev.up.reverse;
						}
						prev = z;
					}
					
					
					return true;
				}
				aux = next;
			}
//			updateForest(k, from);
			update(cur);
			return false;
		}
		
		private void updateTreeEdgesLevelNoRec(Node cur, int k)
		{
			if(cur == null || cur.desptn<<~k>=0)return;
			
			while(cur != null){
				gctUTEL++;
				cur.desptn &= ~(1<<k);
				cur.desptn |= 1<<k+1;
				if(cur.info.level == k && cur.from < cur.to){
					NodeInfo info = cur.info;
					info.level++;
					cur.up = link(cur.from, cur.to, k+1, info);
					cur.reverse.up = cur.up.reverse;
				}
				if(cur.left != null && cur.left.desptn<<~k<0){
					cur = cur.left;
				}else{
					Node pre = null;
					while(cur != null){
						if(cur.right != null && cur.right != pre && cur.right.desptn<<~k<0){
							cur = cur.right;
							break;
						}
						pre = cur;
						cur = cur.parent;
					}
				}
			}
		}
		
		Node[][] lts = new Node[22][2];
		
		public boolean delete(int x, int y)
		{
			if(x == y)return false;
			if(x > y){
				int d = x; x = y; y = d;
			}
			NodeInfo info = (NodeInfo)bank[x].get(y);
			if(info == null){
				// not exist
				throw new RuntimeException();
			}
			if(!info.isTreeNode){ // delete auxiliary edge
				info.dup--;
				if(info.dup == 0){
					bank[x].remove(y);
					removeFromAuxis(info);
				}
				return false;
			}
			
			// delete tree edge
			info.dup--;
			if(info.dup == 0){
				Node xy = ((NodeInfo)bank[x].get(y)).zero;
				bank[x].remove(y);
				for(int k = 0;k <= info.level;k++){
					// remove tree edge from all level
					Node up = xy.up;
					Node yx = xy.reverse;
//					timeval -= System.nanoTime();
					int ixy = index(xy);
					int iyx = index(yx);
//					timeval += System.nanoTime();
					if(ixy < iyx){
						Node[] abc_e = splitEx(yx);
						Node[] a_c = splitEx(xy);
						lts[k][0] = merge(abc_e[1], a_c[0]);
						lts[k][1] = a_c[1];
					}else{
						Node[] abc_e = splitEx(xy);
						Node[] a_c = splitEx(yx);
						lts[k][1] = merge(abc_e[1], a_c[0]);
						lts[k][0] = a_c[1];
					}
					removeFromForest(xy, k);
					removeFromForest(yx, k);
					xy = up;
				}
				
				if(lvs[info.level+1] == null)lvs[info.level+1] = new Level(bank.length);
				for(int k = info.level;k >= 0;k--){
					Node target = count(lts[k][0]) < count(lts[k][1]) ? lts[k][0] : lts[k][1];
					updateTreeEdgesLevelNoRec(target, k); // 30%
					
//					for(int z = 0;z < 20;z++){
//						if(sample(target, k))break inner;
//					}
					
					int cp = -1;
					if(target != null){
						cp = collect(target, 0);
					}else{
						collected[0] = count(lts[k][0]) == 0 ? x : y;
						cp = 1;
					}
					Arrays.sort(collected, 0, cp);
					
					for(int u = 0;u < cp;u++){
						int from = collected[u];
						for(AuxiliaryEdge aux = lvs[k].auxis[from];aux != null;){
							int to = aux.to;
							AuxiliaryEdge next = aux.next;
							if(Arrays.binarySearch(collected, 0, cp, to) >= 0){
								// level up
								NodeInfo linfo = (NodeInfo)bank[Math.min(from, to)].get(Math.max(from, to));
								removeFromAuxis(linfo);
								linfo.level++;
								insertToAuxis(linfo);
							}else{
								// promote
								int f = Math.min(from, to), t = Math.max(from, to);
								NodeInfo linfo = (NodeInfo)bank[f].get(t);
								linfo.isTreeNode = true;
								removeFromAuxis(linfo);
								
								Node prev = null;
								for(int l = 0;l <= k;l++){
									Node z = link(f, t, l, linfo);
									if(l == 0){
										linfo.zero = z;
									}else{
										prev.up = z;
										prev.reverse.up = prev.up.reverse;
									}
									prev = z;
								}
								return false;
							}
							aux = next;
						}
//						updateForest(k, from);
					}
				}
				return true;
			}
			return false;
		}
		
		public boolean areConnected(int x, int y)
		{
			gctCon++;
			if(x == y)return true;
			if(lvs[0].forest[x] == null)return false;
			if(lvs[0].forest[y] == null)return false;
			Node anyx = lvs[0].forest[x];
			Node anyy = lvs[0].forest[y];
			return root(anyx) == root(anyy);
		}
		
		private Node reroot(int x, int level)
		{
			gctReroot++;
			if(lvs[level].forest[x] == null)return null;
			Node any = lvs[level].forest[x];
			Node[] a_b = split(any);
			return merge(a_b[1], a_b[0]);
		}
		
		private Node root(Node a)
		{
			if(a == null)return null;
			while(a.parent != null)a = a.parent;
			return a;
		}
		
		private Node first(Node a)
		{
			if(a == null)return null;
			while(a.left != null)a = a.left;
			return a;
		}
		
		private static Node merge(Node a, Node b, Node... c)
		{
			Node x = merge(a, b);
			for(Node n : c)x = merge(x, n);
			return x;
		}

		private static Node update(Node a)
		{
			if(a == null)return null;
			a.count = 1;
			if(a.left != null)a.count += a.left.count;
			if(a.right != null)a.count += a.right.count;
			
			a.desptn = a.from < a.to ? 1<<a.info.level : 0;
			if(a.left != null)a.desptn |= a.left.desptn;
			if(a.right != null)a.desptn |= a.right.desptn;
			
			a.desaux = a.level.forest[a.from] == a && a.level.auxis[a.from] != null ? a.level.nauxis[a.from] : 0;
			if(a.left != null)a.desaux += a.left.desaux;
			if(a.right != null)a.desaux += a.right.desaux;
			return a;
		}
		
		private static Node disconnect(Node a)
		{
			if(a == null)return null;
			a.left = a.right = a.parent = null;
			return update(a);
		}
		
		private static int count(Node a)
		{
			return a == null ? 0 : a.count;
		}
		
		private static void setParent(Node a, Node par)
		{
			if(a != null)a.parent = par;
		}
		
		private static Node merge(Node a, Node b)
		{
			gctMerge++;
			if(b == null)return a;
			if(a == null)return b;
			if(a.priority > b.priority){
				if(a.right != null)a.right.parent = null;
				b.parent = null;
				a.right = merge(a.right, b);
				a.right.parent = a;
				return update(a);
			}else{
				a.parent = null;
				if(b.left != null)b.left.parent = null;
				b.left = merge(a, b.left);
				b.left.parent = b;
				return update(b);
			}
		}
		
//		private static Node merge(Node a, Node b)
//		{
//			gctMerge++;
//			if(b == null)return a;
//			if(a == null)return b;
//			if(a.priority > b.priority){
//				setParent(a.right, null);
//				setParent(b, null);
//				a.right = merge(a.right, b);
//				setParent(a.right, a);
//				return update(a);
//			}else{
//				setParent(a, null);
//				setParent(b.left, null);
//				b.left = merge(a, b.left);
//				setParent(b.left, b);
//				return update(b);
//			}
//		}
	//	
		// bottom up split
		public static Node[] split(Node x)
		{
			if(x == null)return new Node[]{null, null};
			if(x.left != null)x.left.parent = null;
			Node[] sp = new Node[]{x.left, x};
			x.left = null;
			update(x);
			while(x.parent != null){
				Node p = x.parent;
				x.parent = null;
				if(x == p.left){
					p.left = sp[1];
					if(sp[1] != null)sp[1].parent = p;
					sp[1] = p;
				}else{
					p.right = sp[0];
					if(sp[0] != null)sp[0].parent = p;
					sp[0] = p;
				}
				update(p);
				x = p;
			}
			return sp;
		}
		
		// split excluding me
		public static Node[] splitEx(Node x)
		{
			if(x == null)return new Node[]{null, null};
			if(x.left != null)x.left.parent = null;
			if(x.right != null)x.right.parent = null;
			Node[] sp = new Node[]{x.left, x.right};
			x.left = null;
			x.right = null;
			update(x);
			while(x.parent != null){
				Node p = x.parent;
				x.parent = null;
				if(x == p.left){
					p.left = sp[1];
					if(sp[1] != null)sp[1].parent = p;
					sp[1] = p;
				}else{
					p.right = sp[0];
					if(sp[0] != null)sp[0].parent = p;
					sp[0] = p;
				}
				update(p);
				x = p;
			}
			return sp;
		}
		
		// [0,K),[K,N)
		private static Node[] split(Node a, int K)
		{
			gctSplit++;
			if(a == null)return new Node[]{null, null};
			if(K <= count(a.left)){
				setParent(a.left, null);
				Node[] s = split(a.left, K);
				a.left = s[1];
				setParent(a.left, a);
				s[1] = update(a);
				return s;
			}else{
				setParent(a.right, null);
				Node[] s = split(a.right, K-count(a.left)-1);
				a.right = s[0];
				setParent(a.right, a);
				s[0] = update(a);
				return s;
			}
		}
		
		private static Node insert(Node a, int K, Node b)
		{
			if(a == null)return b;
			if(b.priority < a.priority){
				if(K <= count(a.left)){
					a.left = insert(a.left, K, b);
					setParent(a.left, a);
				}else{
					a.right = insert(a.right, K-count(a.left)-1, b);
					setParent(a.right, a);
				}
				return update(a);
			}else{
				Node[] ch = split(a, K);
				b.left = ch[0]; b.right = ch[1];
				setParent(b.left, b);
				setParent(b.right, b);
				return update(b);
			}
		}
		
		private static Node erase(Node a, int K)
		{
			if(a == null)return null;
			if(K < count(a.left)){
				a.left = erase(a.left, K);
				setParent(a.left, a);
				return update(a);
			}else if(K == count(a.left)){
				setParent(a.left, null);
				setParent(a.right, null);
				Node aa = merge(a.left, a.right);
				disconnect(a);
				return aa;
			}else{
				a.right = erase(a.right, K-count(a.left)-1);
				setParent(a.right, a);
				return update(a);
			}
		}
		
		private static Node get(Node a, int K)
		{
			while(a != null){
				if(K < count(a.left)){
					a = a.left;
				}else if(K == count(a.left)){
					break;
				}else{
					K = K - count(a.left)-1;
					a = a.right;
				}
			}
			return a;
		}
		
		private static int index(Node a)
		{
			if(a == null)return -1;
			int ind = count(a.left);
			while(a != null){
				Node par = a.parent;
				if(par != null && par.right == a){
					ind += count(par.left) + 1;
				}
				a = par;
			}
			return ind;
		}
		
		private static int height(Node a)
		{
			if(a == null)return 0;
			int h = 1;
			if(a.left != null)h = Math.max(h, height(a.left) + 1);
			if(a.right != null)h = Math.max(h, height(a.right) + 1);
			return h;
		}
		
		public static Node[] nodes(Node a) { return nodes(a, new Node[a.count], 0, a.count); }
		public static Node[] nodes(Node a, Node[] ns, int L, int R)
		{
			if(a == null)return ns;
			nodes(a.left, ns, L, L+count(a.left));
			ns[L+count(a.left)] = a;
			nodes(a.right, ns, R-count(a.right), R);
			return ns;
		}
		
		public static String toString(Node a, String indent)
		{
			if(a == null)return "";
			StringBuilder sb = new StringBuilder();
			sb.append(toString(a.left, indent + "  "));
			sb.append(indent).append(a).append("\n");
			sb.append(toString(a.right, indent + "  "));
			return sb.toString();
		}
		
		public String toDot()
		{
			StringBuilder sb = new StringBuilder("graph{\n");
			sb.append("graph[rankdir=LR];\n");
			sb.append("node[shape=circle];\n");
			
			for(int i = 0;i < 20;i++){
				Level lv = lvs[i];
				for(Node node : lv.forest){
					if(node != null){
//						if(node.up == null && node.from < node.to){
						if(node.from < node.to){
							sb.append("\"" + node.from + "\"")
							.append("--")
							.append("\"" + node.to + "\"")
							.append("[label=\"" + i +"\"];\n");
						}
						for(Node x = node.next;x != node;x = x.next){
//							if(x.up == null && x.from < x.to){
							if(x.from < x.to){
								sb.append("\"" + x.from + "\"")
								.append("--")
								.append("\"" + x.to + "\"")
								.append("[label=\"" + i +"\"];\n");
							}
						}
					}
				}
//				for(int from = 0;from < lv.auxis.size();from++){
//					if(lv.auxis.get(from) != null){
//						for(int to : lv.auxis.get(from)){
//							if(from < to){
//								sb.append("\"" + from + "\"")
//								.append("--")
//								.append("\"" + to + "\"")
//								.append("[style=dashed,label=\"" + i +"\"];\n");
//							}
//						}
//					}
//				}
			}
			sb.append("}\n");
			return sb.toString();
		}
		
		public static class IntHashMap {
			public int[] keys;
			public Object[] allocated;
			private int scale = 1<<2;
			private int rscale = 1<<1;
			private int mask = scale-1;
			public int size = 0;
			
			public IntHashMap(){
				allocated = new Object[scale];
				keys = new int[scale];
			}
			
			public boolean containsKey(int x)
			{
				int pos = h(x)&mask;
				while(allocated[pos] != null){
					if(x == keys[pos])return true;
					pos = pos+1&mask;
				}
				return false;
			}
			
			public Object get(int x)
			{
				int pos = h(x)&mask;
				while(allocated[pos] != null){
					if(x == keys[pos])return allocated[pos];
					pos = pos+1&mask;
				}
				return null;
			}
			
			public Object put(int x, Object v)
			{
				int pos = h(x)&mask;
				while(allocated[pos] != null){
					if(x == keys[pos]){
						Object oldval = allocated[pos];
						allocated[pos] = v;
						return oldval;
					}
					pos = pos+1&mask;
				}
				if(size == rscale){
					resizeAndPut(x, v);
				}else{
					keys[pos] = x;
					allocated[pos] = v;
				}
				size++;
				return null;
			}
			
			public boolean remove(int x)
			{
				int pos = h(x)&mask;
				while(allocated[pos] != null){
					if(x == keys[pos]){
						size--;
						// take last and fill rmpos
						int last = pos;
						pos = pos+1&mask;
						while(allocated[pos] != null){
							int lh = h(keys[pos])&mask;
							// lh <= last < pos
							if(
									lh <= last && last < pos ||
									pos < lh && lh <= last ||
									last < pos && pos < lh
									){
								keys[last] = keys[pos];
								allocated[last] = allocated[pos];
								last = pos;
							}
							pos = pos+1&mask;
						}
						keys[last] = 0;
						allocated[last] = null;
						
						return true;
					}
					pos = pos+1&mask;
				}
				return false;
			}
			
			private void resizeAndPut(int x, Object v)
			{
				int nscale = scale<<1;
				int nrscale = rscale<<1;
				int nmask = nscale-1;
				Object[] nallocated = new Object[nscale];
				int[] nkeys = new int[nscale];
				itrreset();
				while(true){
					int y = next();
					if(end())break;
					int pos = h(y)&nmask;
					while(nallocated[pos] != null)pos = pos+1&nmask;
					nkeys[pos] = y;
					nallocated[pos] = allocated[itr];
				}
				{
					int pos = h(x)&nmask;
					while(nallocated[pos] != null)pos = pos+1&nmask;
					nkeys[pos] = x;
					nallocated[pos] = v;
				}
				allocated = nallocated;
				keys = nkeys;
				scale = nscale;
				rscale = nrscale;
				mask = nmask;
			}
			
			public int itr = -1;
			
			public void itrreset() { itr = -1; }
			public boolean end() { return itr == -1; }
			
			private static int NG = Integer.MIN_VALUE;
			public int next() {
				while(++itr < scale && allocated[itr] == null);
				if(itr == scale){
					itr = -1;
					return NG;
				}
				return keys[itr];
			}
			
			public int h(int x)
			{
				x ^= x>>>16;
				x *= 0x85ebca6b;
				x ^= x>>>13;
				x *= 0xc2b2ae35;
				x ^= x>>>16;
				return x;
			}
			
//			private long h(long x)
//			{
//				x ^= x>>>33;
//				x *= 0xff51afd7ed558ccdL;
//				x ^= x>>>33;
//				x *= 0xc4ceb9fe1a85ec53L;
//				x ^= x>>>33;
//				return x;
//			}
			
			@Override
			public String toString()
			{
				itrreset();
				int[] vals = new int[size];
				int p = 0;
				while(true){
					int y = next();
					if(end())break;
					vals[p++] = y;
				}
				return Arrays.toString(vals);
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
	
	public static void main(String[] args) throws Exception { new F().run(); }
	
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