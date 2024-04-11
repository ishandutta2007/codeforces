#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define ldb long double
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main()
{
	int n;
	scanf("%i",&n);
	vector<int> a(n);
	for(int &i:a) scanf("%i",&i);
	for(int mask=0;mask<1<<n;mask++)
	{
		int sum[2];
		sum[0]=sum[1]=0;
		for(int i=0;i<n;i++) sum[__builtin_popcount((mask>>i)&1)]+=a[i];
		if(sum[0]%360==sum[1]%360) return 0*printf("YES\n");
	}
	printf("NO\n");
	return 0;
}