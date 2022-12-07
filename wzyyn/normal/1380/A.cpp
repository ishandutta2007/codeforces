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
#define all(v) v.begin(),v.end()
using namespace std;
int n,p[10005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&p[i]);
	For(i,2,n-1) if (p[i]>p[i-1]&&p[i]>p[i+1])
		return printf("YES\n%d %d %d\n",i-1,i,i+1),void(0);
	puts("NO");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}