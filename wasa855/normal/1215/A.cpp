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
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n,m,x,y,a;
	cin>>n>>m>>x>>y>>a;
	int d=(x-1)*n+(y-1)*m;
	if(a<=d) cout<<"0 ";
	else cout<<a-d<<" ";
	if(x>y)
	{
		int d=min(m,a/y);
		a-=d*y;
		cout<<d+a/x<<endl;
	}
	else
	{
		int d=min(n,a/x);
		a-=d*x;
		cout<<d+a/y<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}