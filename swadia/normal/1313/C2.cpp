#include <bits/stdc++.h>
#define DB double
#define LL long long

#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 510000
#define MAXM 410000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

LL a[MAXN];
int n;
typedef pair<LL,int> pii;
pii re[MAXN];
LL top=0;
LL sum1[MAXN];
LL sum2[MAXN];
int ans[MAXN];

int main()
{
	LL lst;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	if (n==1)
	{
		cout<<a[1];
		return 0;
	}
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=re[top].first)
		{
			re[++top]={a[i],i};
			sum1[i]=sum1[i-1]+a[i];
		}
		else
		{
			while (re[top].first>a[i])
				top--;
			sum1[i]=sum1[re[top].second]+a[i]*(i-re[top].second);
			re[++top]={a[i],i};
		}
	}
	for (int i=1;2*i<n+1;i++)
		swap(a[i],a[n-i+1]);
	//for (int i=1;i<=n;i++)
	//	cout<<a[i]<<' ';
	//cout<<endl;
	MST(re,0);
	top=0;
	for (int i=1;i<=n;i++)
	{
		if (a[i]>=re[top].first)
		{
			re[++top]={a[i],i};
			sum2[i]=sum2[i-1]+a[i];
		}
		else
		{
			while (re[top].first>a[i])
				top--;
			sum2[i]=sum2[re[top].second]+a[i]*(i-re[top].second);
			re[++top]={a[i],i};
		}
	}
	//for (int i=1;i<=n;i++)
	//	cout<<sum1[i]<<' '<<sum2[i]<<endl;
	for (int i=1;2*i<n+1;i++)
		swap(a[i],a[n-i+1]);
	LL ansv=0;
	int pos=0;
	for (int i=0;i<=n;i++)
		if (sum1[i]+sum2[n-i]>ansv)
		{
			//cout<<i<<' '<<sum1[i]<<' '<<sum2[n-i]<<endl;
			ansv=sum1[i]+sum2[n-i];
			pos=i;
		}
	//WRT(pos);
	lst=a[pos+1];
	ans[pos+1]=lst;
	for (int j=pos+2;j<=n;j++)
	{
		lst=min(lst,a[j]);
		ans[j]=lst;
	}
	lst=a[pos];
	ans[pos]=lst;
	for (int j=pos-1;j>=1;j--)
	{
		lst=min(lst,a[j]);
		ans[j]=lst;
		
	}
	for (int i=1;i<=n;i++)
		cout<<ans[i]<<' ';
	return ~~(0^_^0);
}