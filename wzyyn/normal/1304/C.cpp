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
int T[505],L[505],R[505],n;
void solve(){
	int l=0,r=0,c;
	scanf("%d%d",&n,&c);
	l=r=c;
	For(i,1,n) scanf("%d%d%d",&T[i],&L[i],&R[i]);
	For(i,1,n){
		l=max(l-(T[i]-T[i-1]),L[i]);
		r=min(r+(T[i]-T[i-1]),R[i]);
		if (l>r) return puts("NO"),void(0);
	}
	puts("YES");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}