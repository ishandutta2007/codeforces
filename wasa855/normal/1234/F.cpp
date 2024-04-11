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
#define M (1<<20)
#define N 1000005
char a[N];
int f[M];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	scanf("%s",a+1);
	int n=strlen(a+1);
	for(int i=1;i<=n;i++)
	{
		bool used[25];
		memset(used,false,sizeof(used));
		int tmp=0;
		for(int j=i;j<=n;j++)
		{
			if(used[a[j]-'a'])
			{
				break;
			}
			used[a[j]-'a']=true;
			tmp|=(1<<(a[j]-'a'));
			if(j-i+1>f[tmp]) f[tmp]=j-i+1;
		}
	}
	for(int i=0;i<20;i++)
	{
		for(int j=0;j<M;j++)
		{
			if(j&(1<<i))
			{
				if(f[j^(1<<i)]>f[j]) f[j]=f[j^(1<<i)];
			}
		}
	}
//	cout<<"Passed\n";
	int ans=0;
	for(int i=0;i<M;i++)
	{
		if(f[i]+f[(M-1)^i]>ans) ans=f[i]+f[(M-1)^i];
	}
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}