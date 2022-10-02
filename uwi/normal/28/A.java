//package round28;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	private Scanner in;
	private PrintWriter out;
//	private String INPUT = "4 2 0 0 0 2 2 2 2 0 4 4";
//	private String INPUT = "6 3 0 0 1 0 1 1 2 1 2 2 0 2 2 2 3";
	private String INPUT = "";
	
	public void solve()
	{
		int n = ni();
		int m = ni();
		int[] nx = new int[n+2];
		int[] ny = new int[n+2];
		for(int i = 0;i < n;i++){
			nx[i] = ni(); ny[i] = ni();
		}
		nx[n] = nx[0]; ny[n] = ny[0];
		nx[n+1] = nx[1]; ny[n+1] = ny[1];
		
		long sumlen = 0;
		for(int i = 0;i < n;i++){
			if(nx[i] == nx[i+1]){
				sumlen += Math.abs(ny[i] - ny[i+1]);
			}else{
				sumlen += Math.abs(nx[i] - nx[i+1]);
			}
		}
		
		long sum = 0;
		int[] r = new int[m];
		Arrays.fill(r, -1);
		int[] news = new int[200001];
		Arrays.fill(news, -1);
		for(int i = 0;i < m;i++){
			int v = ni();
			if(news[v] != -1){
				r[i] = news[v];
			}
			news[v] = i;
			sum += v;
		}
//		tr(Arrays.toString(Arrays.copyOf(news, 10)));
//		tr(Arrays.toString(r));
		
		if(sumlen > sum){
			out.println("NO");
			return;
		}
		
		int[] hist = new int[n];
		boolean suc = true;
		{
			int[] nn;
			nn = Arrays.copyOf(news, 200001);
			for(int i = 0;i < n;i+=2){
				int len = 0;
				if(nx[i] == nx[i+1]){
					len += Math.abs(ny[i] - ny[i+1]);
				}else{
					len += Math.abs(nx[i] - nx[i+1]);
				}
				if(nx[i+1] == nx[i+2]){
					len += Math.abs(ny[i+1] - ny[i+2]);
				}else{
					len += Math.abs(nx[i+1] - nx[i+2]);
				}
				if(len >= 200001 || nn[len] == -1){
					suc = false;
					break;
				}
				hist[i+1] = nn[len] + 1;
				hist[i] = -1;
				nn[len] = r[nn[len]];
			}
		}
		
		if(!suc){
			suc = true;
			int[] nn;
			nn = Arrays.copyOf(news, 200001);
			for(int i = 1;i < n + 1;i+=2){
				int len = 0;
				if(nx[i] == nx[i+1]){
					len += Math.abs(ny[i] - ny[i+1]);
				}else{
					len += Math.abs(nx[i] - nx[i+1]);
				}
				if(nx[i+1] == nx[i+2]){
					len += Math.abs(ny[i+1] - ny[i+2]);
				}else{
					len += Math.abs(nx[i+1] - nx[i+2]);
				}
				if(len >= 200001 || nn[len] == -1){
					suc = false;
					break;
				}
				hist[(i+1)%n] = nn[len] + 1;
				hist[i] = -1;
				nn[len] = r[nn[len]];
			}
		}
		
		if(suc){
			StringBuilder sb = new StringBuilder();
			for(int u : hist){
				sb.append(u);
				sb.append(' ');
			}
			out.println("YES");
			out.println(sb.toString());
		}else{
			out.println("NO");
		}
	}
	
	public void run() throws Exception
	{
		in = INPUT.isEmpty() ? new Scanner(System.in) : new Scanner(INPUT);
		out = new PrintWriter(System.out);
		
		solve();
		out.flush();
	}
	
	
	public static void main(String[] args) throws Exception
	{
		new A().run();
	}
	
	private int ni() { return Integer.parseInt(in.next()); }
	private void tr(Object... o) { if(INPUT.length() != 0)System.out.println(o.length == 1 ? o[0] : Arrays.toString(o)); }
}