#include <stdio.h>
#include <vector>
using namespace std;
const int N=200050;
const int M=2*N;
vector<int> Lazy[N];
int x[M],ls[M],rs[M],clock,root,a[N],id[N];
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
vector< pair<int,int> > Q[N];
int sol[N];
int main()
{
	int n,m,i,l,r,j;
	scanf("%i %i",&n,&m);
	for(i=1;i<=n;i++) scanf("%i",&a[i]),id[a[i]]=i;
	for(i=1;i<=m;i++) scanf("%i %i",&l,&r),Q[l].push_back(make_pair(r,i));
	for(i=n;i;i--)
	{
		for(j=0;j<Lazy[i].size();j++) Set(root,1,N,Lazy[i][j]);
		for(j=1;j*j<=a[i];j++)
		{
			if(a[i]%j==0)
			{
				int k=a[i]/j;
				if(k==j)
				{
					if(id[j]>=i) Set(root,1,N,id[j]);
					else Lazy[id[j]].push_back(i);
				}
				else
				{
					if(id[j]>=i) Set(root,1,N,id[j]);
					else Lazy[id[j]].push_back(i);
					if(id[k]>=i) Set(root,1,N,id[k]);
					else Lazy[id[k]].push_back(i);
				}
			}
		}
		for(j=0;j<Q[i].size();j++)
		{
			sol[Q[i][j].second]=Get(root,1,N,i,Q[i][j].first);
		}
	}
	for(i=1;i<=m;i++) printf("%i\n",sol[i]);
	return 0;
}