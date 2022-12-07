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
int n,a[200005];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	int S=a[1];
	for (int i=1;i<=n;i++) S&=a[i];
	int ss=0;
	for (int i=1;i<=n;i++) ss+=(a[i]==S);
	if (ss<2) puts("0");
	else{
		int ans=1;
		for (int i=1;i<=n-2;i++)
			ans=1ll*ans*i%1000000007;
		ans=1ll*ans*ss%1000000007;
		ans=1ll*ans*(ss-1)%1000000007;
		printf("%d\n",ans);
	}
} 
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}