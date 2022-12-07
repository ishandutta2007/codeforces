#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define IT iterator
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
#define debug puts("wzpakking")
#define y1 ysghysgsygsh
using namespace std;
ll mul(ll x,ll y,ll mo){
	ll t=x*y-(ll)((long double)x/mo*y)*mo;
	return (t%mo+mo)%mo;
}
ll power(ll x,ll y,ll mo){
	ll s=1;
	for (;y;y/=2,x=mul(x,x,mo))
		if (y&1) s=mul(s,x,mo);
	return s;
}
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
const int P[]={0,2,3,5,7,11,13,17,19,23,29};
bool isprime(ll x){
	if (x==2) return 1;
	if (x%2==0) return 0;
	ll p=x-1,t=0;
	for (;p%2==0;p/=2,++t);
	For(T,1,10){
		if (x==P[T]) return 1;
		ll v=power(P[T],p,x);
		For(j,1,t){
			ll y=mul(v,v,x);
			if (y==1&&v!=1&&v!=x-1) return 0;
			v=y;
		}
		if (v!=1) return 0;
	}
	return 1;
}
ll pollard(ll x){
	ll y=rand()%x,z=y,c=1,i=0,j=2;
	for (;;){
		y=(mul(y,y,x)+c)%x;
		if (y==z) c++,y=z=rand()%x,i=0,j=2;
		else{
			ll v=gcd(z+x-y,x);
			if (v!=1&&v!=x) return v;
			if ((++i)==j) z=y,j<<=1;
		}
	}
}
const int N=200005;
int n,cnt[N];
ll X,Y,ans;
ll a[N],di[20];
void solve(ll x){
	if (x==1) return;
	//cout<<x<<endl;
	if (isprime(x)){
		di[++*di]=x;
		return;
	}
	ll v=pollard(x);
	assert(v!=1&&v!=x);
	solve(v); solve(x/v);
}
int get_sta(ll x){
	ll ans=0;
	For(i,1,*di)
		if (x%di[i]==0)
			ans|=1<<(i-1);
	return ans;
}
int main(){
	scanf("%d%lld%lld",&n,&X,&Y);
	if (Y%X) return puts("0"),0;
	solve(Y);
	sort(di+1,di+*di+1);
	*di=unique(di+1,di+*di+1)-di-1;
	//For(i,1,*di) cout<<di[i]<<endl;
	int all=(1<<(*di))-1,alll=get_sta(Y/X);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,n) if (a[i]%X==0)
		++cnt[get_sta(a[i]/X)&alll];
	For(i,0,(*di)-1) For(j,0,all)
		if (j&(1<<i)) cnt[j]+=cnt[j^(1<<i)];
	For(i,1,n) if (Y%a[i]==0)
		ans+=cnt[all^get_sta(Y/a[i])];
	printf("%lld\n",ans);
}