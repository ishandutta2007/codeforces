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
#define inf 1000000000
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
template<class T> inline void MAX(T&x,T y){if(x<y)x=y;}
template<class T> inline void MIN(T&x,T y){if(x>y)x=y;}
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
//head
const int N=22;
int n,k;
double p[N];
double dp[1<<20],ans[N];
int main() {
	read(n,k);
	int ct=0;
	rep(i,1,n)scanf("%lf",&p[i]),ct+=(p[i]>1e-9);
	dp[0]=1;
	MIN(k,ct);
	re(s,0,1<<n){
		int cnt=__builtin_popcount(s);
		if(cnt==k){
			rep(i,1,n)if(s>>(i-1)&1){
				ans[i]+=dp[s];
			}
		}
		double tot=0;
		rep(i,1,n)if(!(s>>(i-1)&1))tot+=p[i];
		if(tot<1e-9)continue;
		rep(i,1,n)if(!(s>>(i-1)&1)){
			dp[s|(1<<(i-1))]+=dp[s]*p[i]/(tot);
		}
	}
	rep(i,1,n)printf("%.10lf ",ans[i]);
	puts("");
	return 0;
}