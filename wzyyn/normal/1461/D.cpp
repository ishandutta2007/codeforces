#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;

const int N=100005;
int n,Q,a[N],f[N];
map<ll,int> mp;
ll S[N];
void divide(int l,int r){
	mp[S[r]-S[l-1]]=1;
	int mv=(a[l]+a[r])/2;
	int p=upper_bound(a+l,a+r+1,mv)-a-1;
	if (p==l-1||p==r) return;
	divide(l,p);
	divide(p+1,r);
}
void solve(){
	scanf("%d%d",&n,&Q);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	mp.clear();
	For(i,1,n) S[i]=S[i-1]+a[i];
	divide(1,n);
	For(i,1,Q){
		ll x;
		scanf("%lld",&x);
		printf(mp.count(x)?"Yes\n":"No\n");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}