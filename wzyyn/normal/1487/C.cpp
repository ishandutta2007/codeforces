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
	int n;
	scanf("%d",&n);
	For(i,1,n) For(j,i+1,n)
		if ((j-i)*2==n) printf("0 ");
		else printf((j-i)*2<=n?"-1 ":"1 ");
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}