#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
#define N 205
int a[N],b[N];
bool va[N],vb[N];
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		va[a[i]]=true;
	}
	int m;
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		b[i]=read();
		vb[b[i]]=true;
	}
//	cout<<a[1]<<endl;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
//			printf("%d %d\n",va[i],vb[j]);
			int s=a[i]+b[j];
			if(va[s]==false&&vb[s]==false)
			{
				printf("%d %d\n",a[i],b[j]);
				return 0;
			}
		}
	}
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}
//asevf