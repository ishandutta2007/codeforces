// xtqqwq
#include<bits/stdc++.h>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template<typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template<typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
ll a[20];

int main(){
	int T=readint();
	while(T--){
		n=readint();
		ll x,y=1;
		for(int i=1;i<=n;i++){
			x=readint();
			while(x%2==0) y<<=1,x>>=1;
			a[i]=x;
		}
		sort(a+1,a+n+1);
		ll ans=a[n]*y;
		for(int i=1;i<n;i++) ans+=a[i];
		printf("%lld\n",ans);
	}
	return 0;
}