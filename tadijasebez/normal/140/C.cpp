#include <stdio.h>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#define mp make_pair
vector<int> tmp,sol;
vector< pair<int,int> > v;
int k;
map<int,int> C;
map<int,int>::iterator it;
int min(int a, int b){ return a>b?b:a;}
int main()
{
	int n,i,j,x;
	scanf("%i",&n);
	for(i=1;i<=n;i++) scanf("%i",&x),C[x]++;
	for(it=C.begin();it!=C.end();it++) v.push_back(mp(it->second,it->first));
	int top=n,bot=0,mid;
	while(top>=bot)
	{
		mid=top+bot>>1;
		tmp.clear();
		for(i=0;i<v.size();i++) for(j=0;j<min(v[i].first,mid);j++) tmp.push_back(v[i].second);
		if(tmp.size()>=mid*3) k=mid,sol=tmp,bot=mid+1;
		else top=mid-1;
	}
	printf("%i\n",k);
	for(i=0;i<k;i++)
	{
		tmp.clear();
		tmp.push_back(sol[i]);
		tmp.push_back(sol[i+k]);
		tmp.push_back(sol[i+k+k]);
		sort(tmp.begin(),tmp.end());
		printf("%i %i %i\n",tmp[2],tmp[1],tmp[0]);
	}
	return 0;
}