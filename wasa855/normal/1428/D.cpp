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
#define N 100005
vector<pii> ans;
int pos[N][2],a[N],n;
signed main()
{
	cin>>n; for(int i=1;i<=n;i++) a[i]=read();
	queue<int> q1,q2;
	int cnt=0;
	for(int i=n;i>=1;i--)
	{
		if(!a[i]) continue;
		if(a[i]==1)
		{
			pos[i][0]=++cnt;
			ans.eb(i,cnt);
			q1.push(i);
		}
		else if(a[i]==2)
		{
			if(q1.empty()) {cout<<"-1\n"; return 0;}
			int u=q1.front(); q1.pop();
			pos[i][0]=pos[u][0];
			ans.eb(i,pos[i][0]);
			q2.push(i);
		}
		else
		{
			if(!q2.empty())
			{
				int u=q2.front(); q2.pop();
				pos[i][0]=pos[u][1]=++cnt;
				ans.eb(i,pos[i][0]);
				ans.eb(u,pos[u][1]);
				q2.push(i);
			}
			else if(!q1.empty())
			{
				int u=q1.front(); q1.pop();
				pos[i][0]=pos[u][1]=++cnt;
				ans.eb(i,pos[i][0]);
				ans.eb(u,pos[u][1]);
				q2.push(i);
			}
			else {cout<<"-1\n"; return 0;}
		}
	}
	cout<<ans.size()<<endl;
	for(auto [x,y]:ans) printf("%d %d\n",n-y+1,x);
	return 0;
}