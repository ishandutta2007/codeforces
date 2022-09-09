#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
const int N=100050;
const int mod=1e9+7;
int sol[N],a[N];
vector<int> Find(int x, int n)
{
	vector<int> lo,hi;
	for(int i=1;i*i<=x;i++)
	{
		if(x%i==0)
		{
			if(i<=n) lo.pb(i);
			if(i*i!=x && x/i<=n) hi.pb(x/i);
		}
	}
	reverse(lo.begin(),lo.end());
	for(int i:lo) hi.pb(i);
	return hi;
}
void add(int &x, int y){ x+=y;if(x>=mod) x-=mod;}
int main()
{
	int n,i;
	scanf("%i",&n);
	sol[0]=1;
	for(i=1;i<=n;i++)
	{
		scanf("%i",&a[i]);
		vector<int> work=Find(a[i],n);
		for(int j:work) add(sol[j],sol[j-1]);
	}
	int ans=0;
	for(i=1;i<=n;i++) add(ans,sol[i]);
	printf("%i\n",ans);
	return 0;
}