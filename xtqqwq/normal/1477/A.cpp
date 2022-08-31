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
ll a[200005];

int main(){
	int T=readint();
	while(T--){
		n=readint(); k=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=1;i<n;i++) a[i]-=a[n];
		k-=a[n];
		ll g=0;
		for(int i=1;i<n;i++) g=__gcd(g,a[i]);
		if(k%g==0) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}