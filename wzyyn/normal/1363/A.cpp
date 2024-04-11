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
#define double long double
using namespace std;
int k,n,x,a[2];
void solve(){
	scanf("%d%d",&n,&k);
	a[0]=a[1]=0;
	For(i,1,n) scanf("%d",&x),++a[x&1];
	if (!a[1]) puts("No");
	else if (k==n) puts(a[1]&1?"Yes":"No");
	else puts(a[0]||(k&1)?"Yes":"No");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}