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
int n,k,a[105];
void solve(){
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int m=unique(a+1,a+n+1)-a-1;
	if (m>k) return puts("-1"),void(0);
	for (;m<k;a[++m]=1);
	printf("%d\n",n*m);
	For(i,1,n) For(j,1,m) printf("%d ",a[j]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}