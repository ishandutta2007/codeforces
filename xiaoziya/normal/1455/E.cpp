#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=500005;
int T,ans;
int p[5],x[5],y[5];
struct point{
	int x,y;
}t[5],w[5];
signed main(){
	scanf("%lld",&T);
	while(T--){
		ans=1e18;
		for(int i=1;i<=4;i++)
			scanf("%lld%lld",&t[i].x,&t[i].y),p[i]=i;
		do{
			for(int i=1;i<=4;i++)
				w[i]=t[p[i]];
			int xl=min(w[1].x,w[3].x),xr=max(w[1].x,w[3].x);
			int yl=min(w[1].y,w[2].y),yr=max(w[1].y,w[2].y);
			int xdl=min(w[2].x,w[4].x),xdr=max(w[2].x,w[4].x);
			int ydl=min(w[3].y,w[4].y),ydr=max(w[3].y,w[4].y);
			int dxl=xdl-xr,dxr=xdr-xl;
			int dyl=ydl-yr,dyr=ydr-yl;
			dxl=max(dxl,0ll),dyl=max(dyl,0ll);
			if(dxl>dxr||dyl>dyr)
				continue;
			int val=xr-xl+yr-yl+xdr-xdl+ydr-ydl;
			if(dxl<=dyr&&dyl<=dxr)
				ans=min(ans,val);
			else ans=min(ans,val+(max(dxl,dyl)-min(dxr,dyr))*2);
		}while(next_permutation(p+1,p+1+4));
		printf("%lld\n",ans);
	}
	return 0;
}