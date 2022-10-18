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
#define N 1000005
int prim[N],phi[N];
bool vis[N];
int cnt;
void init()
{
	phi[1]=1;
	int n=1000000;
	for(int i=2;i<=n;i++)
	{
		if(!vis[i])
		{
			phi[i]=i-1;
			prim[++cnt]=i;
		}
		for(int j=1;j<=cnt;j++)
		{
			if(i*prim[j]>n) break;
			vis[i*prim[j]]=true;
			phi[i*prim[j]]=phi[i]*phi[prim[j]];
			if(i%prim[j]==0)
			{
				phi[i*prim[j]]=phi[i]*prim[j];
				break;
			}
		}
	}
}
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	init();
	int n=read(),k=read();
	if(k==1)
	{
		cout<<3<<endl;
		return 0;
	}
	long long ans=0;
	sort(phi+1,phi+n+1);
//	for(int i=1;i<=n;i++)
//	{
//		printf("%d ",phi[i]);
//	}
//	cout<<"\n";
	for(int i=1;i<=k+2;i++) ans+=phi[i];
	cout<<ans<<endl;
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}

//