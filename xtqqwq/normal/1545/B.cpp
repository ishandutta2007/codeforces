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

const int N=100000,cys=998244353;
int n;
ll fac[100005],inv[100005];
char s[100005];

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	int T=readint();
	fac[0]=inv[0]=1;
	for(int i=1;i<=N;i++) fac[i]=fac[i-1]*i%cys;
	inv[N]=qpow(fac[N],cys-2);
	for(int i=N-1;i>=1;i--) inv[i]=inv[i+1]*(i+1)%cys;
	while(T--){
		n=readint();
		scanf("%s",s+1);
		int cnt=0,tmp=0;
		for(int i=2;i<=n;i++){
			if(s[i]==s[i-1]&&s[i]=='1') cnt++,i++;
		}
		for(int i=1;i<=n;i++) if(s[i]=='0') tmp++;
		printf("%lld\n",fac[cnt+tmp]*inv[cnt]%cys*inv[tmp]%cys);
	}
	return 0;
}