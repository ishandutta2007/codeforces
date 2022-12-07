#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=300005;
int cnt[66666];
int n,a[N];
ll b[N],S;
int count(ll x){
	return cnt[x&65535]+cnt[(x>>16)&65535]+
		   cnt[(x>>32)&65535]+cnt[(x>>48)&65535];
}
int main(){
	For(i,0,(1<<16)-1) cnt[i]=cnt[i/2]+(i&1);
	scanf("%d",&n);
	For(i,1,n){
		scanf("%d%lld",&a[i],&b[i]);
		S+=a[i];
	}
	if (S<0){
		For(i,1,n) a[i]*=-1;
		S*=-1;
	}
	ll ans=0;
	Rep(i,61,0){
		ans|=(1ll<<i);
		ll tmp=0,val=(1ll<<i)-1;
		For(j,1,n){
			if (!(b[j]&val))
				if (count(b[j]&ans)&1)
					tmp-=a[j];
				else tmp+=a[j];
		}
		if (tmp>=0)
			ans^=(1ll<<i);
	}
	printf("%lld\n",ans);
}
/*
f[1]=f[0]-f[1];
f[0]=f[0]+f[1];
*/