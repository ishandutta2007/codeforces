import static java.lang.Math.*;
import java.util.*;
import java.io.*;

public class a{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
			int n = sc.nextInt();
			int []a = new int[n];
			for(int i = 0; i < n; i ++){
				a[i] = sc.nextInt();
			}
			Arrays.sort(a);
			int ans = 0;
			for(int i = 0; i < n; i ++) ans += (a[i] == a[0]?0:1);
			System.out.println(ans);
		}
	}
}