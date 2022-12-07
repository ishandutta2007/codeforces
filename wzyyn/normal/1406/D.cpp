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
const int N=100005;
int n;
int a[N];
ll di[N];
ll MD(ll x){
	if (x>=0) return x/2;
	return -((-x+1)/2);
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n-1) di[i]=a[i+1]-a[i];
	ll ed=a[n],sn=0;
	For(i,1,n-1) if (di[i]<0) sn+=di[i];
	int Q;
	scanf("%d",&Q);
	printf("%lld\n",MD(ed-sn+1));
	while (Q--){
		int l,r,x;
		scanf("%d%d%d",&l,&r,&x);
		if (r==n) ed+=x;
		if (l!=1){
			if (di[l-1]<0) sn-=di[l-1];
			di[l-1]+=x;
			if (di[l-1]<0) sn+=di[l-1];
		}
		if (r<n){
			if (di[r]<0) sn-=di[r];
			di[r]-=x;
			if (di[r]<0) sn+=di[r];
		}
		printf("%lld\n",MD(ed-sn+1));
	}
}