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
const int N=1111;
//head
const int K=8;
int pre[K+5][N+5],n;
int dp[1<<K+1][K+5];
int find(int col,int len){
	if(pre[col][n]<len)return -1;
	int ps=lower_bound(pre[col]+1,pre[col]+n+1,len)-pre[col];
	return ps;
}
void MIN(int &x,int y){if(x>y)x=y;}
bool ok(int num){
	int len=num/K,yu=num%K,all=(1<<K)-1;
	rep(i,0,all)re(j,0,K)dp[i][j]=n+1;dp[0][0]=0;
	rep(i,0,all)
		re(j,0,K){
			if(dp[i][j]>n)continue;
			re(col,0,K){
				if(i&(1<<col))continue;
				rep(x,0,1){
					int ps=find(col,pre[col][dp[i][j]]+len+x);
					if(ps==-1)continue;
					MIN(dp[i^(1<<col)][j+x],ps);
				}
			}
		}
	return dp[all][yu]<=n;
}
int main() {
	read(n);rep(i,1,n){
		int x;read(x);x--;
		re(j,0,K)pre[j][i]=pre[j][i-1];
		pre[x][i]++;
	}
	int L=1,R=n;
	while(L<R){
		int md=(L+R+1)>>1;
		if(ok(md))L=md;
		else R=md-1;
	}
	printf("%d\n",L);
	return 0;
}