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
int n;
ll h[1000005];
ll res[1000005];
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%lld",&h[i]);
	ll sum=0;
	For(i,1,n) sum+=h[i];
	For(i,1,n) res[i]=i-1,sum-=i-1;
	int p=1;
	for (;sum%n;sum--,++res[p++]);
	For(i,1,n) printf("%lld ",res[i]+sum/n);
}