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
#define N 1000005
vector<int> v[N];
int a[N];
int ans[N];
int l[N],r[N],res[N];
int c[N];
struct Node
{
	int pl,dat;
};
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		v[i].pb(a[i]);
		for(int j=0;j<a[i];j++)
		{
			int x=read();
//			cout<<x<<endl;
			v[i].pb(x);
			if(res[i]<x) res[i]=x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		l[i]=a[i],r[i]=m-a[i]+1;
		if(a[i]==m)
		{
			for(int j=1;j<=a[i];j++)
			{
				ans[j]+=v[i][j];
			}
			continue;
		}
		if(l[i]>r[i])
		{
			deque<Node> q;
			for(int j=1;j<=m;j++)
			{
				if(j<=a[i])
				{
					while(!q.empty()&&v[i][j]>q.back().dat) q.pop_back();
				}
				while(!q.empty()&&q.front().pl<j+a[i]-m) q.pop_front();
				if(j<=a[i]) q.push_back((Node){j,v[i][j]});
//				cout<<v[1][1]<<endl;
				if(j>l[i]||j<r[i]) ans[j]+=max(q.front().dat,0LL);
				else ans[j]+=q.front().dat;
//				cout<<q.front().dat<<endl;
			}
		}
		else if(l[i]<r[i])
		{
			int pre=0;
			for(int j=1;j<=a[i];j++)
			{
				if(v[i][j]>pre) pre=v[i][j];
				ans[j]+=pre;
			}
			pre=0;
			for(int j=m,k=1;j>=m-a[i]+1;j--,k++)
			{
				if(v[i][a[i]-k+1]>pre) pre=v[i][a[i]-k+1];
				ans[j]+=pre;
			}
			c[l[i]+1]+=res[i],c[r[i]]-=res[i];
//			printf("%lld %lld %lld\n",l[i],r[i],res[i]);
		}
		else
		{
			int pre=0;
			for(int j=1;j<=a[i];j++)
			{
				if(v[i][j]>pre) pre=v[i][j];
				ans[j]+=pre;
			}
			pre=0;
			for(int j=m,k=1;j>m-a[i]+1;j--,k++)
			{
				if(v[i][a[i]-k+1]>pre) pre=v[i][a[i]-k+1];
				ans[j]+=pre;
			}
		}
		
//		for(int i=1;i<=m;i++)
//		{
//			printf("%lld ",ans[i]);
//		}
//		cout<<"\n";
	}
	int tmp=0;
	for(int i=1;i<=m;i++)
	{
		tmp+=c[i];
		printf("%lld ",tmp+ans[i]);
	}
	cout<<"\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//