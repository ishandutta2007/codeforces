#include<bits/stdc++.h>
#define ll long long
#define uint unsigned
#define ull unsigned ll
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a))
#define CPY(a,b) memcpy(a,b,sizeof(a))
using namespace std;
const int N=1000005;
int n,m,top;
pii q[N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) For(j,1,m) q[++top]=pii(i,j);
	int h=1,t=top;
	for (;h<=t;){
		if (h<=t) printf("%d %d\n",q[h].fi,q[h].se),++h;
		if (h<=t) printf("%d %d\n",q[t].fi,q[t].se),--t;
	}
}