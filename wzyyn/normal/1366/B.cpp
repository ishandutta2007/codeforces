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
using namespace std;

void solve(){
	int n,x,m,l,r,vl,vr;
	cin>>n>>x>>m;
	l=r=x;
	while (m--){	
		cin>>vl>>vr;
		if (vr>=l&&vl<=r)
			l=min(l,vl),r=max(r,vr);
	}
	cout<<r-l+1<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}