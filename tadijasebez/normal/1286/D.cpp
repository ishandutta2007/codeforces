#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}
const int mod=998244353;
int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
void ckadd(int&a,int b){a=add(a,b);}
int sub(int a,int b){a-=b;return a<0?a+mod:a;}
void cksub(int&a,int b){a=sub(a,b);}
int mul(int a,int b){return (ll)a*b%mod;}
void ckmul(int&a,int b){a=mul(a,b);}
int powmod(int x,int k){int ans=1;for(;k;k>>=1,ckmul(x,x))if(k&1)ckmul(ans,x);return ans;}
int inv(int x){return powmod(x,mod-2);}
const int N=100050;
const int M=2*N;
const ll inf=1e18;
int p[N];
int tme[N][2][2],now;
struct Node{
	int dp[2][2],ss,se;
	Node(){}
	Node(int x){
		ss=se=x;
		dp[0][1]=dp[1][0]=0;
		dp[0][0]=sub(1,p[x]);
		dp[1][1]=p[x];
	}
	int get(){return add(add(dp[0][0],dp[0][1]),add(dp[1][0],dp[1][1]));}
}node[M];
Node operator+(Node a,Node b){
	Node ans;ans.ss=a.ss;ans.se=b.se;
	for(int i=0;i<2;++i)
		for(int j=0;j<2;++j){
			ans.dp[i][j]=0;
			for(int k=0;k<2;k++)
				for(int l=0;l<2;l++)if(tme[a.se][k][l]>now){
					ckadd(ans.dp[i][j],mul(a.dp[i][k],b.dp[l][j]));
				}
		}
	return ans;
}
int ls[M],rs[M],tsz,root;
void Build(int&c,int ss,int se){
	c=++tsz;if(ss==se){node[c]=Node(ss);return;}
	int mid=ss+se>>1;
	Build(ls[c],ss,mid);
	Build(rs[c],mid+1,se);
	node[c]=node[ls[c]]+node[rs[c]];
}
void Upd(int c,int ss,int se,int qi){
	if(ss==se)return;
	int mid=ss+se>>1;
	if(qi<=mid)Upd(ls[c],ss,mid,qi);
	else Upd(rs[c],mid+1,se,qi);
	node[c]=node[ls[c]]+node[rs[c]];
}
int x[N],v[N];
pll ck(ll q,ll p){return q>0?(pll){p,q}:(pll){inf,1};}
int main(){
	int n=ri(),inv_100=inv(100);
	for(int i=1;i<=n;i++){
		rd(x[i],v[i],p[i]);
		ckmul(p[i],inv_100);
	}
	vector<pair<pll,int>> sts;
	for(int i=1;i<n;i++){
		ll dst=x[i+1]-x[i];
		sts.pb({ck(v[i+1]-v[i],dst),i*4+0});
		sts.pb({{dst,v[i+1]+v[i]},i*4+1});
		sts.pb({{inf,1},i*4+2});
		sts.pb({ck(v[i]-v[i+1],dst),i*4+3});
	}
	sort(sts.begin(),sts.end(),[&](pair<pll,int> a,pair<pll,int> b){
		if(a.first.first==inf)return false;
		if(b.first.first==inf)return true;
		return a.first.first*b.first.second<b.first.first*a.first.second;
	});
	for(int i=0;i<sts.size();i++)tme[sts[i].second/4][sts[i].second%2][sts[i].second/2%2]=i+1;
	now=0;
	Build(root,1,n);
	vector<pii> dp;
	dp.pb({1,0});
	for(int i=0;i<sts.size();i++){
		if(sts[i].first.first==inf)break;
		now++;Upd(root,1,n,sts[i].second/4);
		dp.pb({node[root].get(),mul(sts[i].first.first%mod,inv(sts[i].first.second%mod))});
	}
	int ans=0;
	for(int i=1;i<dp.size();i++)ckadd(ans,mul(dp[i].second,sub(dp[i-1].first,dp[i].first)));
	printf("%i\n",ans);
	return 0;
}