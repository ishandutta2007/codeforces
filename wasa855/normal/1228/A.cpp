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
bool vis[15];
bool judge(int x)
{
	memset(vis,false,sizeof(vis));
	while(x)
	{
		if(vis[x%10]==true) return false;
		vis[x%10]=true;
		x/=10;
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int l=read(),r=read();
	for(int i=l;i<=r;i++)
	{
		if(judge(i))
		{
			cout<<i<<endl;
			return 0;
		}
	 } 
	 cout<<"-1\n";
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}