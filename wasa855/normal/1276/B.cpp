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
#define N 500005
int f[N];
int x[N],y[N];
int find(int x)
{
	while(x!=f[x]) x=f[x]=f[f[x]];
	return x;
}
void work()
{
	int n,m,a,b;
	cin>>n>>m>>a>>b;
	for(int i=1;i<=n;i++) f[i]=i,x[i]=0,y[i]=0;
	for(int i=1;i<=m;i++)
	{
		int u=read(),v=read();
		if(u==a||v==a) x[find(u)]=x[find(v)]=1;
		else if(u==b||v==b) y[find(u)]=y[find(v)]=1;
		else if(f[find(u)]!=f[find(v)])
		{
			x[find(v)]|=x[find(u)];
			y[find(v)]|=y[find(u)];
			f[find(u)]=f[find(v)];
		}
	}
	int ca=0,cb=0;
	for(int i=1;i<=n;i++)
	{
		if(i!=a&&i!=b)
		{
			if((x[find(i)]&&!y[find(i)])) ca++;
			if((y[find(i)]&&!x[find(i)])) cb++;
		}
	}
	cout<<ca*cb<<endl;
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--) work();
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}