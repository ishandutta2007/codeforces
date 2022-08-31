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
char s[11]={' ','c','o','d','e','f','o','r','c','e','s'};

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x) if(p&1) ret=ret*x;
	return ret;
}

int main(){
	n=readint();
	ll x=0;
	for(int i=1;i<=100;i++){
		if(qpow(i,10)<=n) x=i;
		else break;
	}
	ll t=qpow(x,10),cnt=0;
	while(t<n) cnt++,t=t/x*(x+1);
	for(int i=1;i<=cnt;i++) for(int j=1;j<=x+1;j++) printf("%c",s[i]);
	for(int i=cnt+1;i<=10;i++) for(int j=1;j<=x;j++) printf("%c",s[i]);
	printf("\n");
	return 0;
}