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
int n,m,x,y,ans;
char s[105][1005];
void solve(){
	scanf("%d%d%d%d",&n,&m,&x,&y);
	ans=0; y=min(y,2*x);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) For(j,1,m)
		if (s[i][j]=='.'&&s[i][j+1]=='.')
			ans+=y,s[i][j]=s[i][j+1]='*';
		else if (s[i][j]=='.') ans+=x;
	printf("%d\n",ans);
}
int main(){
	int T;
	scanf("%d",&T);
	while (T--) solve();
}