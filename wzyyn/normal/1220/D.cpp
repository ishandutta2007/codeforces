#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
const int N=200005;
int n;
vector<ll> vec[65];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		ll x;
		scanf("%lld",&x);
		int t=0;
		for (ll y=x;y%2==0;y/=2,++t);
		vec[t].PB(x);
	}
	int ans=n+1,id=0;
	For(i,0,60)
		if (n-vec[i].size()<ans)
			id=i,ans=n-vec[i].size();
	printf("%d\n",ans);
	For(i,0,60) if (i!=id)
		For(j,0,vec[i].size()-1) printf("%lld ",vec[i][j]);
}