#include <bits/stdc++.h>
using namespace std;
#define ldb long double
int main()
{
	int n,i;
	vector<ldb> p,f;
	scanf("%i",&n);
	p.resize(n);
	for(i=0;i<n;i++)
	{
		cin>>p[i];
		if(p[i]==1) return 0*printf("1\n");
	}
	sort(p.begin(),p.end());
	ldb ans=0,tmp=0,rs=1;
	for(i=n-1;~i;i--)
	{
		tmp=tmp*(1-p[i])+rs*p[i];
		rs*=1-p[i];
		ans=max(ans,tmp);
	}
	cout<<fixed<<setprecision(12)<<ans<<"\n";
	return 0;
}