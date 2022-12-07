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

void solve(){
	ll k; int n;
	scanf("%d%lld",&n,&k);
	int l=2,r=n,p;
	while (l<=r){
		int mid=(l+r)/2;
		if (1ll*mid*(mid-1)/2>=k)
			p=mid,r=mid-1;
		else l=mid+1;
	}
	int p1=p,p2=k-1ll*(p-1)*(p-2)/2;
	For(i,1,n) putchar(n-i+1==p1||n-i+1==p2?'b':'a');
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}