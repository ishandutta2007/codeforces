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
int n;
int a[N],b[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	b[0]=-(1<<30);
	For(i,1,n) b[i]=max(b[i-1],a[i]);
	int ans=0,p=0;
	For(i,1,n) p=max(p,b[i]-a[i]);
	for (;p;p>>=1,++ans);
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();	
}