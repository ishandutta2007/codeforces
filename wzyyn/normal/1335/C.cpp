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
int n,a[200005],x;
void solve(){
	scanf("%d",&n);
	For(i,1,n) a[i]=0;
	For(i,1,n) scanf("%d",&x),++a[x];
	int v1=0,v2=0;
	For(i,1,n) v1+=(a[i]!=0),v2=max(v2,a[i]);
	printf("%d\n",min(v1,v2)-(v1==v2));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}