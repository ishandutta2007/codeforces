#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int N=200050;
const int mod=1e9+7;
vector<int> id;
int BIT[N],l[N],r[N];
void Set(int i, int f){ for(;i<N;i+=i&-i) BIT[i]+=f,BIT[i]%=mod;}
int Get(int i){ int ret=0;for(;i;i-=i&-i) ret+=BIT[i],ret%=mod;return ret;}
vector<int> L[N];
int main()
{
	int n,m,i,j;
	scanf("%i %i",&n,&m);
	id.push_back(n);
	id.push_back(0);
	for(i=1;i<=m;i++) scanf("%i %i",&l[i],&r[i]),id.push_back(l[i]),id.push_back(r[i]);
	sort(id.begin(),id.end());
	id.erase(unique(id.begin(),id.end()),id.end());
	Set(1,1);
	for(i=1;i<=m;i++) L[lower_bound(id.begin(),id.end(),r[i])-id.begin()].push_back(l[i]);
	int sol;
	for(i=1;i<id.size();i++)
	{
		sol=0;
		for(j=0;j<L[i].size();j++)
		{
			int index=lower_bound(id.begin(),id.end(),L[i][j])-id.begin();
			sol+=Get(i+1);
			sol%=mod;
			sol-=Get(index);
			if(sol<0) sol+=mod;
		}
		Set(i+1,sol);
	}
	printf("%i\n",sol);
	return 0;
}