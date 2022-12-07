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
int n,a[100005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	a[0]=a[n+1]=-1;
	int l=1<<30,r=-1,v=0;
	For(i,1,n) if (a[i]==-1){
		if (a[i-1]!=-1) l=min(l,a[i-1]),r=max(r,a[i-1]);
		if (a[i+1]!=-1) l=min(l,a[i+1]),r=max(r,a[i+1]);
	}
	else if (a[i-1]!=-1)
		v=max(v,abs(a[i]-a[i-1]));
	if (r==-1) puts("0 0\n");
	else printf("%d %d\n",max(v,(r-l+1)/2),(r+l)/2);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}