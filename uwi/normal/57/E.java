//package round53;
import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Queue;

public class E {
	InputStream is;
	PrintWriter out;
	String INPUT = "";
	
	static int[] DRK = {-2,-2,-1,-1,1,1,2,2};
	static int[] DCK = {-1,1,-2,2,-2,2,-1,1};
	
	void solve()
	{
		long K = nl();
		int n = ni();
		boolean[][] obs = new boolean[21][21];
//		Random gen = new Random();
//		for(int i = 0;i < 440;i++){
//			obs[gen.nextInt(21)][gen.nextInt(21)] = true;
//		}
		for(int i = 0;i < n;i++){
			obs[ni()+10][ni()+10] = true;
		}
		int mod = 1000000007;
		int U = 400;
		int O = U/2;
		int[][] B = new int[U][U];
		for(int i = 0;i < U;i++){
			for(int j = 0;j < U;j++){
				B[i][j] = 9999999;
			}
		}
		B[O][O] = 0;
		Queue<int[]> q = new ArrayDeque<int[]>();
		q.add(new int[]{O, O});
		int[] ct = new int[100];
		while(!q.isEmpty()){
			int[] cur = q.poll();
			if(B[cur[0]][cur[1]] < 100){
				ct[B[cur[0]][cur[1]]]++;
			}else{
				break;
			}
			for(int k = 0;k < 8;k++){
				int nr = cur[0] + DRK[k], nc = cur[1] + DCK[k];
				if(nr >= 0 && nr < U && nc >= 0 && nc < U && B[nr][nc] == 9999999){
					if(nr >= O-10 && nr <= O+10 && nc >= O-10 && nc <= O+10 && obs[nr-O+10][nc-O+10]){
						continue;
					}
					B[nr][nc] = B[cur[0]][cur[1]]+1;
					q.add(new int[]{nr, nc});
				}
			}
		}
		if(K < 100){
			long S = 0;
			for(int i = 0;i <= K;i++){
				S += ct[i];
			}
			out.println(S % mod);
		}else if(ct[99] == 0){
			long S = 0;
			for(int i = 0;i < 100;i++){
				S += ct[i];
			}
			out.println(S % mod);
		}else{
			long S = 0;
			for(int i = 0;i < 100;i++){
				S += ct[i];
			}
			// (a+a+(k-1)d)/2*k=a*k+k(k-1)/2*d
			out.println(
					(((ct[99]+28)%mod)*((K-99)%mod)%mod+
					((K-99)%mod)*((K-99-1)%mod)%mod*14%mod+S)%mod
					);
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