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
ll x[105],y[105];
ll ax,ay,bx,by,sx,sy,T;
int ans;
int main(){
	scanf("%lld%lld%lld%lld%lld%lld",&x[0],&y[0],&ax,&ay,&bx,&by);
	scanf("%lld%lld%lld",&sx,&sy,&T);
	int n=1;
	for (;;n++){
		x[n]=x[n-1]*ax+bx;
		y[n]=y[n-1]*ay+by;
		if (abs(x[n])>=(3e16)||abs(y[n])>=3e16) break;
	}
	For(i,0,n) For(j,i,n){
		ll v=abs(sx-x[i])+abs(sy-y[i])+abs(x[i]-x[j])+abs(y[i]-y[j]);
		if (v<=T) ans=max(ans,j-i+1);
		v=abs(sx-x[j])+abs(sy-y[j])+abs(x[i]-x[j])+abs(y[i]-y[j]);
		if (v<=T) ans=max(ans,j-i+1);
	}
	cout<<ans<<endl;
}