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

int n,e,tot;
int now[200005],lst[200005],nxt[200005],a[200005],prm[1000005];
bool fl[1000005];

void getprime(int m){
	fl[1]=1;
	for(int i=2;i<=m;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=m;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

int main(){
	int T=readint();
	getprime(1000000);
	while(T--){
		n=readint(); e=readint();
		for(int i=1;i<=n;i++) a[i]=readint();
		for(int i=0;i<e;i++) now[i]=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1);
			else if(!fl[a[i]]) lst[i]=now[i%e],now[i%e]=i;
			else now[i%e]=i;
		}
		for(int i=0;i<e;i++) now[i]=n+1;
		for(int i=n;i>=1;i--){
			if(a[i]==1);
			else if(!fl[a[i]]) nxt[i]=now[i%e],now[i%e]=i;
			else now[i%e]=i;
		}
		ll ans=0;
		for(int i=1;i<=n;i++){
			if(fl[a[i]]) continue;
			int lf=(i-lst[i]-1)/e,rg=(nxt[i]-i-1)/e;
			ans=(ans+1ll*(lf+1)*(rg+1)-1);
		}
		printf("%lld\n",ans);
	}
	return 0;
}