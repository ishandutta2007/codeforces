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
map<int,int> a;
void work()
{
	int x=read(),y=read();
	if(x>=y)
	{
		cout<<"Yes\n";return ;
	}
	if(x>=100)
	{
		cout<<"Yes\n";return ;
	}
	a.clear();
	while(1)
	{
		if(a[x]==1)
		{
			cout<<"No\n";return ;
		}
		if(x>=100||x>=y)
		{
			cout<<"Yes\n";return ;
		}
		a[x]=1;
		if(x%2==0) x=3*x/2;
		else x--;
	}
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