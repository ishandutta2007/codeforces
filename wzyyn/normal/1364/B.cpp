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
int n,x,a[100005],b[100005];
void solve(){
	x=0;
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	b[++x]=a[1];
	For(i,2,n-1)
		if ((a[i]<a[i-1])^(a[i+1]<a[i]))
			b[++x]=a[i];
	b[++x]=a[n];
	printf("%d\n",x);
	For(i,1,x) printf("%d ",b[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}