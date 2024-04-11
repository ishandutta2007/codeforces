#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define int long long
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 100005
int x[N];
int c[N];
struct Node
{
	int d;
	bool operator < (const Node &x) const
	{
		return d>x.d;
	}
};
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) x[i]=read();
	int a=read();
	for(int i=1;i<=n;i++) c[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(x[i]-k>a*i)
		{
			cout<<"-1\n";
			return 0;
		}
	}
	priority_queue<Node> q;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		q.push((Node){c[i]});
		while(!q.empty()&&k<x[i])
		{
			ans+=q.top().d;
			q.pop();
			k+=a;
		}
		if(k<x[i])
		{
			cout<<"-1\n";
			return 0;
		}
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//