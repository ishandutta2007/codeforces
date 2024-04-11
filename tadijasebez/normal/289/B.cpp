#include <stdio.h>
#include <vector>
using namespace std;
const int inf=1000000000;
vector<int> v;
int abs(int x){ return x>0?x:-x;}
int ans,sol=inf;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,m,i,j,k,x;
	scanf("%i %i %i",&n,&m,&k);
	for(i=0;i<n;i++) for(j=0;j<m;j++) scanf("%i",&x),v.push_back(x);
	int p=v[0]%k;
	bool ok=true;
	for(i=0;i<v.size();i++) if(v[i]%k!=p) ok=false;
	if(!ok) return printf("-1\n"),0;
	for(i=0;i<v.size();i++) v[i]=v[i]/k;
	for(j=0;j<=10000;j++)
	{
		ans=0;
		for(i=0;i<v.size();i++)
		{
			ans+=abs(v[i]-j);
		}
		sol=min(sol,ans);
	}
	printf("%i\n",sol);
	return 0;
}