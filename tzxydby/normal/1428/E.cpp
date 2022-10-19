#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int n,k,a[N],c[N],sum,ans;
set<pair<int,int>>s;
int cal(int v,int t)
{
	int k=v/t,x=v%t;
	return k*k*(t-x)+(k+1)*(k+1)*x;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=1;
		sum+=cal(a[i],1);
		if(a[i]!=1)
			s.insert(make_pair(cal(a[i],2)-cal(a[i],1),i));
	}
	for(int i=1;i<=k-n;i++)
	{
		int x=s.begin()->second,y=s.begin()->first;
		s.erase(s.begin());
		sum+=y;
		c[x]++;
		if(c[x]!=a[x])
			s.insert(make_pair(cal(a[x],c[x]+1)-cal(a[x],c[x]),x));
	}
	cout<<sum<<endl;
	return 0;
}