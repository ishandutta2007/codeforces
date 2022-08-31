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

const int cys=998244353,inv6=(cys+1)/6;
int n;
ll d[1000005];

int main(){
	n=readint();
	if(n==1) return printf("5\n"),0;
	d[0]=1,d[1]=3;
	for(int i=1;i<=n;i++) d[i]=(d[i-1]+(d[i-1]-d[i-2])+d[i-1]*(d[i-1]+1)/2-d[i-2]*(d[i-2]+1)/2)%cys;
	ll ans=(d[n]-d[n-1]-(d[n-1]-d[n-2])+(d[n-1]+2)*(d[n-1]+1)%cys*d[n-1]%cys*inv6-(d[n-2]+2)*(d[n-2]+1)%cys*d[n-2]%cys*inv6)%cys;
	if(ans<0) ans+=cys;
	ans=ans*2%cys;
	for(int i=1;i<=n;i++){
		ll lf=d[i-1]-(i-1?d[i-2]:0);
		if(lf<0) lf+=cys;
		ll rg=d[n-i]-(n-i?d[n-i-1]:0);
		if(n-i-1) rg-=d[n-i-1]-d[n-i-2];
		else if(n-i) rg-=d[n-i-1];
		rg%=cys;
		if(rg<0) rg+=cys;
		ans=(ans+lf*rg)%cys;
	}
	printf("%lld\n",ans);
	return 0;
}