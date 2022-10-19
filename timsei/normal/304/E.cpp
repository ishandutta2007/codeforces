using namespace std;
#include<bits/stdc++.h>
int a[5001] , n , b[1000001];
int vis[1000001] , m , k;
int main() {
	scanf("%d%d",&n,&k);
	for(int i = 1;i <= n ;i ++) {
		scanf("%d",&a[i]);
	}
	sort(a+1 , a+n+1);
	for(int j = 1;j <= n ;j ++){
		for(int i =1;i <= j -1 ; i++) {
			b[a[j] - a[i]] ++;
		}
	}
	for(int i = n - k; i<=1000000; i++) {
		int tot = 0;
		for(int j = i; j<=1000000 ;j += i) {
			tot += b[j];
		}
		if(tot > (k+1) * k / 2) continue;
		int cnt = 0;
		for(int j = 1; j <= n; j ++) {
			if(vis[a[j] % i] == i) {
				cnt ++;
			}
			vis[a[j] % i] = i;
		}
		if(cnt <= k) {
			cout<<i<<endl;return 0;
		}
	}
}