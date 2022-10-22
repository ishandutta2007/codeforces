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

void get_factor(vector<LL> &v,LL n)
{
	v.clear();
	LL i;
	for (i=2;i*i<=n;i++)
		while (n%i==0)
		{
			n/=i;
			v.push_back(i);
		}
	if (n>=2)
		v.push_back(n);
}

LL gcd(LL x,LL y)
{
	if (x<y)
		swap(x,y); 
	if (y==0)
		return x;
	return gcd(y,x%y);
}
vector<LL> v;


LL gcd1(LL m,LL n)
{
	return n?gcd1(n,m%n):m;
}

LL gcd2(LL m,LL n)
{
	return m%n?gcd2(n,m%n):n;
}


LL a,m;
int main()
{
	LL t;
	cin>>t;
	while (t--)
	{
		cin>>a>>m;
		LL g=gcd2(a,m); 
		LL A=a/g;
		LL M=m/g;
		map<LL,LL> mp;
		v.clear();
		get_factor(v,M);
		for (auto p:v)
			mp[p]++;
		LL ans=M;
		for (auto p:mp)
			ans=ans/p.first*(p.first-1);
		//WRT(ans);
		cout<<ans<<endl;
	}
	return ~~(0^_^0);
}