#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
#define pll pair<ll,ll> 
#define y1 orzkcz
using namespace std;

void solve(){
	int n,a,b,c,d;
	scanf("%d%d%d%d%d",&n,&a,&b,&c,&d);
	
	For(i,0,1) For(j,0,1) For(k,0,1) For(l,0,1)
		if (a-i-j>=0&&a-i-j<=n-2)
		if (b-j-k>=0&&b-j-k<=n-2)
		if (c-k-l>=0&&c-k-l<=n-2)
		if (d-l-i>=0&&d-l-i<=n-2)
			return puts("YES"),void(0);
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}