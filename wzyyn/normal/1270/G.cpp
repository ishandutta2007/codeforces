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
const int N=1000005;
int n,a[N],q[N],vis[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) vis[i]=0; *q=0;
	int i,j;
	for (i=1;!vis[i];i=i-a[i]) vis[i]=1;
	for (j=i;!*q||j!=i;j=j-a[j]) q[++*q]=j;
	printf("%d\n",*q);
	ll S=0;
	For(i,1,*q) printf("%d ",q[i]),S+=a[q[i]];
	assert(S==0);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}
/*
1
7
-3 -5 -3 -3 4 4 4
*/