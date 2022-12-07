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
ll mul(ll x,ll y,ll moo){
	return (x*y-(ll)((long double)x/moo*y)*moo+moo)%moo;
	//return (t%moo+moo)%moo;
}
ll power(ll x,ll y,ll moo){
	ll s=1;
	for (;y;y/=2,x=mul(x,x,moo))
		if (y&1) s=mul(s,x,moo);
	return s;
}
const int pri[]={3,5,7,11,13,17,19,23,29,31,37,41};
bool Miller_rabin(ll n){
	if (n==2) return 1;
	if (n==1||n%2==0) return 0;
	ll y=n-1,d=0;
	for (;y%2==0;y/=2,d++);
	For(i,0,11){
		if (n%pri[i]==0) return n==pri[i];
		ll v=power(pri[i],y,n);
		For(j,0,d){
			ll vv=mul(v,v,n);
			if (vv==1&&v!=1&&v!=n-1) return 0;
			v=vv;
		}
		if (v!=1) return 0;
	}
	return 1;
}
ll gcd(ll x,ll y){
	ll v=1;
	for (;x&&y;){
		//cout<<x<<' '<<y<<endl;
		for (;!(x&1)&&!(y&1);x>>=1,y>>=1,v<<=1);
		for (;!(x&1);x>>=1);
		for (;!(y&1);y>>=1);
		x>y?x-=y:y-=x;
	}
	return v*(x+y);
}
ll find_Divisor(ll n){
	for (int c=1;;++c){
		ll x=rand()%n,y=x,t1=1,t2=2;
		for (;;){
			ll z=(mul(x,x,n)+c)%n;
			if (y==z) break;
			ll v=gcd(y-z+n,n);
			if (v!=1&&v!=n) return v;
			if ((++t1)==t2) y=z,t2<<=1;
			x=z;
		}
	}
}
int n;
ll m,b,p,e;
ll di[555];
void factorize(ll n){
	//cout<<"F "<<n<<endl;
	if (n==1) return;
	if (Miller_rabin(n)){
		di[++*di]=n;
		return;
	}
	ll v=find_Divisor(n);
	factorize(v);
	factorize(n/v);
}
int main(){
	scanf("%d%lld%lld",&n,&m,&b);
	for (int i=2;(1ll<<i)<=m;++i){
		ll v=floor(pow(m,1.0/i)+0.5);
		if (!power(v,i,m)) p=v,e=i; 
	}
	if (!p) p=m,e=1;
	if (e!=1) di[++*di]=p;
	factorize(p-1);
	if (b%p==0) b=1;
	ll phi=m-m/p,ord=phi;
	For(i,1,*di)
		for (;ord%di[i]==0;ord/=di[i])
			if (power(b,ord/di[i],m)!=1)
				break;
	if (phi-ord<n) return puts("-1"),0;
	int pos=1;
	//cout<<"axiba"<<endl;
	//cout<<ord<<endl;
	//cout<<p<<' '<<e<<endl;
	For(i,1,n){
		for (;;++pos) if (pos%p){
			if (power(pos,ord,m)!=1) break;
			if (p==2&&e>=3){
				if (ord>=2&&power(pos,ord/2,m)==1){
					if (pos%8!=1) break;
				}
				else{
					if (pos%8!=b%8) break;
				}
			}
		}
		printf("%d\n",pos);
		++pos;
	}
}