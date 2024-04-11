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
#define ll long long
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
void printv(vector<int> x){printf("%d ",(int)x.size());for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
int n,m,k;
void work()
{
	cin>>n>>m>>k;
	auto inc=[&](int x) {return x==n?1:x+1;};
	auto print=[&](int beg)
	{
		int q=n%m,t=n/m;
		vector<vector<int>> r(m);
		for(int i=0;i<q;i++) for(int j=1;j<=t+1;j++) r[i].pb(beg),beg=inc(beg);
		for(int i=q;i<m;i++) for(int j=1;j<=t;j++) r[i].pb(beg),beg=inc(beg);
		for(int i=0;i<m;i++) printv(r[i]);
	};
	int tmp=0,g=(n%m)*(n/m+1);
	for(int i=1;i<=k;i++) print(tmp+1),tmp=(tmp+g)%n;
	cout<<"\n";
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}