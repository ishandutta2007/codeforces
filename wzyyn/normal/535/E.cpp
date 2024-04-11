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
const int N=200005;
int n,x[N],y[N];
int mx[N],Mx,q[N],vis[N];
int main(){
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%d",&x[i],&y[i]);
		mx[x[i]]=max(mx[x[i]],y[i]);
		Mx=max(Mx,x[i]);
	}
	int t=1; q[1]=Mx;
	Rep(i,Mx-1,1) if (mx[i]>mx[q[t]]){
		for (;t>1;--t){
			int ox=q[t-1],oy=mx[ox];
			int ax=i,ay=mx[ax];
			int bx=q[t],by=mx[bx];
			if (1ll*(ox-ax)*(oy-by)*bx*ay<=
				1ll*(ox-bx)*(oy-ay)*ax*by) break;
		}
		q[++t]=i;
	}
	For(i,1,t) vis[q[i]]=1;
	For(i,1,n)
		if (vis[x[i]]&&mx[x[i]]==y[i])
			printf("%d ",i); 
}