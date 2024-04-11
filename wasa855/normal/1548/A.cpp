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
#define N 200005
set<int> s[N];
int ans;
int get(int u)
{
	if(s[u].empty()) return 0;
	int maxn=*(--s[u].end());
	if(maxn>u) return 1;
	else return 0;
}
signed main()
{
	int n=read(),m=read(); ans=n;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if(get(u)) ans++;
		if(get(v)) ans++;
		s[u].insert(v),s[v].insert(u);
		if(get(u)) ans--;
		if(get(v)) ans--;
	}
	int Q=read();
	while(Q--)
	{
		int op=read();
		if(op==1)
		{
			int u=read(),v=read();
			if(get(u)) ans++;
			if(get(v)) ans++;
			s[u].insert(v),s[v].insert(u);
			if(get(u)) ans--;
			if(get(v)) ans--;
		}
		else if(op==2)
		{
			int u=read(),v=read();
			if(get(u)) ans++;
			if(get(v)) ans++;
			s[u].erase(v),s[v].erase(u);
			if(get(u)) ans--;
			if(get(v)) ans--;
		}
		else printf("%d\n",ans);
	}
	return 0;
}