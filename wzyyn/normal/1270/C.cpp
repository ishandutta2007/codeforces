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
ll b[105];
void solve(){
	scanf("%d",&n);
	ll S=0,SS=0;
	For(i,1,n) scanf("%d",&a[i]),S+=a[i],SS^=a[i];
	ll v=(1ll<<55)+(S&1); S+=v; SS^=v;
	assert(2*SS>S); assert(S%2==0);
	ll vv=(2*SS-S)/2;
	S+=vv+vv; SS^=vv^vv;
	assert(S==SS*2);
	printf("3\n%lld %lld %lld\n",v,vv,vv);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}