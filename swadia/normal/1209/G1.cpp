#include <bits/stdc++.h>
#define INL inline
#define REG register
#define DB double
#define LDB long double
#define ULL unsigned long long
#define LL long long

#define RPT(i,x,y) for (REG int i=(x);i<(y);i++)
#define DRPT(i,x,y) for (REG int i=(x);i>(y);i--)
#define MST(a,b) memset((a),(b),sizeof(a))
#define MRK() cout<<"Mark"<<endl;
#define WRT(x) cout<<#x<<" = "<<(x)<<endl;

#define MAXN 210000
#define MAXM 10000
#define MOD 998244353
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define EPS 1e-5

#define _ 0
using namespace std;

int a[MAXN];
int beg[MAXN];
int en[MAXN];
int size[MAXN];
int now;

int main()
{
	int sum=0;
	int n,q;
	cin>>n>>q;
	RPT(i,1,n+1)
	{
		cin>>a[i];
		if (beg[a[i]])
			beg[a[i]]=i;
		en[a[i]]=i;
		size[a[i]]++;
	}
	now=0;
	RPT(i,1,n+1)
	{
		if (i>now)
		{
			int mx=size[a[i]];
			int tmp=en[a[i]];
			RPT(j,i,tmp+1)
			{
				tmp=max(tmp,en[a[j]]);
				mx=max(mx,size[a[j]]);
			}
			//WRT(mx);
			//WRT(tmp);
			sum+=tmp-now-mx;
			now=tmp;
		}
	}	
	cout<<sum;
	return ~~(0^_^0);
}