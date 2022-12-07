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
	int n;
	scanf("%d",&n);
	pll v1(0,0),v2(0,0);
	For(i,1,n){
		int x;
		scanf("%d",&x);
		if (x>0) v1=max(v1,pll(v2.fi+1,v2.se+x));
		if (x<0) v2=max(v2,pll(v1.fi+1,v1.se+x));
	}
	v1=max(v1,v2);
	printf("%lld\n",v1.se);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}