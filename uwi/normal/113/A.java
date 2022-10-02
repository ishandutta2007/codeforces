//package round86;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		String line = in.nextLine();
		String[] sp = line.split(" ");
		if(sp.length == 1){
			int i = 0;
			if(sp[i].endsWith("lios")){
			}else if(sp[i].endsWith("liala")){
			}else if(sp[i].endsWith("etr")){
			}else if(sp[i].endsWith("etra")){
			}else if(sp[i].endsWith("initis")){
			}else if(sp[i].endsWith("inites")){
			}else{
				out.println("NO");
				return;
			}
			out.println("YES");
			return;
		}
		
		int state = 0; // 0:adj, 1:noun, 2:verb
		int gender = 0;
		int[] count = new int[3];
		for(int i = 0;i < sp.length;i++){
			if(sp[i].endsWith("lios")){
				gender |= 1;
				if(state == 0){
					count[0]++;
				}else{
					out.println("NO");
					return;
				}
			}else if(sp[i].endsWith("liala")){
				gender |= 2;
				if(state == 0){
					count[0]++;
				}else{
					out.println("NO");
					return;
				}
			}else if(sp[i].endsWith("etr")){
				gender |= 1;
				if(state == 0){
					state = 1;
					count[1]++;
				}else{
					out.println("NO");
					return;
				}
			}else if(sp[i].endsWith("etra")){
				gender |= 2;
				if(state == 0){
					state = 1;
					count[1]++;
				}else{
					out.println("NO");
					return;
				}
			}else if(sp[i].endsWith("initis")){
				gender |= 1;
				if(state == 1 || state == 2){
					state = 2;
					count[2]++;
				}else{
					out.println("NO");
					return;
				}
			}else if(sp[i].endsWith("inites")){
				gender |= 2;
				if(state == 1 || state == 2){
					state = 2;
					count[2]++;
				}else{
					out.println("NO");
					return;
				}
			}else{
				out.println("NO");
				return;
			}
		}
		if(gender == 3 || gender == 0){
			out.println("NO");
			return;
		}
		
		if(!(state == 1 || state == 2)){
			out.println("NO");
			return;
		}
		if(count[1] != 1){
			out.println("NO");
			return;
		}
		
		out.println("YES");
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
		new A().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	boolean oj = System.getProperty("ONLINE_JUDGE") != null;
	void tr(Object... o) { if(!oj)System.out.println(Arrays.deepToString(o)); }
}