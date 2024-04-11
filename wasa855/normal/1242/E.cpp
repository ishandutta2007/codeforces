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
void print(vector<int> x){for(int i=0;i<(int)x.size();i++) printf("%d%c",x[i]," \n"[i==(int)x.size()-1]);}
#define N 300005
struct Node{int v,id;};
Node a[N];
int n;
vector<int> ans[N];
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++) a[i].v=read(),a[i].id=i;
	sort(a+1,a+n+1,[&](Node x,Node y){return x.v>y.v;});
	int m=0;
	deque<int> q;
	for(int i=1;i<=a[1].v;i++) q.pb(++m),ans[a[1].id].pb(m);
	for(int i=2;i<=n;i++)
	{
		auto [f,id]=a[i];
		int go=min(f-1,((int)q.size()+f-(i==n?3:a[i+1].v))/2);
		for(int j=1;j<go;j++) ans[id].pb(q.back()),q.pop_back();
		ans[id].pb(q.back());
		for(int j=go+1;j<f;j++) ans[id].pb(++m),q.pb(m);
		ans[id].pb(q.front());
		q.pb(q.front()),q.pop_front();
	}
	cout<<m<<endl;
	for(int i=1;i<=n;i++) print(ans[i]);
	return 0;
}