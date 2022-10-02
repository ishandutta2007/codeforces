//package round81;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class E {
	Scanner in;
	PrintWriter out;
//	String INPUT = "9 3 3\r\n" +
//	"4 3 1\r\n" +
//	"2 3 3";
	String INPUT = "8 10 10\r\n" +
	"9 10 10\r\n" +
	"10 10 10";
//	String INPUT = "1 1 1 2 1 10 5 1 1";
	
	void solve()
	{
		int[][] s = new int[3][4];
		for(int i = 0;i < 3;i++){
			for(int j = 0;j < 3;j++){
				s[i][j] = ni();
			}
		}
		
		int ct = 0;
		int[] iord = new int[9];
		for(int j = 0;j < 9;j++)iord[j] = j;
		gmax = 0;
		do{
			if(iord[1] < iord[2] && iord[4] < iord[5] && iord[7] < iord[8]){
				int[] ord = new int[9];
				for(int j = 0;j < 9;j++){
					ord[iord[j]] = j;
				}
				int[] u = new int[3];
				outer:
				for(int i = 0;i < 27;i++, inc(u, 3)){
					for(int j = 0;j < 3;j++){
						if(u[j] == j ){
							for(int k = 0;k < 3;k++){
								if(iord[j*3+2] > iord[k*3])continue outer;
							}
							for(int k = j+1;k < 3;k++){
								if(iord[j*3+2] > iord[k*3+1])continue outer;
							}
						}
					}
					boolean[] lifted = new boolean[3];
					boolean[] lift = new boolean[3];
					for(int j = 0;j < 9;j++){
						int me = ord[j]/3;
						int targ = u[ord[j]/3];
						if(lifted[me])continue outer;
						if(ord[j] % 3 == 0 && lift[me])continue outer;
						if(ord[j] % 3 == 1 && targ != me){
							if(lifted[targ])continue outer;
							lifted[targ] = true;
							lift[me] = true;
						}
						if(ord[j] % 3 == 2 && targ != me){
							if(!lifted[targ])continue outer;
							lifted[targ] = false;
							lift[me] = false;
						}
					}
					
					for(int j = 0;j < 3;j++){
						s[j][3] = s[j][0];
					}
					gmax = Math.max(gmax, rec(ord, u, 0, s, 0, 0));
					ct++;
//					if(ct % 100 == 0)tr(ct);
				}
			}
		}while(nextPermutation(iord));
//		tr(ct);
		out.println(gmax);
	}
	
	int gmax;
	boolean invalid(int[] ord, int[] u, int pos, int[][] s)
	{
		int[] ss = new int[3];
		for(int i = 0;i < 3;i++){
			ss[i] = s[i][3];
		}
		for(int i = pos;i < 9;i++){
			int me = ord[i]/3;
			int targ = u[ord[i]/3];
			int com = ord[i] % 3;
			if(com == 0){
				ss[me] += s[me][1];
			}else if(com == 1 && me != targ){
				for(int j = 0;j < 3;j++){
					if(me != j)ss[j]++;
				}
			}else if(com == 2 && me != targ){
				for(int j = 0;j < 3;j++){
					if(me != j)ss[j] += s[me][2];
				}
			}
		}
		
		int mx = Math.max(Math.max(ss[0], ss[1]), ss[2]);
		return mx <= gmax;
	}
	
	int rec(int[] ord, int[] u, int pos, int[][] s, int lift, int lifted)
	{
		if(pos == 9){
			return Math.max(Math.max(s[0][3], s[1][3]), s[2][3]);
		}
		if(invalid(ord, u, pos, s))return 0;
		
		int me = ord[pos]/3;
		int targ = u[ord[pos]/3];
		int com = ord[pos]%3;
		int max = 0;
		if(com == 0){
			outer:
			for(int i = s[me][1];i >= -s[me][1];i--){
				for(int j = 0;j < 3;j++){
					if(me != j && s[me][3] + i == s[j][3])continue outer;
				}
				s[me][3] += i;
				max = Math.max(max, rec(ord, u, pos+1, s, lift, lifted));
				s[me][3] -= i;
//				if(pos == 8)break;
			}
		}else if(com == 1){
			if(me == targ){
				max = Math.max(max, rec(ord, u, pos+1, s, lift, lifted));
			}else{
				if(Math.abs(s[me][3] - s[targ][3]) == 1){
					lift ^= 1<<me;
					lifted ^= 1<<targ;
					int o = s[targ][3];
					s[targ][3] = s[me][3];
					if(lift<<31-targ<0){
						int other = Integer.numberOfTrailingZeros(7-(1<<me)-(1<<targ));
						s[other][3] = s[me][3];
					}
					max = Math.max(max, rec(ord, u, pos+1, s, lift, lifted));
					s[targ][3] = o;
					if(lift<<31-targ<0){
						int other = Integer.numberOfTrailingZeros(7-(1<<me)-(1<<targ));
						s[other][3] = s[targ][3];
					}
					lift ^= 1<<me;
					lifted ^= 1<<targ;
				}
			}
		}else if(com == 2){
			if(me == targ){
				max = Math.max(max, rec(ord, u, pos+1, s, lift, lifted));
			}else{
				outer2:
				for(int i = s[me][2];i >= -s[me][2];i--){
					for(int j = 0;j < 3;j++){
						if(s[targ][3] + i == s[j][3])continue outer2;
					}
					int o = s[targ][3];
					s[targ][3] = s[me][3] + i;
					if(lift<<31-targ<0){
						int other = Integer.numberOfTrailingZeros(7-(1<<me)-(1<<targ));
						s[other][3] = s[targ][3];
					}
					lifted ^= 1<<targ;
					lift ^= 1<<me;
					max = Math.max(max, rec(ord, u, pos+1, s, lift, lifted));
					lifted ^= 1<<targ;
					lift ^= 1<<me;
					s[targ][3] = o;
					if(lift<<31-targ<0){
						int other = Integer.numberOfTrailingZeros(7-(1<<me)-(1<<targ));
						s[other][3] = s[targ][3];
					}
//					if(pos == 8)break;
				}
			}
		}
		return max;
	}
	
	public static boolean inc(int[] a, int base)
	{
		int n = a.length;
		int i;
		for(i = n - 1;i >= 0 && a[i] == base - 1;i--);
		if(i == -1)return false;
		
		a[i]++;
		Arrays.fill(a, i + 1, n, 0);
		return true;
	}
	
	public static boolean nextPermutation(int[] src)
	{
		int i;
		for(i = src.length - 2;i >= 0 && src[i] > src[i+1];i--);
		if(i == -1)return false;
		int j;
		for(j = i + 1;j < src.length && src[i] < src[j];j++);
		int d = src[i]; src[i] = src[j - 1]; src[j - 1] = d;
		for(int p = i + 1, q = src.length - 1;p < q;p++,q--){
			d = src[p]; src[p] = src[q]; src[q] = d;
		}
		return true;
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
		new E().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}