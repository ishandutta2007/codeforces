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
#define N 505
vector<pii> ans;
int siz[N],id[N],n;
set<int> s;
int Query(vector<int> x,vector<int> y,int z)
{
	cout<<x.size()<<"\n"; print(x);
	cout<<y.size()<<"\n"; print(y);
	cout<<z<<endl;
	cout<<"\n";
	return read();
}
void query(int nd,vector<int> v,int siz)
{
	if(!siz) return ;
	if((int)v.size()==siz)
	{
		for(int i:v) ans.eb(i,nd),s.erase(i);
		return ;
	}
	int mid=v.size()/2;
	vector<int> l,r;
	for(int i=0;i<mid;i++) l.pb(v[i]);
	for(int i=mid;i<(int)v.size();i++) r.pb(v[i]);
	int lsiz=Query({1},l,nd);
	query(nd,l,lsiz),query(nd,r,siz-lsiz);
}
signed main()
{
	cin>>n; siz[1]=n;
	for(int i=2;i<=n;i++)
	{
		vector<int> v;
		for(int j=2;j<=n;j++) v.pb(j);
		siz[i]=Query({1},v,i);
	}
	for(int i=1;i<=n;i++) id[i]=i;
	sort(id+1,id+n+1,[&](int x,int y){return siz[x]<siz[y];});
	for(int i=1;i<n;i++)
	{
		vector<int> v;
		for(int i:s) v.pb(i);
		if(!v.empty()) query(id[i],v,Query({1},v,id[i]));
		s.insert(id[i]);
	}
	for(int i:s) ans.eb(1,i);
	cout<<"ANSWER\n";
	for(auto [x,y]:ans) printf("%d %d\n",x,y);
	return 0;
}