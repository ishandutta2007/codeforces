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
const int N=200005;
int n,a[N],c[N];
void solve(){
	scanf("%d",&n);
	For(i,1,n) c[i]=0;
	For(i,1,n) scanf("%d",&a[i]),c[a[i]]++;
	pii ans(1<<30,-1);
	For(i,1,n) if (c[a[i]]==1) ans=min(ans,pii(a[i],i));
	cout<<ans.se<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}