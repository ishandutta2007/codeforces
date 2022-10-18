#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define Fast_IO ios::sync_with_stdio(false);
#define fir first
#define sec second
inline int read()
{
	char ch=getchar(); int nega=1; while(!isdigit(ch)) {if(ch=='-') nega=-1; ch=getchar();}
	int ans=0; while(isdigit(ch)) {ans=ans*10+ch-48;ch=getchar();}
	if(nega==-1) return -ans;
	return ans;
}
typedef pair<int,int> pii;
#define N 300005
int a[N][10];
int x[305];
int n,m;
signed main()
{
#ifdef __LOCAL__
	freopen("in.txt","r",stdin);
#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++) a[i][j]=read();
	}
	int l=0,r=1e9;
	int ansl,ansr;
	int lim=1<<m;
	while(l<=r)
	{
		int mid=(l+r)/2;
//		printf("%d : \n",mid);
		for(int i=0;i<lim;i++) x[i]=0;
		for(int i=1;i<=n;i++)
		{
			int res=0;
			for(int j=1;j<=m;j++)
			{
				if(a[i][j]>=mid) res|=(1<<(j-1));
			}
			x[res]=i;
//			printf("%d ",res);
		}
//		cout<<"\n";
		for(int i=0;i<lim;i++)
		{
			if(!x[i]) continue;
			for(int j=0;j<=lim;j++)
			{
				if(!x[j]) continue;
				if((i|j)==(lim-1))
				{
					l=mid+1;
					ansl=x[i],ansr=x[j];
					goto go;
				}
			}
		}
		r=mid-1;
		go:;
	}
	printf("%d %d\n",ansl,ansr);
#ifdef __LOCAL__
	printf("Time Used : %d\n",clock());
#endif
	return 0;
}