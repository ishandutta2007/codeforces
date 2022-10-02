//package yandex2011.r1;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		int n = ni();
		char[][] ti = new char[4][n];
		if(n % 2 == 0){
			for(int i = 0;i < n;i+=2){
				char c = i % 4 == 0 ? 'a' : 'b';
				ti[0][i] = c;
				ti[0][i+1] = c;
				ti[3][i] = c;
				ti[3][i+1] = c;
			}
			ti[1][0] = 'c';
			ti[2][0] = 'c';
			ti[1][n-1] = 'd';
			ti[2][n-1] = 'd';
			for(int i = 1;i < n-1;i+=2){
				char c = i % 4 == 1 ? 'e' : 'f';
				char d = i % 4 == 3 ? 'e' : 'f';
				ti[1][i] = c;
				ti[1][i+1] = c;
				ti[2][i] = d;
				ti[2][i+1] = d;
			}
		}else{
			for(int i = 0;i < n-1;i+=2){
				char c = i % 4 == 0 ? 'a' : 'b';
				char d = i % 4 == 2 ? 'a' : 'b';
				ti[0][i] = c;
				ti[0][i+1] = c;
				ti[1][i] = d;
				ti[1][i+1] = d;
			}
			for(int i = 1;i < n;i+=2){
				char c = i % 4 == 1 ? 'c' : 'd';
				char d = i % 4 == 3 ? 'c' : 'd';
				ti[2][i] = c;
				ti[2][i+1] = c;
				ti[3][i] = d;
				ti[3][i+1] = d;
			}
			ti[0][n-1] = 'e';
			ti[1][n-1] = 'e';
			ti[2][0] = 'f';
			ti[3][0] = 'f';
		}
		for(char[] r : ti){
			out.println(new String(r));
		}
	}
	
	void run() throws Exception
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
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}