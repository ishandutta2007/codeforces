#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=100005;
int T,n,m,a[N],s[N],ans[N];
signed main(){
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=m;i++)scanf("%lld",&a[i]);
	for (int i=m;i;i--)s[i]=s[i+1]+a[i];
	if (s[1]<n){
		puts("-1");
		return 0;
	}
	int now=0,last=0;
	for (int i=1;i<=m;i++){
		if (a[i]+i-1>n){
			puts("-1");
			return 0;
		}
		now++;
		while (n-max(now+a[i]-1,last)>s[i+1])now++;
		ans[i]=now;last=max(last,a[i]+now-1);
	}
	for (int i=1;i<=m;i++)printf("%lld ",ans[i]);
}