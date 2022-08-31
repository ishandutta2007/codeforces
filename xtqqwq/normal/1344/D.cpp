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

ll n,k;
ll a[100005],b[100005];
pll c[100005];

ll getsqrt(ll x){
	ll l=0,r=3000000000ll,ret;
	while(l<=r){
		ll mid=(l+r)/2;
		if(mid*mid<=x) ret=mid,l=mid+1;
		else r=mid-1;
	}
	return ret;
}

ll check(ll x){
	ll cnt=0;
	for(int i=1;i<=n;i++){
		if(x>a[i]-1) continue;
		ll tmp=getsqrt(3ull*(a[i]-x-1))/3;
		tmp=min(tmp,a[i]);
		while(3*tmp*tmp+3*tmp>a[i]-x-1) tmp--;
		cnt+=b[i]=tmp;
	}
	return cnt;
}

int main(){
	n=readint(); k=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll l=-3000000100000000000ll,r=1000000000,ret;
	while(l<=r){
		ll mid=(l+r)/2;
		if(check(mid)>=k) ret=mid,l=mid+1;
		else r=mid-1;
	}
//	cout<<"test "<<ret<<endl;
	ll now=check(ret),maxa=0;
	for(int i=1;i<=n;i++) c[i]=mp(-3*b[i]*b[i]-3*b[i]+a[i]-1,i);
	sort(c+1,c+n+1);
	for(int i=1;i<=now-k;i++) b[c[i].se]--;
	for(int i=1;i<=n;i++) printf("%lld ",b[i]);
	printf("\n");
	return 0;
}