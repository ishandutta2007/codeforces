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

int a,b,c;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		
	cin>>a>>b>>c;
	int ans=0;
	if (a>0)
	{
		a--;
		ans++;
	}
	if (b>0)
	{
		b--;
		ans++;
	}
	if (c>0)
	{
		c--;
		ans++;
	}
	if (a>=2 && b>=2 && c>=2)
	{
		a-=2;
		b-=2;
		c-=2;
		ans+=3;
	}
	else if (a>=1 && b>=1 && c>=2)
	{
		a-=1;
		b-=1;
		c-=2;
		ans+=2;
	}
	else if (a>=1 && b>=2 && c>=1)
	{
		a-=1;
		b-=2;
		c-=1;
		ans+=2;
	}
	else if (a>=2 && b>=1 && c>=1)
	{
		a-=2;
		b-=1;
		c-=1;
		ans+=2;
	}
	else if (a>=1 && b>=1)
	{
		a--;
		b--;
		ans++;
	}
	else if (a>=1 && c>=1)
	{
		a--;
		c--;
		ans++;
	}
	else if (c>=1 && b>=1)
	{
		c--;
		b--;
		ans++;
	}
	if (a>=1 && b>=1 && c>=1)
	{
		ans++;
	}
	cout<<ans<<endl;;
	}
	
	return ~~(0^_^0);
}