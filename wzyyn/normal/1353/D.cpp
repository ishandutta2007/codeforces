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
int n,a[200005];
priority_queue<pii> Q;
void solve(){
	*a=0;
	scanf("%d",&n);
	Q.push(pii(n,-1));
	while (!Q.empty()){
		pii x=Q.top(); Q.pop(); x.se*=-1;
		//cout<<x.fi<<' '<<x.se<<endl;
		int p=x.se+(x.fi-1)/2,l=x.se,r=x.se+x.fi-1; a[p]=++*a;
		if (p!=l) Q.push(pii(p-l,-l));
		if (p!=r) Q.push(pii(r-p,-(p+1)));
	}
	For(i,1,n) printf("%d ",a[i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}