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
void work()
{
	int n=read(),x=read();
	int maxd=0,maxn=0;
	int u,v;
	for(int i=1;i<=n;i++)
	{
		u=read(),v=read();
		if(u-v>maxd) maxd=u-v;
		if(u>maxn) maxn=u;
	}
	if(maxd==0)
	{
		if(maxn>=x) cout<<"1\n";
		else cout<<"-1\n";
	}
	else
	{
		int dd=x-maxn;
		if(dd<=0) cout<<"1\n";
		else cout<<1+dd/maxd+(bool)(dd%maxd)<<"\n";
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

//ascw