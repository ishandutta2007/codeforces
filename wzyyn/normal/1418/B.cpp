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
int n,a[100005],b[100005],q[100005];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) scanf("%d",&b[i]);
	*q=0;
	For(i,1,n) if (!b[i]) q[++*q]=a[i];
	sort(q+1,q+*q+1);
	For(i,1,n) if (!b[i]) a[i]=q[(*q)--];
	For(i,1,n) printf("%d%c",a[i],(i==n?'\n':' '));
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}