#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define For(i,x,y) for(ll i = (ll)(x);i <= (ll)(y);++i)
#define rep(i,x,y) for(ll i = (ll)(x);i < (ll)(y);++i)
#define FOr(i,x,y) for(ll i = (ll)(x);i >= (ll)(y);--i)
#define fi first
#define se second
#define cpy(a,b) memcpy(a,b,sizeof (b))
#define fi first 
#define se second
#define pa pair<ll,ll>
#define y1 yyyyyyyyyyyyyyyyy
#define pb push_back
#define mk make_pair
#define debug puts("@@@@@@@@@@@@@@@@@@@@@@@")
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
void write(ll x){
	if (x<0)putchar('-'),x=-x;
	if (x>=10)write(x/10);
	putchar(x%10+'0');
}
const ll N=1600010,mod=998244353;
ll n,k,A,B,C,D,E,F,a[N],b[N],ans[N];
void Or(ll x,ll y){
	cout<<"or "<<x<<' '<<y<<endl;
	fflush(stdout);
}
void And(ll x,ll y){
	cout<<"and "<<x<<' '<<y<<endl;
	fflush(stdout);
}
ll q(ll x,ll i){return x>>i&1;}
int main(){
	n=read();	k=read();
	For(i,2,n){
		Or(1,i);
		a[i]=read();
		And(1,i);
		b[i]=read();
	}
	Or(2,3);	A=read();
	And(2,3);	B=read();
	C=a[2];D=b[2];
	E=a[3];F=b[3]; 
	ll lbc=0;
	For(i,0,30)
		lbc|=((q(C,i)+q(D,i)+q(E,i)+q(F,i)-q(A,i)-q(B,i))>0)<<i;
	For(i,1,n)ans[i]=lbc^a[i]^b[i];
	sort(ans+1,ans+n+1);
	cout<<"finish"<<' '<<ans[k]<<endl; 
}