#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	int ans=0;
	for (int i=1;i<=n;i++){
		int p=upper_bound(a+1,a+n+1,a[i])-a;
		int sum=p-i;
		for (;p<n+1;){
			sum++;
			p=upper_bound(a+1,a+n+1,2*a[p]-a[i]-1)-a;
		}
		ans=max(ans,sum);
	}
	cout<<n-ans<<endl;
	/*
	a is good iff convex
	*/
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}