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
int n,Q,c[35];
ll query(int x){
	ll ned;
	scanf("%lld",&ned);
	ll sum=0;
	For(i,0,n-1) sum+=(1ll<<i)*c[i];
	if (sum<ned) return -1;
	// 
	
	sum=0;
	For(i,0,x) sum+=c[i];
	if (sum>=ned) return 0;
	
	//
	ned-=sum;
	sum=0;
	For(i,0,x)
		sum+=((1ll<<i)-1)*c[i];
	
	ll ans=1ll<<60;
	ll opp=0;
	int p=x+1;
	for (;p<n;++p){
		ll rnd=min(1ll*c[p],ned>>(p-x));
		ned-=rnd<<(p-x);
		opp+=((1ll<<(p-x))-1)*rnd;
		sum+=((1ll<<x)-1)*(1ll<<(p-x))*rnd;
		if (rnd<c[p]) break;
	}
	
	//cout<<sum<<' '<<ned<<' '<<"DEBUG "<<p<<' '<<sum<<endl;
	//assert(sum>ned);
	if (sum>=ned) ans=opp+ned;
	if (p>=n) return ans;
	
	for (;p>x;--p){
		++opp;
		if (p==x+1){
			ned-=2;
			sum+=2*((1ll<<x)-1);
			if (ned<=sum)
				ans=min(ans,opp+max(0ll,min(ned,sum)));
			break;
		}
		if (ned>=(1ll<<(p-x-1))){
			ned-=(1ll<<(p-x-1));
			opp+=(1ll<<(p-x-1))-1;
			sum+=((1ll<<x)-1)*(1ll<<(p-x-1));
		}
		if (ned<=sum)
			ans=min(ans,opp+min(ned,sum));
	}
	
	return ans;
}
int main(){
	scanf("%d%d",&n,&Q);
	For(i,0,n-1) scanf("%d",&c[i]);
	while (Q--){
		int tp,x;
		scanf("%d%d",&tp,&x);
		if (tp==1) scanf("%d",&c[x]);
		else printf("%lld\n",query(x));
	}
}