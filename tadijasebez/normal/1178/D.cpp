#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
bool prime(int x)
{
	for(int i=2;i*i<=x;i++) if(x%i==0) return 0;
	return 1;
}
int main()
{
	/*for(int i=3,j;i<=1000;i++)
	{
		for(j=i;!prime(j);j++);
		if(i+i/2<=j) printf("%i\n",i);
	}*/
	int n,m;
	scanf("%i",&n);
	for(m=n;!prime(m);m++);
	vector<pair<int,int>> ans;
	for(int i=0;i<n;i++) ans.pb({i+1,(i+1)%n+1});
	int hal=(n+1)/2;
	for(int i=1;i<=m-n;i++)
	{
		ans.pb({i,i+hal});
	}
	printf("%i\n",ans.size());
	for(auto p:ans) printf("%i %i\n",p.first,p.second);
	return 0;
}