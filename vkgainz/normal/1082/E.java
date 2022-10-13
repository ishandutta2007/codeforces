import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class E {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int c = sc.nextInt();
		int a[] = new int[n];
		
		for(int i=0;i<n;i++) {
			a[i] = sc.nextInt();
		}
		solve(a,n,c);
	}
	static void solve(int a[], int n,int c) {
		int ans =0;
		ArrayList<Integer>[] pos = new ArrayList[500000+1];
		for(int i=1;i<=500000;i++) pos[i] = new ArrayList<>();
		int pref[] = new int[n];
		Set<Integer> elements = new HashSet<Integer>();
		elements.add(a[0]);
		if(a[0]==c) {
			pref[0]++;
			ans++;
		}
		else {
			pos[a[0]].add(0);
		}
		for(int i=1;i<n;i++) {
			pref[i] = pref[i-1];
			if(a[i]==c) {
				ans++;
				pref[i]++;
				
			}
			else {
				pos[a[i]].add(i);
			}
			
			elements.add(a[i]);
		}
		int cnt =0;
		for(int e : elements) {
			if(e!=c) {
				cnt = Math.max(cnt, findAns(e,c,pos,pref));
			}
		}
		ans+=cnt;
		System.out.println(ans);
	}
	static int findAns(int x,int c, ArrayList<Integer>[] pos, int[] pref) {
		int l = 0;
		int r = 0;
		int cnt = 0;
		while(l<pos[x].size()) {
			int sub = 0;
			if(pos[x].get(l)>0) {
				sub-=pref[pos[x].get(l)-1];
			}
			int temp = 0;
			while(r<pos[x].size()) {
				if(pos[x].get(r)>0) {
					temp = sub+pref[pos[x].get(r)-1];
				}
				int num = r-l+1;
//				System.out.println( temp + " " + r + " " + l);
				cnt = Math.max(cnt, num-temp);
				if(temp>=num) {
					break;
				}
				else {
					r++;
				}
			}
//			r++;
			l = r;
		}
		return cnt;
	}
}