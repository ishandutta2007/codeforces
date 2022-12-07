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
#define all(v) v.begin(),v.end()
using namespace std;
const ll INF=1ll<<60;
ll n;
int c[15];
char s[15]={' ','c','o','d','e','f','o','r','c','e','s'};
int main(){
	ll n;
	scanf("%lld",&n);
	For(i,1,10) c[i]=1;
	for (;;){
		ll v=1;
		For(i,1,10) v*=c[i];
		if (v>=n) break;
		int p=1;
		For(i,1,10) if (c[i]<c[p]) p=i;
		++c[p];
	}
	For(i,1,10) For(j,1,c[i]) putchar(s[i]);
}