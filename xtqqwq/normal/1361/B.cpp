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

const int cys=1000000007;
int n,p;
int k[1000005],cnt[2][1000005];
vector<int> gar;

ll mod(ll x){return x>=cys?x-cys:x;}

ll qpow(ll x,ll p){
	ll ret=1;
	for(;p;p>>=1,x=x*x%cys) if(p&1) ret=ret*x%cys;
	return ret;
}

int main(){
	int T=readint();
	while(T--){
		n=readint(); p=readint();
		for(int i=1;i<=n;i++) k[i]=readint();
		if(p==1){
			printf("%d\n",n&1);
			continue;
		}
		sort(k+1,k+n+1);
		reverse(k+1,k+n+1);
		gar.clear();
		int now=0,maxa=-1;
		for(int i=1;i<=n;i++){
			cnt[now][k[i]]++;
			if(k[i]>maxa) now^=1,maxa=k[i];
			else if(k[i]==maxa) cnt[0][maxa]--,cnt[1][maxa]--,maxa=-1;
			else{
				int pl=k[i];
				while(cnt[now][pl]==p){
					cnt[now][pl]=0,cnt[now][pl+1]++;
					pl++;
					gar.pb(pl);
				}
				if(pl==maxa) cnt[0][maxa]--,cnt[1][maxa]--,maxa=-1;
			}
		}
		if(maxa>=0){
			ll ans=qpow(p,maxa);
			for(int i=1;i<=n;i++)
				if(cnt[now][k[i]])
					ans=mod(ans+cys-cnt[now][k[i]]*qpow(p,k[i])%cys),cnt[now][k[i]]=0;
			for(auto x:gar)
				if(cnt[now][x])
					ans=mod(ans+cys-cnt[now][x]*qpow(p,x)%cys),cnt[now][x]=0;
			cnt[now^1][maxa]=0;
			printf("%lld\n",ans);
		}
		else printf("0\n");
	}
	return 0;
}