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
int n,a[500005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	ll ans=1ll<<60;
	for (int i=1;;i++){
		ll v=1,res=0;
		For(j,1,n){
			res+=abs(a[j]-v);
			if (j!=n&&(1ll<<35)/v<i){
				res=1ll<<60;
				break;
			}
			v*=i;
		}
		if (res>1ll<<50) break;
		ans=min(ans,res);
	}
	cout<<ans<<endl;
}