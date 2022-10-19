#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1000000000000000000ll
ll D,ans;
int p[]={2,3,5,7,11,13,17,19,23,29};
void dfs(int pos,ll n,int d,int prev)
{
	int i;
	ll n2=n;
	if(d==D)
	{
		ans=min(ans,n);
		return;
	}
	for(int i=1;i<=prev;i++)
	{
		if(n2>ans/p[pos])
			break;
		n2*=p[pos];
		if(D%(d*(i+1))==0)
			dfs(pos+1,n2,d*(i+1),i);
	}
}
int main()
{
	cin>>D;
	ans=INF;
	dfs(0,1,1,100);
	cout<<ans<<endl;
	return 0;
}