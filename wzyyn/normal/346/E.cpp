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
int Func(int a,int n,int p){
	int t=1ll*a*n/p;
	if (!t) return max(a,p-a*n);
	return Func(a-p%a,t-(1ll*a*n%p<(p/a-1)*a),a);
}
void solve(){
	int a,n,p,h;
	scanf("%d%d%d%d",&a,&n,&p,&h);a%=p;
	puts((1ll*a*n<p?a:Func(a,n,p))<=h?"YES":"NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}