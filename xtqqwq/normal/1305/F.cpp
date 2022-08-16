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

int n,tot;
ll prm[1000005],a[200005];
bool fl[1000005];
vector<ll> dv;

void getprime(int N){
	fl[1]=1;
	for(int i=2;i<=N;i++){
		if(!fl[i]) prm[++tot]=i;
		for(int j=1;j<=tot&&i*prm[j]<=N;j++){
			fl[i*prm[j]]=1;
			if(i%prm[j]==0) break;
		}
	}
}

void getdiv(ll x){
	dv.clear();
	for(int i=1;i<=tot&&prm[i]<=sqrt(x);i++){
		if(x%prm[i]==0){
			dv.push_back(prm[i]);
			while(x%prm[i]==0) x/=prm[i];
		}
	}
	if(x>1) dv.push_back(x);
}

ll check(ll x){
	getdiv(x);
	ll ret=1ll<<60;
	for(auto r:dv){
		ll ans=0;
		for(int i=1;i<=n;i++){
			ll tmp=a[i]%r;
			ans+=min(a[i]==tmp?(1ll<<60):tmp,r-tmp);
		}
		chkmin(ret,ans);
	}
	return ret;
}

int main(){
	getprime(1000000);
	srand(time(0)^(unsigned long long)(new char));
	n=readint();
	for(int i=1;i<=n;i++) a[i]=readint();
	ll ans=1ll<<60;
	for(int i=1;i<=20;i++){
		ll x=((ll)rand()*RAND_MAX+rand())%n+1;
		chkmin(ans,check(a[x]));
		if(a[x]>1) chkmin(ans,check(a[x]-1));
		chkmin(ans,check(a[x]+1));
	}
	printf("%lld\n",ans);
	return 0;
}