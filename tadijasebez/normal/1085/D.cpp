#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n,s,i,u,v;
	scanf("%i %i",&n,&s);
	vector<int> deg(n+1,0);
	for(i=1;i<n;i++) scanf("%i %i",&u,&v),deg[u]++,deg[v]++;
	int leaf=0;
	for(i=1;i<=n;i++) leaf+=deg[i]==1;
	cout<<fixed<<setprecision(12)<<(double)s/leaf*2<<"\n";
	return 0;
}