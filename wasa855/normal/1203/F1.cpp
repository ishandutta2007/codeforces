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
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n=read(),r=read();
	for(int i=1;i<=n;i++)
	{
		int u=read(),v=read();
		if(v>=0) a.pb((Node){u,v});
		else b.pb((Node){u,v});
	}
	sort(a.begin(),a.end(),cmp1);
	sort(b.begin(),b.end(),cmp2);
	for(auto i:a)
	{
		if(r<i.a)
		{
			cout<<"NO\n";
			return 0;
		}
		r+=i.b;
		if(r<0)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	for(auto i:b)
	{
		if(r<i.a)
		{
			cout<<"NO\n";
			return 0;
		}
		r+=i.b;
		if(r<0)
		{
			cout<<"NO\n";
			return 0;
		}
	}
	cout<<"YES\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}