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

ll readint(){
	ll x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n;

ll get1(ll n){
	int maxa=0;
	for(int i=0;i<=60;i+=2) if(n>=(1ll<<i)) maxa=i;
	return n/3-(1ll<<maxa)/3+(1ll<<maxa);
}

ll get2(ll n){
	int maxa=0;
	for(int i=0;i<=60;i+=2) if(n>=(1ll<<i)) maxa=i;
	ll tmp=(n-(1ll<<maxa)-1)/3;
	ll ans=(1ll<<(maxa+1));
	for(int i=0;i<=30;i++){
		int ts=(tmp>>(i*2))&3;
		if(ts==0);
		else if(ts==1) ans+=2*(1ll<<(2*i));
		else if(ts==2) ans+=3*(1ll<<(2*i));
		else ans+=(1ll<<(2*i));
	}
	return ans;
}

int main(){
	int T=readint();
	while(T--){
		n=readint();
		if(n%3==1){
			printf("%lld\n",get1(n));
		}
		else if(n%3==2){
			printf("%lld\n",get2(n));
		}
		else{
			printf("%lld\n",get1(n-2)^get2(n-1));
		}
	}
	return 0;
}