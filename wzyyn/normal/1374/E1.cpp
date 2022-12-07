#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
#define all(v) v.begin(),v.end()
using namespace std;
int n,k;
vector<ll> v[4];
int main(){
	scanf("%d%d",&n,&k);
	For(i,0,3) v[i].resize(0);
	For(i,1,n){
		int x,a,b;
		scanf("%d%d%d",&x,&a,&b);
		v[2*a+b].PB(x);
	}
	For(i,1,3) sort(v[i].begin(),v[i].end());
	if (v[3].size()+min(v[2].size(),v[1].size())<k)
		return puts("-1"),0;
	For(i,1,v[1].size()-1) v[1][i]+=v[1][i-1];
	For(i,1,v[2].size()-1) v[2][i]+=v[2][i-1];
	For(i,1,v[3].size()-1) v[3][i]+=v[3][i-1];
	int m=min(v[1].size(),v[2].size());
	ll ans=1ll<<60;
	For(v1,0,v[3].size()) if (v1<=k&&k-v1<=m){
		ll val=0;
		if (v1) val+=v[3][v1-1];
		if (k-v1){
			val+=v[2][k-v1-1];
			val+=v[1][k-v1-1];
		}
		//cout<<v1<<' '<<val<<endl;
		ans=min(ans,val);
	}
	cout<<ans<<endl;
}