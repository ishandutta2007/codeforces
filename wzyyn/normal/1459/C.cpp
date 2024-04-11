#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
int n,m;
ll a[200005];
ll b[200005];
ll gcd(ll x,ll y){
	return y?gcd(y,x%y):x;
}
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%lld",&a[i]);
	For(i,1,m) scanf("%lld",&b[i]);
	ll G=0;
	For(i,2,n) G=gcd(G,abs(a[i]-a[1]));
	For(i,1,m) printf("%lld ",gcd(G,a[1]+b[i]));
}