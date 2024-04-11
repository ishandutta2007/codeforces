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
#define N 105
#define M 60005
struct Node
{
	int a,b;
};
vector<Node> a,b;
bool cmp1(Node x,Node y)
{
	return x.a<y.a;
}
bool cmp2(Node x,Node y)
{
	return x.a+x.b>y.a+y.b;
}
int f[M];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read(),r=read();
	memset(f,-1,sizeof(f));
	for(int i=1;i<=n;i++)
	{
		int u=read(),v=read();
		if(v>=0) a.pb((Node){u,v});
		else b.pb((Node){u,v});
	}
	sort(a.begin(),a.end(),cmp1);
	sort(b.begin(),b.end(),cmp2);
	int tmp=0;
	for(auto i:a)
	{
		if(r>=i.a)
		{
			r+=i.b;
			tmp++;
		}
	}
	f[r]=tmp;
	for(auto i:b)
	{
		for(int j=max(i.a,-i.b);j<=r;j++)
		{
			if(f[j]!=-1&&f[j]+1>f[j+i.b])
			{
				f[j+i.b]=f[j]+1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=r;i++)
	{
		if(f[i]>ans) ans=f[i];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}