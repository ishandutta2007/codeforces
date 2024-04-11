#include<bits/stdc++.h>
#define rep(i,a,n) for(int _tmp=n,i=a;i<=_tmp;++i)
#define dep(i,a,n) for(int _tmp=n,i=a;i>=_tmp;--i)
#define re(i,a,n) for(int _tmp=n,i=a;i<_tmp;++i)
#define fec(i,a) for(__typeof a.begin() i=a.begin();i!=a.end();++i)
#define For(i,v,u) for(int i=H[u],v=to[i];i;i=nxt[i],v=to[i])
#define si(x) (int)x.size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define inf 10000000
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=16;
//head
int dp[1<<16][200];
void MAX(int &a,int b){if(a<b)a=b;}
void MIN(int &a,int b){if(a>b)a=b;}
int n,r[N],b[N];
bool op[N];
int totr,totb;
int main() {
	read(n);re(i,0,n){
		char s[5];
		scanf("%s%d%d",s,&r[i],&b[i]);
		if(s[0]=='R')op[i]=0;else op[i]=1;
		totr+=r[i];totb+=b[i];
	}
	memset(dp,-1,sizeof dp);dp[0][0]=0;
	int mx=0;
	rep(i,1,n)mx+=i;
	int all=1<<n;
	re(S,0,all)rep(j,0,mx){
		int c=dp[S][j];if(c==-1)continue;
		int A=0,B=0;
		re(i,0,n)if(S>>i&1){
			if(op[i]==0)A++;
			else B++;
		}
		re(i,0,n){
			if(S>>i&1)continue;
			MAX(dp[S^(1<<i)][j+min(r[i],A)],c+min(b[i],B));
		}
	}
	int ans=2000000000;
	rep(j,0,mx){
		if(~dp[all-1][j])MIN(ans,max(totr-j,totb-dp[all-1][j]));
	}
	cout<<ans+n;
	return 0;
}