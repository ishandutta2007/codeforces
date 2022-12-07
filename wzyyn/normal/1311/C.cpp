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
int n,m,ans[26];
int a[N][26];
char s[N];
void solve(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	For(i,0,25) ans[i]=0;
	For(i,1,n){
		memcpy(a[i],a[i-1],sizeof(a[i]));
		++a[i][s[i]-'a'];
	}
	while (m--){
		int x;
		scanf("%d",&x);
		For(j,0,25) ans[j]+=a[x][j];
	}
	For(i,0,25) printf("%d ",ans[i]+a[n][i]);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}