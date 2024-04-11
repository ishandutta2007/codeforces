//package round150;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.InputMismatchException;
import java.util.List;
import java.util.Set;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] map = nm(n,n);
		
		Node root = universal(n);
		for(int i = 0;i < n;i++){
			Set<Integer> set = new HashSet<>();
			for(int j = 0;j < n;j++){
				if(map[i][j] == '1'){
					set.add(j);
				}
			}
			root = reduce(root, set);
		}
		if(root == null){
			out.println("NO");
		}else{
			out.println("YES");
			List<Integer> f = root.frontier();
			for(int i = 0;i < n;i++){
				for(int j = 0;j < n;j++){
					out.print(map[i][f.get(j)]);
				}
				out.println();
			}
		}
	}
	
	public static enum NodeType
	{
		LEAF, P, Q;
	}
	
	public static class Node
	{
		public NodeType type; // 0=leaf, 1=P, 2=Q
		public int id;
		public List<Node> children;
		
		public Node(int id) {
			this.type = NodeType.LEAF;
			this.id = id;
		}
		
		public Node(NodeType type, List<Node> children) {
			this.type = type;
			this.children = children;
		}
		
		public Node reverse()
		{
			for(int i = 0, j = children.size()-1;i < j;i++,j--){
				Node L = children.get(i);
				Node R = children.get(j);
				children.set(j, L);
				children.set(i, R);
			}
			return this;
		}
		
		public List<Integer> frontier()
		{
			List<Integer> ret = new ArrayList<Integer>();
			return frontierdfs(ret);
		}
		
		private List<Integer> frontierdfs(List<Integer> f)
		{
			if(this.type == NodeType.LEAF){
				f.add(this.id);
				return f;
			}else{
				for(Node c : this.children)c.frontierdfs(f);
				return f;
			}
		}

		@Override
		public String toString() {
			if(type == NodeType.LEAF){
				return "" + id;
			}else if(type == NodeType.P){
				StringBuilder sb = new StringBuilder("(");
				assert this.children.size() >= 1;
				for(Node c : this.children){
					sb.append(c.toString());
					sb.append(",");
				}
				sb.deleteCharAt(sb.length()-1);
				sb.append(")");
				return sb.toString();
			}else{
				StringBuilder sb = new StringBuilder("[");
				assert this.children.size() >= 1;
				for(Node c : this.children){
					sb.append(c.toString());
					sb.append(",");
				}
				sb.deleteCharAt(sb.length()-1);
				sb.append("]");
				return sb.toString();
			}
		}
	}
	
	public static Node universal(int n)
	{
		Node root = new Node(NodeType.P, new ArrayList<Node>());
		for(int i = 0;i < n;i++)root.children.add(new Node(i));
		return root;
	}
	
	public static Node reduce(Node root, Set<Integer> S)
	{
		if(root == null)return null;
		try{
			DFSResult res = dfs(root, S);
			return res.node;
		}catch(NoMatchError e){
			return null;
		}
	}
	
	@SuppressWarnings("serial")
	private static class NoMatchError extends Error{};
	
	private static class DFSResult
	{
		Node node;
		int nins;
		int des;
		boolean nomore;
		
		public DFSResult(Node node, int nins, int des, boolean nomore) {
			this.node = node;
			this.nins = nins;
			this.des = des;
			this.nomore = nomore;
		}
	}
	
	public static DFSResult dfs(Node root, Set<Integer> S)
	{
		if(root.type == NodeType.LEAF){
			int ins = S.contains(root.id) ? 1 : 0;
			return new DFSResult(root, ins, 1, ins == S.size());
		}else if(root.type == NodeType.P){
			List<Node> fulls = new ArrayList<>();
			List<Node> empties = new ArrayList<>();
			List<Node> partials = new ArrayList<>();
			int nins = 0;
			int des = 0;
			for(int i = 0;i < root.children.size();i++){
				DFSResult res = dfs(root.children.get(i), S);
				root.children.set(i, res.node);
				if(res.nomore)return new DFSResult(root, -1, -1, true);
				nins += res.nins;
				des += res.des;
				if(res.nins == res.des){
					fulls.add(res.node);
				}else if(res.nins == 0){
					empties.add(res.node);
				}else{
					partials.add(res.node);
					if(partials.size() > 2)throw new NoMatchError();
				}
			}
			if(fulls.size() == root.children.size()){
				return new DFSResult(root, nins, des, nins == S.size());
			}
			if(empties.size() == root.children.size()){
				return new DFSResult(root, 0, des, nins == S.size());
			}
			if(nins == S.size()){
				// root = ROOT(T,S)
				if(partials.isEmpty()){
					if(fulls.size() > 1){
						root.children = empties;
						Node f = new Node(NodeType.P, fulls);
						root.children.add(f);
					}
				}else if(partials.size() == 1){
					assert partials.get(0).type == NodeType.Q;
					if(fulls.size() >= 1){
						root.children = empties;
						root.children.addAll(partials);
						Node f = fulls.size() > 1 ? new Node(NodeType.P, fulls) : fulls.get(0);
						partials.get(0).children.add(f); // E-F
						if(root.children.size() == 1){
							root = partials.get(0);
						}
					}
				}else if(partials.size() == 2){
					assert partials.get(0).type == NodeType.Q;
					assert partials.get(1).type == NodeType.Q;
					root.children = empties;
					root.children.add(partials.get(0));
					if(fulls.size() >= 1){
						Node f = fulls.size() > 1 ? new Node(NodeType.P, fulls) : fulls.get(0);
						partials.get(0).children.add(f); // E-F
					}
					partials.get(0).children.addAll(partials.get(1).reverse().children);
				}
			}else{
				if(partials.isEmpty()){
					Node L = empties.size() > 1 ? new Node(NodeType.P, empties) : empties.get(0);
					Node R = fulls.size() > 1 ? new Node(NodeType.P, fulls) : fulls.get(0);
					Node ret = new Node(NodeType.Q, new ArrayList<Node>());
					ret.children.add(L);
					ret.children.add(R);
					root = ret;
				}else if(partials.size() == 1){
					assert partials.get(0).type == NodeType.Q;
					Node ret = partials.get(0);
					if(empties.size() >= 1){
						Node e = empties.size() > 1 ? new Node(NodeType.P, empties) : empties.get(0);
						ret.children.add(0, e);
					}
					if(fulls.size() >= 1){
						Node f = fulls.size() > 1 ? new Node(NodeType.P, fulls) : fulls.get(0);
						ret.children.add(f);
					}
					root = ret;
				}else if(partials.size() == 2){
					throw new NoMatchError();
				}
			}
			
			return new DFSResult(root, nins, des, nins == S.size());
		}else if(root.type == NodeType.Q){
			List<Node> fulls = new ArrayList<>();
			List<Node> empties = new ArrayList<>();
			List<Node> partials = new ArrayList<>();
			int nins = 0;
			int des = 0;
			// EEPFFPEE
			DFSResult[] ress = new DFSResult[root.children.size()];
			int firstF = -1;
			int lastF = -1;
			int lastP = -1;
			for(int i = 0;i < root.children.size();i++){
				DFSResult res = dfs(root.children.get(i), S);
				root.children.set(i, res.node);
				if(res.nomore)return new DFSResult(root, -1, -1, true);
				nins += res.nins;
				des += res.des;
				ress[i] = res;
				
				if(res.nins == res.des){
					if(firstF == -1)firstF = i;
					lastF = i;
					fulls.add(res.node);
				}else if(res.nins == 0){
					empties.add(res.node);
				}else{
					lastP = i;
					partials.add(res.node);
					if(partials.size() > 2)throw new NoMatchError();
				}
			}
			
			// validation
			if(firstF != -1){
				// FFF
				if(lastF - firstF + 1 != fulls.size())throw new NoMatchError();
				int np = 0;
				if(firstF - 1 >= 0 && ress[firstF-1].nins > 0)np++;
				if(lastF + 1 < root.children.size() && ress[lastF + 1].nins > 0)np++;
				if(np != partials.size())throw new NoMatchError();
			}else if(lastP != -1){
				if(partials.size() == 2 && !(lastP - 1 >= 0 && ress[lastP - 1].nins > 0))throw new NoMatchError();
			}
			
			if(fulls.size() == root.children.size()){
				return new DFSResult(root, nins, des, nins == S.size());
			}
			if(empties.size() == root.children.size()){
				return new DFSResult(root, 0, des, nins == S.size());
			}
			
			if(nins == S.size()){
				// root = ROOT(T,S)
				if(partials.isEmpty()){
					// as is
				}else if(partials.size() == 1){
					assert partials.get(0).type == NodeType.Q;
					if(fulls.size() >= 1){
						if(lastP == firstF - 1){
							root.children.remove(lastP);
							root.children.addAll(lastP, partials.get(0).children); // E-F
						}else{
							root.children.remove(lastP);
							root.children.addAll(lastP, partials.get(0).reverse().children); // F-E
						}
					}
				}else if(partials.size() == 2){
					assert partials.get(0).type == NodeType.Q;
					assert partials.get(1).type == NodeType.Q;
					int firstP = lastP - fulls.size() - 1;
					root.children.remove(lastP);
					root.children.addAll(lastP, partials.get(1).reverse().children); // F-E
					root.children.remove(firstP);
					root.children.addAll(firstP, partials.get(0).children); // E-F
				}
			}else{
				if(firstF == -1){
					// partial only
					if(partials.size() == 1){
						if(lastP == 0){
							root.reverse();
							int ind = root.children.size()-1;
							root.children.remove(ind);
							root.children.addAll(ind, partials.get(0).children); // E-F
						}else if(lastP == root.children.size()-1){
							int ind = root.children.size()-1;
							root.children.remove(ind);
							root.children.addAll(ind, partials.get(0).children); // E-F
						}else{
							throw new NoMatchError();
						}
					}else{
						throw new NoMatchError();
					}
				}else if(firstF == 0){
					root.reverse();
					if(partials.size() == 1){
						int ind = root.children.size() - 1 - lastP;
						root.children.remove(ind);
						root.children.addAll(ind, partials.get(0).children); // E-F
					}else if(partials.size() > 1){
						throw new NoMatchError();
					}
				}else if(lastF == root.children.size() - 1){
					if(partials.size() == 1){
						int ind = lastP;
						root.children.remove(ind);
						root.children.addAll(ind, partials.get(0).children); // E-F
					}else if(partials.size() > 1){
						throw new NoMatchError();
					}
				}else{
					throw new NoMatchError();
				}
			}
			return new DFSResult(root, nins, des, nins == S.size());
		}else{
			throw new NoMatchError();
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
	
	public static void main(String[] args) throws Exception { new E().run(); }
	
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