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
const int N=500005;
int n,top;
pii ans[N];
void work(int l,int r){
	for (int d=1;d<r-l+1;d<<=1)
		for (int i=0;i<r-l;i++)
			if (!(i&d))
				ans[++top]=pii(l+i,l+i+d);
}
int main(){
	scanf("%d",&n);
	int l=1;
	for (;l*2<=n;l*=2);
	work(1,l); work(n-l+1,n);
	printf("%d\n",top);
	For(i,1,top)
		printf("%d %d\n",ans[i].fi,ans[i].se);
}