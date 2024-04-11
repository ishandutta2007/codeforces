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
	int n,m,l1,r1,l2,r2;
	scanf("%d%d",&n,&m);
	scanf("%d%d",&l1,&r1);
	scanf("%d%d",&l2,&r2);
	int len1=max(r1,r2)-min(l1,l2);
	int len2=min(r1,r2)-max(l1,l2);
	if (len2>=0){
		ll v=1ll*len2*n;
		if (v>=m) puts("0");
		else if (1ll*len1*n>=m)	printf("%lld\n",m-1ll*len2*n);
		else printf("%lld\n",1ll*(len1-len2)*n+2ll*(m-1ll*len1*n));
	}
	else{
		ll ans=1ll<<60;
		For(i,1,n){
			ll val=0;
			if (1ll*i*len1<=m)
				val=1ll*i*(len1-len2)+2ll*(m-1ll*i*len1);
			else val=1ll*(m/len1)*(len1-len2)+(m%len1?m%len1-len2:0);
			ans=min(ans,val);
		}
		cout<<ans<<endl;
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}