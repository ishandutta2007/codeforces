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
const int N=2005;
int n,m,ans;
char s[N][N];
int a[N][N];
int b[N][N];
int c[N][N];
int d[N][N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	s[0][1]=s[0][m]=s[n+1][0]=s[n+1][m]='?';
	For(i,1,n) For(j,1,m) a[i][j]=(s[i-1][j]==s[i][j-1]&&s[i-1][j]==s[i][j]?min(a[i-1][j],a[i][j-1])+1:0);
	Rep(i,n,1) For(j,1,m) b[i][j]=(s[i+1][j]==s[i][j-1]&&s[i+1][j]==s[i][j]?min(b[i+1][j],b[i][j-1])+1:0);
	For(i,1,n) Rep(j,m,1) c[i][j]=(s[i-1][j]==s[i][j+1]&&s[i-1][j]==s[i][j]?min(c[i-1][j],c[i][j+1])+1:0);
	Rep(i,n,1) Rep(j,m,1) d[i][j]=(s[i+1][j]==s[i][j+1]&&s[i+1][j]==s[i][j]?min(d[i+1][j],d[i][j+1])+1:0);
	For(i,1,n) For(j,1,m) ans+=min(min(a[i][j],b[i][j]),min(c[i][j],d[i][j]))+1;
	cout<<ans<<endl;
}