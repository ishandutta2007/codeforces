// author: xay5421
// created: Mon Nov 15 21:12:04 2021
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
const int N=500005,INF=0X3F3F3F3F;
int n;
pair<int,int>dp[N*2],cost[N*2];
char s1[N],s2[N],s[N*2];
struct seg{
	int a,k,sz;
};
int main(){
	scanf("%s%s",s1+1,s2+1);
	{
		int len=strlen(s1+1);
		rep(i,1,len)s[++n]=s1[i],s[++n]=s2[i];
	}
	vector<seg>G;
	dp[0]={0,0};
	rep(i,1,n){ // G[0].k: undefined >n
		vector<seg>G1,G2;
		for(auto&x:G)if(x.a>1&&s[x.a-1]==s[i])G1.pb((seg){x.a-1,x.k,x.sz});
		int pos=-INF;
		for(auto&x:G1){
			if(x.a-pos!=x.k){
				G2.pb((seg){x.a,x.a-pos,1});
				if(x.sz>1)G2.pb((seg){x.a+x.k,x.k,x.sz-1});
			}else{
				G2.pb(x);
			}
			pos=x.a+x.k*(x.sz-1);
		}
		if(i>1&&s[i-1]==s[i])G2.pb((seg){i-1,i-1-pos,1}),pos=i-1;
		G2.pb((seg){i,i-pos,1});
		
		G.clear();
		seg cur=G2[0];
		rep(_,1,SZ(G2)-1){
			auto&x=G2[_];
			if(cur.k==x.k){
				cur.sz+=x.sz;
			}else{
				G.pb(cur);
				cur=x;
			}
		}
		G.pb(cur);
		/*D("i=%d G=",i);
		for(auto&x:G)D("(%d,%d,%d)",x.a,x.k,x.sz);
		D("\n");*/
		
		// dp
		dp[i]={INF,0};
		if(s[i]==s[i-1])dp[i]={dp[i-2].first,i-2};
		for(auto&x:G){
			pos=x.a+x.k*(x.sz-1);
			pair<int,int>cur={dp[pos-1].first+1,pos-1};
			if(x.sz>1)cur=min(cur,cost[x.a-x.k]);
			if(x.a-x.k>=0)cost[x.a-x.k]=cur;
			if(~i&1)dp[i]=min(dp[i],cur);
		}
	}
	if(dp[n].first>=INF)puts("-1"),exit(0);
	printf("%d\n",dp[n].first);
	int i=n;
	while(i){
		int i_=dp[i].second;
		if(i_<i-2){
			printf("%d %d\n",i_/2+1,i/2);
		}
		i=i_;
	}
	return 0;
}