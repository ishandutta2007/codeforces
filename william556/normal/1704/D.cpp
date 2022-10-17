#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int in(){
	int x;
	scanf("%d",&x);
	return x;
}
typedef long long ll;
int n,m;
void solve(){
	n=in(),m=in();
	__int128 mx=0,mn=1e36;
	int id=0;
	for(int i=1;i<=n;i++){
		__int128 s=0,sum=0;
		for(int j=1;j<=m;j++){
			ll x;scanf("%lld",&x);
			s+=x,sum+=s;	
		}
		if(sum<mn)mn=sum,id=i;
		mx=max(mx,sum);
	}
	ll ans=mx-mn;
	printf("%d %lld\n",id,ans);
}
int main(){
	int t=in();
	while(t--)solve();
	return 0;
}