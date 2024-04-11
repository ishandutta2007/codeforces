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
const int N=300005;
int n;
ll l,r;
void solve(){
	scanf("%d%lld%lld",&n,&l,&r);
	ll p=0;
	For(i,1,n-1){
		ll pl=p+1,pr=p+2*(n-i);
		ll ppl=max(pl,l),ppr=min(pr,r);
		if (ppl<=ppr){
			//cerr<<"DEBUG "<<ppl<<' '<<ppr<<' '<<i<<endl;
			for (ll j=ppl;j<=ppr;j++)//For(j,ppl,ppr)
				if (j%2==1) printf("%d ",i);
				else printf("%d ",(j-p)/2+i);
		}
		p=pr;
	}
	if (r>p) printf("1 ");
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1 2 1 3         2 3 1
1 2 1 3 1 4     2 3 2 4 3 4 1
1 2 1 3 1 4 1 5 2 3 2 4 2 5 3 4 3 5 4 5 1
*/