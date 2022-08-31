#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n1,n2,n3;
ll a1[100005],a2[100005],a3[100005];

ll sqr(ll x){return x*x;}
ll getans(ll x,ll y,ll z){return sqr(a1[x]-a2[y])+sqr(a2[y]-a3[z])+sqr(a3[z]-a1[x]);}

int main(){
	int T=readint();
	while(T--){
		n1=readint(); n2=readint(); n3=readint();
		for(int i=1;i<=n1;i++) a1[i]=readint();
		for(int i=1;i<=n2;i++) a2[i]=readint();
		for(int i=1;i<=n3;i++) a3[i]=readint();
		sort(a1+1,a1+n1+1);
		sort(a2+1,a2+n2+1);
		sort(a3+1,a3+n3+1);
		int now2=1,now3=1;
		ll ans=1ll<<61;
		for(int i=1;i<=n1;i++){
			while(now2<=n2&&a2[now2]<=a1[i]) now2++;
			while(now3<=n3&&a3[now3]<=a1[i]) now3++;
			if(now2>1){
				ll x=a1[i],y=a2[now2-1];
				int pl=upper_bound(a3+1,a3+n3+1,(x+y)/2)-a3;
				if(pl>1) chkmin(ans,getans(i,now2-1,pl-1));
				if(pl<=n3) chkmin(ans,getans(i,now2-1,pl));
			}
			if(now2<=n2){
				ll x=a1[i],y=a2[now2];
				int pl=upper_bound(a3+1,a3+n3+1,(x+y)/2)-a3;
				if(pl>1) chkmin(ans,getans(i,now2,pl-1));
				if(pl<=n3) chkmin(ans,getans(i,now2,pl));
			}
			if(now3>1){
				ll x=a1[i],z=a3[now3-1];
				int pl=upper_bound(a2+1,a2+n2+1,(x+z)/2)-a2;
				if(pl>1) chkmin(ans,getans(i,pl-1,now3-1));
				if(pl<=n2) chkmin(ans,getans(i,pl,now3-1));
			}
			if(now3<=n3){
				ll x=a1[i],z=a3[now3];
				int pl=upper_bound(a2+1,a2+n2+1,(x+z)/2)-a2;
				if(pl>1) chkmin(ans,getans(i,pl-1,now3));
				if(pl<=n2) chkmin(ans,getans(i,pl,now3));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}