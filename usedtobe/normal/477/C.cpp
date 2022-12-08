#include<cstring>
#include<cstdio>
#include<algorithm>
#include<set>
#include<cmath>
#include<vector>
#include<map>
#include<iostream>
#define rep(i,a,b) for (int i=a;i<=b;++i)
#define dep(i,a,b) for (int i=a;i>=b;--i)
#define For(i,u) for (int i=H[u];i;i=nxt[i])
#define re(it,a) for (it=a.begin();it!=a.end();++it)
#define mod 1000000007 
#define N 2005
#define pb push_back
#define all(x) x.begin(),x.end() 
#define mp make_pair
#define INF 1<<30
#define X first
#define Y second
using namespace std;
template<class T> inline void read(T&x){bool fu=0;char c;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x=-x;};
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z){read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
//head
char s[N],p[N];int n,m,dp[N][N],to[N],c[N];
int main() {
	scanf("%s%s",s+1,p+1);n=strlen(s+1),m=strlen(p+1);
	rep(i,1,n) {
		int j=1,k=i;while (j<=m&&k<=n){
			while (k<=n&&s[k]!=p[j])++k,++c[i];
			if(k<=n)++k,++j;
		}
		if (j<=m)c[i]=INF;else to[i]=k;
	}
	dep(i,n,1)rep(j,0,n-i+1){dp[i][j]=dp[i+1][j];if(j-c[i]<=n-to[i]+1&&j>=c[i])dp[i][j]=max(dp[i][j],dp[to[i]][j-c[i]]+1);}
	rep(i,0,n)printf("%d%c",dp[1][i],i==n?'\n':' ');
	return 0;
}