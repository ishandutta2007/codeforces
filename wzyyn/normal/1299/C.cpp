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
int n,a[1000005];
pll q[1000005];
bool cmp(pll a,pll b){
	return 1ll*a.fi*b.se<1ll*b.fi*a.se;
}
int main(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	int t=0;
	For(i,1,n){
		pll tmp(a[i],1);
		for (;t&&cmp(tmp,q[t]);--t){
			tmp.fi+=q[t].fi;
			tmp.se+=q[t].se;
		}
		q[++t]=tmp;
	}
	For(i,1,t)
		For(j,1,q[i].se)
			printf("%.10lf\n",q[i].fi*1.0/q[i].se);
}