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
int n,a[N],s[N][205];
vector<int> v[N];
void solve(){
	scanf("%d",&n);
	For(i,1,200) v[i].resize(0);
	For(i,1,n) scanf("%d",&a[i]);
	For(i,1,n) v[a[i]].PB(i);
	For(i,1,n) For(j,1,200) s[i][j]=s[i-1][j]+(a[i]==j);
	int ans=0;
	For(i,1,200) ans=max(ans,s[n][i]);
	For(i,1,200) For(j,1,v[i].size()/2){
		int pl=v[i][j-1],pr=v[i][v[i].size()-j];
		For(k,1,200) ans=max(ans,2*j+s[pr-1][k]-s[pl][k]);
	}
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}