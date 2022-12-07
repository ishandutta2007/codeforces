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
int n,a[100005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	if (a[1]+a[2]<=a[n]) printf("%d %d %d\n",1,2,n);
	else puts("-1"); 
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}