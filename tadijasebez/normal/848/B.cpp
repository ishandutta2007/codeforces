#include <stdio.h>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
const int N=100050;
map<int, vector<int> > Group;
map<int, vector<int> >::iterator it;
int t[N],x[N],y[N];
pair<int,int> sol[N];
bool Comp1(int i, int j)
{
	if(t[i]==t[j] && t[i]==1) return x[i]<x[j];
	if(t[i]==t[j] && t[i]==2) return x[i]>x[j];
	return t[i]<t[j];
}
bool Comp2(int i, int j)
{
	if(t[i]==t[j] && t[i]==1) return x[i]<x[j];
	if(t[i]==t[j] && t[i]==2) return x[i]>x[j];
	return t[i]>t[j];
}
int main()
{
	int n,w,h,i;
	scanf("%i %i %i",&n,&w,&h);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i %i",&t[i],&x[i],&y[i]);
		Group[x[i]-y[i]].push_back(i);
	}
	for(it=Group.begin();it!=Group.end();it++)
	{
		vector<int> tmp,ans;
		tmp=it->second;
		ans=tmp;
		sort(tmp.begin(),tmp.end(),Comp1);
		sort(ans.begin(),ans.end(),Comp2);
		for(i=0;i<tmp.size();i++)
		{
			if(t[tmp[i]]==1)
			{
				sol[ans[i]].first=x[tmp[i]];
				sol[ans[i]].second=h;
			}
			else
			{
				sol[ans[i]].first=w;
				sol[ans[i]].second=x[tmp[i]];
			}
		}
	}
	for(i=1;i<=n;i++) printf("%i %i\n",sol[i].first,sol[i].second);
	return 0;
}