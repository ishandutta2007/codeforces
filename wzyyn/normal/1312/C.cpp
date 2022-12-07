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
ll a[105],S[105];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	For(i,1,n) scanf("%lld",&a[i]);
	memset(S,0,sizeof(S));
	For(T,1,100) For(i,1,n)
		S[T]+=(a[i]%k),a[i]/=k;
	For(T,1,100) if (S[T]>1) return puts("NO"),void(0);
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}