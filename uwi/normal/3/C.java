//package round3;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class C {
	Scanner in;
	PrintWriter out;
	String INPUT = "";
	
	void solve()
	{
		char[][] b = new char[3][3];
		for(int i = 0;i < 3;i++) {
			b[i] = in.next().toCharArray();
		}
		
		int res = check(b);
		if(res == -1) {
			out.println("illegal");
		}else if(res == 0) {
			out.println("first");
		}else if(res == 1) {
			out.println("second");
		}else if(res == 5) {
			out.println("draw");
		}else if(res == 3) {
			boolean f = true;
			for(int i = 0;i < 3;i++) {
				for(int j = 0;j < 3;j++) {
					if(b[i][j] == 'X') {
						b[i][j] = '.';
						int re = check(b);
						if(re != 3) {
							f = false;
						}
						b[i][j] = 'X';
					}
				}
			}
			if(f) {
				out.println("illegal");
			}else {
				out.println("the first player won");
			}
		}else if(res == 4) {
			boolean f = true;
			for(int i = 0;i < 3;i++) {
				for(int j = 0;j < 3;j++) {
					if(b[i][j] == '0') {
						b[i][j] = '.';
						int re = check(b);
						if(re != 4) {
							f = false;
						}
						b[i][j] = '0';
					}
				}
			}
			if(f) {
				out.println("illegal");
			}else {
				out.println("the second player won");
			}
		}
	}
	
	int check(char[][] b)
	{
		boolean fs = false;
		int gcto = 0;
		int gctc = 0;
		for(int i = 0;i < 3;i++) {
			for(int j = 0;j < 3;j++) {
				if(b[i][j] == '0')gcto++;
				if(b[i][j] == 'X')gctc++;
			}
		}
		if(gctc - gcto == 0) {
			fs = true;
		}else if(gctc - gcto == 1) {
			fs = false;
		}else {
			return -1;
		}
		
		boolean swon = false;
		boolean fwon = false;
		for(int i = 0;i < 3;i++) {
			int cto = 0;
			int ctc = 0;
			for(int j = 0;j < 3;j++) {
				if(b[i][j] == '0')cto++;
				if(b[i][j] == 'X')ctc++;
			}
			if(cto == 3)swon = true;
			if(ctc == 3)fwon = true;
		}
		for(int i = 0;i < 3;i++) {
			int cto = 0;
			int ctc = 0;
			for(int j = 0;j < 3;j++) {
				if(b[j][i] == '0')cto++;
				if(b[j][i] == 'X')ctc++;
			}
			if(cto == 3)swon = true;
			if(ctc == 3)fwon = true;
		}
		{
			int cto = 0;
			int ctc = 0;
			for(int j = 0;j < 3;j++) {
				if(b[j][j] == '0')cto++;
				if(b[j][j] == 'X')ctc++;
			}
			if(cto == 3)swon = true;
			if(ctc == 3)fwon = true;
		}
		{
			int cto = 0;
			int ctc = 0;
			for(int j = 0;j < 3;j++) {
				if(b[j][2-j] == '0')cto++;
				if(b[j][2-j] == 'X')ctc++;
			}
			if(cto == 3)swon = true;
			if(ctc == 3)fwon = true;
		}
		if(fwon && fs)return -1;
		if(swon && !fs)return -1;
		if(swon && fwon)return -1;
		if(swon)return 4;
		if(fwon)return 3;
		
		if(gctc + gcto == 9)return 5; // draw
		return fs ? 0 : 1;
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
		new C().run();
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
}