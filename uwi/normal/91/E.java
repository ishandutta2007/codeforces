//package round75;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E2 {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		int q = ni();
		int[] a = new int[n];
		int[] b = new int[n];
		for(int i = 0;i < n;i++){
			a[i] = (int)nl();
			b[i] = (int)nl();
		}
		SegmentTreeRMQ st = new SegmentTreeRMQ(a, b); // long!
		for(int i = 1;i < st.H;i++){
			tr(i, st.maxs[i]);
		}

		for(int i = 0;i < q;i++){
			int l = ni()-1;
			int r = ni()-1;
			int t = ni();
//			int g = st.max(l,r,t);
			out.println(st.max(l, r, t)+1);

//			long max = -1;
//			BitSet maxi = new BitSet();
//			for(int j = l;j <= r;j++){
//				long v = a[j] + (long)b[j]*t;
//				if(v > max){
//					max = v;
//					maxi.clear();
//				}
//				if(v == max){
//					maxi.set(j);
//				}
//			}
//			if(!maxi.get(g)){
//				tr("NG!");
//			}
		}
	}
	
	public static int[][] mergeMaxContours(int[][] x, int[][] y, int[] a, int[] b)
	{
		int m = x[0].length;
		int n = y[0].length;
		
		int[][] ret = new int[2][(m+n)+2];
		int p = 0;
		int low = 0;
		for(int i = 0, j = 0;i < m && j < n;){
			int high = Math.min(x[0][i], y[0][j]);
			int I = x[1][i];
			int J = y[1][j];
			
			long dc = (long)(b[I]-b[J])*(high-low);
			long yy = a[J]+(long)b[J]*low-a[I]-(long)b[I]*low;
			if(dc != 0 && ((dc > 0 && yy > 0 && yy < dc) || (dc < 0 && yy < 0 && yy > dc))){
				int il = low + (int)(yy / (b[I]-b[J]));
				if(a[I]+(long)b[I]*high > a[J]+(long)b[J]*high){
					// J,I
					if(p == 0 || ret[0][p-1] < il){
						if(p-1 >= 0 && ret[1][p-1] == J)p--;
						ret[0][p] = il;
						ret[1][p] = J;
						p++;
					}
					if(p == 0 || ret[0][p-1] < high){
						ret[0][p] = high;
						ret[1][p] = I;
						p++;
					}
				}else{
					// I,J
					if(p == 0 || ret[0][p-1] < il){
						if(p-1 >= 0 && ret[1][p-1] == I)p--;
						ret[0][p] = il;
						ret[1][p] = I;
						p++;
					}
					if(p == 0 || ret[0][p-1] < high){
						ret[0][p] = high;
						ret[1][p] = J;
						p++;
					}
				}
			}else{
				if(a[I]*2+(long)b[I]*(high+low) < a[J]*2+(long)b[J]*(high+low)){
					if(p == 0 || ret[0][p-1] < high){
						// J
						if(p-1 >= 0 && ret[1][p-1] == J)p--;
						ret[0][p] = high;
						ret[1][p] = J;
						p++;
					}
				}else{
					if(p == 0 || ret[0][p-1] < high){
						// I
						if(p-1 >= 0 && ret[1][p-1] == I)p--;
						ret[0][p] = high;
						ret[1][p] = I;
						p++;
					}
				}
			}
			if(i == m-1){
				j++;
			}else if(j == n-1){
				i++;
			}else if(x[0][i] < y[0][j]){
				i++;
			}else{
				j++;
			}
			low = high;
		}
		ret[0] = Arrays.copyOf(ret[0], p);
		ret[1] = Arrays.copyOf(ret[1], p);
		return ret;
	}

	public class SegmentTreeRMQ {
		public int M, H, N;
		public int[][][] maxs;
		public int[] a;
		public int[] b;
		
		public SegmentTreeRMQ(int[] a, int[] b)
		{
			N = a.length;
			M = Integer.highestOneBit(Math.max(N-1, 1))<<2;
			H = M>>>1;
			maxs = new int[M][][];
			this.a = a; this.b = b;
			for(int i = 0;i < N;i++){
				maxs[H+i] = new int[][]{{1000001}, {i}};
			}
			for(int i = (M>>1)-1;i >= 1;i--){
				if(maxs[2*i+1] == null){
					maxs[i] = maxs[2*i];
				}else{
					maxs[i] = mergeMaxContours(maxs[2*i], maxs[2*i+1], a, b);
				}
			}
		}
		
		public int max(int f, int t, int time)
		{
			return max(f, t, H, time);
		}
		
		public int max(int f, int t, int ph, int time)
		{
			if((f&(ph-1))==0 && (t&(ph-1))==ph-1){
				int h = (H|f)/ph;
				if(maxs[h] == null)return -1;
				int ind = Arrays.binarySearch(maxs[h][0], time);
				if(ind < 0)ind = -ind-1;
				return maxs[h][1][ind];
			}
			
			ph>>=1;
			if(((f^t)&ph) != 0){
				int w = t&~(ph-1);
				int A = max(f, w-1, ph, time);
				int B = max(w, t, ph, time);
				if(B == -1)return A;
				if(A == -1)return B;
				if(a[A]+(long)b[A]*time < a[B]+(long)b[B]*time){
					return B;
				}else{
					return A;
				}
			}else{
				return max(f, t, ph, time);
			}
		}
	}
	
	void run() throws Exception
	{
		in = oj ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);

		long s = System.currentTimeMillis();
		solve();
		out.flush();
		tr(System.currentTimeMillis()-s+"ms");
	}
	
	public static void main(String[] args) throws Exception
	{
		new E2().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}