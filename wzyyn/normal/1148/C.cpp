#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
int n,tot,a[N];
pii ans[N*5];
void SWAP(int x,int y){
	ans[++tot]=pii(x,y);
	swap(a[x],a[y]);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int p1=1,p2=n;
	for (;;){
		for (;a[p1]<=n/2;++p1);
		for (;a[p2]>n/2;--p2);
		if (p1>n/2||p2<=n/2) break;
		if ((p2-p1)*2>=n)
			SWAP(p1,p2);
		else{
			SWAP(1,p2); SWAP(p1,n);
			SWAP(1,n);
			SWAP(1,p2); SWAP(p1,n);
		}
	}
	For(i,1,n/2) if (a[i]!=i){
		SWAP(i,n);
		for (;a[i]!=i;SWAP(a[n],n));
	}
	For(i,n/2+1,n) if (a[i]!=i){
		SWAP(i,1);
		for (;a[i]!=i;SWAP(a[1],1));
	}
	printf("%d\n",tot);
	For(i,1,tot)
		printf("%d %d\n",ans[i].fi,ans[i].se);
}