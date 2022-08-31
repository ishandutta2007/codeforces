import static java.lang.Math.*;
import java.util.*;
import java.io.*;

public class a{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t -- > 0){
			int n = sc.nextInt();
			int []a = new int[n];
			for(int i = 0; i < n; i ++) a[i] = sc.nextInt();
			Arrays.sort(a);
			int ans = 0;
			int mn = 1000000000;
			for(int i = 0; i < n; i ++){
				if(a[i] <= 0){
					ans++;
					if(i > 0) mn = min(mn,a[i]-a[i-1]);
				}
				else{
					if(a[i] <= mn) ans++;
					break;
				}
			}
			System.out.println(ans);
		}
	}
}