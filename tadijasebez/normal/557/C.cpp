#include <stdio.h>
#include <vector>
#include <map>
using namespace std;
const int N=100050;
vector<int> len[N];
map<int,int> cnt;
map<int,int>::iterator it;
int sol=1000000000;
int min(int a, int b){ return a>b?b:a;}
void Solve()
{
	int i,j,ovr=0;
	for(i=N-1;i;i--)
	{
		for(j=0;j<len[i].size();j++) cnt[len[i][j]]--;
		int k=len[i].size()-1,tmp=0,all=0;
		it=cnt.end();
		while(it!=cnt.begin())
		{
			it--;
			all+=it->first*it->second;
			int e=min(k,it->second);
			k-=e;
			tmp+=e*it->first;
		}
		sol=min(sol,ovr+all-tmp);
		for(j=0;j<len[i].size();j++) ovr+=len[i][j];
	}
	printf("%i\n",sol);
}
int l[N],s[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&l[i]);
	for(i=1;i<=n;i++) scanf("%i",&s[i]),len[l[i]].push_back(s[i]),cnt[s[i]]++;
	Solve();
	return 0;
}