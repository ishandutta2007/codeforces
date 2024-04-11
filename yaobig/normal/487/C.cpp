#include<bits/stdc++.h>
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,a,n) for(int i=n;i>=a;i--)
#define pb push_back
#define mp make_pair
#define FI first
#define SE second
#define maxn 100000
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef double db;

bool prime(int n)
{
	for(int i=2;i*i<=n;i++) if(n%i==0) return 0;
	return 1;
}

int mod;

ll qp(ll a,int k)
{
	ll res=1;
	while(k)
	{
		if(k&1) res=res*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return res;
}

int main()
{
	int n; scanf("%d",&n);
	if(n==1) puts("YES\n1");
	else if(n==4) puts("YES\n1\n3\n2\n4");
	else if(prime(n))
	{
		puts("YES");
		puts("1");
		mod=n;
		rep(i,2,n-1) printf("%d\n",i*qp(i-1,mod-2)%mod);
		printf("%d\n",n);
	}
	else puts("NO");
	return 0;
}