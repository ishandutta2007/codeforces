#ifdef xay5421
#define D(...) fprintf(stderr,__VA_ARGS__)
#else
#define D(...) ((void)0)
//#define NDEBUG
#endif
#include<bits/stdc++.h>
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
using namespace std;
using LL=long long;
int n,deg[8005],bel[8005],num[8005];
bool g[8005][8005];
char s[2005];
LL ans;
int main(){
	scanf("%d",&n);
	rep(i,1,n){
		scanf("%s",s+1);
		rep(j,1,n/4){
			int t=isdigit(s[j])?s[j]-'0':s[j]-'A'+10;
			rep(k,0,3){
				g[i][j*4-k]=t>>k&1;
			}
		}
	}
	rep(i,1,n)rep(j,1,n)if(g[i][j])++deg[j];
	vector<int>que;
	rep(i,1,n)if(!deg[i])que.pb(i);
	int rem=n;
	rep(i,0,SZ(que)-1){
		int u=que[i];
		bel[u]=3;
		ans+=1LL*(614LL*n+1)*(--rem);
		rep(v,1,n)if(g[u][v]&&!--deg[v])que.pb(v);
	}
	if(!rem)printf("%lld\n",ans),exit(0);
	int x=max_element(deg+1,deg+1+n)-deg;
	rep(i,1,n)if(bel[i]!=3)bel[i]=i==x||g[i][x]?1:2;
	rep(i,1,n)if(bel[i]!=3)rep(j,1,n)if(bel[j]!=3)if(bel[i]!=bel[j]&&g[i][j])++num[j];
	rep(i,1,n)if(bel[i]!=3)rep(j,i+1,n)if(bel[j]!=3)ans+=3+(bel[i]==bel[j]&&num[i]==num[j]);
	printf("%lld\n",ans);
	return 0;
}