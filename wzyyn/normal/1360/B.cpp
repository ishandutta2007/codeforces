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
	int n,a[1005];
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	int v=1<<30;
	For(i,2,n) v=min(v,a[i]-a[i-1]);
	printf("%d\n",v);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve(); 
}