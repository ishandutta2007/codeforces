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
#define N 5005
char s[N];
int n,m,vis[200];
vector<int> p[200];
char t[N][N];
signed main()
{
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++) p[s[i]].pb(i);
	int ans=0;
	auto inc=[&](int x) {return x==n?1:x+1;};
	int q=0;
	for(int i='a';i<='z';i++)
	{
		m=0;
		for(int id:p[i])
		{
			m++; int cur=id;
			for(int j=1;j<=n;j++) t[m][j]=s[cur],cur=inc(cur);
		}
		// for(int k=1;k<=m;k++)
		// {
			// for(int c=1;c<=n;c++) putchar(t[k][c]);
			// cout<<"\n";
		// }
		// cout<<"\n";
		int mx=0;
		for(int j=2;j<=n;j++)
		{
			int cnt=0;
			q++;
			for(int k=1;k<=m;k++)
			{
				if(vis[t[k][j]]<q*2) vis[t[k][j]]=q*2,cnt++;
				else if(vis[t[k][j]]==q*2) vis[t[k][j]]=q*2+1,cnt--;
			}
			mx=max(mx,cnt);
		}
		ans+=mx;
	}
	printf("%.7lf\n",(double)ans/n);
	return 0;
}