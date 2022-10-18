#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define ll long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>=mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
int mul(int x,int y){return 1LL*x*y%mod;}
#define N 105
string a[N];
bool vis[N];
vector<int> x,y;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	vector<int> al;
	for(int i=1;i<=n;i++)
	{
		if(vis[i]) continue;
		for(int j=i+1;j<=n;j++)
		{
			if(vis[j]) continue;
			bool ok=1;
			for(int k=0;k<m;k++)
			{
				if(a[i][k]!=a[j][m-k-1]) ok=0;
			}
			if(ok)
			{
				x.pb(i),y.pb(j);
				vis[i]=vis[j]=1;
			}
		}
		bool ok=1;
		for(int k=0;k<m;k++)
		{
			if(a[i][k]!=a[i][m-k-1]) ok=0;
		}
		if(ok) al.pb(i);
	}
	int id=0;
	for(int i=0;i<al.size();i++)
	{
		if(!vis[al[i]]) id=al[i];
	}
	if(id)
	{
		cout<<(x.size()*2+1)*m<<endl;
		for(int i=0;i<x.size();i++) cout<<a[x[i]];
		cout<<a[id];
		for(int i=y.size()-1;i>=0;i--) cout<<a[y[i]];
		cout<<"\n";
	}
	else
	{
		cout<<(x.size()*2)*m<<endl;
		for(int i=0;i<x.size();i++) cout<<a[x[i]];
		for(int i=y.size()-1;i>=0;i--) cout<<a[y[i]];
		cout<<"\n";
	}
#ifdef __LOCAL__
	cout<<"Time Used : "<<clock()<<endl;
#endif
	return 0;
}