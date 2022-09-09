#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int inf=1e9+69;
const int N=200050;
const int M=31*N;
int x[M],ls[M],rs[M],clock,root;
void Set(int &c, int ss, int se, int qi)
{
	if(!c) c=++clock;
	x[c]++;
	if(ss==se) return;
	int mid=ss+se>>1;
	if(qi<=mid) Set(ls[c],ss,mid,qi);
	else Set(rs[c],mid+1,se,qi);
}
int Get(int c, int ss, int se, int qs, int qe)
{
	if(ss>qe || qs>se) return 0;
	if(qs<=ss && qe>=se) return x[c];
	int mid=ss+se>>1;
	return Get(ls[c],ss,mid,qs,qe)+Get(rs[c],mid+1,se,qs,qe);
}
vector< pair<int,int> > events;
int L[N],R[N],sol[N];
int main()
{
	int n,i;
	scanf("%i",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%i %i",&L[i],&R[i]);
		events.push_back(make_pair(L[i],i));
		events.push_back(make_pair(R[i],i));
	}
	sort(events.begin(),events.end());
	for(i=0;i<events.size();i++)
	{
		int time=events[i].first;
		int index=events[i].second;
		if(time==L[index])
		{
			sol[index]-=Get(root,-inf,inf,L[index],R[index]-1);
			Set(root,-inf,inf,R[index]);
		}
		else
		{
			sol[index]+=Get(root,-inf,inf,L[index],R[index]-1);
		}
	}
	for(i=1;i<=n;i++) printf("%i\n",sol[i]);
	return 0;
}