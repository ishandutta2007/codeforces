#include<bits/stdc++.h>

using namespace std;

const int N=200005;
int n,a[N],b[N],p[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
		scanf("%d",&a[i]),p[a[i]]=i;
	for (int i=1;i<=n;i++)
		scanf("%d",&b[i]),p[b[i]]=i;
	int ans=1<<30,re=1<<30;
	for (int i=2*n-1;i>=1;i-=2){
		re=min(re,p[i+1]);
		ans=min(ans,re+p[i]);
	}
	cout<<ans-2<<endl; 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}