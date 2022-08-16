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

int n;
pll cnt[25];

int main(){
	n=readint();
	for(int i=0;i<20;i++) cnt[i].se=i;
	ll x;
	for(int i=1;i<=n;i++){
		x=readint();
		for(int j=0;j<20;j++) if(x&(1<<j)) cnt[j].fi++;
	}
	sort(cnt,cnt+20);
	ll lst=0,now=(1<<20)-1,ans=0;
	for(int i=0;i<20;i++){
		ans+=(cnt[i].fi-lst)*now*now;
		now-=(1<<cnt[i].se);
		lst=cnt[i].fi;
	}
	printf("%lld\n",ans);
	return 0;
}