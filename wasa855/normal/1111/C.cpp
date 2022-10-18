#include<bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a;
int n,k,A,B;
int work(int l,int r)
{
	int x=lower_bound(a.begin(),a.end(),l)-a.begin();
	int y=lower_bound(a.begin(),a.end(),r+1)-a.begin();
	y--;
	int k=y-x+1;
	if(k==0)
	{
		return A;
	}
	int re=(r-l+1)*B*k;
	if(l!=r)
	{
		int res=work(l,(l+r)/2)+work((l+r)/2+1,r);
		if(res<re)
		{
			re=res;
		}
	}
	return re;
}
signed main()
{
	cin>>n>>k>>A>>B;
	int u;
	for(int i=1;i<=k;i++)
	{
		scanf("%I64d",&u);
		a.push_back(u);
	}
	sort(a.begin(),a.end());
	cout<<work(1,1<<n)<<endl;
	return 0;
}