#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 5005
int v[N];
int r[N],sum[N];
struct Node
{
	int a,b,c;
	int id;
};
Node a[N];
bool cmp(Node x,Node y)
{
	return x.c==y.c?v[x.id]>v[y.id]:x.c>y.c;
}
int A[N],B[N],C[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		A[i]=a[i].a=read(),B[i]=a[i].b=read(),C[i]=a[i].c=read();
		a[i].id=i,v[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		int x=read(),y=read();
		if(x>v[y]) v[y]=x;
	}
	int now=k;
	for(int i=1;i<=n;i++)
	{
		if(now<A[i])
		{
			cout<<"-1\n";
			return 0;
		}
		now+=B[i];
		r[i]=now;
	}
	int ans=0;
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)
	{
		bool x=1;
		for(int j=v[a[i].id];j<=n;j++)
		{
			if(r[j]<=A[j+1])
			{
				x=0;break;
			}
		}
		if(!x) continue;
		for(int j=v[a[i].id];j<=n;j++)
		{
			r[j]--;
		}
		ans+=a[i].c;
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}