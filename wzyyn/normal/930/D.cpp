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
const int N=100005;
pii p[N*4],s[N*4];
int n;
void UPD(pii &x,pii y){
	x.fi=min(x.fi,y.fi);
	x.se=max(x.se,y.se);
}
int main(){
	scanf("%d",&n);
	For(i,0,4*N-1) p[i]=pii(1<<30,-(1<<30));
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		UPD(p[x+y+N+N],pii(x-y,x-y));
	}
	For(i,0,4*N-1) s[i]=p[i];
	For(i,2,4*N-1) UPD(p[i],p[i-2]);
	Rep(i,4*N-3,0) UPD(s[i],s[i+2]);
	ll ans=0;
	For(i,1,4*N-2){
		int mn=max(p[i-1].fi,s[i+1].fi);
		int mx=min(p[i-1].se,s[i+1].se);
		if (mx>mn) ans+=(mx-mn)/2;
	}
	cout<<ans<<endl;
}