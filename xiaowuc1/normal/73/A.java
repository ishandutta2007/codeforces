import java.util.*;
import java.io.*;
public class Main {
	static StreamTokenizer br;
	final static int MOD = 100000000;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int a = Integer.parseInt(st.nextToken());
		int b = Integer.parseInt(st.nextToken());
		int c = Integer.parseInt(st.nextToken());
		int d = Integer.parseInt(st.nextToken());
		int e = 1;
		int f = 1;
		int g = 1;
		for(int i = 0; d > 0; i++)	{
			if(a == e && b == f && c == g)
				break;
			if(i%3==0 && a != e) {
				e++;
				d--;
			}
			if(i%3==1 && b != f){
				f++;
				d--;
			}
			if(i%3==2 && c != g){
				d--;
				g++;
			}
		}
		long p = e;
		p *= f;
		p *= g;
		System.out.println(p);
	}
}