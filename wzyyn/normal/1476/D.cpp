#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
using namespace std;
const int N=300005;
char s[N];
int f[N][2],g[N][2];
void solve(){
	int n;
	scanf("%d%s",&n,s+1);
	f[0][0]=f[0][1]=0;
	g[n][0]=g[n][1]=0;
	For(i,1,n){
		f[i][0]=(s[i]=='L'?f[i-1][1]+1:0);
		f[i][1]=(s[i]=='R'?f[i-1][0]+1:0);
	}
	Rep(i,n,1){
		g[i-1][0]=(s[i]=='R'?g[i][1]+1:0);
		g[i-1][1]=(s[i]=='L'?g[i][0]+1:0);
	}
	For(i,0,n) printf("%d ",f[i][0]+g[i][0]+1);
	puts("");
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}