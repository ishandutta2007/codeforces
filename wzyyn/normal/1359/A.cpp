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

void solve(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	if (m<=n/k) printf("%d\n",m);
	else{
		int rem=m-n/k;
		printf("%d\n",n/k-(rem+k-2)/(k-1));
	}
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}