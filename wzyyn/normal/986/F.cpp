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


struct Qnode{
	ll n,k;
	int id;
	bool operator <(const Qnode &a)const{
		return k<a.k;
	}
}a[10005];
int n,flg[10005];

const int pri[]={2,2333,17};
ll di[55],f[100005];
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
ll isprime(ll k){
	if (k==2) return 1;
	if (k==1||k%2==0) return 0;
	ll x=k-1,y=0;
	for (;x%2==0;x>>=1,++y);
	For(T,0,2){
		if (k==pri[T]) return 1;
		if (k%pri[T]==0) return 0;
		ll v=power(pri[T]%k,x,k);
		For(i,1,y){
			ll vv=mul(v,v,k);
			if (v!=1&&v!=k-1&&vv==1) return 0;
			v=vv;
		}
		if (v!=1) return 0;
	}
	return 1;
}
ll find_di(ll k){
	for (int c=0;;++c){
		ll x=rand()%k,y=x;
		int p1=0,p2=1;
		for (;;){
			y=(mul(y,y,k)+c)%k;
			ll v=gcd(k,y+k-x);
			if (v!=1&&v!=k) return v;
			if (x==y) break;
			if ((++p1)==p2) p2<<=1,x=y;
		}
	}
}
void Pollard(ll k){
	//cout<<k<<' '<<find_endl;
	if (k==1) return;
	if (isprime(k)){
		di[++*di]=k;
		return;
	}
	//cout<<"AAA "<<k<<endl;
	//cout<<"AAA "<<k<<' '<<find_di(k)<<endl;
	ll v=find_di(k);
	Pollard(v);
	Pollard(k/v);
}
void solve(int l,int r){
	//cout<<l<<' '<<r<<endl;
	*di=0;
	Pollard(a[l].k);
	sort(di+1,di+*di+1);
	*di=unique(di+1,di+*di+1)-di-1;
	if (*di==0){
		For(i,l,r)
			flg[a[i].id]=(a[i].n==0);
	}
	else if (*di==1){
		For(i,l,r)
			flg[a[i].id]=(a[i].n%di[1]==0);
	}
	else if (*di==2){
		ll a=di[1],b=di[2];
		ll Inv=power(b%a,a-2,a);
		For(i,l,r){
			ll T=1ll*(::a[i].n%a)*Inv%a;
			flg[::a[i].id]=(::a[i].n/b>=T);
		}
	}
	else{
		ll a=di[1];
		For(i,0,a-1) f[i]=(i?1ll<<60:0);
		For(i,2,*di){
			int x=0;
			For(T,1,2*a){
				int y=(x+di[i])%a;
				f[y]=min(f[y],f[x]+di[i]);
				x=y;
			}
		}
		For(i,l,r) flg[::a[i].id]=(f[::a[i].n%a]<=::a[i].n);
	}
	//For(i,1,*di) cout<<di[i]<<' '; cout<<endl;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld%lld",&a[i].n,&a[i].k);
	For(i,1,n) a[i].id=i;
	sort(a+1,a+n+1);
	for (int l=1,r;l<=n;l=r){
		for (r=l;r<=n&&a[r].k==a[l].k;++r);
		solve(l,r-1);
	}
	For(i,1,n)
		puts(flg[i]?"YES":"NO");
}
/*
5
1 21
1 23
1 27
1 35
1 105
*/