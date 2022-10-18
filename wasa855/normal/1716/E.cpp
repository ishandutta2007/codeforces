#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define DEBUG fprintf(stderr,"Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
//mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define fir first
#define sec second
#define mod 998244353
#define int long long
#define inf 0x3f3f3f3f
#define INF 0x3f3f3f3f3f3f3f3f
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%lld%c",x[i]," \n"[i==(int)x.size()-1]);}
struct Node
{
	int l,r,v,s;
	Node(int a=0,int b=0,int c=0,int d=0) {l=a,r=b,v=c,s=d;}
};
Node merge(Node x,Node y)
{
	int tl=max(x.l,x.s+y.l);
	int tr=max(y.r,y.s+x.r);
	int tv=max({x.v,y.v,x.r+y.l});
	int ts=x.s+y.s;
	return Node(tl,tr,tv,ts);
}
vector<Node> solve(vector<int> v)
{
	// print(v);
	if(v.size()==1) return {Node(v[0],v[0],v[0],v[0])};
	int n=v.size();
	vector<int> L(v.begin(),v.begin()+n/2),R(v.begin()+n/2,v.end());
	auto sl=solve(L),sr=solve(R);
	vector<Node> ans(n);
	for(int i=0;i<n/2;i++) ans[i]=merge(sl[i],sr[i]);
	for(int i=0;i<n/2;i++) ans[i+n/2]=merge(sr[i],sl[i]);
	return ans;
}
signed main()
{
	int n=read();
	vector<int> a(1<<n);
	for(int i=0;i<1<<n;i++) a[i]=read();
	auto ans=solve(a);
	int cur=0,Q=read();
	while(Q--)
	{
		cur^=1<<read();
		printf("%lld\n",max(0LL,ans[cur].v));
	}
	return 0;
}