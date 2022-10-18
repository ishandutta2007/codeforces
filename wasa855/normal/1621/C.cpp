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
#define N 10005
int ans[N],vis[N];
int query(int p)
{
	printf("? %d\n",p); fflush(stdout);
	return read();
}
void work()
{
	int n=read();
	for(int i=1;i<=n;i++) ans[i]=vis[i]=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		// int cur=query(i);
		vector<int> p;
		while(1)
		{
			int t=query(i);
			if(vis[t]) break;
			p.pb(t),vis[t]=1;
		}
		p.pb(p[0]);
		for(int j=0;j+1<(int)p.size();j++) ans[p[j]]=p[j+1];
	}
	cout<<"! "; for(int i=1;i<=n;i++) printf("%d%c",ans[i]," \n"[i==n]);
	cout<<endl;
}
signed main()
{
	int T=read(); while(T--) work();
	return 0;
}