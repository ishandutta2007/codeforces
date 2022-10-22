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

string s;
int a[MAXN];
int sum[MAXN];
int pool[MAXN<<1];
int *p=pool+MAXN;
int n;
int x;
int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		int ans=0;
		cin>>n>>x>>s;
		x=-x;
		for (int i=-n-5;i<n+5;i++)
			p[i]=0;
		for (int i=0;i<n;i++)
		{
			if (s[i]=='0')
				a[i]=-1;
			else
				a[i]=1;
			//WRT(a[i]);
		}
		sum[0]=a[0];
		p[sum[0]]++;
		for (int i=1;i<n;i++)
		{
			sum[i]=sum[i-1]+a[i];
			//WRT(sum[i]);
			p[sum[i]]++;
		}
		p[0]++;
		int d=sum[n-1];
		p[sum[n-1]]--;
		//WRT(d);
		//WRT(8%-2);
		bool f=0;
		for (int i=-n-3;i<n+3;i++)
		{
			//cout<<'!'<<i<<' '<<p[i]<<endl;
			int tmp=x-i;
			if ((tmp>0 && d>0 || tmp<0 && d<0 || tmp==0 || d==0) && p[i])
			{
				if (d==0 && tmp==0)
				{
					f=1;
				}
				if (d!=0 && tmp%d==0 )
					ans+=p[i];
				//WRT(ans);
			}
		}
		if (f)
		{
			cout<<-1<<endl;
			continue;
		}
		if (d==0 && !f)
		{
			cout<<0<<endl;
		}
		else
			if (!f)
				cout<<ans<<endl;
	}
	return ~~(0^_^0);
}