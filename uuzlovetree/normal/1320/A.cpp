#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
using namespace std;
int n,b[maxn];
vector<int> A[1000005];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&b[i]);
	for(int i=1;i<=n;++i)A[b[i]-i+500000].push_back(b[i]);
	ll ans=0;
	for(int i=1;i<=1000000;++i)
	{
		ll res=0;
		for(int x:A[i])res+=x;
		ans=max(ans,res);
	}
	cout<<ans<<endl;
}