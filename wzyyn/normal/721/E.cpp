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
int n,p,t,f[N],h[N];
void UPD(int x,int y,int l,int r){
	int v1=(r-l)/p,v2=l+v1*p;
	if (v1+f[x]>f[y]) f[y]=v1+f[x],h[y]=v2;
	if (v1+f[x]==f[y]) h[y]=min(h[y],v2);
}
int main(){
	scanf("%*d%d%d%d",&n,&p,&t);
	h[0]=-t;
	int pos=0;
	For(i,1,n){
		int x,y;
		scanf("%d%d",&x,&y);
		if (pos) --pos;
		for (;pos<i&&h[pos]+t<=y;++pos)
			UPD(pos,i,max(h[pos]+t,x),y);
		if (f[i-1]>f[i]) f[i]=f[i-1],h[i]=h[i-1];
		if (f[i-1]==f[i]) h[i]=min(h[i-1],h[i]);
		//cout<<f[i]<<' '<<h[i]<<' '<<endl;
	}
	printf("%d\n",f[n]);
}