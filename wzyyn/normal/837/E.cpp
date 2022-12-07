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

ll x,y;
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
ll F(ll x,ll y){
	if (x==1) return y;
	ll T=1ll<<60;
	for (int i=1;1ll*i*i<=x;i++) if (x%i==0){
		if (i!=1) T=min(T,y%i);
		T=min(T,y%(x/i));
	}
	y-=T;
	ll G=gcd(x,y);
	x/=G; y/=G;
	return F(x,y)+T;
}
int main(){
	scanf("%lld%lld",&x,&y);
	ll G=gcd(x,y); x/=G; y/=G;
	printf("%lld\n",F(x,y));
}