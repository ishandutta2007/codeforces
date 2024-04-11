#include<cstdio>
#include<algorithm>
#define ll long long
#define pii std::pair<ll,ll>
#define mp std::make_pair
#define fir first
#define sec second
#define N 100005

inline ll mul(ll a,ll b,ll P){
	ll res=0;
	a=(a%P+P)%P;
	b=(b%P+P)%P;
	for(;b;b>>=1,a=(a+a)%P)
		if(b&1)
			res=(res+a)%P;
	return res;
}
inline ll exgcd(ll a,ll b,ll &x,ll &y){
	if(!b){
		x=1;
		y=0;
		return a;
	}
	ll res=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return res;
}
pii crt(pii a,pii b){
	ll x,y,g=exgcd(a.sec,b.sec,x,y);
	if((a.fir-b.fir)%g!=0)
		return mp(-1,-1);
	pii res;
	res.sec=a.sec/g*b.sec;
	res.fir=(a.fir+a.sec*mul(x,(b.fir-a.fir)/g,b.sec/g)%res.sec+res.sec)%res.sec;
	return res;
}

ll n,m,k,a[N];

pii ans;

int main(){
	scanf("%lld%lld%lld",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%lld",&a[i]);
		if(i==1)
			ans=mp(-(i-1),a[i]);
		else
			ans=crt(ans,mp(-(i-1),a[i]));
		if(ans.sec==-1){
			puts("NO");
			return 0;
		}
		if(!ans.fir)
			ans.fir=ans.sec;
		if(ans.fir+k-1>n||ans.sec>m){
			puts("NO");
			return 0;
		}
//	printf("%lld %lld\n",ans.fir,ans.sec);
	}
	ll x,y;
	for(int i=1;i<=k;i++)
		if(exgcd(ans.fir+i-1,ans.sec,x,y)!=a[i]){
			puts("NO");
			return 0;
		}
	puts("YES");
}