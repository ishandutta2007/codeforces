#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
#define mod 998244353
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
int add(int x,int y){return x+y>mod?x+y-mod:x+y;}
int sub(int x,int y){return x-y<0?x-y+mod:x-y;}
#define N 200005
int a[N];
map<int,bool> vis;
int n,m;
int ans=0;
int pl[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	set<int> s;
	for(int i=1;i<=n;i++)
	{
		int u=read();
		vis[u]=1;
		s.insert(u);
	}
	vector<set<int>::iterator> del;
	int cnt=0;
	for(int i=1;;i++)
	{
//		cout<<cnt<<endl;
		set<int>::iterator j;
		del.clear();
//		cout<<s.size()<<endl;
		for(j=s.begin();j!=s.end();++j)
		{
			if(cnt==m) break;
			int l=(*j)-i,r=(*j)+i;
			if(vis[l]&&vis[r]) del.pb(j);
			if(!vis[l]) pl[++cnt]=l,ans+=i,vis[l]=1;
			if(cnt==m) break;
			if(!vis[r]) pl[++cnt]=r,ans+=i,vis[r]=1;
//			printf("%d %d\n",l,r);
		}
		if(cnt==m) break;
//		cout<<s.size()<<endl;
		for(auto j:del) s.erase(j);
	}
	cout<<ans<<endl;
	for(int i=1;i<=m;i++) printf("%lld ",pl[i]); cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}