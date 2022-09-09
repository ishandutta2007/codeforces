#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000050;
int a[N],last[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	ll all=0,tmp=0;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		tmp+=i-last[a[i]];
		last[a[i]]=i;
		all+=2*tmp-1;
	}
	cout<<fixed<<setprecision(12)<<(double)all/n/n<<"\n";
	return 0;
}