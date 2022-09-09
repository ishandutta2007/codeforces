#include <bits/stdc++.h>
using namespace std;
#define db long double
#define ll long long
const int N=100050;
int a[N];
db all[N];
struct BIT
{
	ll sum[N];
	BIT(){ for(int i=0;i<N;i++) sum[i]=0;}
	void Set(int i, int f){ for(;i;i-=i&-i) sum[i]+=f;}
	ll Get(int i){ ll ret=0;for(;i<N;i+=i&-i) ret+=sum[i];return ret;}
} Tree[2];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&a[i]);
	db sol=0;
	for(i=2;i<=n;i++) all[i]=(db)i*(i-1)/4;
	for(i=1;i<=n;i++) sol+=all[i]*(n-i+1);
	//cout << sol << "\n";
	for(i=1;i<=n;i++)
	{
		ll mul=Tree[0].Get(a[i]);
		int cnt=Tree[1].Get(a[i]);
		sol+=(db)cnt*n*(n+1)/2;
		sol-=(db)mul*(n-i+1);
		Tree[0].Set(a[i],i);
		Tree[1].Set(a[i],1);
	}
	sol=sol*2/n/(n+1);
	cout << fixed << setprecision(12) << sol << "\n";
	return 0;
}