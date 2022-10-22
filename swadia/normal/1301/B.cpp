#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int n;
int a[MAXN];
bool f[MAXN];

int getabs(int x,int y)
{
	if (x==-1 || y==-1)
		return -INF;
	return abs(x-y);
}
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>n;
		a[0]=-INF;
		a[n+1]=-INF;
		int cnt=0;
		for (int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			if (a[i]==-1)
				cnt++;
		}
		if (cnt==n)
		{
			printf("%d %d\n",0,0);
			continue;
		}
		int mx=-INF;
		int mi=INF;
		for (int i=1;i<=n;i++)
		{
			if (a[i]!=-1 && (a[i-1]==-1 || a[i+1]==-1))
			{
				mx=max(mx,a[i]);
				mi=min(mi,a[i]);
			}
		}
		//WRT(mx);
		//WRT(mi);
		int ans=-INF;
		for (int i=1;i<=n-1;i++)
			if (a[i]!=-1 && a[i+1]!=-1)
				ans=max(ans,abs(a[i+1]-a[i]));
		if (mx!=INF)
		{
			int tmp=(mx+mi)/2;
			printf("%d %d\n",max(max(mx-tmp,tmp-mi),ans),tmp);
		}
		else
			printf("%d %d\n",ans,1);
			
		
	}
	return ~~(0^_^0);
}