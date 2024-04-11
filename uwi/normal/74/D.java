//package round68;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class D2 {
	IntReader in;
	PrintWriter out;
//	String INPUT = "9 11\r\n" +
//	"1\r\n" +
//	"2\r\n" +
//	"0 5 8\r\n" +
//	"1\r\n" +
//	"1\r\n" +
//	"3\r\n" +
//	"0 3 8\r\n" +
//	"9\r\n" +
//	"0 6 9\r\n" +
//	"6\r\n" +
//	"0 1 9";
//	String INPUT = "8 9 1 2 1 2 1 2 1 2 0 1 8";
//	String INPUT = "3 3 10 10 0 1 3";
//	String INPUT = "9 9 1 2 3 4 5 6 7 8 0 1 8";
	String INPUT = "";
	
	static class Interval implements Comparable<Interval>
	{
		public int ind, len;

		public Interval(int ind, int len) {
			this.ind = ind;
			this.len = len;
		}
		
		public int compareTo(Interval b)
		{
			if(len != b.len)return b.len - this.len; // longer
			return b.ind - this.ind; // right
		}
	}
	
	void solve()
	{
		int n = ni();
		int q = ni();
		int[][] com = new int[q][];
		
		Map<Integer, Integer> arranged = new HashMap<Integer, Integer>();
		TreeSet<Interval> ints = new TreeSet<Interval>(); // Interval
		ints.add(new Interval(1, n));
		TreeMap<Integer, Interval> indint = new TreeMap<Integer, Interval>(); // Interval
		HashSet<Integer> aped = new HashSet<Integer>(); // index
		for(int i = 0;i < q;i++){
			int c = ni();
			if(c == 0){
				com[i] = new int[]{ni(), ni()};
			}else{
				if(arranged.containsKey(c)){
					int ind = arranged.remove(c);
					Map.Entry<Integer, Interval> left = indint.floorEntry(ind);
					Map.Entry<Integer, Interval> right = indint.ceilingEntry(ind+1);
					ints.remove(right.getValue());
					ints.remove(left.getValue());
					Interval merged = new Interval(left.getKey(), left.getValue().len + 1 + right.getValue().len);
					ints.add(merged);
					indint.remove(left.getKey());
					indint.remove(right.getKey());
					indint.put(left.getKey(), merged);
					com[i] = new int[]{ind};
				}else{
					Interval v = ints.pollFirst();
					int ind = v.ind + v.len / 2;
					Interval left = new Interval(v.ind, v.len/2);
					Interval right = new Interval(ind+1, v.ind+v.len-ind-1);
					ints.add(left);
					ints.add(right);
					indint.put(v.ind, left);
					indint.put(ind+1, right);
					arranged.put(c, ind);
					aped.add(ind);
					com[i] = new int[]{ind};
				}
			}
		}
		List<Integer> l = new ArrayList<Integer>(aped); // hanger_indexes
		Collections.sort(l);
		HashMap<Integer, Integer> apmap = new HashMap<Integer, Integer>(); // <hanger_index after_index>
		for(int i = 0;i < l.size();i++){
			apmap.put(l.get(i), i+1);
		}
//		tr(arranged);
		
		int u = l.size();
		int[] f = new int[u+1];
		int[] a = new int[u+1];
		for(int i = 0;i < q;i++){
			if(com[i].length == 2){
				int low = Collections.binarySearch(l, com[i][0]);
				if(low < 0)low = -low - 1;
				int high = Collections.binarySearch(l, com[i][1]);
				if(high < 0)high = -high - 2;
//				tr(l, com[i], low, high);
				if(high+1 < low){
					out.println(0);
				}else{
					out.println(sumFenwick(f, high+1) - sumFenwick(f, low));
				}
			}else{
				int ind = apmap.get(com[i][0]);
				if(a[ind] == 1){
					a[ind]--;
					addFenwick(f, ind, -1);
				}else{
					a[ind]++;
					addFenwick(f, ind, 1);
				}
			}
		}
	}
	
	public static int sumFenwick(int[] ft, int i)
	{
		int sum = 0;
		for(;i > 0;i -= i&-i)sum += ft[i];
		return sum;
	}
	
	public static void addFenwick(int[] ft, int i, int v)
	{
		int n = ft.length;
		for(;i < n;i += i&-i)ft[i] += v;
	}
	
	void run() throws Exception
	{
		in = INPUT.isEmpty() ? new IntReader(System.in) : new IntReader(new ByteArrayInputStream(INPUT.getBytes()));
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	public static void main(String[] args) throws Exception
	{
		new D2().run();
	}
	
	public class IntReader {
		private InputStream is;
		
		public IntReader(InputStream is)
		{
			this.is = is;
		}
		
		public int nui()
		{
			try {
				int num = 0;
				while((num = is.read()) != -1 && (num < '0' || num > '9'));
				num -= '0';
				
				while(true){
					int b = is.read();
					if(b == -1)return num;
					if(b >= '0' && b <= '9'){
						num = num * 10 + (b - '0');
					}else{
						return num;
					}
				}
			} catch (IOException e) {
			}
			return -1;
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
					if(b == -1)return minus ? -num : num;
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
		
		public String nl()
		{
			try{
				int b = 0;
				StringBuilder sb = new StringBuilder();
				while((b = is.read()) != -1 && (b == '\r' || b == '\n'));
				if(b == -1)return "";
				sb.append((char)b);
				while(true){
					b = is.read();
					if(b == -1)return sb.toString();
					if(b == '\r' || b == '\n')return sb.toString();
					sb.append((char)b);
				}
			} catch (IOException e) {
			}
			return "";
		}
	}
	
	int ni() { return in.ni(); }
	int nui() { return in.nui(); }
	String nl() { return in.nl(); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}