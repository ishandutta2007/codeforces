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
string a,b,c;

int main()
{
	int t;
	cin>>t;
	while (t--)
	{
		cin>>a>>b>>c;
		bool f=true;
		for (int i=0;i<a.size();i++)
			if (c[i]!=a[i] && c[i]!=b[i])
			{
				f=0;
				break;
			}
		if (f)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return ~~(0^_^0);
}