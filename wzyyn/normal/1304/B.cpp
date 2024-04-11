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
const int N=105;
int n,m,ans,vis[N];
char s[N][N];
int main(){
	scanf("%d%d",&n,&m);
	For(i,1,n) scanf("%s",s[i]+1);
	For(i,1,n) if (!vis[i])
		For(j,i+1,n) if (!vis[i]&&!vis[j]){
			bool flg=0;
			For(k,1,m) if (s[i][k]!=s[j][m-k+1]) flg=1;
			if (!flg) vis[i]=j,vis[j]=i,ans+=2;
		}
	int idd=0;
	For(i,1,n) if (!vis[i]){
		bool flg=0;
		For(j,1,m) if (s[i][j]!=s[i][m-j+1]) flg=1;
		if (!flg) idd=i;
	}
	if (idd) ++ans;
	printf("%d\n",ans*m);
	For(i,1,n) if (vis[i]&&i<vis[i]) printf("%s",s[i]+1);
	if (idd) printf("%s",s[idd]+1);
	Rep(i,n,1) if (vis[i]&&i<vis[i]) printf("%s",s[vis[i]]+1);
}