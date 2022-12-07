#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;
const int N=200005;
ll a[N];
int n;
void solve(){
	scanf("%d",&n);
	For(i,1,2*n) scanf("%lld",&a[i]);
	sort(a+1,a+2*n+1);
	For(i,1,2*n) if (a[i]&1) return puts("No"),void(0);
	For(i,1,n) if (a[i*2-1]!=a[i*2]) return puts("No"),void(0);
	ll rem=0;
	For(i,2,n){
		ll del=a[2*i-1]-a[2*i-2];
		if (del==0) return puts("No"),void(0);
		if (del%(2*(i-1))) return puts("No"),void(0);
		rem+=(n-i+1)*del/(2*(i-1))*2;
	}
	//cout<<rem<<' '<<a[1]<<endl;
	if (a[1]<=rem||(a[1]-rem)%(2*n)) puts("No");
	else puts("Yes");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}