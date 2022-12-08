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
using namespace std;
template<class T> inline void read(T&x){char c;bool fu=0;for(c=getchar();c<=32;c=getchar());if(c=='-')fu=1,c=getchar();for(x=0;c>32;c=getchar())x=x*10+c-'0';if(fu)x*=-1;}
template<class T> inline void read(T&x,T&y){read(x);read(y);}
template<class T> inline void read(T&x,T&y,T&z) {read(x,y);read(z);}
typedef long long ll;
typedef pair<int,int> pii;
const int N=22;
//head
ll jc[N],dp[N][N];
int a[N],k;
ll C(int n,int m){
	return jc[n]/jc[m]/jc[n-m];
}
ll get(int L){
	memset(dp,0,sizeof dp);
	dp[0][0]=1;
	rep(i,0,15)
		rep(j,0,a[i])
			rep(k,0,L-j)
			dp[i+1][k+j]+=dp[i][k]*C(L-k,j);
	return dp[16][L];
}
ll n;
int wei,ans[N];
int main() {
	read(n);read(k);n--;
	jc[0]=1;rep(i,1,20)jc[i]=jc[i-1]*i;
	rep(i,0,15)a[i]=k;
	wei=1;a[0]--;
	while(1){
		ll tmp=get(wei-1)*15;
		if(n>=tmp)n-=tmp;
		else break;
		++wei;
	}a[0]++;
	dep(i,wei,1){
		rep(j,i==wei,15)if(a[j]){
			a[j]--;
			ll tmp=get(i-1);
			if(n>=tmp)n-=tmp;
			else {
				ans[wei-i+1]=j;
				break;
			}
			a[j]++;
		}
	}
	rep(i,1,wei){
		if(ans[i]<10)printf("%d",ans[i]);
		else printf("%c",ans[i]-10+'a');
	}
	return 0;
}