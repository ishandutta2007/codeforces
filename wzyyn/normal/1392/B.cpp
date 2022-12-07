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
int n;
ll k;
int a[200005];
void solve(){
	scanf("%d%lld",&n,&k);
	int mn=1e9,mx=-1e9;
	For(i,1,n){
		scanf("%d",&a[i]);
		mn=min(mn,a[i]);
		mx=max(mx,a[i]);
	}
	if (k&1){
		For(i,1,n)
			printf("%d ",mx-a[i]);
		puts("");
	}
	else{
		For(i,1,n)
			printf("%d ",a[i]-mn);
		puts("");
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}