#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
#define ll long long
#define ull unsigned long long
using namespace std;
const int N=505;
char s[N][N];
int n,m,f[N][N];
void solve(){
	int ans=0;
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,0,n+1) For(j,0,m+1) f[i][j]=0;
	Rep(i,n,1) For(j,1,m)
		if (s[i][j]=='.') f[i][j]=0;
		else ans+=(f[i][j]=min(min(f[i+1][j],f[i+1][j-1]),f[i+1][j+1])+1);
	cout<<ans<<endl;
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}