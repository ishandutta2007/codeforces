import java.util.*;

public class a{
	public static void main(String args[]){
		Scanner inp = new Scanner(System.in);
		int t;
		int []a = new int[300000];
		t = inp.nextInt();
		for(int cas = 0; cas < t; cas++){
			int n;
			n = inp.nextInt();
			int ans = 0;
			for(int i = 1; i <= n; i ++){
				a[i] = inp.nextInt();
				int r = a[i]-i%a[i];
				for(int j = r; j < i; j += a[i]){
					if(i+j == a[i]*a[j]) ans++;
				}
			}
			System.out.println(ans);
		}
	}
}