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
int v1[N];
int v2[N];
int k1,k2;
int ans=0;
void query()
{
	printf("%d %d ",k1,k2);
	for(int i=1;i<=k1;i++) printf("%d ",v1[i]);
	for(int i=1;i<=k2;i++) printf("%d ",v2[i]);
	cout<<"\n";
	fflush(stdout);
	int res=read();
	if(res>ans) ans=res;
}
signed main()
{
#ifdef __LOCAL__
//	freopen("in.txt","r",stdin);
#endif
	int T=read();
	while(T--)
	{
		int n=read();
		ans=0;
		for(int i=0;i<=7;i++)
		{
			k1=k2=0;
			for(int j=1;j<=n;j++)
			{
				if(j&(1<<i)) v1[++k1]=j;
				else v2[++k2]=j;
			}
			if(k1>0&&k2>0) query();
		}
		cout<<"-1 "<<ans<<endl;
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}