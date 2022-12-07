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

ll Q1(ll p){
	ll fi=1;
	for (;p>fi;p-=fi,fi*=4);
	return p+fi-1;
}
int mp[4]={0,2,3,1};
ll Q2(ll p){
	ll fi=1;
	for (;p>fi;p-=fi,fi*=4);
	ll ans=fi*2,k=1;
	for (p--;p;ans+=mp[p%4]*k,p/=4,k*=4);
	return ans;
}
int tmp;
void solve(){
	ll n=++tmp;
	scanf("%lld",&n);
	if (n%3==1) printf("%lld\n",Q1(n/3+1));
	if (n%3==2) printf("%lld\n",Q2(n/3+1));
	if (n%3==0) printf("%lld\n",Q1(n/3)^Q2(n/3));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}