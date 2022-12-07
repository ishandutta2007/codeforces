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

int n,m;
ll a[105];
void solve(){
	scanf("%d%d",&n,&m);
	a[n+1]=1ll<<m;
	For(i,1,n){
		char s[65];
		scanf("%s",s+1);
		a[i]=0;
		For(j,1,m) a[i]=a[i]*2+s[j]-'0';
	}
	sort(a+1,a+n+1);
	//For(i,1,n+1) cout<<a[i]<<' '; cout<<endl;
	ll rk=((1ll<<m)-n+1)/2;
	For(i,1,n+1)
		if (a[i]-i+1>=rk){
			ll v=rk+i-2;
			For(j,1,m) putchar('0'+((v>>(m-j))&1));
			puts("");
			return;
		}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}