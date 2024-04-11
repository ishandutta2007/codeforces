#include<bits/stdc++.h>
using namespace std;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
const int N=2e5+5;
int n,q;
int a[N];
long long s[N];
void solve(){
	n=in(),q=in();
	for(int i=1;i<=n;i++){
		a[i]=in(),s[i]=s[i-1]+a[i];
		a[i]=max(a[i],a[i-1]);
	}
	while(q--){
		int x=in();
		int p=upper_bound(a+1,a+n+1,x)-a-1;
		printf("%lld ",s[p]);
	}
	puts("");
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}