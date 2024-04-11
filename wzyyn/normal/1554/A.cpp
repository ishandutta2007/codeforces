#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
using namespace std;

const int N=100005;
int n,a[N];
void solve(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	ll mx=0;
	for (int i=2;i<=n;i++)
		mx=max(mx,1ll*max(a[i],a[i-1])*min(a[i],a[i-1]));
	cout<<mx<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}